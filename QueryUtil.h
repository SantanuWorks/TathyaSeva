#ifndef QUERYUTIL_H
#define QUERYUTIL_H
#include <QApplication>
#include<QTextEdit>
#include "Automata.h"

typedef QVector<QString> StrVec;
typedef QStringList StrList ;
typedef QMap<QString,QString> MapStrStr ;
typedef QMap<QString,QStringList> MapStrStrList ;

Automata AUTA;

class Query{
public:
    MapStrStr CommonName_Value;
    MapStrStrList TokenKey_KeyList;

    Query();
    StrList TokensToCommonTokens( StrList Tokens );
    StrVec Tokenizer(QString Query);
    QString QueryRefiner(QString Query);
    void Parser( QString Query, QTextEdit *REPLWIN, QVector<QString>* CHV);
    QString StringDetector(QString Str);
    StrList DatatypeDetector( int index, int * ID, StrList Tokens );
    StrList KeywordDetector( int index, StrList Tokens );
    StrList IdentifierDetector( int index, int * ID, StrList Tokens );
    StrList NumericDetector( int index, int*ID, StrList Tokens );
    StrList LangDetector( int index, int*ID, StrList Tokens );
    void EmptyMaps();
};
Query::Query(){
    TokenKey_KeyList["DATATYPES"] = {};
    TokenKey_KeyList["IDENTIFIERS"] = {};
    TokenKey_KeyList["DATA"] = {};
    TokenKey_KeyList["LANGUAGES"] = {};
}
void Query::EmptyMaps(){
    TokenKey_KeyList["DATATYPES"] = {};
    TokenKey_KeyList["IDENTIFIERS"] = {};
    TokenKey_KeyList["DATA"] = {};
    TokenKey_KeyList["LANGUAGES"] = {};
    CommonName_Value = {};
}
StrList Query::Tokenizer(QString Query){
    StrList Tokens;
    Tokens = Query.split(LANG.Space);
    if ( Tokens.contains("") ) Tokens.removeAll("");
    return Tokens;
}
QString Query::QueryRefiner(QString Query){
    for( auto OP : LANG.OperatorList ) if( Query.contains(OP) ) Query.replace(OP," "+OP+" ");
    return Query;
}
QString Query::StringDetector(QString Str){
    regx StrMatch;
    int ID=0;
    QString Key;
    StrMatch.setPattern("\"[^\"]*\"");
    QRegularExpressionMatchIterator i = StrMatch.globalMatch(Str);
    while( i.hasNext() ){
        QRegularExpressionMatch m = i.next();
        if( m.hasMatch() ){
            Key = " STR"+QString::number(ID)+" ";
            Str.replace(Str.indexOf(m.captured(0)),m.captured(0).size(),Key);
            CommonName_Value.insert(Key.trimmed(),m.captured(0));
            LANG.STR_TOKENS << Key.trimmed();
            TokenKey_KeyList["DATA"] << Key.trimmed();
            ID++;
        }
    }
    return Str;
}
StrList Query::DatatypeDetector( int index, int * ID, StrList Tokens ){
    QString DatatypeKey = "DATATYPE", Datatype;
    DatatypeKey += QString::number(*ID);
    TokenKey_KeyList["DATATYPES"] << DatatypeKey;
    Datatype = Tokens[index].toLower();
    Tokens.replace(index, DatatypeKey);
    CommonName_Value.insert(DatatypeKey, Datatype);
    (*ID) ++ ;
    return Tokens;
}
StrList Query::KeywordDetector( int index, StrList Tokens ){
    QString Keyword = Tokens[index].toLower();
    Tokens.replace(index, LANG.KeywordVal_KeywordCode[Keyword]);
    CommonName_Value.insert(LANG.KeywordVal_KeywordCode[Keyword],Keyword);
    return Tokens;
}
StrList Query::IdentifierDetector( int index, int * ID, StrList Tokens ){
    QString IdentifierKey = "IDENTIFIER", Identifier;
    IdentifierKey += QString::number(*ID);
    TokenKey_KeyList["IDENTIFIERS"] << IdentifierKey;
    Identifier = Tokens[index];
    Tokens.replace(index, IdentifierKey);
    CommonName_Value.insert(IdentifierKey, Identifier);
    (*ID) ++ ;
    return Tokens;
}
StrList Query::NumericDetector(int index, int *ID, StrList Tokens){
    QString NumericString = Tokens[index];
    QString NumericKey = "NUMERIC";
    NumericKey += QString::number(*ID);
    TokenKey_KeyList["DATA"] << NumericKey;
    Tokens.replace(index, NumericKey);
    CommonName_Value.insert(NumericKey, NumericString);
    (*ID) ++ ;
    return Tokens;
}
StrList Query::LangDetector(int index, int *ID, StrList Tokens){
    QString LangStr = Tokens[index];
    QString LangKey = "LANG";
    LangKey += QString::number(*ID);
    TokenKey_KeyList["LANGUAGES"] << LangKey;
    Tokens.replace(index, LangKey);
    CommonName_Value.insert(LangKey, LangStr);
    (*ID) ++ ;
    return Tokens;
}
StrList Query::TokensToCommonTokens(StrList Tokens ){
    int i = 0;
    int DatatypeID = 0;
    int IdentifierID = 0;
    int NumericID = 0;
    int LanguageID = 0;
    int LangID = 0 ;
    for( i = 0 ; i < Tokens.length() ; i ++ ){
        if( LANG.isSTR_TOKEN(Tokens[i],LANG.STR_TOKENS) ) ;
        else if( LANG.OperatorList.contains(Tokens[i]) ) ;
        else if( LANG.EnvDatatypes.contains(Tokens[i],Qt::CaseInsensitive))
            Tokens = DatatypeDetector(i,&DatatypeID,Tokens);
        else if( LANG.isKeyword(Tokens[i])){
            Tokens = KeywordDetector(i,Tokens);
        }
        else if( (LangID = LANG.WhichNumericLang(Tokens[i])) != -1  ){
            if( LangID == LANG.EnvLang ){
                Tokens = NumericDetector(i,&NumericID,Tokens);
            }else{
                qWarning()  << ER.ErrorCode_ErrorValue["MISMATCHED_NUMERIC_LANG"];
            }
        }
        else if( LANG.isValidLang(Tokens[i]) ) Tokens = LangDetector(i,&LanguageID,Tokens);
        else if( LANG.isIdentifier(Tokens[i]) ) Tokens = IdentifierDetector(i,&IdentifierID,Tokens);
        else{
            qWarning() << ER.ErrorCode_ErrorValue["UNKNOWN_TOKEN"];
        }
        //piechart create student from df ;
    }
    return Tokens;
}
void Query::Parser(QString Query, QTextEdit *REPLWIN, QVector<QString>* CHV ){
    StrList TokenList, TokenCommonNames;
    MapStrStr StrMap;
    Query = StringDetector(Query);
    Query = QueryRefiner(Query);
    TokenList = Tokenizer(Query);
    TokenCommonNames = TokensToCommonTokens(TokenList);
    for( int i = 0 ; i < TokenList.size() ; i++ ) if( TokenList[i].startsWith("STR") ) TokenList[i] = CommonName_Value[TokenList[i]];
    AUTA.StartAutomata(TokenCommonNames,TokenList,TokenKey_KeyList,CommonName_Value,REPLWIN,CHV);
    EmptyMaps();
}
#endif // QUERYUTIL_H
