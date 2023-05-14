#include "repl.h"
#include "ui_repl.h"
#include "QueryUtil.h"
#include "Automata.h"

typedef QTextCursor Cursor;

// Object for Query util
Query QUERY;

REPL::REPL(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::REPL)
{
    ui->setupUi(this); // setup user interface
    setCentralWidget( ui->Editor ); // set the central widget as text box
    qApp->installEventFilter(this); // install the event filter for the application
    ui->Editor->setContextMenuPolicy(Qt::NoContextMenu); // remove the default context menu
//    QE.ReadyAppAttrs(ui->Editor);
    DecidePrompt( ui->Editor->textCursor() ); // inserting the first prompt
    LoginWnd LW;
    LW.show();
}
REPL::~REPL()
{
    delete ui;
}
void REPL::InsertPrompt( Cursor c )
{
    // show the collected query
    QueryMain = ""; // empty for the next round
    // defining the prompt insertion operation - take curosr as parameter
    ui->Editor->append(Prompt); // append prompt symbol
    c.movePosition( Cursor::End); // move the cursor to the end of the line
    ui->Editor->setTextCursor(c); // set the text cursor
    QueryStartPosition = QueryInsertPosition = c.position(); // holds the insert position and query start position
    Line = 2; // if this prompt opens vanish the previous sub prompt
}
void REPL::InsertLine( Cursor c )
{
    QueryMain += (QuerySegment + " "); // concatenate the query segments into main query
    if( !CodeHistory.contains(QuerySegment) ){
        CodeHistory.append(QuerySegment); // insert currently entered code into code history
        CurrentIndexCH++; // Increase current index of CHV
    }
    // defining the prompt insertion operation - take curosr as parameter
    QString LineString = QString( "%1  " ).arg(Line, 3,10) ; // decide the line number
    ui->Editor->append(LineString); // append line number
    c.movePosition( Cursor::End); // move the cursor to the end of the line
    ui->Editor->setTextCursor(c); // set the text cursor
    QueryStartPosition = QueryInsertPosition = c.position(); // hold the current insert position
    Line ++; // next line
}
QString REPL::DecidePrompt( Cursor c )
{
    c.movePosition( Cursor::End); // move the cursor to the end of the line
    EditorCurrentLineNumber++; // increase the line number
    QueryEndPosition = c.position(); // when enter is clicked then that is the query end position
    c.setPosition(QueryStartPosition); // set the start position - to select the text
    c.setPosition(QueryEndPosition, Cursor::KeepAnchor); // move the cursor to the end - to select the text
    QuerySegment = c.selectedText(); // extract the query from start to end
    if( QuerySegment.trimmed().size() == 0 && QueryMain.size() == 0 ) InsertPrompt( c ); // if nothing is entered then insert normal prompt
    else if( QuerySegment.trimmed().size() == 0 && QueryMain.size() != 0 ) return QueryMain.trimmed();
    else InsertLine(c); // if something is there then insert line sub prompt
    return "";
}
bool REPL::AuthSelectedText(Cursor c )
{
    // checkes whether paste operation applicable or not
    if( !(c.anchor() >= QueryInsertPosition && c.position() >= QueryInsertPosition) ) return true ; // if cut applied over selected text; it should check the selected text positions; if the selected text contains previous prompt then override event
    return false;
}
QString REPL::MultiToOneLine( QString line )
{
    // returns a single line string if applicable
    if( line.contains("\n") ) return line.replace("\n", " ") ; // replaces all the newline characters with space
    else return line; // return line
}
void REPL::PrintHistoryCode(QString HistoryCode, Cursor  TextCursor){
    TextCursor.setPosition( QueryStartPosition ); // move the cursor to the currnt prompt
    ui->Editor->setTextCursor(TextCursor); // set the cursor to the position
    TextCursor.insertText( HistoryCode ); // insert the code to specified cursor position
    TextCursor.movePosition( Cursor::End ); // move the cursor to the currnt prompt
    ui->Editor->setTextCursor(TextCursor); // set the cursor to the position
}
void REPL::HandleCodeHistory(bool KeyType){
    Cursor  TextCursor ( ui->Editor->textCursor() ); // defining the text cursor
    TextCursor.movePosition(Cursor::End); // First move to end of the line
    ui->Editor->setTextCursor(TextCursor); // set the text cursor
    int CurrentLineEnd = TextCursor.position(); // Store the end position
    int CodeHistoryIndex = DecideIndexingCHV(KeyType) ; // Get the next Code position
    QString HistoryCode = CodeHistory.at(CodeHistoryIndex) ; // get the next code from CHV
    TextCursor.setPosition(QueryStartPosition); // set the start position - to select the text
    TextCursor.setPosition(CurrentLineEnd, Cursor::KeepAnchor ); // Set Cursor at end-  Select the Text from start to end
    TextCursor.removeSelectedText(); // remove the selected code from prompt
    PrintHistoryCode(HistoryCode, TextCursor); // Print the Next Code
}
int REPL::DecideIndexingCHV(bool BoolKey ){
    // true for up ; false for down
    if( BoolKey ){ // for UP Key
        if(CurrentIndexCH == 0) CurrentIndexCH = CodeHistory.size() - 1 ; // if at o, then move the end of vector i.e. Size-1
        else CurrentIndexCH -- ; // else move back
    }else{ // for DOWN key
        if(CurrentIndexCH == CodeHistory.size() - 1 ) CurrentIndexCH = 0 ; // if at last, then move to first element of vector
        else CurrentIndexCH ++ ; // else move forward
    }
    return CurrentIndexCH; // return the next code index
}
StrList REPL::CollectMatchedKeywords(){
    StrList KeywordList ;
    KeywordList << "Hey" << "Hii" << "Cat" << "Tomboy" << "New" << "Things";
    return KeywordList;
}
void REPL::DisplaySuggestions( StrList KeywordList, Cursor TextCursor ){
    SuggestionBox = new QComboBox(this);
    SuggestionBox->addItems(KeywordList);
    if( PredictiveY < (ui->Editor->height() - 100) ) PredictiveY = (20 * EditorCurrentLineNumber);
    int LineEnd = TextCursor.position();
    TextCursor.setPosition(QueryStartPosition); // set the start position - to select the text
    TextCursor.setPosition(LineEnd, Cursor::KeepAnchor );
    if ( PredictiveX < (ui->Editor->width() - 60) ) PredictiveX = TextCursor.selectedText().size() * 5 + 20 ;
    SuggestionBox->move(PredictiveX, PredictiveY);
    SuggestionBox->showPopup();
}
bool REPL::eventFilter(QObject *obj, QEvent *event)
{
    // defining the event filter to modify event
    Cursor TextCursor ( ui->Editor->textCursor() ); // defining the text cursor
    if( obj == ui->Editor ) // events handled for editor
    {
        if( CodeHistory.isEmpty() ) CurrentIndexCH = -1;
        if( event->type() == QEvent::KeyPress ) // handling keyboard keys
        {
            QKeyEvent *KeyboardKey = static_cast<QKeyEvent *>(event); // holding the comming key event
            if( KeyboardKey->matches(QKeySequence::Copy) ) return false; // don't override these events
            else if( KeyboardKey->matches(QKeySequence::Redo) || KeyboardKey->matches(QKeySequence::Undo )) return true;
            else if( AuthSelectedText(TextCursor) && TextCursor.selectedText().size() != 0 ) return true; // Universally override for this condition
            else if( KeyboardKey->matches(QKeySequence::Paste) && TextCursor.position() >= QueryInsertPosition ){
                // modifying the paste operation so that it can paste multiple lines in a single line
                TextCursor.insertText( MultiToOneLine( QApplication::clipboard()->text() ) );
                return true;
            }
            // Universal ends
            if( TextCursor.position() < QueryInsertPosition )
            {
                // if the text cursor is at the prevoius prompt area then
                TextCursor.setPosition( QueryInsertPosition ); // move the cursor to the currnt prompt
                ui->Editor->setTextCursor(TextCursor); // set the cursor to the position
                return true;
            }
            else if( TextCursor.position() >= QueryInsertPosition ) // if the text cursor is exactly at current prompt or after the current prompt then
            {
                // override some key event
                if( TextCursor.position() == QueryInsertPosition ){ // if insert at a prompt
                    if( KeyboardKey->key() == Qt::Key_Backspace ) return true; // disable backspace key
                }
                if( KeyboardKey->key() == Qt::Key_Return ){ // insert new prompt for enter key
                    QString Query = DecidePrompt(TextCursor); // decide the prompt to be inserted
                    if(Query.size()){
                        QUERY.Parser(Query,ui->Editor,&CodeHistory);
                        TextCursor.movePosition(Cursor::End);
                        QueryStartPosition = TextCursor.position();
                        QueryMain=QuerySegment="";
                        DecidePrompt(TextCursor);
                    }
                    return true;
                }

                // Currently Disabled ;;; if(KeyboardKey->key() == Qt::Key_Space) DisplaySuggestions(CollectMatchedKeywords(), TextCursor );

                if( KeyboardKey->key() == Qt::Key_Up ){ // for previous commands return
                    if ( CurrentIndexCH != -1 ) HandleCodeHistory(true); // show post codes
                    return true;
                }
                if( KeyboardKey->key() == Qt::Key_Down && CurrentIndexCH != -1 ){ // for previous commands return
                    if ( CurrentIndexCH != -1 ) HandleCodeHistory(false); // show pre codes
                    return true;
                }

            }
        }
    }
    return QObject::eventFilter(obj, event);
}
