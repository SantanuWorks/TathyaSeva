#ifndef REPL_H
#define REPL_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QTextCursor>
#include <QClipboard>
#include <QKeySequence>
#include <QVector>
#include <QComboBox>
#include "loginwnd.h"

namespace Ui {
class REPL;
}

class REPL : public QMainWindow
{
    Q_OBJECT

public:
    explicit REPL(QWidget *parent = nullptr);
    ~REPL();
private:
    Ui::REPL *ui;

protected:



    // Properties

    QString Prompt = ">>  "; // prompt symbol used in the application
    int QueryInsertPosition ; // hold the insert position for query
    int QueryStartPosition = 0,  QueryEndPosition ; // define query start and end position
    QString QuerySegment, QueryMain = "" ; // initial query report
    int Line = 2; // provides line number to the subprompt
    QVector<QString> CodeHistory; // store code history
    int CurrentIndexCH = -1; // Code history current index // initially points to nothing in Code History
    int EditorCurrentLineNumber = 1; //Current Line Number
    QComboBox *SuggestionBox ; // Keyword Suggestion box
    int PredictiveX = 0, PredictiveY = 0 ; // Predictive Coordinates of cursor

    // Methods

    bool eventFilter(QObject *obj, QEvent *event); // filters events for application
    void InsertPrompt( QTextCursor c ); // inserts normal prompt
    void InsertLine( QTextCursor c ) ; // inserts sub prompt with line number
    bool AuthSelectedText( QTextCursor c ); // checks rules for selected text
    QString MultiToOneLine( QString line ); // converts multiple lines into single line
    QString DecidePrompt( QTextCursor c ); // decides which prompt will be used
    void PrintHistoryCode(QString HistoryCode,  QTextCursor TextCursor);
    int DecideIndexingCHV( bool upordown ); // CHV:Code History Vector - It will handle indexing
    void HandleCodeHistory( bool KeyType ); // handles the printing and internal operations for code history
//    QString GetCurrentTypingWord(); // It will collect the typing word using event handling
    QStringList CollectMatchedKeywords(); // collect and return matched words with typing word
    void DisplaySuggestions( QStringList KeywordList, QTextCursor TextCursor ); // Displays the collected words as combo box

};

#endif // REPL_H
