#ifndef LANGUAGEUTIL_H
#define LANGUAGEUTIL_H

#include <QApplication>
#include <QRegularExpression>
#include "FileHandler.h"

typedef QRegularExpression regx;
typedef QStringList StrList ;
typedef QMap<QString,QString> MapStrStr ;

enum LangID { ODIA, ENG, HINDI } ;

class Language{
public:
    // Data Members
    QString Operators ;
    regx Space;
    regx SingleQuoteStr, DoubleQuoteStr, String;
    StrList OperatorList ;
    MapStrStr LangX_LangEng;
    int CountLangs;
    int EnvLang;
    QString EnvLangName;
    StrList KeywordCodes ;
    StrList EnvKeywords;
    StrList EnvDatatypes;
    StrList EnvLangsList;
    regx EnvIdentifierRegx;
    regx EnvIntegerRegx;
    regx EnvFloatRegx;
    regx EnvScinotRegx;
    MapStrStr KeywordVal_KeywordCode;
    StrList STR_TOKENS;
    QString BGCOLOR ;
    QString TEXTCOLOR ;
    QString Title;
    // Member Functions
    Language();
    void InitiateLangVars();
    double SciNotStrToDouble( QString SciNotStr ); // Converts the Scientific Notation String to Double
    QString NonEngNumericToEng( QString NumericString ); // Converts other lang numeric value to eng numeric values
    void SetupLanx_LangEng() ;
    int WhichNumericLang( QString NumStr );
    void SetUpKeywordCode();
    StrList getEnvKeywords();
    StrList getEnvDatatypes();
    StrList getEnvLangsList();
    int getEnvLang();
    regx getEnvIdentifierRegx();
    regx getEnvIntegerRegx();
    regx getEnvFloatRegx();
    regx getEnvScinotRegx();
    bool isIdentifier( QString Name );
    bool isSTR_TOKEN(QString Token, StrList STR_TOKENS);
    bool isKeyword( QString Token );
    bool isEnvLang(int LangID );
    bool isValidLang(QString LangStr);
    bool isNumeric(QString Str);
    QString EnvLangString( int LangID );
    QString getEnvAttributes( QString Group, QString Key );
    int LangNameToID(QString LangName);

};
Language::Language(){
    InitiateLangVars();
}
void Language::InitiateLangVars(){
    CountLangs   = getEnvAttributes("EnvLang","Langs").split(" ").count();
    EnvLangName = getEnvAttributes("EnvLang","lang");
    EnvKeywords = getEnvKeywords();
    EnvDatatypes = getEnvDatatypes();
    EnvFloatRegx = getEnvFloatRegx();
    EnvIdentifierRegx = getEnvIdentifierRegx();
    EnvIntegerRegx = getEnvIntegerRegx();
    EnvScinotRegx = getEnvScinotRegx();
    EnvLang = getEnvLang();
    EnvLangsList = getEnvLangsList();
    Operators = getEnvAttributes("EnvLang","Operators") ;
    OperatorList = Operators.split(" ");
    KeywordCodes = getEnvAttributes("EnvLang","KeywordCodes").split(" ") ;
    Space.setPattern(getEnvAttributes("EnvLang","SpaceRegx"));
    DoubleQuoteStr.setPattern(getEnvAttributes("EnvLang","DoubleQuoteStrRegx"));
    SingleQuoteStr.setPattern(getEnvAttributes("EnvLang","SingleQuoteStrRegx"));
    String.setPattern(getEnvAttributes("EnvLang","StringRegx"));
    BGCOLOR = getEnvAttributes("EnvLang","ColorBG");
    TEXTCOLOR = getEnvAttributes("EnvLang","TextColor");
    Title = getEnvAttributes(getEnvAttributes("EnvLang","lang"),"AppName");
    SetupLanx_LangEng();
    SetUpKeywordCode();
}
QString Language::getEnvAttributes(QString Group, QString Key){
    QFile LangFile;
    LangFile.setFileName("P:/Projects/Qt Projects/TathyaSeva/Language.json");
    if(!LangFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    QString LangData = LangFile.readAll() ;
    QJsonDocument LangDoc = QJsonDocument::fromJson(LangData.toUtf8());
    QJsonObject LangObject = LangDoc.object();
    QJsonObject EnvLangObject = LangObject[Group].toObject() ;
    LangFile.close();
    return EnvLangObject[Key].toString();
}
regx Language::getEnvIdentifierRegx(){
    return regx(getEnvAttributes(EnvLangName,"Identifier"));
}
regx Language::getEnvScinotRegx(){
    return regx(getEnvAttributes(EnvLangName,"SciNotation"));
}
regx Language::getEnvFloatRegx(){
    return regx(getEnvAttributes(EnvLangName,"Floating"));
}
regx Language::getEnvIntegerRegx(){
    return regx(getEnvAttributes(EnvLangName,"Integer"));
}
bool Language::isIdentifier(QString Name){
    return ( EnvIdentifierRegx.match(Name).hasMatch() && (!EnvKeywords.contains(Name,Qt::CaseInsensitive)) );
}
StrList Language::getEnvKeywords(){
    return getEnvAttributes(EnvLangName,"Keywords").split(" ");
}
StrList Language::getEnvDatatypes(){
    return getEnvAttributes(EnvLangName,"Datatypes").split(" ");
}
int Language::getEnvLang(){
    return LangNameToID(EnvLangName);
}
int Language::LangNameToID(QString LangName){
    if( LangName == "English" ) return ENG;
    else if( LangName == "Hindi" ) return HINDI;
    else if( LangName == "Odia" ) return ODIA;
    else return -1;
}
StrList Language::getEnvLangsList(){
    return getEnvAttributes(EnvLangName,"Langs").split(" ");;
}
bool Language::isSTR_TOKEN(QString Token, StrList STR_TOKENS){
    return STR_TOKENS.contains(Token);
}
bool Language::isKeyword(QString Token){
    return EnvKeywords.contains(Token, Qt::CaseInsensitive) ;
}
bool Language::isEnvLang(int LangID){
    return (EnvLang == LangID) ;
}
void Language::SetupLanx_LangEng(){
    if( EnvLangName == "English" ) return ;
    StrList eDigits = QString("1,2,3,4,5,6,7,8,9,0").split(",");
    StrList EnvLangDigits = getEnvAttributes(EnvLangName,"Digits").split(",");
    for( int i = 0; i < 10 ; i ++  ) LangX_LangEng.insert(EnvLangDigits[i],eDigits[i]);
    LangX_LangEng.insert(".",".");
    LangX_LangEng.insert("-","-");
    LangX_LangEng.insert("+","+");
    LangX_LangEng.insert("e","e");
    LangX_LangEng.insert("E","E");
}
void Language::SetUpKeywordCode(){
    for(int i = 0 ; i < EnvKeywords.count() ; i ++) KeywordVal_KeywordCode.insert(EnvKeywords[i],KeywordCodes[i]);
}
double Language::SciNotStrToDouble( QString SciNotStr ){
    return SciNotStr.toDouble() ;
}
QString Language::NonEngNumericToEng( QString NumericString ){
    if (EnvLangName == "English") return NumericString;
    QString EngNumericString = "";
    for(auto digit : NumericString ) EngNumericString += LangX_LangEng[digit];
    return EngNumericString;
}
int Language::WhichNumericLang(QString NumStr){
    int LangID = -1 ;
    for( auto LangName:getEnvAttributes("EnvLang","Langs").split(" ") ){
        regx FloatRegx = regx(getEnvAttributes(LangName,"Floating"));
        regx IntRegx = regx(getEnvAttributes(LangName,"Integer"));
        regx SciRegx = regx(getEnvAttributes(LangName,"SciNotation"));
        if( FloatRegx.match(NumStr).hasMatch() || IntRegx.match(NumStr).hasMatch() || SciRegx.match(NumStr).hasMatch() ) return LangNameToID(LangName);
    }
    return LangID;
}
QString Language::EnvLangString(int LangID){
    if( LangID == ENG )
        return "English";
    else if( LangID == ODIA )
        return "Odia";
    else if( LangID == HINDI )
        return "Hindi";
    return "Unknown";
}
bool Language::isValidLang(QString LangStr){
    return EnvLangsList.contains(LangStr, Qt::CaseInsensitive);
}
bool Language::isNumeric(QString Str){
    if( WhichNumericLang(Str) == -1 ) return false;
    else return true;
}
#endif // LANGUAGEUTIL_H
