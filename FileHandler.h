#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <QApplication>
#include <QFile>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QDir>
#include <QStringList>
#include <QDate>
#include <QTime>
#include <QRegularExpression>
#include <QChart>
#include <QChartView>
#include <QPieSeries>
#include <QOpenGLWidget>
#include <QBarSeries>
#include <QBarSet>
#include <QLineSeries>
#include <QBarCategoryAxis>
#include <QValueAxis>
#include "Error.h"

typedef QStringList StrList ;
typedef QMap<QString,QString> MapStrStr;
typedef QMap<QString,QStringList> MapStrStrList ;
typedef QRegularExpression regx ;
typedef QMap<QString,QJsonArray> MapStrJA ;

Error ER;

struct DatastoreDefination{
    QJsonArray BargraphList;
    int CountBargraphs ;
    int CountLinegraphs ;
    int CountPiecharts ;
    int CountStructures ;
    int CountTables ;
    QString DOC ;
    QJsonArray LinegraphList ;
    QJsonArray PiechartList ;
    QJsonArray TableList ;
};
struct TableDefinition{
    QString Name;
    QString DOC;
    QString Datastore ;
    int CountRows;
    int CountCols;
    MapStrStr ColType;
};
struct PiechartDefinition{
    QString Name;
    QString DOC;
    QString Datastore ;
    int CountAttrs;
    QJsonArray Attrs;
    QString Link;
};
struct BargraphDefinition{
    QString Name;
    QString DOC;
    QString Datastore ;
    int CountAttrs;
    QJsonArray Attrs;
    QString Link;
};struct LinegraphDefinition{
    QString Name;
    QString DOC;
    QString Datastore ;
    int CountAttrs;
    QJsonArray Attrs;
    QString Link;
};

struct Datatypes{
    QString STRING;
    QString INT;
    QString FLOAT;
    regx STR_REGX;
    regx INT_REGX;
    regx FLT_REGX;
}DT;

class FileHandler{
public:

    QString TodayDateTime = QDate::currentDate().toString()+" "+QTime::currentTime().toString();

    QString TABLE = "<table border='1'>" ;
    QString _TABLE = "</table>";
    QString TH = "<th>" ;
    QString _TH = "</th>";
    QString TR = "<tr>" ;
    QString _TR = "</tr>";
    QString TD = "<th>" ;
    QString _TD = "</th>";

    QString STORAGE_PATH = "DATA/";
    QString DATASTORE_PATH = "P:/Projects/Qt Projects/TathyaSeva/DS.json";
    QString LANGUAGE_PATH = "P:/Projects/Qt Projects/TathyaSeva/Language.json";
    QString QUERY_FORMAT_PATH = "P:/Projects/Qt Projects/TathyaSeva/QueryFormat.json";
    QString TABLEINFO_PATH = "P:/Projects/Qt Projects/TathyaSeva/TableInfo.json";
    QString PIECHARTINFO_PATH = "P:/Projects/Qt Projects/TathyaSeva/PiechartInfo.json";
    QString LINEGRAPHINFO_PATH = "P:/Projects/Qt Projects/TathyaSeva/LinegraphInfo.json";
    QString BARGRAPHINFO_PATH = "P:/Projects/Qt Projects/TathyaSeva/BargraphInfo.json";
    QString TableExtsn = ".tbl";
    QString PiechartExtsn = ".pie";
    QString LinegraphExtsn = ".lin";
    QString BargraphExtsn = ".bar";
    QString DEFAULT_DATASTORE_PATH = "OPENSTORE_SYSTEM_DIR_RESTRICTED";
    QString DATASTORE_USE = DEFAULT_DATASTORE_PATH;

    QString DEFAULT_INT_VALUE = "0";
    QString DEFAULT_STR_VALUE = "";
    QString DEFAULT_FLOAT_VALUE = "0.0";

    //  QFile LangFile;
    FileHandler();
    ~FileHandler();

    QString GetEnvLang();
    void GetEnvTypeList();
    QString GetCurrentDS();
    void ChangeEnvLang( QString Lang );
    QJsonObject GetQueryStates( QString CommandType );
    StrList GetDirList();
    bool isDirExits(QString DirName);
    bool isEmptyDir(QString DirName);
    void AddDatastore(QString DirName);
    void AddDSAttr(QString DirName, DatastoreDefination DSD);
    void RemoveDatastore( QString DirName );
    void RenameDatastore(QString ODir,QString NDir);
    bool CreateDir(QString Name);
    bool DeleteDir(QString Name);
    bool DeleteForceDir(QString Name);
    bool ClearDir(QString Name);
    bool ClearDirContent(QString DirName, QString FileName);
    bool RenameDir(QString ODir,QString NDir);
    bool ChangeCurDS(QString DirName);
    int CountDSStructs(QString DirName, QString StructName);
    bool isTableExist(QString Tname);
    bool isPiechartExist(QString Pname);
    bool isBargraphExist(QString Bname);
    bool isLinegraphExist(QString Lname);
    void CreateTableFile(QString TableName, StrList Cols, StrList Dtypes);

    void UpdateDSInfo( QString Dir, QString StructType, QString StructName );
    void UpdateTableInfo(TableDefinition TD);
    void CreateEmptyTable(QString Name, StrList Cols);

    StrList GetDatastoreAll(QString DirName);
    StrList GetDatastoreTables(QString DirName);
    StrList GetDatastorePiecharts(QString DirName);
    StrList GetDatastoreLinegraphs(QString DirName);
    StrList GetDatastoreBargraphs(QString DirName);
    StrList JsonArrayToStrList(QJsonArray Arr);
    QJsonArray RemoveFromJA( QJsonArray Ja, QString Val );
    QJsonArray ReplaceInJA( QJsonArray Ja, QString Old, QString New );
    QJsonArray StrListToJA( StrList List );
    bool isContainsJA(QJsonArray Ja, QString Name);
    QString GetEnvLangAttr(QString Group, QString Attr);

    int CountRows(QString TableName);
    StrList MatchColumns(QString TableName, StrList Cols);
    StrList SetTableDatatypes(QString TableName, StrList Cols, StrList Values);
    void SetColumnTypes(QString TName,MapStrStr ColTypePair);
    bool isRequiredGenType(MapStrStr ColTypePair);
    MapStrStr GenerateTypes( Datatypes DT, StrList Cols , StrList Values , MapStrStr ColTypePair );
    StrList RecognizeTypeFromData(StrList Data);
    StrList isCorrectData_Types(StrList Values , StrList Types);
    void UpdateRowCount(QString Tname);
    void InsertIntoTable(QString TName, StrList Cols, StrList Values);

    void EditCol(QString Tname, QString Col, QString Type);
    void EditColTypes(QString TableName, StrList Cols, StrList Types);
    int GetRowCount(QString Tname);
    void EditColVal(QString TableName, QString Col, QJsonArray Arr);
    void EditColValues(QString TableName, StrList Cols, StrList Types);
    void ChangeTableDatatypes(QString TableName, StrList Cols, StrList Types);

    StrList FindRepeatCols(QString Tname, StrList Cols);
    void AddToTableFile(QString TableName, StrList Cols, StrList Types);
    void AddToTableInfo(QString TableName, StrList Cols, StrList Types);
    void AddToTableData(QString TableName, StrList Cols);
    bool RenameTable(QString Old , QString New);
    bool RenamePiechart(QString Old , QString New);
    bool RenameBargraph(QString Old , QString New);
    bool RenameLinegraph(QString Old , QString New);
    bool StructFileRename(QString Old , QString New, QString StuctName);
    void RenameStructAtInfo(QString Old , QString New, QString StuctName);
    void UpdateStructNameDS(QString Old,QString New, QString StuctType);
    void RenameTableCols(QString Tname,StrList OldCols,StrList NewCols);
    bool isEmptyTable(QString Tname);
    void EmptyTableData(QString Tname);
    StrList GetEmptyCols(QString Tname,StrList Cols);
    void ClearColData(QString Tname,StrList Cols);

    MapStrStrList GetTableData(QString Tname);
    MapStrStrList GetTableColData(QString Tname, StrList Cols);
    MapStrStrList GetTableFileData(QString Tname);

    bool RemoveStruct(QString Tname, QString StructName);
    void RemoveFromDS(QString Datastore, QString StructName, QString StructList);
    void RemoveFromStructInfo(QString StructName, QString StructType);
    bool RemoveTable(QString Tname);
    bool RemovePiechart(QString Tname);
    bool RemoveBargraph(QString Tname);
    bool RemoveLinegraph(QString Tname);
    StrList FindNotPresentCols(QString Tname, StrList Cols);
    void RemoveTableCols(QString Tname, StrList Cols);

    int GetColCount(QString Tname);
    bool AtleastOneNumericCol(QString Tname);
    bool TwoNumericCol(QString Tname);
    StrList FindNonNumericCols(QString Tname,StrList Cols);
    bool CreatePiechart(QString Name, StrList Attrs, StrList AttrVals);
    bool CreateLinegraph(QString Name, StrList Attrs, StrList AttrVals);
    bool CreateBargraph(QString Name, StrList Attrs, StrList AttrVals);
    bool CreatePieFileFromTable(QString Pname, QString Tname);
    bool CreateBarFileFromTable(QString Bname, QString Tname);
    bool CreateLineFileFromTable(QString Lname, QString Tname);
    void UpdatePiechartInfo(PiechartDefinition PD);
    void UpdateLinegraphInfo(LinegraphDefinition LD);
    void UpdateBargraphInfo(BargraphDefinition BD);
    MapStrJA GetXYPlots(QString Tname);

    bool CreatePieFromData(QString Name, StrList Attrs, StrList AttrVals);
    bool CreateBarFromData(QString Name, StrList Attrs, StrList AttrVals);
    bool CreateLineFromData(QString Name, StrList Attrs, StrList AttrVals);
    void StructLinkChange(QString Name, QString FilePath);
    void StructLinkWithTable(QString Name,QString Tname,QString StructType,QTextEdit* REPLWIN);

    MapStrStr GetStructData(QString Name,QString StructType);

    QChartView* CreatePiechartView(QString Pname, MapStrStr PieData);
    QChartView* CreateBargraphView(QString Pname, MapStrStr BarData);
    QChartView* CreateLinegraphView(QString Pname, MapStrStr LineData);

    double CalMean(StrList Datavals);
    double CalMode(StrList Datavals);
    double CalMedian(StrList Datavals);
    double CalSum(StrList Datavals);
    double CalMin(StrList Datavals);
    double CalMax(StrList Datavals);
    double CalAvg(StrList Datavals);
    double CalSD(StrList Datavals);
    double CalVarience(StrList Datavals);
    QMap<QString,int> CalFrequency(StrList Datavals);
    MapStrStrList GetColsVals(QString Tname, StrList Cols);

    MapStrStrList SortBy(MapStrStrList TableData,StrList Cols,StrList Odrs);


};

