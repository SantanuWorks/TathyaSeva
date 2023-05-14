#ifndef ERROR_H
#define ERROR_H
#include <QApplication>
#include <QTextEdit>

typedef QMap<QString,QString> MapStrStr ;

class Error{
public:

    MapStrStr ErrorCode_ErrorValue;

    QString ErrorRedOpenTag = "<label style='color:red;' >" ;
    QString ErrorRedCloseTag = "</label>" ;

    QString ErrorPurpleOpenTag = "<label style='color:purple;' >" ;
    QString ErrorPurpleCloseTag = "</label>" ;

    QString ErrorUnderlineOpenTag = "<label style='text-decoration:underline;text-decoration-color:red;' >" ;
    QString ErrorUnderlineCloseTag = "</label>" ;

    // methods
    bool isError(QString Code );
    QString ErrorMesssage(QString ErrCode);
    void PrintError(QStringList Tokens, int index, QString ErrCode, QTextEdit * REPLWIN);
    QString PrepareErrorQuery(QStringList Tokens, int index);
    Error();
    void PrintSysGenError(QString ErrCode, QTextEdit *REPLWIN);
    void DatastoreDeleteSuggestionMessage(QTextEdit *REPLWIN);
};
Error::Error(){

    ErrorCode_ErrorValue.insert("INCOMPLETE_DATASTORE_LIST_QUERY","datastore list query is incomplete!");
    ErrorCode_ErrorValue.insert("INCOMPLETE_DATASTORE_CREATE_QUERY","datastore create query is incomplete!");
    ErrorCode_ErrorValue.insert("INCOMPLETE_TABLE_CREATE_QUERY","table create query is incomplete!");
    ErrorCode_ErrorValue.insert("INCOMPLETE_TABLE_INSERT_QUERY","table insert query is incomplete!");
    ErrorCode_ErrorValue.insert("INCOMPLETE_TABLE_CHANGE_QUERY","table change query is incomplete!");
    ErrorCode_ErrorValue.insert("INCOMPLETE_TABLE_ADD_QUERY","table add query is incomplete!");
    ErrorCode_ErrorValue.insert("INCOMPLETE_TABLE_RENAME_QUERY","table rename query is incomplete!");
    ErrorCode_ErrorValue.insert("INCOMPLETE_TABLE_CLEAR_QUERY","table clear query is incomplete!");
    ErrorCode_ErrorValue.insert("INCOMPLETE_TABLE_CLEAR_QUERY","table clear query is incomplete!");
    ErrorCode_ErrorValue.insert("INCOMPLETE_TABLE_DISPLAY_QUERY","table display query is incomplete!");
    ErrorCode_ErrorValue.insert("INCOMPLETE_TABLE_UPDATE_QUERY","table update query is incomplete!");
    ErrorCode_ErrorValue.insert("INCOMPLETE_TABLE_DELETE_QUERY","table delete query is incomplete!");
    ErrorCode_ErrorValue.insert("INCOMPLETE_TABLE_DISPLAY_QUERY","table display query is incomplete!");

    ErrorCode_ErrorValue.insert("INCOMPLETE_TABLE_SUM_QUERY","table sum query is incomplete!");
    ErrorCode_ErrorValue.insert("INCOMPLETE_TABLE_COUNT_QUERY","table count query is incomplete!");
    ErrorCode_ErrorValue.insert("INCOMPLETE_TABLE_AVG_QUERY","table average query is incomplete!");
    ErrorCode_ErrorValue.insert("INCOMPLETE_TABLE_MIN_QUERY","table min query is incomplete!");
    ErrorCode_ErrorValue.insert("INCOMPLETE_TABLE_MAX_QUERY","table max query is incomplete!");
    ErrorCode_ErrorValue.insert("INCOMPLETE_TABLE_MEAN_QUERY","table mean query is incomplete!");
    ErrorCode_ErrorValue.insert("INCOMPLETE_TABLE_MODE_QUERY","table mode query is incomplete!");
    ErrorCode_ErrorValue.insert("INCOMPLETE_TABLE_MEDIAN_QUERY","table median query is incomplete!");
    ErrorCode_ErrorValue.insert("INCOMPLETE_TABLE_FREQUENCY_QUERY","table frequency query is incomplete!");
    ErrorCode_ErrorValue.insert("INCOMPLETE_TABLE_SD_QUERY","table standard deviation query is incomplete!");
    ErrorCode_ErrorValue.insert("INCOMPLETE_TABLE_VARIENCE_QUERY","table varience query is incomplete!");

    ErrorCode_ErrorValue.insert("INCOMPLETE_PIECHART_CREATE_QUERY","piechart create query is incomplete!");
    ErrorCode_ErrorValue.insert("INCOMPLETE_LINEGRAPH_CREATE_QUERY","linegraph create query is incomplete!");
    ErrorCode_ErrorValue.insert("INCOMPLETE_BARGRAPH_CREATE_QUERY","bargraph create query is incomplete!");
    ErrorCode_ErrorValue.insert("INCOMPLETE_PIECHART_DISPLAY_QUERY","piechart display query is incomplete!");
    ErrorCode_ErrorValue.insert("INCOMPLETE_LINEGRAPH_DISPLAY_QUERY","linegraph display query is incomplete!");
    ErrorCode_ErrorValue.insert("INCOMPLETE_BARGRAPH_DISPLAY_QUERY","bargraph display query is incomplete!");
    ErrorCode_ErrorValue.insert("INCOMPLETE_PIECHART_DELETE_QUERY","piechart delete query is incomplete!");
    ErrorCode_ErrorValue.insert("INCOMPLETE_LINEGRAPH_DELETE_QUERY","linegraph delete query is incomplete!");
    ErrorCode_ErrorValue.insert("INCOMPLETE_BARGRAPH_DELETE_QUERY","bargraph delete query is incomplete!");

    ErrorCode_ErrorValue.insert("INCOMPLETE_PIECHART_RENAME_QUERY","piechart rename query is incomplete!");
    ErrorCode_ErrorValue.insert("INCOMPLETE_LINEGRAPH_RENAME_QUERY","linegraph rename query is incomplete!");
    ErrorCode_ErrorValue.insert("INCOMPLETE_BARGRAPH_RENAME_QUERY","bargraph rename query is incomplete!");

    ErrorCode_ErrorValue.insert("INCOMPLETE_PIECHART_LINK_QUERY","piechart link query is incomplete!");
    ErrorCode_ErrorValue.insert("INCOMPLETE_LINEGRAPH_LINK_QUERY","linegraph link query is incomplete!");
    ErrorCode_ErrorValue.insert("INCOMPLETE_BARGRAPH_LINK_QUERY","bargraph link query is incomplete!");

    ErrorCode_ErrorValue.insert("INVALID_PIECHART_NAME", "invalid piechart name!");
    ErrorCode_ErrorValue.insert("INVALID_BARGRAPH_NAME", "invalid bargraph name!");
    ErrorCode_ErrorValue.insert("INVALID_LINEGRAPH_NAME", "invalid linegraph name!");

    ErrorCode_ErrorValue.insert("INVALID_DATA_NAME", "invalid attribute name!");

    ErrorCode_ErrorValue.insert("INCOMPLETE_ENV_CLEAR_QUERY","env clear query is incomplete!");
    ErrorCode_ErrorValue.insert("INCOMPLETE_ENV_HISTORY_QUERY","env history query is incomplete!");
    ErrorCode_ErrorValue.insert("INCOMPLETE_ENV_EXIT_QUERY","env exit query is incomplete!");
    ErrorCode_ErrorValue.insert("INCOMPLETE_ENV_MEAN_QUERY","env mean query is incomplete!");
    ErrorCode_ErrorValue.insert("INCOMPLETE_ENV_MODE_QUERY","env mode query is incomplete!");
    ErrorCode_ErrorValue.insert("INCOMPLETE_ENV_MEDIAN_QUERY","env median query is incomplete!");
    ErrorCode_ErrorValue.insert("INCOMPLETE_ENV_SUM_QUERY","env sum query is incomplete!");
    ErrorCode_ErrorValue.insert("INCOMPLETE_ENV_MIN_QUERY","env min query is incomplete!");
    ErrorCode_ErrorValue.insert("INCOMPLETE_ENV_MAX_QUERY","env max query is incomplete!");
    ErrorCode_ErrorValue.insert("INCOMPLETE_ENV_AVG_QUERY","env average query is incomplete!");
    ErrorCode_ErrorValue.insert("INCOMPLETE_ENV_SD_QUERY","env standard deviation query is incomplete!");
    ErrorCode_ErrorValue.insert("INCOMPLETE_ENV_VARIENCE_QUERY","env varience query is incomplete!");
    ErrorCode_ErrorValue.insert("INCOMPLETE_ENV_FREQUENCY_QUERY","env frequency query is incomplete!");

    ErrorCode_ErrorValue.insert("INCOMPLETE_DATASTORE_DELETE_QUERY","datastore delete query is incomplete!");
    ErrorCode_ErrorValue.insert("INCOMPLETE_DATASTORE_CLEAR_QUERY","datastore delete query is incomplete!");
    ErrorCode_ErrorValue.insert("INCOMPLETE_DATASTORE_RENAME_QUERY","datastore delete query is incomplete!");
    ErrorCode_ErrorValue.insert("INCOMPLETE_DATASTORE_DISPLAY_QUERY","datastore display query is incomplete!");
    ErrorCode_ErrorValue.insert("INCOMPLETE_DATASTORE_USE_QUERY","datastore use query is incomplete!");
    ErrorCode_ErrorValue.insert("INCOMPLETE_DATASTORE_COUNT_QUERY","datastore count query is incomplete!");
    ErrorCode_ErrorValue.insert("INCOMPLETE_LANG_QUERY","lang display query is incomplete!");
    ErrorCode_ErrorValue.insert("UNKNOWN_TOKEN", "unrecognized token(s)!");
    ErrorCode_ErrorValue.insert("UNKNOWN_QUERY","unrecognized query!");
    ErrorCode_ErrorValue.insert("INVALID_DATASTORE_QUERY","invalid datastore query!");
    ErrorCode_ErrorValue.insert("INVALID_TABLE_QUERY","invalid table query!");
    ErrorCode_ErrorValue.insert("INVALID_PIECHART_QUERY","invalid piechart query!");
    ErrorCode_ErrorValue.insert("INVALID_LINEGRAPH_QUERY","invalid linegraph query!");
    ErrorCode_ErrorValue.insert("INVALID_BARGRAPH_QUERY","invalid bargraph query!");
    ErrorCode_ErrorValue.insert("MISSING_SEMICOLON","missing ; : can not find end of query!");
    ErrorCode_ErrorValue.insert("INVALID_DATASTORE_NAME", "invalid datastore name!");
    ErrorCode_ErrorValue.insert("INVALID_TABLE_NAME", "invalid table name!");
    ErrorCode_ErrorValue.insert("INVALID_STRUCTURE_NAME", "invalid structure name!");
    ErrorCode_ErrorValue.insert("DATASTORE_EXISTS", " datastore already exists!");
    ErrorCode_ErrorValue.insert("TABLE_EXISTS", " table already exists!");
    ErrorCode_ErrorValue.insert("DATASTORE_NOT_EXISTS", " datastore does not exists!");
    ErrorCode_ErrorValue.insert("TABLE_NOT_EXISTS", " table does not exists!");
    ErrorCode_ErrorValue.insert("INVALID_DATASTORE_DELETE_QUERY","invalid datastore delete query!");
    ErrorCode_ErrorValue.insert("INVALID_DATASTORE_CLEAR_QUERY","invalid datastore query!");
    ErrorCode_ErrorValue.insert("INVALID_ENV_QUERY","invalid env query!");
    ErrorCode_ErrorValue.insert("INVALID_LANG_QUERY","invalid lang query!");
    ErrorCode_ErrorValue.insert("EXPECTING_DATATYPE", "invalid token: expecting datatype!");
    ErrorCode_ErrorValue.insert("INVALID_COL_NAME", "invalid column name!");
    ErrorCode_ErrorValue.insert("INVALID_COUNT_ROW", "invalid number of columns!");
    ErrorCode_ErrorValue.insert("INVALID_ROW", "column(s) not present in table!");
    ErrorCode_ErrorValue.insert("INVALID_ROW_DATA", "type of data not not matching with column!");
    ErrorCode_ErrorValue.insert("DUPLICATE_COL", "columns are already present!");
    ErrorCode_ErrorValue.insert("COL_NOT_EXISTS", " col(s) not exists!");
    ErrorCode_ErrorValue.insert("NOT_BINARY_TABLE", "table should have two cols!");
    ErrorCode_ErrorValue.insert("NUMERIC_COLUMN_NOT_EXIST", "table should have atleast one numeric col!");

    ErrorCode_ErrorValue.insert("PIECHART_EXISTS", " piechart already exists!");
    ErrorCode_ErrorValue.insert("PIECHART_NOT_EXISTS", " piechart does not exists!");
    ErrorCode_ErrorValue.insert("BARGRAPH_EXISTS", " bargraph already exists!");
    ErrorCode_ErrorValue.insert("BARGRAPH_NOT_EXISTS", " bargraph does not exists!");
    ErrorCode_ErrorValue.insert("LINEGRAPH_EXISTS", " linegraph already exists!");
    ErrorCode_ErrorValue.insert("LINEGRAPH_NOT_EXISTS", " linegraph does not exists!");

    ErrorCode_ErrorValue.insert("FILEHANDLER_ERROR", "unexpected error while handling file, please try again!");
    ErrorCode_ErrorValue.insert("FILEHANDLER_CREATE_ERROR", "unexpected error while creating file, please try again!");
    ErrorCode_ErrorValue.insert("FILEHANDLER_REMOVE_ERROR", "unexpected error while removing file, please try again!");
    ErrorCode_ErrorValue.insert("FILEHANDLER_RENAME_ERROR", "unexpected error while renaming file, please try again!");
    ErrorCode_ErrorValue.insert("FILEHANDLER_LINK_ERROR", "unexpected error while linking, please try again!");

    ErrorCode_ErrorValue.insert("INVALID_COMMAND","invalid Command");
    ErrorCode_ErrorValue.insert("MISMATCHED_NUMERIC_LANG", "Numeric token is not matching with environment lang" );
    ErrorCode_ErrorValue.insert("INVALID_TABLE_NAME", "Invalid table name");
    ErrorCode_ErrorValue.insert("INVALID_PIECHART_NAME", "Invalid piechart name");

    ErrorCode_ErrorValue.insert("INVALID_DATA_NAME", "Invalid data name");
    ErrorCode_ErrorValue.insert("INVALID_LINEGRAPH_NAME", "Invalid linegraph name");
    ErrorCode_ErrorValue.insert("INVALID_BARGRAPH_NAME", "Invalid bargraph name");
    ErrorCode_ErrorValue.insert("EXPECTING_LANGUAGE", "invalid token: expecting language name");
    ErrorCode_ErrorValue.insert("INVALID_RENAME_COMMAND","Invalid rename command");
    ErrorCode_ErrorValue.insert("INVALID_CLEAR_COMMAND","Invalid clear command");
    ErrorCode_ErrorValue.insert("INVALID_DISPLAY_COMMAND","Invalid display command");
    ErrorCode_ErrorValue.insert("INVALID_DELETE_COMMAND","Invalid delete command");
    ErrorCode_ErrorValue.insert("EXPECTING_DATA", "invalid token: expecting valid data");
    ErrorCode_ErrorValue.insert("EXPECTING_NUMERIC_DATA", "invalid token: expecting valid numeric data");
}
QString Error::ErrorMesssage(QString ErrCode){
    return ErrorCode_ErrorValue[ErrCode];
}
bool Error::isError( QString Code){
    return ErrorCode_ErrorValue.contains(Code);
}
QString Error::PrepareErrorQuery(QStringList Tokens, int index){
    int i = 0 ;
    QString ErrorQuery = "";
    for( auto EachToken : Tokens ){
        if( i == index ){
            ErrorQuery = ErrorQuery + ErrorUnderlineOpenTag+EachToken+ErrorUnderlineCloseTag + " " ;
            continue;
        }
        ErrorQuery += (EachToken + " ");
        i ++;
    }
    return ErrorQuery;
}
void Error::PrintError(QStringList Tokens, int index, QString ErrCode, QTextEdit *REPLWIN){
    QString ErrorQueryMessage = PrepareErrorQuery(Tokens,index);
    REPLWIN->insertHtml("<br>"+ErrorRedOpenTag+"Error found in \" "+ErrorRedCloseTag+ErrorPurpleOpenTag+ErrorQueryMessage+ErrorPurpleCloseTag+ErrorRedOpenTag+"\""+ErrorRedCloseTag+"<br>");
    REPLWIN->insertHtml(ErrorRedOpenTag+"Error Code: "+ErrCode+ErrorRedCloseTag+"<br>");
    REPLWIN->insertHtml(ErrorRedOpenTag+"Error Message: "+ErrorCode_ErrorValue[ErrCode]+ErrorRedCloseTag);
}
void Error::PrintSysGenError(QString ErrCode, QTextEdit *REPLWIN){
    REPLWIN->insertHtml("<br>"+ErrorRedOpenTag+"Error Code: "+ErrCode+ErrorRedCloseTag+"<br>");
    REPLWIN->insertHtml(ErrorRedOpenTag+"Error Message: "+ErrorCode_ErrorValue[ErrCode]+ErrorRedCloseTag);
}
void Error::DatastoreDeleteSuggestionMessage(QTextEdit *REPLWIN){
    REPLWIN->insertHtml("<br>"+ErrorRedOpenTag+"Note: Datastore is not empty!"+ErrorRedCloseTag+"<br>");
    REPLWIN->insertHtml(ErrorRedOpenTag+"Try Query: "+ErrorRedCloseTag+"DATASTORE DELETE FORCE DARSTORE_NAME ;");
}
#endif // ERROR_H