FileHandler::FileHandler(){
    GetEnvTypeList();
}
FileHandler::~FileHandler(){
    ChangeCurDS(DEFAULT_DATASTORE_PATH);
}
void FileHandler::GetEnvTypeList(){
    DT.STR_REGX = regx(GetEnvLangAttr("EnvLang","StringRegx"));
    DT.FLT_REGX = regx(GetEnvLangAttr(GetEnvLang(),"Floating"));
    DT.INT_REGX = regx(GetEnvLangAttr(GetEnvLang(),"Integer"));
    StrList EnvLangTypes = GetEnvLangAttr(GetEnvLang(),"Datatypes").split(" ");
    DT.STRING = EnvLangTypes[4];
    DT.FLOAT = EnvLangTypes[1];
    DT.INT = EnvLangTypes[0];
}
StrList FileHandler::JsonArrayToStrList(QJsonArray Arr){
    StrList SL = {};
    for( auto Each: Arr ) SL << Each.toString();
    return SL;
}
QJsonArray FileHandler::RemoveFromJA(QJsonArray Ja, QString Val){
    QJsonArray Arr;
    for( auto E:Ja ){
        if( E.toString() == Val ) continue;
        Arr.append(E);
    }
    return Arr;
}
QJsonArray FileHandler::ReplaceInJA(QJsonArray Ja, QString Old, QString New){
    QJsonArray Arr;
    int i = 0;
    for( auto E:Ja ){
        if( E.toString() == Old ){
            Arr.append( New );
            continue;
        }
        Arr.append(E);
        i ++;
    }
    return Arr;
}
QJsonArray FileHandler::StrListToJA(StrList List){
    QJsonArray Arr ;
    for( auto L : List ) Arr.append(L);
    return Arr;
}
bool FileHandler::isContainsJA(QJsonArray Ja, QString Name){
    for( auto E:Ja ) if( E.toString() == Name ) return true;
    return false;
}
QString FileHandler::GetEnvLang(){
    QFile LangFile;
    LangFile.setFileName(LANGUAGE_PATH);
    if(!LangFile.open(QIODevice::ReadWrite | QIODevice::Text));
    else{
        QString LangData = LangFile.readAll() ;
        QJsonDocument LangDoc = QJsonDocument::fromJson(LangData.toUtf8());
        QJsonObject LangObject = LangDoc.object();
        QJsonObject EnvLang =  LangObject["EnvLang"].toObject();
        return EnvLang["lang"].toString();
    }
    LangFile.close();
    return "";
}
QJsonObject FileHandler::GetQueryStates(QString CommandType){
    QFile QSFile;
    QSFile.setFileName(QUERY_FORMAT_PATH);
    if(!QSFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    QString QSData = QSFile.readAll() ;
    QJsonDocument QSDoc = QJsonDocument::fromJson(QSData.toUtf8());
    QJsonObject QSObject = QSDoc.object();
    QJsonObject QSCommandObject =  QSObject[CommandType].toObject();
    QSFile.close();
    return QSCommandObject;
}
StrList FileHandler::GetDirList(){
    QFile DirFile;
    StrList DatastoreList;
    DirFile.setFileName(DATASTORE_PATH);
    if(!DirFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    QString DirData = DirFile.readAll() ;
    QJsonDocument DirDoc = QJsonDocument::fromJson(DirData.toUtf8());
    QJsonObject DirObject = DirDoc.object();
    QJsonArray DirList = DirObject["ListDatastore"].toArray();
    DatastoreList = JsonArrayToStrList(DirList);
    DirFile.close();
    return DatastoreList;
}
void FileHandler::AddDSAttr(QString DirName, DatastoreDefination DSD){
    QFile DSFile;
    DSFile.setFileName(DATASTORE_PATH);
    if(!DSFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    QString DSData = DSFile.readAll() ;
    QJsonDocument DSDoc = QJsonDocument::fromJson(DSData.toUtf8());
    QJsonObject DSObject = DSDoc.object();
    QJsonValue DSDefVal = DSObject[DirName];
    QJsonObject DSDefObject = DSDefVal.toObject();
    DSDefObject["BargraphList"] = DSD.BargraphList;
    DSDefObject["CountBargraphs"] = DSD.CountBargraphs;
    DSDefObject["CountLinegraphs"] = DSD.CountLinegraphs;
    DSDefObject["CountPiecharts"] = DSD.CountPiecharts;
    DSDefObject["CountStructures"] = DSD.CountStructures;
    DSDefObject["CountTables"] = DSD.CountTables;
    DSDefObject["DOC"] = DSD.DOC;
    DSDefObject["LinegraphList"] = DSD.LinegraphList;
    DSDefObject["PiechartList"] = DSD.PiechartList;
    DSDefObject["TableList"] = DSD.TableList;
    DSObject[DirName] = DSDefObject;
    DSDoc.setObject(DSObject);
    DSFile.close();
    DSFile.setFileName(DATASTORE_PATH);
    if(!DSFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    DSFile.write(DSDoc.toJson());
    DSFile.close();
}
void FileHandler::AddDatastore(QString DirName){
    QFile DSFile;
    DSFile.setFileName(DATASTORE_PATH);
    if(!DSFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    QString DSData = DSFile.readAll() ;
    QJsonDocument DSDoc = QJsonDocument::fromJson(DSData.toUtf8());
    QJsonObject DSObject = DSDoc.object();
    QJsonValue DSListVal = DSObject["ListDatastore"];
    QJsonArray ListDS = DSListVal.toArray() ;
    ListDS.append(DirName);
    DSObject["ListDatastore"] = ListDS;
    DSDoc.setObject(DSObject);
    DSFile.close();
    DSFile.setFileName(DATASTORE_PATH);
    if(!DSFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    DSFile.write(DSDoc.toJson());
    DSFile.close();
    DatastoreDefination DirDFD;
    DirDFD = {QJsonArray(),0,0,0,0,0,TodayDateTime,QJsonArray(),QJsonArray(),QJsonArray()};
    AddDSAttr(DirName,DirDFD);
}
void FileHandler::RemoveDatastore(QString DirName){
    QFile DSFile;
    DSFile.setFileName(DATASTORE_PATH);
    if(!DSFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    QString DSData = DSFile.readAll() ;
    QJsonDocument DSDoc = QJsonDocument::fromJson(DSData.toUtf8());
    QJsonObject DSObject = DSDoc.object();
    QJsonValue DSListVal = DSObject["ListDatastore"];
    QJsonObject DSListObject = DSListVal.toObject();
    QJsonObject DirAttr = DSObject[DirName].toObject();
    QJsonArray ListDS = DSListVal.toArray() ;
    DSObject["ListDatastore"] = RemoveFromJA(ListDS,DirName);
    DSObject[DirName] = DSListObject;
    DSObject.remove(DirName);
    DSDoc.setObject(DSObject);
    DSFile.close();
    DSFile.setFileName(DATASTORE_PATH);
    if(!DSFile.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Truncate )) qWarning() << "Unsucessfull!";
    DSFile.write(DSDoc.toJson());
    DSFile.close();
}
void FileHandler::RenameDatastore(QString ODir, QString NDir){
    QFile DSFile;
    DSFile.setFileName(DATASTORE_PATH);
    if(!DSFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    QString DSData = DSFile.readAll() ;
    QJsonDocument DSDoc = QJsonDocument::fromJson(DSData.toUtf8());
    QJsonObject DSObject = DSDoc.object();
    QJsonValue DSListVal = DSObject["ListDatastore"];
    QJsonObject DSListObject = DSListVal.toObject();
    QJsonObject DirAttr = DSObject[ODir].toObject();
    QJsonArray ListDS = DSListVal.toArray() ;
    DSObject["ListDatastore"] = ReplaceInJA(ListDS,ODir,NDir);
    DSObject[ODir] = DSListObject;
    DSObject.remove(ODir);
    DSObject[NDir] = DirAttr;
    DSDoc.setObject(DSObject);
    DSFile.close();
    DSFile.setFileName(DATASTORE_PATH);
    if(!DSFile.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Truncate )) qWarning() << "Unsucessfull!";
    DSFile.write(DSDoc.toJson());
    DSFile.close();
}
bool FileHandler::isDirExits(QString DirName){
    if( DirName == DEFAULT_DATASTORE_PATH ) return true;
    QFile DSFile;
    DSFile.setFileName(DATASTORE_PATH);
    if(!DSFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    QString DSData = DSFile.readAll() ;
    QJsonDocument DSDoc = QJsonDocument::fromJson(DSData.toUtf8());
    QJsonObject DSObject = DSDoc.object();
    QJsonValue DSListVal = DSObject["ListDatastore"];
    QJsonObject DSListObject = DSListVal.toObject();
    QJsonObject DirAttr = DSObject[DirName].toObject();
    QJsonArray ListDS = DSListVal.toArray() ;
    DSFile.close();
    return isContainsJA(ListDS,DirName);
}
bool FileHandler::isEmptyDir(QString DirName){
    QFile DSFile;
    int count ;
    DSFile.setFileName(DATASTORE_PATH);
    if(!DSFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    QString DSData = DSFile.readAll() ;
    QJsonDocument DSDoc = QJsonDocument::fromJson(DSData.toUtf8());
    QJsonObject DSObject = DSDoc.object();
    QJsonValue DSListVal = DSObject[DirName];
    QJsonObject DSListObject = DSListVal.toObject();
    count = DSListObject["CountStructures"].toInt();
    DSFile.close();
    if( count ) return false;
    else return true;
}
bool FileHandler::CreateDir(QString Name){
    bool Mkstate = QDir(STORAGE_PATH).mkdir(Name);
    if( Mkstate ) AddDatastore(Name);
    return Mkstate;
}
bool FileHandler::DeleteDir(QString Name){
    bool Delstate = QDir(STORAGE_PATH).rmdir(Name);
    if( Delstate ) RemoveDatastore(Name);
    return Delstate;
}
bool FileHandler::DeleteForceDir(QString Name){
    bool Delstate = QDir(STORAGE_PATH+Name).removeRecursively();
    if( Delstate ) RemoveDatastore(Name);
    return Delstate;
    // Update at structure file too...
}
bool FileHandler::ClearDir(QString Name){
    bool DelState = DeleteForceDir(Name);
    if ( DelState ) return CreateDir(Name);
    else return false ;
    // Update at structure file too...
}
bool FileHandler::ClearDirContent(QString DirName, QString FileName){
    return QDir(STORAGE_PATH+DirName).remove(FileName+".docx");
    // Update When update table,pie etc
}
bool FileHandler::RenameDir(QString ODir, QString NDir){
    bool RenameState = QDir(STORAGE_PATH).rename(ODir,NDir);
    if( RenameState ) RenameDatastore(ODir,NDir);
    return RenameState;
}
StrList FileHandler::GetDatastoreAll(QString DirName){
    StrList AllStrucs;
    StrList Tables = GetDatastoreTables(DirName);
    StrList Piecharts = GetDatastorePiecharts(DirName);
    StrList Bargraphs = GetDatastoreBargraphs(DirName);
    StrList Linegraphs = GetDatastoreLinegraphs(DirName);
    AllStrucs << Tables;
    AllStrucs << Piecharts;
    AllStrucs << Bargraphs;
    AllStrucs << Linegraphs;
    return AllStrucs;
}
StrList FileHandler::GetDatastoreTables(QString DirName){
    QFile DSFile;
    DSFile.setFileName(DATASTORE_PATH);
    if(!DSFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    QString DSData = DSFile.readAll() ;
    QJsonDocument DSDoc = QJsonDocument::fromJson(DSData.toUtf8());
    QJsonObject DSObject = DSDoc.object();
    QJsonValue DSListVal = DSObject[DirName];
    QJsonObject DSListObject = DSListVal.toObject();
    QJsonArray TableList = DSListObject["TableList"].toArray();
    DSFile.close();
    return JsonArrayToStrList(TableList);
}
StrList FileHandler::GetDatastorePiecharts(QString DirName){
    QFile DSFile;
    DSFile.setFileName(DATASTORE_PATH);
    if(!DSFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    QString DSData = DSFile.readAll() ;
    QJsonDocument DSDoc = QJsonDocument::fromJson(DSData.toUtf8());
    QJsonObject DSObject = DSDoc.object();
    QJsonValue DSListVal = DSObject[DirName];
    QJsonObject DSListObject = DSListVal.toObject();
    QJsonArray PiechartList = DSListObject["PiechartList"].toArray();
    DSFile.close();
    return JsonArrayToStrList(PiechartList);
}
StrList FileHandler::GetDatastoreBargraphs(QString DirName){
    QFile DSFile;
    DSFile.setFileName(DATASTORE_PATH);
    if(!DSFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    QString DSData = DSFile.readAll() ;
    QJsonDocument DSDoc = QJsonDocument::fromJson(DSData.toUtf8());
    QJsonObject DSObject = DSDoc.object();
    QJsonValue DSListVal = DSObject[DirName];
    QJsonObject DSListObject = DSListVal.toObject();
    QJsonArray BargraphList = DSListObject["BargraphList"].toArray();
    DSFile.close();
    return JsonArrayToStrList(BargraphList);
}
StrList FileHandler::GetDatastoreLinegraphs(QString DirName){
    QFile DSFile;
    DSFile.setFileName(DATASTORE_PATH);
    if(!DSFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    QString DSData = DSFile.readAll() ;
    QJsonDocument DSDoc = QJsonDocument::fromJson(DSData.toUtf8());
    QJsonObject DSObject = DSDoc.object();
    QJsonValue DSListVal = DSObject[DirName];
    QJsonObject DSListObject = DSListVal.toObject();
    QJsonArray LinegraphList = DSListObject["LinegraphList"].toArray();
    DSFile.close();
    return JsonArrayToStrList(LinegraphList);
}
bool FileHandler::ChangeCurDS(QString DirName){
    if( DirName == DATASTORE_USE ) return false;
    QFile DSFile;
    DSFile.setFileName(DATASTORE_PATH);
    if(!DSFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    QString DSData = DSFile.readAll() ;
    QJsonDocument DSDoc = QJsonDocument::fromJson(DSData.toUtf8());
    QJsonObject DSObject = DSDoc.object();
    QJsonValue DSListVal = DSObject["DefaultUseDS"];
    QJsonObject DSListObject = DSListVal.toObject();
    DSObject["DefaultUseDS"] = DirName;
    DSListObject = DSObject;
    DSDoc.setObject(DSObject);
    DSFile.close();
    DSFile.setFileName("P:/Projects/Qt Projects/TathyaSeva/DS.json");
    if(!DSFile.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Truncate )) qWarning() << "Unsucessfull!";
    DSFile.write(DSDoc.toJson());
    DSFile.close();
    DATASTORE_USE = DirName;
    return true;
}
QString FileHandler::GetCurrentDS(){
    QString DirName;
    QFile DSFile;
    DSFile.setFileName(DATASTORE_PATH);
    if(!DSFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    QString DSData = DSFile.readAll() ;
    QJsonDocument DSDoc = QJsonDocument::fromJson(DSData.toUtf8());
    QJsonObject DSObject = DSDoc.object();
    DirName = DSObject["DefaultUseDS"].toString();
    DSFile.close();
    if( DirName == DEFAULT_DATASTORE_PATH ) return "default";
    else return DirName;
}
int FileHandler::CountDSStructs(QString DirName, QString StructName){
    QFile DSFile;
    int count ;
    DSFile.setFileName(DATASTORE_PATH);
    if(!DSFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    QString DSData = DSFile.readAll() ;
    QJsonDocument DSDoc = QJsonDocument::fromJson(DSData.toUtf8());
    QJsonObject DSObject = DSDoc.object();
    QJsonValue DSDirVal = DSObject[DirName];
    QJsonObject DSDirObject = DSDirVal.toObject();
    count = DSDirObject[StructName].toInt();
    DSFile.close();
    return count;
}
bool FileHandler::isTableExist(QString Tname){
    QFile DSFile;
    DSFile.setFileName(DATASTORE_PATH);
    if(!DSFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    QString DSData = DSFile.readAll() ;
    QJsonDocument DSDoc = QJsonDocument::fromJson(DSData.toUtf8());
    QJsonObject DSObject = DSDoc.object();
    QJsonValue DSDirVal = DSObject[DATASTORE_USE];
    QJsonObject DSDirObject = DSDirVal.toObject();
    QJsonArray TableList = DSDirObject["TableList"].toArray();
    DSFile.close();
    return isContainsJA(TableList,Tname);
}
bool FileHandler::isPiechartExist(QString Pname){
    QFile DSFile;
    DSFile.setFileName(DATASTORE_PATH);
    if(!DSFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    QString DSData = DSFile.readAll() ;
    QJsonDocument DSDoc = QJsonDocument::fromJson(DSData.toUtf8());
    QJsonObject DSObject = DSDoc.object();
    QJsonValue DSDirVal = DSObject[DATASTORE_USE];
    QJsonObject DSDirObject = DSDirVal.toObject();
    QJsonArray PiechartList = DSDirObject["PiechartList"].toArray();
    DSFile.close();
    return isContainsJA(PiechartList,Pname);
}
bool FileHandler::isBargraphExist(QString Bname){
    QFile DSFile;
    DSFile.setFileName(DATASTORE_PATH);
    if(!DSFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    QString DSData = DSFile.readAll() ;
    QJsonDocument DSDoc = QJsonDocument::fromJson(DSData.toUtf8());
    QJsonObject DSObject = DSDoc.object();
    QJsonValue DSDirVal = DSObject[DATASTORE_USE];
    QJsonObject DSDirObject = DSDirVal.toObject();
    QJsonArray BargraphList = DSDirObject["BargraphList"].toArray();
    DSFile.close();
    return isContainsJA(BargraphList,Bname);
}
bool FileHandler::isLinegraphExist(QString Lname){
    QFile DSFile;
    DSFile.setFileName(DATASTORE_PATH);
    if(!DSFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    QString DSData = DSFile.readAll() ;
    QJsonDocument DSDoc = QJsonDocument::fromJson(DSData.toUtf8());
    QJsonObject DSObject = DSDoc.object();
    QJsonValue DSDirVal = DSObject[DATASTORE_USE];
    QJsonObject DSDirObject = DSDirVal.toObject();
    QJsonArray LinegraphList = DSDirObject["LinegraphList"].toArray();
    DSFile.close();
    return isContainsJA(LinegraphList,Lname);
}
void FileHandler::ChangeEnvLang( QString Lang ){
    QFile LangFile;
    LangFile.setFileName(LANGUAGE_PATH);
    if(!LangFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    QString LangData = LangFile.readAll() ;
    QJsonDocument LangDoc = QJsonDocument::fromJson(LangData.toUtf8());
    QJsonObject LangObject = LangDoc.object();
    QJsonValue EnvLangVal = LangObject["EnvLang"];
    QJsonObject EnvLangObject = EnvLangVal.toObject();
    EnvLangObject["lang"] = Lang;
    LangObject["EnvLang"] = EnvLangObject;
    LangDoc.setObject(LangObject);
    LangFile.close();
    QDir("P:/Projects/Qt Projects/TathyaSeva/").remove("Language.json");
    LangFile.setFileName(LANGUAGE_PATH);
    if(!LangFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    LangFile.write(LangDoc.toJson());
    LangFile.close();
}
void FileHandler::UpdateDSInfo(QString Dir, QString StructType, QString StructName){
    QString CountAttr ;
    if( StructType == "TableList" ) CountAttr = "CountTables";
    else if( StructType == "PiechartList" ) CountAttr = "CountPiecharts";
    else if( StructType == "BargraphList" ) CountAttr = "CountBargraphs";
    else CountAttr = "CountLinegraphs";
    QFile DSFile;
    DSFile.setFileName(DATASTORE_PATH);
    if(!DSFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    QString DSData = DSFile.readAll() ;
    QJsonDocument DSDoc = QJsonDocument::fromJson(DSData.toUtf8());
    QJsonObject DSObject = DSDoc.object();
    QJsonValue DSDirValue = DSObject[Dir];
    QJsonObject DirAttr = DSDirValue.toObject();
    QJsonArray ListDS = DirAttr[StructType].toArray() ;
    int Total = DirAttr["CountStructures"].toInt() + 1 ;
    int TotalTables = DirAttr[CountAttr].toInt() + 1 ;
    ListDS.append(StructName);
    DirAttr[StructType] = ListDS;
    DirAttr["CountStructures"] = Total;
    DirAttr[CountAttr] = TotalTables ;
    DSObject[Dir] = DirAttr;
    DSDoc.setObject(DSObject);
    DSFile.close();
    DSFile.setFileName(DATASTORE_PATH);
    if(!DSFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    DSFile.write(DSDoc.toJson());
    DSFile.close();
}
void FileHandler::UpdateTableInfo(TableDefinition TD){
    QFile TFile;
    TFile.setFileName(TABLEINFO_PATH);
    if(!TFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    QString TData = TFile.readAll() ;
    QJsonDocument TDoc = QJsonDocument::fromJson(TData.toUtf8());
    QJsonObject TObject = TDoc.object();
    QJsonValue TDefVal = TObject[TD.Name];
    QJsonObject TDefObject = TDefVal.toObject();
    TDefObject["CountCols"] = TD.CountCols;
    TDefObject["CountRows"] = TD.CountRows;
    TDefObject["DOC"] = TD.DOC;
    TDefObject["Datastore"] = TD.Datastore;
    QJsonValue TColDefVal = TDefObject["Columns"];
    QJsonObject TColDefObject = TColDefVal.toObject();
    for( auto Key:TD.ColType.keys() ) TColDefObject[Key] = TD.ColType[Key];
    TDefObject["Columns"] = TColDefObject;
    TObject[TD.Name] = TDefObject;
    TDoc.setObject(TObject);
    TFile.close();
    TFile.setFileName(TABLEINFO_PATH);
    if(!TFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    TFile.write(TDoc.toJson());
    TFile.close();
}
void FileHandler::CreateEmptyTable(QString Name, StrList Cols){
    QFile TDataFile;
    QString TDataFilePath = STORAGE_PATH+DATASTORE_USE+"/"+Name+TableExtsn ;
    TDataFile.setFileName(TDataFilePath);
    if(!TDataFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    QJsonDocument TDataDoc;
    QJsonObject TDataObject = TDataDoc.object();
    for( auto Col:Cols ) TDataObject[Col] = QJsonArray();
    TDataDoc.setObject(TDataObject);
    TDataFile.write(TDataDoc.toJson());
    TDataFile.close();
}
void FileHandler::CreateTableFile(QString TableName, StrList Cols, StrList Dtypes){
    UpdateDSInfo(DATASTORE_USE,"TableList",TableName);
    MapStrStr ColTypePair;
    int CountCols = Cols.size();
    for( int i = 0 ; i < CountCols; i++ ) ColTypePair[Cols.at(i)] = Dtypes.at(i);
    UpdateTableInfo({TableName,TodayDateTime,DATASTORE_USE,0,CountCols,ColTypePair});
    CreateEmptyTable(TableName,Cols);
}
int FileHandler::CountRows(QString TableName){
    QFile TDataFile;
    int Count ;
    TDataFile.setFileName(TABLEINFO_PATH);
    if(!TDataFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    QString TData = TDataFile.readAll() ;
    QJsonDocument TDataDoc = QJsonDocument::fromJson(TData.toUtf8());
    QJsonObject TDataObject = TDataDoc.object();
    QJsonValue TDataValue = TDataObject[TableName];
    QJsonObject TableObject = TDataValue.toObject();
    Count = TableObject["CountCols"].toInt();
    TDataFile.close();
    return Count;
}
StrList FileHandler::MatchColumns(QString TableName, StrList Cols){
    StrList InvalidCols ;
    QFile TFile ;
    TFile.setFileName(TABLEINFO_PATH);
    if(!TFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    QString TData = TFile.readAll() ;
    QJsonDocument TDataDoc = QJsonDocument::fromJson(TData.toUtf8());
    QJsonObject TDataObject = TDataDoc.object();
    QJsonObject TableObject = TDataObject[TableName].toObject();
    QJsonObject ColsObject = TableObject["Columns"].toObject();
    for( auto C:Cols ) if( !ColsObject.keys().contains(C) ) InvalidCols << C;
    TFile.close();
    return InvalidCols;
}
QString FileHandler::GetEnvLangAttr(QString Group, QString Attr){
    QFile LangFile;
    LangFile.setFileName(LANGUAGE_PATH);
    if(!LangFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    QString LangData = LangFile.readAll() ;
    QJsonDocument LangDoc = QJsonDocument::fromJson(LangData.toUtf8());
    QJsonObject LangObject = LangDoc.object();
    QJsonObject EnvLangObject = LangObject[Group].toObject() ;
    LangFile.close();
    return EnvLangObject[Attr].toString();
}
void FileHandler::SetColumnTypes(QString TName, MapStrStr ColTypePair){
    QFile TFile;
    TFile.setFileName(TABLEINFO_PATH);
    if(!TFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    QString TData = TFile.readAll() ;
    QJsonDocument TDoc = QJsonDocument::fromJson(TData.toUtf8());
    QJsonObject TObject = TDoc.object();
    QJsonValue TDefVal = TObject[TName];
    QJsonObject TDefObject = TDefVal.toObject();
    QJsonValue TColDefVal = TDefObject["Columns"];
    QJsonObject TColDefObject = TColDefVal.toObject();
    for( auto Key:ColTypePair.keys() ) TColDefObject[Key] = ColTypePair[Key];
    TDefObject["Columns"] = TColDefObject;
    TObject[TName] = TDefObject;
    TDoc.setObject(TObject);
    TFile.close();
    TFile.setFileName(TABLEINFO_PATH);
    if(!TFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    TFile.write(TDoc.toJson());
    TFile.close();
}
MapStrStr FileHandler::GenerateTypes(Datatypes DT, StrList Cols , StrList Values , MapStrStr ColTypePair){
    for( int i = 0 ; i < Cols.size() ; i++ ){
        if( DT.STR_REGX.match(Values[i]).hasMatch() && ColTypePair[Cols[i]].isEmpty()){
            ColTypePair[Cols[i]] = DT.STRING;
        }
        else if( DT.FLT_REGX.match(Values[i]).hasMatch() && ColTypePair[Cols[i]].isEmpty()){
             ColTypePair[Cols[i]] = DT.FLOAT;
        }
        else if( DT.INT_REGX.match(Values[i]).hasMatch() && ColTypePair[Cols[i]].isEmpty()) {
            ColTypePair[Cols[i]] = DT.INT;
        }
    }
    return ColTypePair;
}
bool FileHandler::isRequiredGenType(MapStrStr ColTypePair){
    for( auto Val : ColTypePair.values() ) if( Val.isEmpty() ) return true;
    return false;
}
void FileHandler::UpdateRowCount(QString Tname){
    QFile TDataFile;
    int RowCount;
    TDataFile.setFileName(TABLEINFO_PATH);
    if(!TDataFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    QString TData = TDataFile.readAll() ;
    QJsonDocument TDataDoc = QJsonDocument::fromJson(TData.toUtf8());;
    QJsonObject TDataObject = TDataDoc.object();
    QJsonValue TableVal = TDataObject[Tname];
    QJsonObject TableObject = TableVal.toObject();
    RowCount = TableObject["CountRows"].toInt() + 1;
    TableObject["CountRows"] = RowCount;
    TDataObject[Tname] = TableObject;
    TDataDoc.setObject(TDataObject);
    TDataFile.close();
    TDataFile.setFileName(TABLEINFO_PATH);
    if(!TDataFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    TDataFile.write(TDataDoc.toJson());
    TDataFile.close();
}
void FileHandler::InsertIntoTable(QString TName ,StrList Cols, StrList Values){
    QFile TDataFile;
    QString TDataFilePath = STORAGE_PATH+DATASTORE_USE+"/"+TName+TableExtsn ;
    TDataFile.setFileName(TDataFilePath);
    if(!TDataFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    QString TData = TDataFile.readAll() ;
    QJsonDocument TDataDoc = QJsonDocument::fromJson(TData.toUtf8());;
    QJsonObject TDataObject = TDataDoc.object();
    for( int i = 0 ; i < Cols.size() ; i++ ){
        QJsonValue ColnVal = TDataObject[Cols[i]] ;
        QJsonArray Coln = ColnVal.toArray();
        Coln.append(Values[i]);
        TDataObject[Cols[i]]= Coln;
    }
    TDataDoc.setObject(TDataObject);
    TDataFile.close();
    TDataFile.setFileName(TDataFilePath);
    if(!TDataFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    TDataFile.write(TDataDoc.toJson());
    TDataFile.close();
    UpdateRowCount(TName);
}
StrList FileHandler::RecognizeTypeFromData(StrList Data){
    StrList Types ;
    for( auto eachData : Data ){
        if( DT.STR_REGX.match(eachData).hasMatch()){
            Types << DT.STRING;
        }
        else if( DT.FLT_REGX.match(eachData).hasMatch()){
             Types << DT.FLOAT;
        }
        else if( DT.INT_REGX.match(eachData).hasMatch()) {
            Types << DT.INT;
        }
    }
    return Types ;
}
StrList FileHandler::isCorrectData_Types(StrList Values, StrList Types){
    StrList RequiredTypes = RecognizeTypeFromData(Values);
    StrList IncompitatbleData ;
    for( int i = 0 ; i < Values.size() ; i++ ) if( RequiredTypes[i] != Types[i] ) IncompitatbleData << Values[i];
    return IncompitatbleData;
}
StrList FileHandler::SetTableDatatypes(QString TableName, StrList Cols, StrList Values){
    QFile TFile ;
    MapStrStr ColTypePair ;
    StrList StoredColTypes;
    StrList WrongData ;
    TFile.setFileName(TABLEINFO_PATH);
    if(!TFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    QString TData = TFile.readAll() ;
    QJsonDocument TDataDoc = QJsonDocument::fromJson(TData.toUtf8());
    QJsonObject TDataObject = TDataDoc.object();
    QJsonObject TableObject = TDataObject[TableName].toObject();
    QJsonObject ColsObject = TableObject["Columns"].toObject();
    for( auto Col : Cols ) ColTypePair.insert( Col , ColsObject[Col].toString());
    TFile.close();
    if(isRequiredGenType(ColTypePair)){
        ColTypePair = GenerateTypes(DT,Cols,Values,ColTypePair);
        SetColumnTypes(TableName,ColTypePair);
    }
    TFile.setFileName(TABLEINFO_PATH);
    if(!TFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    TData = TFile.readAll() ;
    TDataDoc = QJsonDocument::fromJson(TData.toUtf8());
    TDataObject = TDataDoc.object();
    TableObject = TDataObject[TableName].toObject();
    ColsObject = TableObject["Columns"].toObject();
    for( auto Col : Cols ) StoredColTypes << ColsObject[Col].toString() ;
    TFile.close();
    WrongData = isCorrectData_Types(Values,StoredColTypes);
    if(WrongData.isEmpty()) InsertIntoTable(TableName, Cols,Values);
    else return WrongData;
    return WrongData;
}
void FileHandler::EditCol(QString Tname, QString Col, QString Type){
    QFile TFile ;
    TFile.setFileName(TABLEINFO_PATH);
    if( !TFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    QString TData = TFile.readAll();
    QJsonDocument TDoc = QJsonDocument::fromJson(TData.toUtf8());
    QJsonObject RootObject = TDoc.object();
    QJsonObject TObject = RootObject[Tname].toObject();
    QJsonObject TColObject = TObject["Columns"].toObject();
    TColObject[Col] = Type ;
    TObject["Columns"] = TColObject;
    RootObject[Tname] = TObject ;
    TFile.close();
    QDir("P:/Projects/Qt Projects/TathyaSeva/").remove("TableInfo.json");
    TDoc.setObject(RootObject);
    TFile.setFileName(TABLEINFO_PATH);
    if(!TFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    TFile.write(TDoc.toJson());
    TFile.close();
}
void FileHandler::EditColTypes(QString TableName, StrList Cols, StrList Types){
    for( int i = 0 ; i < Cols.size() ; i++ ) EditCol(TableName,Cols[i],Types[i]);
}
int FileHandler::GetRowCount(QString Tname){
    QFile TDataFile;
    int RowCount;
    TDataFile.setFileName(TABLEINFO_PATH);
    if(!TDataFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    QString TData = TDataFile.readAll() ;
    QJsonDocument TDataDoc = QJsonDocument::fromJson(TData.toUtf8());;
    QJsonObject TDataObject = TDataDoc.object();
    QJsonObject TableObject = TDataObject[Tname].toObject();
    RowCount = TableObject["CountRows"].toInt();
    TDataFile.close();
    return RowCount;
}
void FileHandler::EditColVal(QString TableName, QString Col, QJsonArray Arr){
    QFile TDataFile;
    QString TDataFilePath = STORAGE_PATH+DATASTORE_USE+"/"+TableName+TableExtsn ;
    TDataFile.setFileName(TDataFilePath);
    if(!TDataFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    QString TData = TDataFile.readAll() ;
    QJsonDocument TDataDoc = QJsonDocument::fromJson(TData.toUtf8());;
    QJsonObject TDataObject = TDataDoc.object();
    TDataObject[Col] = Arr ;
    TDataDoc.setObject(TDataObject);
    TDataFile.close();
    QDir(STORAGE_PATH+DATASTORE_USE+"/").remove(TableName+TableExtsn);
    TDataFile.setFileName(TDataFilePath);
    if(!TDataFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    TDataFile.write(TDataDoc.toJson());
    TDataFile.close();
}
void FileHandler::EditColValues(QString TableName, StrList Cols, StrList Types){
    int CountRow = GetRowCount(TableName);
    QJsonArray Arr;
    for( int  i = 0 ; i < Cols.size() ; i ++ ){
        if( Types[i].compare(DT.STRING) == 0 ){
            for( int j = 0 ; j < CountRow ; j ++ ) Arr.append(DEFAULT_STR_VALUE);
            EditColVal(TableName,Cols[i],Arr);
        }
        else if( Types[i].compare(DT.INT) == 0 ){
            for( int j = 0 ; j < CountRow ; j ++ ) Arr.append(DEFAULT_INT_VALUE);
            EditColVal(TableName,Cols[i],Arr);
        }
        else if( Types[i].compare(DT.FLOAT) == 0 ){
            for( int j = 0 ; j < CountRow ; j ++ ) Arr.append(DEFAULT_FLOAT_VALUE);
            EditColVal(TableName,Cols[i],Arr);
        }
        Arr = QJsonArray();
    }
}
void FileHandler::ChangeTableDatatypes(QString TableName, StrList Cols, StrList Types){
    EditColTypes(TableName, Cols, Types);
    EditColValues(TableName, Cols, Types);
}
StrList FileHandler::FindRepeatCols(QString Tname, StrList Cols){
    QFile TFile ;
    StrList RepeatCols;
    TFile.setFileName(TABLEINFO_PATH);
    if(!TFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    QString TData = TFile.readAll() ;
    QJsonDocument TDataDoc = QJsonDocument::fromJson(TData.toUtf8());;
    QJsonObject TDataObject = TDataDoc.object();
    QJsonObject TableObject = TDataObject[Tname].toObject();
    QJsonObject ColsObject = TableObject["Columns"].toObject();
    StrList StoredCols = ColsObject.keys();
    TFile.close();
    for( auto Col:Cols ) if( StoredCols.contains(Col) ) RepeatCols << Col ;
    return RepeatCols;
}
void FileHandler::AddToTableInfo(QString TableName, StrList Cols, StrList Types){
    QFile TFile ;
    StrList RepeatCols;
    TFile.setFileName(TABLEINFO_PATH);
    if(!TFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    QString TData = TFile.readAll() ;
    QJsonDocument TDataDoc = QJsonDocument::fromJson(TData.toUtf8());;
    QJsonObject TDataObject = TDataDoc.object();
    QJsonObject TableObject = TDataObject[TableName].toObject();
    QJsonObject ColsObject = TableObject["Columns"].toObject();
    for( int i = 0 ; i < Cols.size() ; i++ ) ColsObject[Cols[i]] = Types[i];
    TableObject["CountCols"] = TableObject["CountCols"].toInt() + Cols.size() ;
    TableObject["Columns"] = ColsObject;
    TDataObject[TableName] = TableObject;
    TDataDoc.setObject(TDataObject);
    TFile.close();
    TFile.setFileName(TABLEINFO_PATH);
    if(!TFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    TFile.write(TDataDoc.toJson());
    TFile.close();
}
void FileHandler::AddToTableData(QString TableName, StrList Cols){
    QFile TDataFile;
    int RowCount = GetRowCount(TableName);
    QJsonArray Arr ;
    QString TDataFilePath = STORAGE_PATH+DATASTORE_USE+"/"+TableName+TableExtsn ;
    TDataFile.setFileName(TDataFilePath);
    if(!TDataFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    QString TData = TDataFile.readAll() ;
    QJsonDocument TDataDoc = QJsonDocument::fromJson(TData.toUtf8());;
    QJsonObject TDataObject = TDataDoc.object();
    for( int i = 0 ; i < RowCount ; i ++ ) Arr.append("-");
    for( auto Col:Cols ) TDataObject[Col] = Arr;
    TDataDoc.setObject(TDataObject);
    TDataFile.close();
    TDataFile.setFileName(TDataFilePath);
    if(!TDataFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    TDataFile.write(TDataDoc.toJson());
    TDataFile.close();
}
void FileHandler::AddToTableFile(QString TableName, StrList Cols, StrList Types){
    AddToTableInfo(TableName,Cols,Types);
    AddToTableData(TableName,Cols);
}
bool FileHandler::StructFileRename(QString Old, QString New, QString StructName){
    QString Extension ;
    if( StructName == "Table" ) Extension = TableExtsn;
    else if( StructName == "Piechart" ) Extension = PiechartExtsn;
    else if( StructName == "Bargraph" ) Extension = BargraphExtsn;
    else if( StructName == "Linegraph" ) Extension = LinegraphExtsn;
    return QDir(STORAGE_PATH+DATASTORE_USE).rename(Old+Extension,New+Extension);
}
void FileHandler::RenameStructAtInfo(QString Old, QString New, QString StructName){
    QString FilePath ;
    if( StructName == "Table" ) FilePath = TABLEINFO_PATH;
    else if( StructName == "Piechart" ) FilePath = PIECHARTINFO_PATH;
    else if( StructName == "Bargraph" ) FilePath = BARGRAPHINFO_PATH;
    else if( StructName == "Linegraph" ) FilePath = LINEGRAPHINFO_PATH;
    QFile TDataFile;
    TDataFile.setFileName(FilePath);
    if(!TDataFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    QString TData = TDataFile.readAll() ;
    QJsonDocument TDataDoc = QJsonDocument::fromJson(TData.toUtf8());;
    QJsonObject TDataObject = TDataDoc.object();
    QJsonObject TableObject = TDataObject[Old].toObject();
    TDataObject.remove(Old);
    TDataObject[New] = TableObject;
    TDataDoc.setObject(TDataObject);
    TDataFile.close();
    TDataFile.setFileName(FilePath);
    if(!TDataFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    TDataFile.write(TDataDoc.toJson());
    TDataFile.close();
}
void FileHandler::UpdateStructNameDS(QString Old, QString New, QString StructType){
    QFile DSDataFile;
    DSDataFile.setFileName(DATASTORE_PATH);
    if(!DSDataFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    QString DSData = DSDataFile.readAll() ;
    QJsonDocument DSDataDoc = QJsonDocument::fromJson(DSData.toUtf8());;
    QJsonObject DSDataObject = DSDataDoc.object();
    QJsonObject DSObject = DSDataObject[DATASTORE_USE].toObject();
    QJsonArray List = DSObject[StructType].toArray();
    List = RemoveFromJA(List,Old);
    List.append(New);
    DSObject[StructType] = List ;
    DSDataObject[DATASTORE_USE] = DSObject;
    DSDataDoc.setObject(DSDataObject);
    DSDataFile.close();
    DSDataFile.setFileName(DATASTORE_PATH);
    if(!DSDataFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    DSDataFile.write(DSDataDoc.toJson());
    DSDataFile.close();
}
bool FileHandler::RenameTable(QString Old, QString New){
    if(StructFileRename(Old,New,"Table") ){
        RenameStructAtInfo(Old,New,"Table");
        UpdateStructNameDS(Old,New,"TableList");
    }else return false ;
    return true;
}
bool FileHandler::RenamePiechart(QString Old, QString New){
    if(StructFileRename(Old,New,"Piechart") ){
        RenameStructAtInfo(Old,New,"Piechart");
        UpdateStructNameDS(Old,New,"PiechartList");
    }else return false ;
    return true;
}
bool FileHandler::RenameBargraph(QString Old, QString New){
    if(StructFileRename(Old,New,"Bargraph") ){
        RenameStructAtInfo(Old,New,"Bargraph");
        UpdateStructNameDS(Old,New,"BargraphList");
    }else return false ;
    return true;
}
bool FileHandler::RenameLinegraph(QString Old, QString New){
    if(StructFileRename(Old,New,"Linegraph") ){
        RenameStructAtInfo(Old,New,"Linegraph");
        UpdateStructNameDS(Old,New,"LinegraphList");
    }else return false ;
    return true;
}
void FileHandler::RenameTableCols(QString Tname, StrList OldCols, StrList NewCols){
    QFile TDataFile;
    QString TDataFilePath = STORAGE_PATH+DATASTORE_USE+"/"+Tname+TableExtsn ;
    TDataFile.setFileName(TDataFilePath);
    if(!TDataFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    QString TData = TDataFile.readAll() ;
    QJsonDocument TDataDoc = QJsonDocument::fromJson(TData.toUtf8());;
    QJsonObject TDataObject = TDataDoc.object();
    for( int  i = 0 ; i < OldCols.size() ; i++ ){
        QJsonArray ColArray = TDataObject[OldCols[i]].toArray();
        TDataObject.remove(OldCols[i]);
        TDataObject[NewCols[i]] = ColArray;
    }
    TDataDoc.setObject(TDataObject);
    TDataFile.close();
    TDataFile.setFileName(TDataFilePath);
    if(!TDataFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    TDataFile.write(TDataDoc.toJson());
    TDataFile.close();


    TDataFile.setFileName(TABLEINFO_PATH);
    if(!TDataFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    TData = TDataFile.readAll() ;
    TDataDoc = QJsonDocument::fromJson(TData.toUtf8());;
    TDataObject = TDataDoc.object();
    QJsonObject TableObject = TDataObject[Tname].toObject();
    QJsonObject ColObject = TableObject["Columns"].toObject();
    for( int i = 0 ; i < NewCols.size() ; i++ ){
        QString ColVal = ColObject[OldCols[i]].toString();
        ColObject.remove(OldCols[i]);
        ColObject[NewCols[i]] = ColVal;
    }
    TableObject["Columns"] = ColObject;
    TDataObject[Tname] = TableObject;
    TDataDoc.setObject(TDataObject);
    TDataFile.close();
    TDataFile.setFileName(TABLEINFO_PATH);
    if(!TDataFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    TDataFile.write(TDataDoc.toJson());
    TDataFile.close();
}
bool FileHandler::isEmptyTable(QString Tname){
    if( CountRows(Tname) ) return false;
    return true;
}
void FileHandler::EmptyTableData(QString Tname){
    QFile TDataFile;
    TDataFile.setFileName(TABLEINFO_PATH);
    if(!TDataFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    QString TData = TDataFile.readAll() ;
    QJsonDocument TDataDoc = QJsonDocument::fromJson(TData.toUtf8());;
    QJsonObject TDataObject = TDataDoc.object();
    QJsonObject TableObject = TDataObject[Tname].toObject();
    TableObject["CountRows"] = 0;
    TDataObject[Tname] = TableObject;
    TDataDoc.setObject(TDataObject);
    TDataFile.close();
    TDataFile.setFileName(TABLEINFO_PATH);
    if(!TDataFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    TDataFile.write(TDataDoc.toJson());
    TDataFile.close();

    QString TDataFilePath = STORAGE_PATH+DATASTORE_USE+"/"+Tname+TableExtsn ;
    TDataFile.setFileName(TDataFilePath);
    if(!TDataFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    TData = TDataFile.readAll() ;
    TDataDoc = QJsonDocument::fromJson(TData.toUtf8());;
    TDataObject = TDataDoc.object();
    StrList Cols = TDataObject.keys();
    TDataFile.close();
    QDir(STORAGE_PATH+DATASTORE_USE+"/").remove(Tname+TableExtsn);
    CreateEmptyTable(Tname,Cols);
}
StrList FileHandler::GetEmptyCols(QString Tname, StrList Cols){
    QFile TDataFile;
    StrList EmptyCols ;
    QString TDataFilePath = STORAGE_PATH+DATASTORE_USE+"/"+Tname+TableExtsn ;
    TDataFile.setFileName(TDataFilePath);
    if(!TDataFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    QString TData = TDataFile.readAll() ;
    QJsonDocument TDataDoc = QJsonDocument::fromJson(TData.toUtf8());;
    QJsonObject TDataObject = TDataDoc.object();
    for( auto Col:Cols ) if( TDataObject[Col].toArray().isEmpty()) EmptyCols << Col ;
    TDataDoc.setObject(TDataObject);
    TDataFile.close();
    return EmptyCols;
}
void FileHandler::ClearColData(QString Tname, StrList Cols){
    QFile TDataFile;
    StrList EmptyCols ;
    QString TDataFilePath = STORAGE_PATH+DATASTORE_USE+"/"+Tname+TableExtsn ;
    int CountRow;
    TDataFile.setFileName(TDataFilePath);
    if(!TDataFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    QString TData = TDataFile.readAll() ;
    QJsonDocument TDataDoc = QJsonDocument::fromJson(TData.toUtf8());;
    QJsonObject TDataObject = TDataDoc.object();
    for( auto Col:Cols ){
        QJsonArray Arr ;
        CountRow = TDataObject[Col].toArray().size();
        for( int i = 0 ; i < CountRow ; i++ ) Arr.append("-");
        TDataObject.remove(Col);
        TDataObject[Col] = Arr ;
    }
    TDataDoc.setObject(TDataObject);
    TDataFile.close();
    QDir(STORAGE_PATH+DATASTORE_USE+"/").remove(Tname+TableExtsn);
    TDataFile.setFileName(TDataFilePath);
    if(!TDataFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    TDataFile.write(TDataDoc.toJson());
    TDataFile.close();
}
MapStrStrList FileHandler::GetTableFileData(QString Tname){
    QFile TDataFile;
    MapStrStrList TableData;
    QString TDataFilePath = STORAGE_PATH+DATASTORE_USE+"/"+Tname+TableExtsn ;
    TDataFile.setFileName(TDataFilePath);
    if(!TDataFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    QString TData = TDataFile.readAll() ;
    QJsonDocument TDataDoc = QJsonDocument::fromJson(TData.toUtf8());;
    QJsonObject TDataObject = TDataDoc.object();
    for( auto Col:TDataObject.keys()) TableData[Col] = JsonArrayToStrList(TDataObject[Col].toArray());
    TDataFile.close();
    return TableData;
}
MapStrStrList FileHandler::GetTableColData(QString Tname, StrList Cols){
    QFile TDataFile;
    MapStrStrList TableData;
    QString TDataFilePath = STORAGE_PATH+DATASTORE_USE+"/"+Tname+TableExtsn ;
    TDataFile.setFileName(TDataFilePath);
    if(!TDataFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    QString TData = TDataFile.readAll() ;
    QJsonDocument TDataDoc = QJsonDocument::fromJson(TData.toUtf8());;
    QJsonObject TDataObject = TDataDoc.object();
    for( auto Col:Cols) TableData[Col] = JsonArrayToStrList(TDataObject[Col].toArray());
    TDataFile.close();
    return TableData;
}
MapStrStrList FileHandler::GetTableData(QString Tname){
    MapStrStrList TableData;
    TableData["TABLE_NAME"] << Tname;
    QFile TDataFile;
    TDataFile.setFileName(TABLEINFO_PATH);
    if(!TDataFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    QString TData = TDataFile.readAll() ;
    QJsonDocument TDataDoc = QJsonDocument::fromJson(TData.toUtf8());;
    QJsonObject TDataObject = TDataDoc.object();
    QJsonObject TableObject = TDataObject[Tname].toObject();
    QJsonObject ColObject = TableObject["Columns"].toObject();
    TDataFile.close();
    for( auto Col:ColObject.keys() ){
        TableData["COL_NAMES"] << Col;
        TableData["DATATYPES"] << ColObject[Col].toString();
    }
    TableData["DATASTORE"] << TableObject["Datastore"].toString();
    TableData["DOC"] << TableObject["DOC"].toString();
    TableData["COUNT_ROWS"] << QString::number(TableObject["CountRows"].toInt());
    TableData["COUNT_COLS"] << QString::number(TableObject["CountCols"].toInt());
    return TableData;
}
bool FileHandler::RemoveStruct(QString Tname, QString StructName){
    QString Extension;
    if( StructName == "Table" ) Extension = TableExtsn;
    else if( StructName == "Piechart" ) Extension = PiechartExtsn;
    else if( StructName == "Bargraph" ) Extension = BargraphExtsn;
    else if( StructName == "Linegraph" ) Extension = LinegraphExtsn;
    return QDir(STORAGE_PATH+DATASTORE_USE+"/").remove(Tname+Extension);
}
void FileHandler::RemoveFromDS(QString Datastore, QString StructName, QString StructList){
    QFile DSFile;
    QString CountStruct ;

    if( StructList == "TableList" ) CountStruct = "CountTables";
    else if( StructList == "PiechartList" ) CountStruct = "CountPiecharts";
    else if( StructList == "BargraphList" ) CountStruct = "CountBargraphs";
    else if( StructList == "LinegraphList" ) CountStruct = "CountLinegraphs";

    DSFile.setFileName(DATASTORE_PATH);
    if(!DSFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    QString DSData = DSFile.readAll() ;
    QJsonDocument DSDoc = QJsonDocument::fromJson(DSData.toUtf8());;
    QJsonObject DSDataObject = DSDoc.object();
    QJsonObject DSObject = DSDataObject[Datastore].toObject();
    QJsonArray Arr;
    DSObject[CountStruct] = DSObject[CountStruct].toInt() - 1;
    DSObject["CountStructures"] = DSObject["CountStructures"].toInt() - 1;
    Arr = RemoveFromJA(DSObject[StructList].toArray(),StructName);
    DSObject[StructList] = Arr ;
    DSDataObject[Datastore] = DSObject;
    DSDoc.setObject(DSDataObject);
    DSFile.close();
    QDir("P:/Projects/Qt Projects/TathyaSeva/").remove("DS.json");
    DSFile.setFileName(DATASTORE_PATH);
    if(!DSFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    DSFile.write(DSDoc.toJson());
    DSFile.close();
}
void FileHandler::RemoveFromStructInfo(QString StructName, QString StructType){
    QFile TDataFile;
    QString TDataFilePath ;
    if( StructType == "Table" ) TDataFilePath = TABLEINFO_PATH;
    else if( StructType == "Piechart" ) TDataFilePath = PIECHARTINFO_PATH;
    else if( StructType == "Bargraph" ) TDataFilePath = BARGRAPHINFO_PATH;
    else if( StructType == "Linegraph" ) TDataFilePath = LINEGRAPHINFO_PATH;
    TDataFile.setFileName(TDataFilePath);
    if(!TDataFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    QString TData = TDataFile.readAll() ;
    QJsonDocument TDataDoc = QJsonDocument::fromJson(TData.toUtf8());;
    QJsonObject TDataObject = TDataDoc.object();
    TDataObject.remove(StructName);
    TDataDoc.setObject(TDataObject);
    TDataFile.close();
    QDir("P:/Projects/Qt Projects/TathyaSeva/").remove(StructType+"Info.json");
    TDataFile.setFileName(TDataFilePath);
    if(!TDataFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    TDataFile.write(TDataDoc.toJson());
    TDataFile.close();
}
bool FileHandler::RemoveTable(QString Tname){
    if( RemoveStruct(Tname,"Table") ){
        RemoveFromDS(DATASTORE_USE,Tname,"TableList");
        RemoveFromStructInfo(Tname,"Table");
    }
    else return false;
    return true;
}
StrList FileHandler::FindNotPresentCols(QString Tname, StrList Cols){
    StrList NotPresent ;
    QFile TDataFile;
    TDataFile.setFileName(TABLEINFO_PATH);
    if(!TDataFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    QString TData = TDataFile.readAll() ;
    QJsonDocument TDataDoc = QJsonDocument::fromJson(TData.toUtf8());;
    QJsonObject TDataObject = TDataDoc.object();
    QJsonObject TableObject = TDataObject[Tname].toObject();
    QJsonObject ColObject = TableObject["Columns"].toObject();
    for( auto Col:Cols ) if( !ColObject.keys().contains(Col) ) NotPresent << Col;
    TDataFile.close();
    return NotPresent;
}
void FileHandler::RemoveTableCols(QString Tname, StrList Cols){
    QFile TDataFile;
    TDataFile.setFileName(TABLEINFO_PATH);
    if(!TDataFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    QString TData = TDataFile.readAll() ;
    QJsonDocument TDataDoc = QJsonDocument::fromJson(TData.toUtf8());;
    QJsonObject TDataObject = TDataDoc.object();
    QJsonObject TableObject = TDataObject[Tname].toObject();
    QJsonObject ColObject = TableObject["Columns"].toObject();
    TableObject["CountCols"] = TableObject["CountCols"].toInt() - Cols.size();
    for( auto Col:Cols ) ColObject.remove(Col);
    TableObject["Columns"] = ColObject;
    TDataObject[Tname] = TableObject;
    TDataDoc.setObject(TDataObject);
    TDataFile.close();
    QDir("P:/Projects/Qt Projects/TathyaSeva/").remove("TableInfo.json");
    TDataFile.setFileName(TABLEINFO_PATH);
    if(!TDataFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    TDataFile.write(TDataDoc.toJson());
    TDataFile.close();

    QString TDataFilePath = STORAGE_PATH+DATASTORE_USE+"/"+Tname+TableExtsn ;
    TDataFile.setFileName(TDataFilePath);
    if(!TDataFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    TData = TDataFile.readAll() ;
    TDataDoc = QJsonDocument::fromJson(TData.toUtf8());;
    TDataObject = TDataDoc.object();
    for( auto Col:Cols ) TDataObject.remove(Col);
    TDataDoc.setObject(TDataObject);
    TDataFile.close();
    QDir(STORAGE_PATH+DATASTORE_USE+"/").remove(Tname+TableExtsn);
    TDataFile.setFileName(TDataFilePath);
    if(!TDataFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    TDataFile.write(TDataDoc.toJson());
    TDataFile.close();
}
int FileHandler::GetColCount(QString Tname){
    QFile TDataFile;
    TDataFile.setFileName(TABLEINFO_PATH);
    if(!TDataFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    QString TData = TDataFile.readAll() ;
    QJsonDocument TDataDoc = QJsonDocument::fromJson(TData.toUtf8());;
    QJsonObject TDataObject = TDataDoc.object();
    QJsonObject TableObject = TDataObject[Tname].toObject();
    QJsonObject ColObject = TableObject["Columns"].toObject();
    TDataFile.close();
    return ColObject.keys().size();
}
bool FileHandler::AtleastOneNumericCol(QString Tname){
    QFile TDataFile;
    TDataFile.setFileName(TABLEINFO_PATH);
    if(!TDataFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    QString TData = TDataFile.readAll() ;
    QJsonDocument TDataDoc = QJsonDocument::fromJson(TData.toUtf8());;
    QJsonObject TDataObject = TDataDoc.object();
    QJsonObject TableObject = TDataObject[Tname].toObject();
    QJsonObject ColObject = TableObject["Columns"].toObject();
    TDataFile.close();
    StrList Types ;
    for( auto Col:ColObject.keys() ) Types << ColObject[Col].toString();
    return ( Types.contains(DT.INT) || Types.contains(DT.FLOAT) );
}
bool FileHandler::TwoNumericCol(QString Tname){
    QFile TDataFile;
    TDataFile.setFileName(TABLEINFO_PATH);
    if(!TDataFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    QString TData = TDataFile.readAll() ;
    QJsonDocument TDataDoc = QJsonDocument::fromJson(TData.toUtf8());;
    QJsonObject TDataObject = TDataDoc.object();
    QJsonObject TableObject = TDataObject[Tname].toObject();
    QJsonObject ColObject = TableObject["Columns"].toObject();
    int count = 0 ;
    TDataFile.close();
    for( auto Col:ColObject.keys() ) if( ColObject[Col].toString() == DT.INT || ColObject[Col].toString() == DT.FLOAT ) count ++ ;
    if( count  == 2 ) return true;
    return false;
}
StrList FileHandler::FindNonNumericCols(QString Tname,StrList Cols){
    QFile TDataFile;
    StrList NonNumericCols;
    TDataFile.setFileName(TABLEINFO_PATH);
    if(!TDataFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    QString TData = TDataFile.readAll() ;
    QJsonDocument TDataDoc = QJsonDocument::fromJson(TData.toUtf8());;
    QJsonObject TDataObject = TDataDoc.object();
    QJsonObject TableObject = TDataObject[Tname].toObject();
    QJsonObject ColObject = TableObject["Columns"].toObject();
    TDataFile.close();
    for( auto Col:Cols ) {
        if( !(ColObject[Col].toString() == DT.INT || ColObject[Col].toString() == DT.FLOAT) ) NonNumericCols << Col  ;
//        else NonNumericCols << Col ;
    }
    qWarning() << NonNumericCols;
    return NonNumericCols;
}
MapStrJA FileHandler::GetXYPlots(QString Tname){
    MapStrJA XY;
    QFile TDataFile;
    QString XCol , YCol;
    TDataFile.setFileName(TABLEINFO_PATH);
    if(!TDataFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    QString TData = TDataFile.readAll() ;
    QJsonDocument TDataDoc = QJsonDocument::fromJson(TData.toUtf8());;
    QJsonObject TDataObject = TDataDoc.object();
    QJsonObject TableObject = TDataObject[Tname].toObject();
    QJsonObject ColObject = TableObject["Columns"].toObject();
    TDataFile.close();
    if( ColObject[ColObject.keys()[0]].toString() == DT.FLOAT || ColObject[ColObject.keys()[0]].toString() == DT.INT ){
        YCol = ColObject.keys()[0];
        XCol = ColObject.keys()[1];
    }
    else{
        YCol = ColObject.keys()[1];
        XCol = ColObject.keys()[0];
    }
    TDataFile.setFileName(STORAGE_PATH+DATASTORE_USE+"/"+Tname+TableExtsn);
    if(!TDataFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    TData = TDataFile.readAll() ;
    TDataDoc = QJsonDocument::fromJson(TData.toUtf8());;
    TDataObject = TDataDoc.object();
    TDataFile.close();
    XY["X"] = TDataObject[XCol].toArray();
    XY["Y"] = TDataObject[YCol].toArray();
    return XY;
}
void FileHandler::UpdatePiechartInfo(PiechartDefinition PD){
    QFile PFile;
    PFile.setFileName(PIECHARTINFO_PATH);
    if(!PFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    QString PData = PFile.readAll() ;
    QJsonDocument PDoc = QJsonDocument::fromJson(PData.toUtf8());
    QJsonObject PObject = PDoc.object();
    QJsonValue PDefVal = PObject[PD.Name];
    QJsonObject PDefObject = PDefVal.toObject();
    PDefObject["CountAttrs"] = PD.CountAttrs;
    PDefObject["Attrs"] = PD.Attrs;
    PDefObject["DOC"] = PD.DOC;
    PDefObject["Datastore"] = PD.Datastore;
    PDefObject["Link"] = PD.Link;
    PObject[PD.Name] = PDefObject;
    PDoc.setObject(PObject);
    PFile.close();
    PFile.setFileName(PIECHARTINFO_PATH);
    if(!PFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    PFile.write(PDoc.toJson());
    PFile.close();
}
void FileHandler::UpdateLinegraphInfo(LinegraphDefinition LD){
    QFile LFile;
    LFile.setFileName(LINEGRAPHINFO_PATH);
    if(!LFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    QString LData = LFile.readAll() ;
    QJsonDocument LDoc = QJsonDocument::fromJson(LData.toUtf8());
    QJsonObject LObject = LDoc.object();
    QJsonValue LDefVal = LObject[LD.Name];
    QJsonObject LDefObject = LDefVal.toObject();
    LDefObject["CountAttrs"] = LD.CountAttrs;
    LDefObject["Attrs"] = LD.Attrs;
    LDefObject["DOC"] = LD.DOC;
    LDefObject["Datastore"] = LD.Datastore;
    LDefObject["Link"] = LD.Link;
    LObject[LD.Name] = LDefObject;
    LDoc.setObject(LObject);
    LFile.close();
    LFile.setFileName(LINEGRAPHINFO_PATH);
    if(!LFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    LFile.write(LDoc.toJson());
    LFile.close();
}
void FileHandler::UpdateBargraphInfo(BargraphDefinition BD){
    QFile BFile;
    BFile.setFileName(BARGRAPHINFO_PATH);
    if(!BFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    QString BData = BFile.readAll() ;
    QJsonDocument BDoc = QJsonDocument::fromJson(BData.toUtf8());
    QJsonObject BObject = BDoc.object();
    QJsonValue BDefVal = BObject[BD.Name];
    QJsonObject BDefObject = BDefVal.toObject();
    BDefObject["CountAttrs"] = BD.CountAttrs;
    BDefObject["Attrs"] = BD.Attrs;
    BDefObject["DOC"] = BD.DOC;
    BDefObject["Datastore"] = BD.Datastore;
    BDefObject["Link"] = BD.Link;
    BObject[BD.Name] = BDefObject;
    BDoc.setObject(BObject);
    BFile.close();
    BFile.setFileName(BARGRAPHINFO_PATH);
    if(!BFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    BFile.write(BDoc.toJson());
    BFile.close();
}
bool FileHandler::CreatePiechart(QString Name, StrList Attrs, StrList AttrList){
    QFile PDataFile;
    QString PDataFilePath = STORAGE_PATH+DATASTORE_USE+"/"+Name+PiechartExtsn ;
    PDataFile.setFileName(PDataFilePath);
    if(!PDataFile.open(QIODevice::ReadWrite | QIODevice::Text)) return false;
    QJsonDocument PDataDoc;
    QJsonObject PDataObject = PDataDoc.object();
    for( int i = 0 ; i < Attrs.size() ; i++ ) PDataObject[Attrs[i]] = AttrList[i];
    PDataDoc.setObject(PDataObject);
    PDataFile.write(PDataDoc.toJson());
    PDataFile.close();
    return true;
}
bool FileHandler::CreateBargraph(QString Name, StrList Attrs, StrList AttrList){
    QFile BDataFile;
    QString BDataFilePath = STORAGE_PATH+DATASTORE_USE+"/"+Name+BargraphExtsn ;
    BDataFile.setFileName(BDataFilePath);
    if(!BDataFile.open(QIODevice::ReadWrite | QIODevice::Text)) return false;
    QJsonDocument BDataDoc;
    QJsonObject BDataObject = BDataDoc.object();
    for( int i = 0 ; i < Attrs.size() ; i++ ) BDataObject[Attrs[i]] = AttrList[i];
    BDataDoc.setObject(BDataObject);
    BDataFile.write(BDataDoc.toJson());
    BDataFile.close();
    return true;
}
bool FileHandler::CreateLinegraph(QString Name, StrList Attrs, StrList AttrList){
    QFile LDataFile;
    QString LDataFilePath = STORAGE_PATH+DATASTORE_USE+"/"+Name+LinegraphExtsn ;
    LDataFile.setFileName(LDataFilePath);
    if(!LDataFile.open(QIODevice::ReadWrite | QIODevice::Text)) return false;
    QJsonDocument LDataDoc;
    QJsonObject LDataObject = LDataDoc.object();
    for( int i = 0 ; i < Attrs.size() ; i++ ) LDataObject[Attrs[i]] = AttrList[i];
    LDataDoc.setObject(LDataObject);
    LDataFile.write(LDataDoc.toJson());
    LDataFile.close();
    return true;
}
bool FileHandler::CreatePieFileFromTable(QString Pname, QString Tname){
    PiechartDefinition PD ;
    MapStrJA XY = GetXYPlots(Tname);
    PD.Name = Pname;
    PD.Datastore = DATASTORE_USE;
    PD.Link = Tname;
    PD.DOC = TodayDateTime;
    PD.CountAttrs = XY["X"].size();
    PD.Attrs = XY["X"];
    UpdateDSInfo(DATASTORE_USE,"PiechartList",Pname);
    UpdatePiechartInfo(PD);
    return CreatePiechart(Pname,JsonArrayToStrList(XY["X"]),JsonArrayToStrList(XY["Y"]));
}
bool FileHandler::CreateBarFileFromTable(QString Bname, QString Tname){
    BargraphDefinition BD ;
    MapStrJA XY = GetXYPlots(Tname);
    BD.Name = Bname;
    BD.Datastore = DATASTORE_USE;
    BD.Link = Tname;
    BD.DOC = TodayDateTime;
    BD.CountAttrs = XY["X"].size();
    BD.Attrs = XY["X"];
    UpdateDSInfo(DATASTORE_USE,"BargraphList",Bname);
    UpdateBargraphInfo(BD);
    return CreateBargraph(Bname,JsonArrayToStrList(XY["X"]),JsonArrayToStrList(XY["Y"]));
}
bool FileHandler::CreateLineFileFromTable(QString Lname, QString Tname){
    LinegraphDefinition LD ;
    MapStrJA XY = GetXYPlots(Tname);
    LD.Name = Lname;
    LD.Datastore = DATASTORE_USE;
    LD.Link = Tname;
    LD.DOC = TodayDateTime;
    LD.CountAttrs = XY["X"].size();
    LD.Attrs = XY["X"];
    UpdateDSInfo(DATASTORE_USE,"LinegraphList",Lname);
    UpdateLinegraphInfo(LD);
    return CreateLinegraph(Lname,JsonArrayToStrList(XY["X"]),JsonArrayToStrList(XY["Y"]));
}
bool FileHandler::CreatePieFromData(QString Name, StrList Attrs, StrList AttrVals){
    PiechartDefinition PD;
    PD.Name = Name;
    PD.Datastore = DATASTORE_USE;
    PD.Link = "";
    PD.DOC = TodayDateTime;
    PD.CountAttrs = Attrs.size();
    PD.Attrs = StrListToJA(Attrs);
    UpdateDSInfo(DATASTORE_USE,"PiechartList",Name);
    UpdatePiechartInfo(PD);
    return CreatePiechart(Name,Attrs,AttrVals);
}
bool FileHandler::CreateBarFromData(QString Name, StrList Attrs, StrList AttrVals){
    BargraphDefinition BD ;
    BD.Name = Name;
    BD.Datastore = DATASTORE_USE;
    BD.Link = "";
    BD.DOC = TodayDateTime;
    BD.CountAttrs = Attrs.size();
    BD.Attrs = StrListToJA(Attrs);
    UpdateDSInfo(DATASTORE_USE,"BargraphList",Name);
    UpdateBargraphInfo(BD);
    return CreateBargraph(Name,Attrs,AttrVals);
}
bool FileHandler::CreateLineFromData(QString Name, StrList Attrs, StrList AttrVals){
    LinegraphDefinition LD ;
    LD.Name = Name;
    LD.Datastore = DATASTORE_USE;
    LD.Link = "";
    LD.DOC = TodayDateTime;
    LD.CountAttrs = Attrs.size();
    LD.Attrs = StrListToJA(Attrs);
    UpdateDSInfo(DATASTORE_USE,"LinegraphList",Name);
    UpdateLinegraphInfo(LD);
    return CreateLinegraph(Name,Attrs,AttrVals);
}
bool FileHandler::RemovePiechart(QString Pname){
    if( RemoveStruct(Pname,"Piechart") ){
        RemoveFromDS(DATASTORE_USE,Pname,"PiechartList");
        RemoveFromStructInfo(Pname,"Piechart");
    }
    else return false;
    return true;
}
bool FileHandler::RemoveBargraph(QString Bname){
    if( RemoveStruct(Bname,"Bargraph") ){
        RemoveFromDS(DATASTORE_USE,Bname,"BargraphList");
        RemoveFromStructInfo(Bname,"Bargraph");
    }
    else return false;
    return true;
}
bool FileHandler::RemoveLinegraph(QString Lname){
    if( RemoveStruct(Lname,"Linegraph") ){
        RemoveFromDS(DATASTORE_USE,Lname,"LinegraphList");
        RemoveFromStructInfo(Lname,"Linegraph");
    }
    else return false;
    return true;
}
void FileHandler::StructLinkChange(QString Name, QString FilePath){
    QFile SFile;
    SFile.setFileName(FilePath);
    if(!SFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    QString SData = SFile.readAll() ;
    QJsonDocument SDoc = QJsonDocument::fromJson(SData.toUtf8());
    QJsonObject SObject = SDoc.object();
    QJsonValue SDefVal = SObject[Name];
    QJsonObject SDefObject = SDefVal.toObject();
    SDefObject["Link"] = "";
    SObject[Name] = SDefObject;
    SDoc.setObject(SObject);
    SFile.close();
    SFile.setFileName(FilePath);
    if(!SFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    SFile.write(SDoc.toJson());
    SFile.close();
}
void FileHandler::StructLinkWithTable(QString Name, QString Tname, QString StructType , QTextEdit* REPLWIN){
    if( Tname == "" ){
        if( StructType == "Piechart" ) StructLinkChange(Name, PIECHARTINFO_PATH) ;
        else if( StructType == "Bargraph" ) StructLinkChange(Name, BARGRAPHINFO_PATH) ;
        else if( StructType == "Linegraph" ) StructLinkChange(Name, LINEGRAPHINFO_PATH) ;
    }else{
        if( StructType == "Piechart" ){
            if(!RemovePiechart(Name)) ER.PrintSysGenError("FILEHANDLER_LINK_ERROR",REPLWIN);
            else{
                 if( !CreatePieFileFromTable(Name,Tname) ) ER.PrintSysGenError("FILEHANDLER_LINK_ERROR",REPLWIN);
            }
        }
        else if( StructType == "Bargraph" ){
            if(!RemoveBargraph(Name)) ER.PrintSysGenError("FILEHANDLER_LINK_ERROR",REPLWIN);
            else{
                 if( !CreateBarFileFromTable(Name,Tname) ) ER.PrintSysGenError("FILEHANDLER_LINK_ERROR",REPLWIN);
            }
        }
        else if( StructType == "Linegraph" ){
            if(!RemoveLinegraph(Name)) ER.PrintSysGenError("FILEHANDLER_LINK_ERROR",REPLWIN);
            else{
                 if( !CreateLineFileFromTable(Name,Tname) ) ER.PrintSysGenError("FILEHANDLER_LINK_ERROR",REPLWIN);
            }
        }
    }
}
MapStrStr FileHandler::GetStructData(QString Name,QString StructName){
    QString FilePath ;
    MapStrStr StructData;
    if( StructName == "Piechart" ) FilePath = STORAGE_PATH+DATASTORE_USE+"/"+Name+PiechartExtsn ;
    else if( StructName == "Bargraph" )FilePath = STORAGE_PATH+DATASTORE_USE+"/"+Name+BargraphExtsn ;
    else if( StructName == "Linegraph" )FilePath = STORAGE_PATH+DATASTORE_USE+"/"+Name+LinegraphExtsn ;
    QFile SFile;
    SFile.setFileName(FilePath);
    if(!SFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    QString SData = SFile.readAll() ;
    QJsonDocument SDoc = QJsonDocument::fromJson(SData.toUtf8());
    QJsonObject SObject = SDoc.object();
    for( auto Col:SObject.keys() ) StructData[Col] = SObject[Col].toString();
    SFile.close();
    return StructData ;
}
QChartView* FileHandler::CreatePiechartView(QString Pname, MapStrStr PieData){
    QPieSeries *PieSeries = new QPieSeries();
    for( auto Attr:PieData.keys() ){
        if( DT.FLT_REGX.match(PieData[Attr]).hasMatch() ) PieSeries->append(Attr,PieData[Attr].toDouble());
        else if ( DT.INT_REGX.match(PieData[Attr]).hasMatch() ) PieSeries->append(Attr,PieData[Attr].toInt());
    }
    QChart *PieChart = new QChart();
    PieChart->addSeries(PieSeries);
    PieChart->setTitle("Piechart : "+Pname);
    QChartView *ChartView = new QChartView(PieChart);
    ChartView->setBackgroundRole(QPalette::Light);
    ChartView->setGeometry(0,0,400,400);
    return ChartView;
}
QChartView* FileHandler::CreateBargraphView(QString Bname, MapStrStr BarData){
    QBarSet *Bars = new QBarSet("");
    QBarSeries *BarSeries = new QBarSeries();
    QChart * Barchart = new QChart();
    StrList XAxisValues ;
    QBarCategoryAxis *AxisX = new QBarCategoryAxis();
    QValueAxis *AxisY = new QValueAxis();
    QChartView  *ChartView = new QChartView();
    ChartView->setBackgroundRole(QPalette::Light);
    double max = 0.0;
    for( int i = 0 ; i < BarData.keys().size() ; i++ ){
        XAxisValues << BarData.keys()[i];
        if( DT.FLT_REGX.match(BarData[BarData.keys()[i]]).hasMatch() ) (*Bars) << BarData[BarData.keys()[i]].toDouble();
        else if( DT.INT_REGX.match(BarData[BarData.keys()[i]]).hasMatch() ) (*Bars) << BarData[BarData.keys()[i]].toInt();
        if( BarData[BarData.keys()[i]].toFloat() > max ) max = BarData[BarData.keys()[i]].toDouble() ;
    }
    max += 10 ;
    BarSeries -> append(Bars);
    Barchart->addSeries(BarSeries);
    Barchart->setTitle("Bargraph : "+Bname);
    AxisX->append(XAxisValues);
    Barchart->addAxis(AxisX,Qt::AlignBottom);
    BarSeries->attachAxis(AxisX);
    Barchart->addAxis(AxisY,Qt::AlignLeft);
    BarSeries->attachAxis(AxisY);
    AxisY->setRange(0,max);
    Barchart->legend()->setVisible(false);
    ChartView->setChart(Barchart);
    ChartView->setGeometry(0,0,400,400);
    return ChartView;
}
QChartView* FileHandler::CreateLinegraphView(QString Lname, MapStrStr LineData){
    QLineSeries *LineSeries = new QLineSeries();
    QChart *Linechart = new QChart();
    QValueAxis *AxisX = new QValueAxis();
    QValueAxis *AxisY = new QValueAxis();
    QChartView *ChartView = new QChartView();
    double max1 = 0.0, max2 = 0.0;
    for( int i = 0 ; i < LineData.keys().size() ; i++ ){
        if( DT.FLT_REGX.match(LineData.keys()[i]).hasMatch() ) {
            if( DT.FLT_REGX.match(LineData[LineData.keys()[i]]).hasMatch() ) LineSeries->append(LineData.keys()[i].toDouble(),LineData[LineData.keys()[i]].toDouble());
            else if( DT.INT_REGX.match(LineData[LineData.keys()[i]]).hasMatch() ) LineSeries->append(LineData.keys()[i].toDouble(),LineData[LineData.keys()[i]].toInt());
        }
        else if( DT.INT_REGX.match(LineData[LineData.keys()[i]]).hasMatch() ){
            if( DT.FLT_REGX.match(LineData[LineData.keys()[i]]).hasMatch() ) LineSeries->append(LineData.keys()[i].toInt(),LineData[LineData.keys()[i]].toDouble());
            else if( DT.INT_REGX.match(LineData[LineData.keys()[i]]).hasMatch() ) LineSeries->append(LineData.keys()[i].toInt(),LineData[LineData.keys()[i]].toInt());
        }
        if( LineData.keys()[i].toDouble() > max1 ) max1 = LineData.keys()[i].toDouble() ;
        if( LineData[LineData.keys()[i]].toDouble() > max2 ) max2 = LineData[LineData.keys()[i]].toDouble() ;
    }
    max1 += 10 ;
    max2 += 10 ;
    Linechart->addSeries(LineSeries);
    Linechart->setTitle("Linegraph : "+Lname);
    Linechart->addAxis(AxisX,Qt::AlignBottom);
    Linechart->addAxis(AxisY,Qt::AlignLeft);
    LineSeries->attachAxis(AxisY);
    AxisX->setRange(0,max1);
    AxisY->setRange(0,max2);
    ChartView->setBackgroundRole(QPalette::Light);
    ChartView->setChart(Linechart);
    ChartView->setGeometry(0,0,400,400);
    return ChartView;
}

double FileHandler::CalMean(StrList Datavals){
    int n = 0 ;
    double sum = 0 ;
    double mean;
    for( auto Val : Datavals ){
        n ++;
        sum = sum + Val.toDouble();
    }
    mean = sum / n ;
    return mean;
}
double FileHandler::CalMode(StrList Datavals){
    double mode ;
    int c = 0;
    for( auto Val:Datavals ){
        if( Datavals.count(Val) > c ){
            mode = Val.toDouble();
            c = Datavals.count(Val) ;
        }
    }
    if ( c == 1 ) return -1;
    else return mode ;
}
double FileHandler::CalMedian(StrList Datavals){
    QVector<double> RealVals ;
    int mid = (Datavals.size() / 2) + 1;
    for( auto Val : Datavals ) RealVals << Val.toDouble();
    std::sort(RealVals.begin(),RealVals.end());
    return RealVals[mid];
}
double FileHandler::CalSum(StrList Datavals){
    double sum = 0 ;
    for( auto Val : Datavals ) sum = sum + Val.toDouble() ;
    return sum ;
}
double FileHandler::CalMax(StrList Datavals){
    QVector<double> RealVals ;
    for( auto Val : Datavals ) RealVals << Val.toDouble();
    std::sort(RealVals.begin(),RealVals.end());
    return RealVals[RealVals.size()-1];
}
double FileHandler::CalMin(StrList Datavals){
    QVector<double> RealVals ;
    for( auto Val : Datavals ) RealVals << Val.toDouble();
    std::sort(RealVals.begin(),RealVals.end());
    return RealVals[0];
}
double FileHandler::CalAvg(StrList Datavals){
    return CalMean(Datavals);
}
double FileHandler::CalSD(StrList Datavals){
    double mean = CalMean(Datavals);
    double sum = 0;
    int n = Datavals.size();
    double deviation ;
    double sd;
    for( auto D:Datavals ){
        deviation =  D.toDouble() - mean ;
        sum = sum + deviation * deviation ;
    }
    sd = sqrt( sum / ( n - 1 ) );
    return sd ;
}
double FileHandler::CalVarience(StrList Datavals){
    double mean = CalMean(Datavals);
    double sum = 0;
    int n = Datavals.size();
    double deviation ;
    for( auto D:Datavals ){
        deviation =  D.toDouble() - mean ;
        sum = sum + deviation * deviation ;
    }
    return ( sum / ( n - 1 ) );
}
QMap<QString,int> FileHandler::CalFrequency(StrList Datavals){
    QMap<QString,int> DataFreq ;
    for( auto Val : Datavals ) DataFreq[Val] = Datavals.count(Val);
    return DataFreq;
}
MapStrStrList FileHandler::GetColsVals(QString Tname, StrList Cols){
    MapStrStrList ColsVals ;
    QFile TDataFile;
    QString TDataFilePath = STORAGE_PATH+DATASTORE_USE+"/"+Tname+TableExtsn ;
    TDataFile.setFileName(TDataFilePath);
    if(!TDataFile.open(QIODevice::ReadWrite | QIODevice::Text)) qWarning() << "Unsucessfull!";
    QString TData = TDataFile.readAll() ;
    QJsonDocument TDataDoc = QJsonDocument::fromJson(TData.toUtf8());;
    QJsonObject TDataObject = TDataDoc.object();
    for( auto Col:Cols) ColsVals[Col] = JsonArrayToStrList(TDataObject[Col].toArray());
    TDataFile.close();
    return ColsVals;
}

//MapStrStrList FileHandler::SortBy(MapStrStrList TableData,StrList Cols,StrList Odrs){
//    MapStrStrList SortedTableData;
//    QMap<QString,int> ColIndex ;
//    int row ,int ncol;
//    for( int i = 0 ; i < TableData.keys().size() ; i++ ) ColIndex.insert(TableData.keys()[i],i);
//}


#endif // FILEHANDLER_H
