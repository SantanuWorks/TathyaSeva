#ifndef AUTOMATA_H
#define AUTOMATA_H
#include <QApplication>
#include <QTextEdit>
#include "Error.h"
#include "QueryExecuter.h"

QueryExecuter QE;

typedef QStringList StrList ;
typedef QMap<QString,QStringList> MapStrStrList ;

class Automata{
public:

    // Datastore Commands
    StrList DatastoreListStates ;
    StrList DatastoreCreateStates ;
    StrList DatastoreDeleteStates ;
    StrList DatastoreForceDeleteStates ;
    StrList DatastoreDeleteCommonStates;
    StrList DatastoreClearCommonStates ;
    StrList DatastoreClearAllStates ;
    StrList DatastoreClearSelectedStates ;
    StrList DatastoreRenameStates ;
    StrList DatastoreCountCommonStates ;
    StrList DatastoreUseCountAllStates ;
    StrList DatastoreUseCountTablesStates ;
    StrList DatastoreUseCountPiechartsStates ;
    StrList DatastoreUseCountLinegraphsStates ;
    StrList DatastoreUseCountBargraphsStates ;
    StrList DatastoreNameCountCommonStates ;
    StrList DatastoreCountAllStates ;
    StrList DatastoreCountTablesStates  ;
    StrList DatastoreCountPiechartsStates  ;
    StrList DatastoreCountLinegraphsStates ;
    StrList DatastoreCountBargraphsStates ;
    StrList DatastoreUseCommonStates;
    StrList DatastoreUseStates ;
    StrList DatastoreUseDisplayStates ;
    StrList DatastoreUseDefaultStates ;
    StrList DatastoreDisplayCommonStates ;
    StrList DatastoreDisplayAllStates ;
    StrList DatastoreDisplayTablesStates ;
    StrList DatastoreDisplayPiechartsStates ;
    StrList DatastoreDisplayBargraphsStates ;
    StrList DatastoreDisplayLinegraphsStates ;
    StrList DatastoreUseDisplayAllStates ;
    StrList DatastoreUseDisplayTablesStates ;
    StrList DatastoreUseDisplayPiechartsStates ;
    StrList DatastoreUseDisplayBargraphsStates ;
    StrList DatastoreUseDisplayLinegraphsStates ;
    StrList DatastoreNameDisplayCommonStates;

    // Table Commands
    StrList TableCreateStates ;
    StrList TableInsertStates ;
    StrList TableChangeStates ;
    StrList TableRenameStates ;
    StrList TableRenameColStates ;
    StrList TableRenameCommonStates ;
    StrList TableAddStates ;
    StrList TableClearCommonStates ;
    StrList TableClearTableStates ;
    StrList TableClearColStates ;
    StrList TableDisplayCommonStates ;
    StrList TableDisplayAllStates ;
    StrList TableDisplayColsStates ;
    StrList TableDisplayStructureStates ;
    StrList TableDeleteCommonStates ;
    StrList TableDeleteStates ;
    StrList TableDeleteColStates ;
    StrList TableOrderDisplayCommonStates ;
    StrList TableOrderDisplayStates ;
    StrList TableColsOrderDisplayStates ;

    StrList TableCalCommonStates ;
    StrList TableCalSumStates ;
    StrList TableCalCountStates ;
    StrList TableCalAvgStates ;
    StrList TableCalMinStates ;
    StrList TableCalMaxStates ;
    StrList TableCalMeanStates ;
    StrList TableCalModeStates ;
    StrList TableCalMedianStates ;
    StrList TableCalFrequencyStates ;
    StrList TableCalSDStates ;
    StrList TableCalVarienceStates ;

    // Table Commands - unconfirmed
    StrList TableUpdateStates ;
    StrList TableSelectAllWhereStates = { "TABLE" , "DISPLAY" , "NAME" , "WHERE" ,"(" , "EXPR" , ")" , ";" };
    StrList TableSelectColsWhereStates = { "TABLE" , "DISPLAY" , "NAME" , "(" , "COL" , "," , ")" , "WHERE" , "(" , "EXPR" , ")" , ";" };
    StrList TableUpdateWhereStates = { "TABLE" , "UPDATE" , "NAME" , "{" , "COL" , "=" , "DATA" , ",", "}" , "WHERE" , "(" , "EXPR" , ")", ";" };
    StrList TableDeleteRowStates = { "TABLE", "DELETE" , "NAME" , "WHERE" , "(" , "EXPR" , ")" , ";" };

    // PieChart Commmadss
    StrList PieFromTableStates ;
    StrList PieCreateStates ;
    StrList PieCreateCommonStates ;
    StrList PieDisplayStates ;
    StrList PieDisplayPercentStates ;
    StrList PieDisplayCommonStates ;
    StrList PieDeleteStates ;
    StrList PieRenameStates ;
    StrList PieLinkTableStates ;
    StrList PieRemoveLinkTableStates ;
    StrList PieLinkCommonStates ;

    // BarGraph Commmads
    StrList BarFromTableStates ;
    StrList BarCreateStates ;
    StrList BarCreateCommonStates ;
    StrList BarDisplayStates ;
    StrList BarDeleteStates ;
    StrList BarRenameStates ;
    StrList BarLinkTableStates ;
    StrList BarRemoveLinkTableStates ;
    StrList BarLinkCommonStates ;

    // LineGraph Commmads
    StrList LineFromTableStates ;
    StrList LineCreateStates ;
    StrList LineCreateCommonStates ;
    StrList LineDisplayStates ;
    StrList LineDeleteStates ;
    StrList LineRenameStates ;
    StrList LineLinkTableStates ;
    StrList LineRemoveLinkTableStates ;
    StrList LineLinkCommonStates ;

    // Language Command
    StrList ChangeLangCmdStates ;
    StrList LangDisplayCmdState ;

    // Environment Command
    StrList EnvClearScreenStates ;
    StrList EnvClearHistoryState ;
    StrList EnvExitStates ;

    StrList EnvMeanStates ;
    StrList EnvModeStates ;
    StrList EnvMedianStates ;
    StrList EnvSumStates ;
    StrList EnvMinStates ;
    StrList EnvMaxStates ;
    StrList EnvAvgStates ;
    StrList EnvSDStates ;
    StrList EnvVarienceStates ;

    StrList EnvFrequencyCommonStates ;
    StrList EnvFrequencyStates ;
    StrList EnvFrequencyTableStates ;
    StrList EnvFrequencyTablesStates ;

    // MapStrStr KeyVal_KeyCode;
    MapStrStrList TokenKey_KeyList;
    MapStrStr Key_KeyValue;
    
    // status of various commands
    bool EnvCommandStatus = false;
    bool LangCommandStatus = false;
    bool DatastoreCommandStatus = false;
    bool TableCommandStatus = false;
    bool PiechartCommandStatus = false;
    bool BargraphCommandStatus = false;
    bool LinegraphCommandStatus = false;

    QTextEdit *REPLWIN;
    StrList RawTokens ;
    MapStrStrList QueryData;

    Automata();
    void EmptyMaps();
    void StartAutomata(StrList Tokens, StrList TokensRaw, MapStrStrList TokenKey_KeyList, MapStrStr Key_KeyValue, QTextEdit *REPLWIN, QVector<QString>* CHV);
    void InitializeQueryStates(QString CommandType);
    void InitializeEnvQueryStates(QJsonObject QSCommandObject);
    void InitializeLangQueryStates(QJsonObject QSCommandObject);
    void InitializeDatastoreQueryStates(QJsonObject QSCommandObject);
    void InitializeTableQueryStates(QJsonObject QSCommandObject);
    void InitializePiechartQueryStates(QJsonObject QSCommandObject);
    void InitializeBargraphQueryStates(QJsonObject QSCommandObject);
    void InitializeLinegraphQueryStates(QJsonObject QSCommandObject);

    void ChangeLangCmd(int State, StrList Tokens, int index);
    void LangDisplayCmd(int State, StrList Tokens, int index);

    void EnvClearScreenCmd(int State, StrList Tokens, int index);
    void EnvClearHistoryCmd(int State, StrList Tokens, int index, QVector<QString>* CHV);
    void EnvExitCmd(int State, StrList Tokens, int index);

    void EnvMeanCmd(int State, StrList Tokens, int index);
    void EnvModeCmd(int State, StrList Tokens, int index);
    void EnvMedianCmd(int State, StrList Tokens, int index);
    void EnvSumCmd(int State, StrList Tokens, int index);
    void EnvMinCmd(int State, StrList Tokens, int index);
    void EnvMaxCmd(int State, StrList Tokens, int index);
    void EnvAvgCmd(int State, StrList Tokens, int index);
    void EnvSDCmd(int State, StrList Tokens, int index);
    void EnvVarienceCmd(int State, StrList Tokens, int index);
    void EnvFrequencyDataCmd(int State, StrList Tokens, int index);
    void EnvFrequencyCmd(int State, StrList Tokens, int index);
    void EnvFrequencyTableCmd(int State, StrList Tokens, int index);
    void EnvFrequencyTablesCmd(int State, StrList Tokens, int index);


    void DatastoreListCmd(int State, StrList Tokens, int index);
    void DatastoreCreateCmd(int State, StrList Tokens, int index);
    void DatastoreDeleteCmd(int State, StrList Tokens, int index);
    void DatastoreDeleteNormalCmd(int State, StrList Tokens, int index);
    void DatastoreDeleteForceCmd(int State, StrList Tokens, int index);
    void DatastoreClearCmd(int State, StrList Tokens, int index);
    void DatastoreClearAllCmd(StrList Tokens, int index);
    void DatastoreClearSelectedCmd(int State, StrList Tokens, int index);
    void DatastoreRenameCmd(int State, StrList Tokens, int index);
    void DatastoreUseCmd(int State, StrList Tokens, int index);
    void DatastoreDisplayCmd(int State, StrList Tokens, int index);
    void DatastoreDisplayAllCmd( StrList Tokens, int index);
    void DatastoreDisplayTablesCmd(StrList Tokens, int index);
    void DatastoreDisplayPiechartsCmd(StrList Tokens, int index);
    void DatastoreDisplayLinegraphsCmd(StrList Tokens, int index);
    void DatastoreDisplayBargraphsCmd(StrList Tokens, int index);
    void DatastoreUseNameCmd(StrList Tokens, int index);
    void DatastoreDisplayUseCmd(StrList Tokens, int index);
    void DatastoreUseDefaultCmd(StrList Tokens, int index);
    void DatastoreCountCmd(int State, StrList Tokens, int index);
    void DatastoreUseCountAllCmd(StrList Tokens, int index);
    void DatastoreUseCountTablesCmd(StrList Tokens, int index);
    void DatastoreUseCountPiechartsCmd(StrList Tokens, int index);
    void DatastoreUseCountLinegraphsCmd(StrList Tokens, int index);
    void DatastoreUseCountBargraphsCmd(StrList Tokens, int index);
    void DatastoreNameCountCmd( StrList Tokens, int index);
    void DatastoreCountAllCmd( StrList Tokens, int index);
    void DatastoreCountTablesCmd( StrList Tokens, int index);
    void DatastoreCountPiechartsCmd( StrList Tokens, int index);
    void DatastoreCountLinegraphsCmd(StrList Tokens, int index);
    void DatastoreCountBargraphsCmd(StrList Tokens, int index);
    void DatastoreUseDisplayCmd(StrList Tokens, int index);
    void DatastoreNameDisplayCmd(int State,StrList Tokens, int index);



    void TableCreateCmd(int State, StrList Tokens, int index);
    void TableInsertCmd(int State, StrList Tokens, int index);
    void TableChangeCmd(int State, StrList Tokens, int index);
    void TableAddCmd(int State, StrList Tokens, int index);
    void TableRenameCmd(int State, StrList Tokens, int index);
    void TableRenameColsCmd(int State, StrList Tokens, int index);
    void TableRenameTableCmd(int State, StrList Tokens, int index);
    void TableClearCmd(int State, StrList Tokens, int index);
    void TableClearColsCmd(int State, StrList Tokens, int index);
    void TableClearTableCmd(StrList Tokens, int index);
    void TableDisplayCmd(int State,StrList Tokens, int index);
    void TableDisplayAllCmd(StrList Tokens, int index);
    void TableDisplayColsCmd(int State,StrList Tokens, int index);
    void TableDisplayStructureCmd(StrList Tokens, int index);
    void TableOrderDisplayCmd(int State, StrList Tokens, int index );
    void TableOrderDisplayTableCmd(int State, StrList Tokens, int index);
    void TableOrderDisplayColsCmd(int State, StrList Tokens, int index);
    void TableDeleteCmd(int State,StrList Tokens, int index);
    void TableDeleteTableCmd(StrList Tokens, int index);
    void TableDeleteColsCmd(int State,StrList Tokens, int index);


    void TableCalCmd( int State, StrList Tokens, int index);
    void TableCalSumCmd( int State, StrList Tokens, int index);
    void TableCalCountCmd( int State, StrList Tokens, int index);
    void TableCalAvgCmd( int State, StrList Tokens, int index);
    void TableCalMinCmd( int State, StrList Tokens, int index);
    void TableCalMaxCmd( int State, StrList Tokens, int index);
    void TableCalMeanCmd( int State, StrList Tokens, int index);
    void TableCalModeCmd( int State, StrList Tokens, int index);
    void TableCalMedianCmd( int State, StrList Tokens, int index);
    void TableCalFrequencyCmd( int State, StrList Tokens, int index);
    void TableCalSDCmd( int State, StrList Tokens, int index);
    void TableCalVarienceCmd( int State, StrList Tokens, int index);


    void TableUpdateCmd(int State,StrList Tokens, int index);

    void PieCreateCmd(int State, StrList Tokens, int index);
    void PieCreateFromTableCmd(int State, StrList Tokens, int index);
    void PieCreateFromDataCmd(int State, StrList Tokens, int index);
    void PieDisplayCmd(int State, StrList Tokens, int index);
    void PieDisplayNormalCmd(int State, StrList Tokens, int index);
    void PieDisplayPercentCmd(int State, StrList Tokens, int index);
    void PieDeleteCmd(int State, StrList Tokens, int index);
    void PieRenameCmd(int State, StrList Tokens, int index);
    void PieLinkCmd(int State, StrList Tokens, int index);
    void PieLinkTableCmd(int State, StrList Tokens, int index);
    void PieLinkRemoveCmd(int State, StrList Tokens, int index);

    void BarCreateCmd(int State, StrList Tokens, int index);
    void BarCreateFromTableCmd(int State, StrList Tokens, int index);
    void BarCreateFromDataCmd(int State, StrList Tokens, int index);
    void BarDisplayCmd(int State, StrList Tokens, int index);
    void BarDeleteCmd(int State, StrList Tokens, int index);
    void BarRenameCmd(int State, StrList Tokens, int index);
    void BarLinkCmd(int State, StrList Tokens, int index);
    void BarLinkTableCmd(int State, StrList Tokens, int index);
    void BarLinkRemoveCmd(int State, StrList Tokens, int index);

    void LineCreateCmd(int State, StrList Tokens, int index);
    void LineCreateFromTableCmd(int State, StrList Tokens, int index);
    void LineCreateFromDataCmd(int State, StrList Tokens, int index);
    void LineDisplayCmd(int State, StrList Tokens, int index);
    void LineDeleteCmd(int State, StrList Tokens, int index);
    void LineRenameCmd(int State, StrList Tokens, int index);
    void LineLinkCmd(int State, StrList Tokens, int index);
    void LineLinkTableCmd(int State, StrList Tokens, int index);
    void LineLinkRemoveCmd(int State, StrList Tokens, int index);

};
Automata::Automata(){
    QueryData["DATASTORE_NAMES"] = {} ;
    QueryData["STRUCTURE_NAMES"] = {} ;
    QueryData["TABLE_NAMES"] = {} ;
    QueryData["TABLENAME"] = {} ;
    QueryData["COL_NAMES"] = {} ;
    QueryData["NEWCOL_NAMES"] = {} ;
    QueryData["DATATYPES"] = {} ;
    QueryData["DATA"] = {} ;
    QueryData["PIECHART_NAMES"] = {} ;
    QueryData["BARGRAPH_NAMES"] = {} ;
    QueryData["LINEGRAPH_NAMES"] = {} ;
    QueryData["DATANAMES"] = {} ;
    QueryData["DATAVALS"] = {} ;
    QueryData["Xs"] = {} ;
    QueryData["Ys"] = {} ;
    QueryData["DISPLAY_COL_NAMES"]  = {};
    QueryData["ORDER_COL_NAMES"] = {};
    QueryData["ORDERVALS"] = {};
    QueryData["LANGS"] = {};
}
void Automata::EmptyMaps(){
    QueryData["DATASTORE_NAMES"] = {} ;
    QueryData["STRUCTURE_NAMES"] = {} ;
    QueryData["TABLE_NAMES"] = {} ;
    QueryData["TABLENAME"] = {} ;
    QueryData["COL_NAMES"] = {} ;
    QueryData["NEWCOL_NAMES"] = {} ;
    QueryData["DATATYPES"] = {} ;
    QueryData["DATA"] = {} ;
    QueryData["PIECHART_NAMES"] = {} ;
    QueryData["BARGRAPH_NAMES"] = {} ;
    QueryData["LINEGRAPH_NAMES"] = {} ;
    QueryData["DATANAMES"] = {} ;
    QueryData["DATAVALS"] = {} ;
    QueryData["Xs"] = {} ;
    QueryData["Ys"] = {} ;
    QueryData["DISPLAY_COL_NAMES"]  = {};
    QueryData["ORDER_COL_NAMES"] = {};
    QueryData["ORDERVALS"] = {};
    QueryData["LANGS"] = {};
}
void Automata::InitializeQueryStates(QString CommandType){
    QJsonObject QSCommandObject = FL.GetQueryStates(CommandType);
    if( CommandType == "LANG" ){
        LangCommandStatus = true;
        InitializeLangQueryStates(QSCommandObject);
    }
    else if( CommandType == "ENV" ){
        LangCommandStatus = true;
        InitializeEnvQueryStates(QSCommandObject);
    }
    else if( CommandType == "DATASTORE" ){
        DatastoreCommandStatus = true;
        InitializeDatastoreQueryStates(QSCommandObject);
    }
    else if( CommandType == "TABLE" ){
        TableCommandStatus = true;
        InitializeTableQueryStates(QSCommandObject);
    }
    else if( CommandType == "PIECHART" ){
        PiechartCommandStatus = true;
        InitializePiechartQueryStates(QSCommandObject);
    }
    else if( CommandType == "BARGRAPH" ){
        BargraphCommandStatus = true;
        InitializeBargraphQueryStates(QSCommandObject);
    }
    else if( CommandType == "LINEGRAPH" ){
        LinegraphCommandStatus = true;
        InitializeLinegraphQueryStates(QSCommandObject);
    }
}
void Automata::InitializeLangQueryStates(QJsonObject QSCommandObject){
    ChangeLangCmdStates = QSCommandObject["ChangeLangCmdStates"].toString().split(" ") ;
    LangDisplayCmdState = QSCommandObject["LangDisplayCmdState"].toString().split(" ") ;
}
void Automata::InitializeEnvQueryStates(QJsonObject QSCommandObject){
    EnvClearScreenStates = QSCommandObject["EnvClearScreenStates"].toString().split(" ") ;
    EnvClearHistoryState = QSCommandObject["EnvClearHistoryState"].toString().split(" ") ;
    EnvExitStates = QSCommandObject["EnvExitStates"].toString().split(" ") ;
    EnvMeanStates = QSCommandObject["EnvMeanStates"].toString().split(" ");
    EnvModeStates = QSCommandObject["EnvModeStates"].toString().split(" ");
    EnvMedianStates = QSCommandObject["EnvMedianStates"].toString().split(" ");
    EnvSumStates = QSCommandObject["EnvSumStates"].toString().split(" ");
    EnvMinStates = QSCommandObject["EnvMinStates"].toString().split(" ");
    EnvMaxStates = QSCommandObject["EnvMaxStates"].toString().split(" ");
    EnvAvgStates = QSCommandObject["EnvAvgStates"].toString().split(" ");
    EnvSDStates = QSCommandObject["EnvSDStates"].toString().split(" ");
    EnvVarienceStates = QSCommandObject["EnvVarienceStates"].toString().split(" ");
    EnvFrequencyCommonStates = QSCommandObject["EnvFrequencyCommonStates"].toString().split(" ");
    EnvFrequencyStates = QSCommandObject["EnvFrequencyStates"].toString().split(" ") ;
    EnvFrequencyTableStates = QSCommandObject["EnvFrequencyTableStates"].toString().split(" ") ;
    EnvFrequencyTablesStates = QSCommandObject["EnvFrequencyTablesStates"].toString().split(" ") ;
}
void Automata::InitializeDatastoreQueryStates(QJsonObject QSCommandObject){
    DatastoreListStates = QSCommandObject["DatastoreListStates"].toString().split(" ") ;
    DatastoreCreateStates = QSCommandObject["DatastoreCreateStates"].toString().split(" ") ;
    DatastoreDeleteStates = QSCommandObject["DatastoreDeleteStates"].toString().split(" ") ;
    DatastoreForceDeleteStates = QSCommandObject["DatastoreForceDeleteStates"].toString().split(" ") ;
    DatastoreDeleteCommonStates = QSCommandObject["DatastoreDeleteCommonStates"].toString().split(" ");
    DatastoreClearCommonStates = QSCommandObject["DatastoreClearCommonStates"].toString().split(" ") ;
    DatastoreClearAllStates = QSCommandObject["DatastoreClearAllStates"].toString().split(" ") ;
    DatastoreClearSelectedStates = QSCommandObject["DatastoreClearSelectedStates"].toString().split(" ") ;
    DatastoreRenameStates = QSCommandObject["DatastoreRenameStates"].toString().split(" ") ;
    DatastoreUseStates = QSCommandObject["DatastoreUseStates"].toString().split(" ") ;
    DatastoreUseCommonStates = QSCommandObject["DatastoreUseCommonStates"].toString().split(" ") ;
    DatastoreUseDisplayStates = QSCommandObject["DatastoreUseDisplayStates"].toString().split(" ") ;
    DatastoreUseDefaultStates = QSCommandObject["DatastoreUseDefaultStates"].toString().split(" ") ;
    DatastoreDisplayCommonStates = QSCommandObject["DatastoreDisplayCommonStates"].toString().split(" ") ;
    DatastoreDisplayAllStates = QSCommandObject["DatastoreDisplayAllStates"].toString().split(" ") ;
    DatastoreDisplayTablesStates = QSCommandObject["DatastoreDisplayTablesStates"].toString().split(" ") ;
    DatastoreDisplayPiechartsStates = QSCommandObject["DatastoreDisplayPiechartsStates"].toString().split(" ") ;
    DatastoreDisplayBargraphsStates = QSCommandObject["DatastoreDisplayBargraphsStates"].toString().split(" ") ;
    DatastoreDisplayLinegraphsStates = QSCommandObject["DatastoreDisplayLinegraphsStates"].toString().split(" ") ;
    DatastoreCountCommonStates = QSCommandObject["DatastoreCountCommonStates"].toString().split(" ") ;
    DatastoreUseCountAllStates = QSCommandObject["DatastoreUseCountAllStates"].toString().split(" ") ;
    DatastoreUseCountTablesStates = QSCommandObject["DatastoreUseCountTablesStates"].toString().split(" ") ;
    DatastoreUseCountPiechartsStates = QSCommandObject["DatastoreUseCountPiechartsStates"].toString().split(" ") ;
    DatastoreUseCountLinegraphsStates = QSCommandObject["DatastoreUseCountLinegraphsStates"].toString().split(" ") ;
    DatastoreUseCountBargraphsStates = QSCommandObject["DatastoreUseCountBargraphsStates"].toString().split(" ") ;
    DatastoreCountAllStates = QSCommandObject["DatastoreCountAllStates"].toString().split(" ") ;
    DatastoreNameCountCommonStates  = QSCommandObject["DatastoreNameCountCommonStates"].toString().split(" ") ;
    DatastoreCountTablesStates  = QSCommandObject["DatastoreCountTablesStates"].toString().split(" ") ;
    DatastoreCountPiechartsStates  = QSCommandObject["DatastoreCountPiechartsStates"].toString().split(" ") ;
    DatastoreCountLinegraphsStates = QSCommandObject["DatastoreCountLinegraphsStates"].toString().split(" ") ;
    DatastoreCountBargraphsStates = QSCommandObject["DatastoreCountBargraphsStates"].toString().split(" ") ;
    DatastoreUseDisplayAllStates = QSCommandObject["DatastoreUseDisplayAllStates"].toString().split(" ") ;
    DatastoreUseDisplayTablesStates = QSCommandObject["DatastoreUseDisplayTablesStates"].toString().split(" ") ;
    DatastoreUseDisplayPiechartsStates = QSCommandObject["DatastoreUseDisplayPiechartsStates"].toString().split(" ") ;
    DatastoreUseDisplayBargraphsStates = QSCommandObject["DatastoreUseDisplayBargraphsStates"].toString().split(" ") ;
    DatastoreUseDisplayLinegraphsStates = QSCommandObject["DatastoreUseDisplayLinegraphsStates"].toString().split(" ") ;
    DatastoreNameDisplayCommonStates = QSCommandObject["DatastoreNameDisplayCommonStates"].toString().split(" ") ;
}
void Automata::InitializeTableQueryStates(QJsonObject QSCommandObject){
    TableCreateStates = QSCommandObject["TableCreateStates"].toString().split(" ") ;
    TableInsertStates = QSCommandObject["TableInsertStates"].toString().split(" ") ;
    TableChangeStates = QSCommandObject["TableChangeStates"].toString().split(" ") ;
    TableRenameStates = QSCommandObject["TableRenameStates"].toString().split(" ") ;
    TableRenameColStates = QSCommandObject["TableRenameColStates"].toString().split(" ") ;
    TableRenameCommonStates = QSCommandObject["TableRenameCommonStates"].toString().split(" ") ;
    TableAddStates = QSCommandObject["TableAddStates"].toString().split(" ") ;
    TableClearCommonStates = QSCommandObject["TableClearCommonStates"].toString().split(" ") ;
    TableClearTableStates = QSCommandObject["TableClearTableStates"].toString().split(" ") ;
    TableClearColStates = QSCommandObject["TableClearColStates"].toString().split(" ") ;
    TableDisplayCommonStates = QSCommandObject["TableDisplayCommonStates"].toString().split(" ") ;
    TableDisplayAllStates = QSCommandObject["TableDisplayAllStates"].toString().split(" ") ;
    TableDisplayColsStates = QSCommandObject["TableDisplayColsDscStates"].toString().split(" ") ;
    TableDisplayColsStates = QSCommandObject["TableDisplayColsStates"].toString().split(" ") ;
    TableDisplayStructureStates = QSCommandObject["TableDisplayStructureStates"].toString().split(" ") ;
    TableUpdateStates = QSCommandObject["TableUpdateStates"].toString().split(" ") ;
    TableDeleteCommonStates = QSCommandObject["TableDeleteCommonStates"].toString().split(" ") ;
    TableDeleteStates = QSCommandObject["TableDeleteStates"].toString().split(" ") ;
    TableDeleteColStates = QSCommandObject["TableDeleteColStates"].toString().split(" ") ;
    TableOrderDisplayCommonStates = QSCommandObject["TableOrderDisplayCommonStates"].toString().split(" ") ;
    TableOrderDisplayStates = QSCommandObject["TableOrderDisplayStates"].toString().split(" ") ;
    TableColsOrderDisplayStates = QSCommandObject["TableColsOrderDisplayStates"].toString().split(" ") ;

    TableCalCommonStates = QSCommandObject["TableCalCommonStates"].toString().split(" ");
    TableCalSumStates = QSCommandObject["TableCalSumStates"].toString().split(" ");
    TableCalCountStates = QSCommandObject["TableCalCountStates"].toString().split(" ");
    TableCalAvgStates = QSCommandObject["TableCalAvgStates"].toString().split(" ");
    TableCalMinStates = QSCommandObject["TableCalMinStates"].toString().split(" ");
    TableCalMaxStates = QSCommandObject["TableCalMaxStates"].toString().split(" ");
    TableCalMeanStates = QSCommandObject["TableCalMeanStates"].toString().split(" ");
    TableCalModeStates = QSCommandObject["TableCalModeStates"].toString().split(" ");
    TableCalMedianStates = QSCommandObject["TableCalMedianStates"].toString().split(" ");
    TableCalFrequencyStates = QSCommandObject["TableCalFrequencyStates"].toString().split(" ");
    TableCalSDStates = QSCommandObject["TableCalSDStates"].toString().split(" ");
    TableCalVarienceStates = QSCommandObject["TableCalVarienceStates"].toString().split(" ");
}
void Automata::InitializePiechartQueryStates(QJsonObject QSCommandObject){
    PieFromTableStates = QSCommandObject["PieFromTableStates"].toString().split(" ") ;
    PieCreateStates = QSCommandObject["PieCreateStates"].toString().split(" ") ;
    PieCreateCommonStates = QSCommandObject["PieCreateCommonStates"].toString().split(" ") ;
    PieDisplayStates = QSCommandObject["PieDisplayStates"].toString().split(" ") ;
    PieDisplayPercentStates = QSCommandObject["PieDisplayPercentStates"].toString().split(" ") ;
    PieDisplayCommonStates = QSCommandObject["PieDisplayCommonStates"].toString().split(" ") ;
    PieDeleteStates = QSCommandObject["PieDeleteStates"].toString().split(" ") ;
    PieRenameStates = QSCommandObject["PieRenameStates"].toString().split(" ") ;
    PieLinkTableStates = QSCommandObject["PieLinkTableStates"].toString().split(" ") ;
    PieRemoveLinkTableStates = QSCommandObject["PieRemoveLinkTableStates"].toString().split(" ") ;
    PieLinkCommonStates = QSCommandObject["PieLinkCommonStates"].toString().split(" ") ;
}
void Automata::InitializeBargraphQueryStates(QJsonObject QSCommandObject){
    BarFromTableStates = QSCommandObject["BarFromTableStates"].toString().split(" ") ;
    BarCreateStates = QSCommandObject["BarCreateStates"].toString().split(" ") ;
    BarCreateCommonStates = QSCommandObject["BarCreateCommonStates"].toString().split(" ") ;
    BarDisplayStates = QSCommandObject["BarDisplayStates"].toString().split(" ") ;
    BarDeleteStates = QSCommandObject["BarDeleteStates"].toString().split(" ") ;
    BarRenameStates = QSCommandObject["BarRenameStates"].toString().split(" ") ;
    BarLinkTableStates = QSCommandObject["BarLinkTableStates"].toString().split(" ") ;
    BarRemoveLinkTableStates = QSCommandObject["BarRemoveLinkTableStates"].toString().split(" ") ;
    BarLinkCommonStates = QSCommandObject["BarLinkCommonStates"].toString().split(" ") ;
}
void Automata::InitializeLinegraphQueryStates(QJsonObject QSCommandObject){
    LineFromTableStates = QSCommandObject["LineFromTableStates"].toString().split(" ") ;
    LineCreateStates = QSCommandObject["LineCreateStates"].toString().split(" ") ;
    LineCreateCommonStates = QSCommandObject["LineCreateCommonStates"].toString().split(" ") ;
    LineDisplayStates = QSCommandObject["LineDisplayStates"].toString().split(" ") ;
    LineDeleteStates = QSCommandObject["LineDeleteStates"].toString().split(" ") ;
    LineRenameStates = QSCommandObject["LineRenameStates"].toString().split(" ") ;
    LineLinkTableStates = QSCommandObject["LineLinkTableStates"].toString().split(" ") ;
    LineRemoveLinkTableStates = QSCommandObject["LineRemoveLinkTableStates"].toString().split(" ") ;
    LineLinkCommonStates = QSCommandObject["LineLinkCommonStates"].toString().split(" ") ;
}

// Environment
void Automata::EnvClearHistoryCmd(int State, StrList Tokens, int index, QVector<QString>* CHV){
    if( EnvClearHistoryState[State] == ";" && Tokens[index] == ";" ) QE.ClearCHV(REPLWIN,CHV);
    else{
        if( Tokens[index] == EnvClearHistoryState[State] ){
            if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_ENV_HISTORY_QUERY",REPLWIN);
            else EnvClearHistoryCmd(State+1,Tokens,index+1,CHV);
        }
        else ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
    }
}
void Automata::EnvClearScreenCmd(int State, StrList Tokens, int index){
    if( EnvClearScreenStates[State] == ";" && Tokens[index] == ";" ) QE.ClearScreen(REPLWIN);
    else{
        if( Tokens[index] == EnvClearScreenStates[State] ){
            if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_ENV_CLEAR_QUERY",REPLWIN);
            else EnvClearScreenCmd(State+1,Tokens,index+1);
        }
        else ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
    }
}
void Automata::EnvExitCmd(int State, StrList Tokens, int index){
    if( EnvExitStates[State] == ";" && Tokens[index] == ";" ) QE.CloseApp();
    else{
        if( Tokens[index] == EnvExitStates[State] ){
            if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_ENV_EXIT_QUERY",REPLWIN);
            else EnvExitCmd(State+1,Tokens,index+1);
        }
        else ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
    }
}

void Automata::EnvMeanCmd(int State, StrList Tokens, int index){
//    ENV MEAN ( NUMERIC , ) ;
    if( EnvMeanStates[State] == ";" && Tokens[index] == ";" ){
        if( index == Tokens.size() - 1 ) QE.EnvCalculateMean(REPLWIN,QueryData);
        else ER.PrintError(RawTokens,index,"INVALID_ENV_QUERY",REPLWIN);
    }
    else if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_ENV_MEAN_QUERY",REPLWIN);
    else{
        if( Tokens[index] == EnvMeanStates[State] ){
            if( EnvMeanStates[State] == "," ) EnvMeanCmd(3,Tokens,index+1);
            else{
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_ENV_MEAN_QUERY",REPLWIN);
                else EnvMeanCmd(State+1,Tokens,index+1);
            }
        }else if( EnvMeanStates[State] == "NUMERIC"  ){
            if( TokenKey_KeyList["DATA"].contains(Tokens[index], Qt::CaseInsensitive) && Tokens[index].startsWith("NUMERIC") ){
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_ENV_MEAN_QUERY",REPLWIN);
                else{
                    QueryData["DATAVALS"] << RawTokens[index];
                    if( Tokens[index+1] == ")" ) EnvMeanCmd(5,Tokens,index+1);
                    else EnvMeanCmd(State+1,Tokens,index+1);
                }
            }else ER.PrintError(RawTokens,index,"EXPECTING_NUMERIC_DATA",REPLWIN);
        }else ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
    }
}
void Automata::EnvModeCmd(int State, StrList Tokens, int index){
//    ENV MODE ( NUMERIC , ) ;
    if( EnvModeStates[State] == ";" && Tokens[index] == ";" ){
        if( index == Tokens.size() - 1 ) QE.EnvCalculateMode(REPLWIN,QueryData);
        else ER.PrintError(RawTokens,index,"INVALID_ENV_QUERY",REPLWIN);
    }
    else if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_ENV_MODE_QUERY",REPLWIN);
    else{
        if( Tokens[index] == EnvModeStates[State] ){
            if( EnvModeStates[State] == "," ) EnvModeCmd(3,Tokens,index+1);
            else{
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_ENV_MODE_QUERY",REPLWIN);
                else EnvModeCmd(State+1,Tokens,index+1);
            }
        }else if( EnvModeStates[State] == "NUMERIC"  ){
            if( TokenKey_KeyList["DATA"].contains(Tokens[index], Qt::CaseInsensitive) && Tokens[index].startsWith("NUMERIC") ){
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_ENV_MODE_QUERY",REPLWIN);
                else{
                    QueryData["DATAVALS"] << RawTokens[index];
                    if( Tokens[index+1] == ")" ) EnvModeCmd(5,Tokens,index+1);
                    else EnvModeCmd(State+1,Tokens,index+1);
                }
            }else ER.PrintError(RawTokens,index,"EXPECTING_NUMERIC_DATA",REPLWIN);
        }else ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
    }
}
void Automata::EnvMedianCmd(int State, StrList Tokens, int index){
//    ENV MEDIAN ( NUMERIC , ) ;
    if( EnvMedianStates[State] == ";" && Tokens[index] == ";" ){
        if( index == Tokens.size() - 1 ) QE.EnvCalculateMedian(REPLWIN,QueryData);
        else ER.PrintError(RawTokens,index,"INVALID_ENV_QUERY",REPLWIN);
    }
    else if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_ENV_MEDIAN_QUERY",REPLWIN);
    else{
        if( Tokens[index] == EnvMedianStates[State] ){
            if( EnvMedianStates[State] == "," ) EnvMedianCmd(3,Tokens,index+1);
            else{
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_ENV_MEDIAN_QUERY",REPLWIN);
                else EnvMedianCmd(State+1,Tokens,index+1);
            }
        }else if( EnvMedianStates[State] == "NUMERIC"  ){
            if( TokenKey_KeyList["DATA"].contains(Tokens[index], Qt::CaseInsensitive) && Tokens[index].startsWith("NUMERIC") ){
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_ENV_MEDIAN_QUERY",REPLWIN);
                else{
                    QueryData["DATAVALS"] << RawTokens[index];
                    if( Tokens[index+1] == ")" ) EnvMedianCmd(5,Tokens,index+1);
                    else EnvMedianCmd(State+1,Tokens,index+1);
                }
            }else ER.PrintError(RawTokens,index,"EXPECTING_NUMERIC_DATA",REPLWIN);
        }else ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
    }
}
void Automata::EnvSumCmd(int State, StrList Tokens, int index){
//    ENV SUM ( NUMERIC , ) ;
    if( EnvSumStates[State] == ";" && Tokens[index] == ";" ){
        if( index == Tokens.size() - 1 ) QE.EnvCalculateSum(REPLWIN,QueryData);
        else ER.PrintError(RawTokens,index,"INVALID_ENV_QUERY",REPLWIN);
    }
    else if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_ENV_SUM_QUERY",REPLWIN);
    else{
        if( Tokens[index] == EnvSumStates[State] ){
            if( EnvSumStates[State] == "," ) EnvSumCmd(3,Tokens,index+1);
            else{
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_ENV_SUM_QUERY",REPLWIN);
                else EnvSumCmd(State+1,Tokens,index+1);
            }
        }else if( EnvSumStates[State] == "NUMERIC"  ){
            if( TokenKey_KeyList["DATA"].contains(Tokens[index], Qt::CaseInsensitive) && Tokens[index].startsWith("NUMERIC") ){
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_ENV_SUM_QUERY",REPLWIN);
                else{
                    QueryData["DATAVALS"] << RawTokens[index];
                    if( Tokens[index+1] == ")" ) EnvSumCmd(5,Tokens,index+1);
                    else EnvSumCmd(State+1,Tokens,index+1);
                }
            }else ER.PrintError(RawTokens,index,"EXPECTING_NUMERIC_DATA",REPLWIN);
        }else ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
    }
}
void Automata::EnvMinCmd(int State, StrList Tokens, int index){
//    ENV MIN ( NUMERIC , ) ;
    if( EnvMinStates[State] == ";" && Tokens[index] == ";" ){
        if( index == Tokens.size() - 1 ) QE.EnvCalculateMin(REPLWIN,QueryData);
        else ER.PrintError(RawTokens,index,"INVALID_ENV_QUERY",REPLWIN);
    }
    else if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_ENV_MIN_QUERY",REPLWIN);
    else{
        if( Tokens[index] == EnvMinStates[State] ){
            if( EnvMinStates[State] == "," ) EnvMinCmd(3,Tokens,index+1);
            else{
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_ENV_MIN_QUERY",REPLWIN);
                else EnvMinCmd(State+1,Tokens,index+1);
            }
        }else if( EnvMinStates[State] == "NUMERIC"  ){
            if( TokenKey_KeyList["DATA"].contains(Tokens[index], Qt::CaseInsensitive) && Tokens[index].startsWith("NUMERIC") ){
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_ENV_MIN_QUERY",REPLWIN);
                else{
                    QueryData["DATAVALS"] << RawTokens[index];
                    if( Tokens[index+1] == ")" ) EnvMinCmd(5,Tokens,index+1);
                    else EnvMinCmd(State+1,Tokens,index+1);
                }
            }else ER.PrintError(RawTokens,index,"EXPECTING_NUMERIC_DATA",REPLWIN);
        }else ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
    }
}
void Automata::EnvMaxCmd(int State, StrList Tokens, int index){
//    ENV MAX ( NUMERIC , ) ;
    if( EnvMaxStates[State] == ";" && Tokens[index] == ";" ){
        if( index == Tokens.size() - 1 ) QE.EnvCalculateMax(REPLWIN,QueryData);
        else ER.PrintError(RawTokens,index,"INVALID_ENV_QUERY",REPLWIN);
    }
    else if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_ENV_MAX_QUERY",REPLWIN);
    else{
        if( Tokens[index] == EnvMaxStates[State] ){
            if( EnvMaxStates[State] == "," ) EnvMaxCmd(3,Tokens,index+1);
            else{
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_ENV_MAX_QUERY",REPLWIN);
                else EnvMaxCmd(State+1,Tokens,index+1);
            }
        }else if( EnvMaxStates[State] == "NUMERIC"  ){
            if( TokenKey_KeyList["DATA"].contains(Tokens[index], Qt::CaseInsensitive) && Tokens[index].startsWith("NUMERIC") ){
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_ENV_MAX_QUERY",REPLWIN);
                else{
                    QueryData["DATAVALS"] << RawTokens[index];
                    if( Tokens[index+1] == ")" ) EnvMaxCmd(5,Tokens,index+1);
                    else EnvMaxCmd(State+1,Tokens,index+1);
                }
            }else ER.PrintError(RawTokens,index,"EXPECTING_NUMERIC_DATA",REPLWIN);
        }else ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
    }
}
void Automata::EnvAvgCmd(int State, StrList Tokens, int index){
//    ENV AVG ( NUMERIC , ) ;
    if( EnvAvgStates[State] == ";" && Tokens[index] == ";" ){
        if( index == Tokens.size() - 1 ) QE.EnvCalculateAvg(REPLWIN,QueryData);
        else ER.PrintError(RawTokens,index,"INVALID_ENV_QUERY",REPLWIN);
    }
    else if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_ENV_AVG_QUERY",REPLWIN);
    else{
        if( Tokens[index] == EnvAvgStates[State] ){
            if( EnvAvgStates[State] == "," ) EnvAvgCmd(3,Tokens,index+1);
            else{
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_ENV_AVG_QUERY",REPLWIN);
                else EnvAvgCmd(State+1,Tokens,index+1);
            }
        }else if( EnvAvgStates[State] == "NUMERIC"  ){
            if( TokenKey_KeyList["DATA"].contains(Tokens[index], Qt::CaseInsensitive) && Tokens[index].startsWith("NUMERIC") ){
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_ENV_AVG_QUERY",REPLWIN);
                else{
                    QueryData["DATAVALS"] << RawTokens[index];
                    if( Tokens[index+1] == ")" ) EnvAvgCmd(5,Tokens,index+1);
                    else EnvAvgCmd(State+1,Tokens,index+1);
                }
            }else ER.PrintError(RawTokens,index,"EXPECTING_NUMERIC_DATA",REPLWIN);
        }else ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
    }
}
void Automata::EnvSDCmd(int State, StrList Tokens, int index){
//    ENV SD ( NUMERIC , ) ;
    if( EnvSDStates[State] == ";" && Tokens[index] == ";" ){
        if( index == Tokens.size() - 1 ) QE.EnvCalculateSD(REPLWIN,QueryData);
        else ER.PrintError(RawTokens,index,"INVALID_ENV_QUERY",REPLWIN);
    }
    else if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_ENV_SD_QUERY",REPLWIN);
    else{
        if( Tokens[index] == EnvSDStates[State] ){
            if( EnvSDStates[State] == "," ) EnvSDCmd(3,Tokens,index+1);
            else{
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_ENV_SD_QUERY",REPLWIN);
                else EnvSDCmd(State+1,Tokens,index+1);
            }
        }else if( EnvSDStates[State] == "NUMERIC"  ){
            if( TokenKey_KeyList["DATA"].contains(Tokens[index], Qt::CaseInsensitive) && Tokens[index].startsWith("NUMERIC") ){
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_ENV_SD_QUERY",REPLWIN);
                else{
                    QueryData["DATAVALS"] << RawTokens[index];
                    if( Tokens[index+1] == ")" ) EnvSDCmd(5,Tokens,index+1);
                    else EnvSDCmd(State+1,Tokens,index+1);
                }
            }else ER.PrintError(RawTokens,index,"EXPECTING_NUMERIC_DATA",REPLWIN);
        }else ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
    }
}
void Automata::EnvVarienceCmd(int State, StrList Tokens, int index){
//    ENV VARIENCE ( NUMERIC , ) ;
    if( EnvVarienceStates[State] == ";" && Tokens[index] == ";" ){
        if( index == Tokens.size() - 1 ) QE.EnvCalculateVarience(REPLWIN,QueryData);
        else ER.PrintError(RawTokens,index,"INVALID_ENV_QUERY",REPLWIN);
    }
    else if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_ENV_VARIENCE_QUERY",REPLWIN);
    else{
        if( Tokens[index] == EnvVarienceStates[State] ){
            if( EnvVarienceStates[State] == "," ) EnvVarienceCmd(3,Tokens,index+1);
            else{
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_ENV_VARIENCE_QUERY",REPLWIN);
                else EnvVarienceCmd(State+1,Tokens,index+1);
            }
        }else if( EnvVarienceStates[State] == "NUMERIC"  ){
            if( TokenKey_KeyList["DATA"].contains(Tokens[index], Qt::CaseInsensitive) && Tokens[index].startsWith("NUMERIC") ){
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_ENV_VARIENCE_QUERY",REPLWIN);
                else{
                    QueryData["DATAVALS"] << RawTokens[index];
                    if( Tokens[index+1] == ")" ) EnvVarienceCmd(5,Tokens,index+1);
                    else EnvVarienceCmd(State+1,Tokens,index+1);
                }
            }else ER.PrintError(RawTokens,index,"EXPECTING_NUMERIC_DATA",REPLWIN);
        }else ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
    }
}
void Automata::EnvFrequencyCmd(int State, StrList Tokens, int index){
//    ENV FREQUENCY
    if( index == Tokens.size() - 1 )  ER.PrintError(RawTokens,index,"INVALID_ENV_QUERY",REPLWIN);
    else if( Tokens[index] == EnvFrequencyCommonStates[State] ){
        if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_ENV_FREQUENCY_QUERY",REPLWIN);
        else{
            if( Tokens[index+1] == "(" ) EnvFrequencyDataCmd(State+1,Tokens,index+1);
            else if( TokenKey_KeyList["IDENTIFIERS"].contains( Tokens[index+1], Qt::CaseInsensitive )  ) EnvFrequencyTablesCmd(State+1,Tokens,index+1);
            else  EnvFrequencyCmd(State+1,Tokens,index+1);
        }
    }
    else ER.PrintError(RawTokens,index,"INVALID_ENV_QUERY",REPLWIN);
}
void Automata::EnvFrequencyDataCmd(int State, StrList Tokens, int index){
//    ENV FREQUENCY ( DATA , ) ;
    if( EnvFrequencyStates[State] == ";" && Tokens[index] == ";" ){
        if( index == Tokens.size() - 1 ) QE.EnvCalculateFrequencyData(REPLWIN,QueryData);
        else ER.PrintError(RawTokens,index,"INVALID_ENV_QUERY",REPLWIN);;
    }
    else if(Tokens[index].compare("AS", Qt::CaseInsensitive) == 0 ) EnvFrequencyTableCmd(State+1,Tokens,index+1);
    else if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_ENV_FREQUENCY_QUERY",REPLWIN);
    else{
        if( Tokens[index] == EnvFrequencyStates[State] ){
            if( EnvFrequencyStates[State] == "," ){
                EnvFrequencyDataCmd(3,Tokens,index+1);
            }else{
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_ENV_FREQUENCY_QUERY",REPLWIN);
                else EnvFrequencyDataCmd(State+1,Tokens,index+1);
            }
        }
        else if( EnvFrequencyStates[State] == "DATA"  ){
            if( TokenKey_KeyList["DATA"].contains(Tokens[index], Qt::CaseInsensitive)  ){
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_ENV_FREQUENCY_QUERY",REPLWIN);
                else{
                    QueryData["DATAVALS"] << RawTokens[index];
                    if( Tokens[index+1] == ")" ) EnvFrequencyDataCmd(5,Tokens,index+1);
                    else EnvFrequencyDataCmd(State+1,Tokens,index+1);
                }
            }else ER.PrintError(RawTokens,index,"EXPECTING_DATA",REPLWIN);
        }
        else ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
    }
}
void Automata::EnvFrequencyTableCmd(int State, StrList Tokens, int index){/**/
//    ENV FREQUENCY ( DATA , ) AS TABLE NAME ;
    if( EnvFrequencyTableStates[State] == ";" && Tokens[index] == ";" ){
        if( index == Tokens.size() - 1 ) QE.EnvCalculateFrequencyTable(REPLWIN,QueryData);
        else ER.PrintError(RawTokens,index,"INVALID_ENV_QUERY",REPLWIN);;
    }
    else if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_ENV_FREQUENCY_QUERY",REPLWIN);
    else{
        if( Tokens[index] == EnvFrequencyTableStates[State] ){
            if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_ENV_FREQUENCY_QUERY",REPLWIN);
            else EnvFrequencyTableCmd(State+1,Tokens,index+1);
        }
        else if( EnvFrequencyTableStates[State] == "NAME"  ){
            QueryData["TABLE_NAMES"] << RawTokens[index];
            if( TokenKey_KeyList["IDENTIFIERS"].contains(Tokens[index], Qt::CaseInsensitive) ) EnvFrequencyTableCmd(State+1,Tokens,index+1);
            else ER.PrintError(RawTokens,index,"INVALID_TABLE_NAME",REPLWIN);
        }
        else ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
    }
}
void Automata::EnvFrequencyTablesCmd(int State, StrList Tokens, int index){
//    ENV FREQUENCY TNAME ( COL , ) AS TABLE ( NAME , ) ;
    if( EnvFrequencyTablesStates[State] == ";" && Tokens[index] == ";" ){
        if( index == Tokens.size() - 1 ) QE.EnvCalculateFrequencyTables(REPLWIN,QueryData);
        else ER.PrintError(RawTokens,index,"INVALID_ENV_QUERY",REPLWIN);
    }
    else if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_ENV_FREQUENCY_QUERY",REPLWIN);
    else{
        if( Tokens[index] == EnvFrequencyTablesStates[State] ){
            if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_ENV_FREQUENCY_QUERY",REPLWIN);
            else{
                if( EnvFrequencyTablesStates[State] == "," && EnvFrequencyTablesStates[State-1] == "COL" ) EnvFrequencyTablesCmd(4,Tokens,index+1);
                else if( EnvFrequencyTablesStates[State] == "," && EnvFrequencyTablesStates[State-1] == "NAME" ) EnvFrequencyTablesCmd(10,Tokens,index+1);
                else EnvFrequencyTablesCmd(State+1,Tokens,index+1);
            }
        }else if( EnvFrequencyTablesStates[State] == "COL"  ){
            if( TokenKey_KeyList["IDENTIFIERS"].contains(Tokens[index], Qt::CaseInsensitive) ){
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_ENV_FREQUENCY_QUERY",REPLWIN);
                else{
                    QueryData["COL_NAMES"] << RawTokens[index];
                    if( Tokens[index+1] == ")" ) EnvFrequencyTablesCmd(6,Tokens,index+1);
                    else EnvFrequencyTablesCmd(State+1,Tokens,index+1);
                }
            }
            else ER.PrintError(RawTokens,index,"INVALID_COL_NAME",REPLWIN);
        }else if( EnvFrequencyTablesStates[State] == "TNAME"  ){
            if( TokenKey_KeyList["IDENTIFIERS"].contains(Tokens[index], Qt::CaseInsensitive) ){
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_ENV_FREQUENCY_QUERY",REPLWIN);
                else{
                    QueryData["TABLENAME"] << RawTokens[index];
                    EnvFrequencyTablesCmd(State+1,Tokens,index+1);
                }
            }
            else ER.PrintError(RawTokens,index,"INVALID_TABLE_NAME",REPLWIN);
        }
        else if( EnvFrequencyTablesStates[State] == "NAME"  ){
            if( TokenKey_KeyList["IDENTIFIERS"].contains(Tokens[index], Qt::CaseInsensitive) ){
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_ENV_FREQUENCY_QUERY",REPLWIN);
                else{
                    QueryData["TABLE_NAMES"] << RawTokens[index];
                    if( Tokens[index+1] == ")" ) EnvFrequencyTablesCmd(12,Tokens,index+1);
                    else EnvFrequencyTablesCmd(State+1,Tokens,index+1);
                }
            }
            else ER.PrintError(RawTokens,index,"INVALID_TABLE_NAME",REPLWIN);
        }
        else ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
    }
}

// Language
void Automata::ChangeLangCmd(int State, StrList Tokens, int index){
    if( ChangeLangCmdStates[State] == ";" && Tokens[index] == ";" ) QE.ChangeLang(REPLWIN,QueryData);
    else{
        if( Tokens[index] == ChangeLangCmdStates[State] ){
            if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_LANG_QUERY",REPLWIN);
            else ChangeLangCmd(State+1,Tokens,index+1);
        }
        else if( ChangeLangCmdStates[State] == "LANGNAME"){
            if( TokenKey_KeyList["LANGUAGES"].contains( Tokens[index], Qt::CaseInsensitive ) ){
                QueryData["LANGS"] << RawTokens[index];
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_LANG_QUERY",REPLWIN);
                else  ChangeLangCmd(State+1,Tokens,index+1);
            }else{
                ER.PrintError(RawTokens,index,"EXPECTING_LANGUAGE",REPLWIN);
            }
        }else ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
    }
}
void Automata::LangDisplayCmd(int State, StrList Tokens, int index){
    if( LangDisplayCmdState[State] == ";" && Tokens[index] == ";" ) QE.DisplayEnvLang(REPLWIN);
    else{
        if( Tokens[index] == LangDisplayCmdState[State] ){
            if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_LANG_QUERY",REPLWIN);
            else LangDisplayCmd(State+1,Tokens,index+1);
        }
        else ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
    }
}
// Datastore
void Automata::DatastoreListCmd(int State, StrList Tokens, int index){
    if( DatastoreListStates[State] == ";" && Tokens[index] == ";" ){
        if( index == Tokens.size() - 1 ) QE.DisplayDatastoreList(REPLWIN);
        else ER.PrintError(RawTokens,index,"INVALID_DATASTORE_QUERY",REPLWIN);
    }
    else if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_DATASTORE_LIST_QUERY",REPLWIN);
    else{
        if( Tokens[index] == DatastoreListStates[State] ){
            if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_DATASTORE_LIST_QUERY",REPLWIN);
            else DatastoreListCmd(State+1,Tokens,index+1);
        }
        else ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
    }
}
void Automata::DatastoreCreateCmd(int State, StrList Tokens, int index){
    if( DatastoreCreateStates[State] == ";" && Tokens[index] == ";" ){
        if( index == Tokens.size() - 1 ) QE.CreateDatastore(REPLWIN,RawTokens[index-1]);
        else ER.PrintError(RawTokens,index,"INVALID_DATASTORE_QUERY",REPLWIN);
    }
    else if( index == Tokens.size() - 1 )  ER.PrintError(RawTokens,index,"INCOMPLETE_DATASTORE_CREATE_QUERY",REPLWIN);
    else{
        if( Tokens[index] == DatastoreCreateStates[State] ){
            if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_DATASTORE_CREATE_QUERY",REPLWIN);
            else DatastoreCreateCmd(State+1,Tokens,index+1);
        }
        else if( DatastoreCreateStates[State] == "NAME"){
            if( TokenKey_KeyList["IDENTIFIERS"].contains( Tokens[index], Qt::CaseInsensitive ) ){
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"MISSING_SEMICOLON",REPLWIN);
                else DatastoreCreateCmd(State+1,Tokens,index+1);
            }
            else ER.PrintError(RawTokens,index,"INVALID_DATASTORE_NAME",REPLWIN);
        }
        else ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
    }
}
void Automata::DatastoreDeleteCmd(int State, StrList Tokens, int index){
    if( Tokens[index] == DatastoreDeleteCommonStates[State] ){
        if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_DATASTORE_DELETE_QUERY",REPLWIN);
        else {
            if( DatastoreDeleteCommonStates[State] == "DELETE" ){
                if( TokenKey_KeyList["IDENTIFIERS"].contains(Tokens[index+1], Qt::CaseInsensitive) ) DatastoreDeleteNormalCmd(State+1,Tokens,index+1);
                else if( Tokens[index+1] == "FORCE" ) DatastoreDeleteForceCmd(State+1,Tokens,index+1);
                else ER.PrintError(RawTokens,index,"INVALID_DATASTORE_DELETE_QUERY",REPLWIN);
            }
            else DatastoreDeleteCmd(State+1,Tokens,index+1);
        }
    }
    else ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
}
void Automata::DatastoreDeleteForceCmd(int State, StrList Tokens, int index){
    if( DatastoreForceDeleteStates[State] == ";" && Tokens[index] == ";" ){
        if( index == Tokens.size() - 1 ) QE.DeleteForceDatastore(REPLWIN,RawTokens[index-1]);
        else ER.PrintError(RawTokens,index,"INVALID_DATASTORE_QUERY",REPLWIN);
    }
    else if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_DATASTORE_DELETE_QUERY",REPLWIN);
    else{
        if( Tokens[index] == DatastoreForceDeleteStates[State] ){
            if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_DATASTORE_DELETE_QUERY",REPLWIN);
            else DatastoreDeleteForceCmd(State+1,Tokens,index+1);
        }
        else if( DatastoreForceDeleteStates[State] == "NAME"){
            if( TokenKey_KeyList["IDENTIFIERS"].contains( Tokens[index], Qt::CaseInsensitive ) ){
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"MISSING_SEMICOLON",REPLWIN);
                else DatastoreDeleteForceCmd(State+1,Tokens,index+1);
            }
            else ER.PrintError(RawTokens,index,"INVALID_DATASTORE_NAME",REPLWIN);
        }
        else ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
    }
}
void Automata::DatastoreDeleteNormalCmd(int State, StrList Tokens, int index){
    if( DatastoreDeleteStates[State] == ";" && Tokens[index] == ";" ){
        if( index == Tokens.size() - 1 ) QE.DeleteNormalDatastore(REPLWIN,RawTokens[index-1]);
        else ER.PrintError(RawTokens,index,"INVALID_DATASTORE_QUERY",REPLWIN);
    }
    else if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_DATASTORE_DELETE_QUERY",REPLWIN);
    else if( DatastoreDeleteStates[State] == "NAME"){
        if( TokenKey_KeyList["IDENTIFIERS"].contains( Tokens[index], Qt::CaseInsensitive ) ){
            if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"MISSING_SEMICOLON",REPLWIN);
            else DatastoreDeleteNormalCmd(State+1,Tokens,index+1);
        }
        else ER.PrintError(RawTokens,index,"INVALID_DATASTORE_NAME",REPLWIN);
    }
    else ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
}
void Automata::DatastoreClearCmd(int State, StrList Tokens, int index){
    if( Tokens[index] == DatastoreClearCommonStates[State] ){
        if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_DATASTORE_CLEAR_QUERY",REPLWIN);
        else DatastoreClearCmd(State+1,Tokens,index+1);
    }else if( DatastoreClearCommonStates[State] == "NAME"  ){
        if( TokenKey_KeyList["IDENTIFIERS"].contains(Tokens[index], Qt::CaseInsensitive) ){
            if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_DATASTORE_CLEAR_QUERY",REPLWIN);
            else{
                QueryData["DATASTORE_NAMES"] << RawTokens[index] ;
                if( Tokens[index+1] == "(" ) DatastoreClearSelectedCmd(State+1,Tokens,index+1);
                else if( Tokens[index+1] == ";" ) DatastoreClearAllCmd(Tokens,index+1);
                else ER.PrintError(RawTokens,index,"INVALID_DATASTORE_CLEAR_QUERY",REPLWIN);
            }
        }
        else ER.PrintError(RawTokens,index,"INVALID_DATASTORE_NAME",REPLWIN);
    }
    else ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
}
void Automata::DatastoreClearAllCmd( StrList Tokens, int index){
    if( index == Tokens.size() - 1 ) QE.ClearDatastore(REPLWIN,RawTokens[index-1]);
    else ER.PrintError(RawTokens,index,"INVALID_DATASTORE_CLEAR_QUERY",REPLWIN);
}
void Automata::DatastoreClearSelectedCmd(int State, StrList Tokens, int index){
    if( DatastoreClearSelectedStates[State] == ";" && Tokens[index] == ";" ){
        if( index == Tokens.size() - 1 ) QE.ClearSelectedDatastore(REPLWIN,QueryData);
        else ER.PrintError(RawTokens,index,"INVALID_DATASTORE_CLEAR_QUERY",REPLWIN);;
    }
    else if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_DATASTORE_CLEAR_QUERY",REPLWIN);
    else{
        if( Tokens[index] == DatastoreClearSelectedStates[State] ){
            if( DatastoreClearSelectedStates[State] == "," ){
                DatastoreClearSelectedCmd(4,Tokens,index+1);
            }else{
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_DATASTORE_CLEAR_QUERY",REPLWIN);
                else DatastoreClearSelectedCmd(State+1,Tokens,index+1);
            }
        }
        else if( DatastoreClearSelectedStates[State] == "STRUCTURES"  ){
            if( TokenKey_KeyList["IDENTIFIERS"].contains(Tokens[index], Qt::CaseInsensitive) ){
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_DATASTORE_CLEAR_QUERY",REPLWIN);
                else{
                    QueryData["STRUCTURE_NAMES"] << RawTokens[index] ;
                    if( Tokens[index+1] == ")" ) DatastoreClearSelectedCmd(6,Tokens,index+1);
                    else DatastoreClearSelectedCmd(State+1,Tokens,index+1);
                }
            }
            else ER.PrintError(RawTokens,index,"INVALID_STRUCTURE_NAME",REPLWIN);
        }
        else if( DatastoreClearSelectedStates[State] == ")" ) DatastoreClearSelectedCmd(State+1,Tokens,index+1);
        else ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
    }
}
void Automata::DatastoreRenameCmd(int State, StrList Tokens, int index){
    if( DatastoreRenameStates[State] == ";" && Tokens[index] == ";" ){
        if( index == Tokens.size() - 1 ) QE.RenameDatastore(REPLWIN,QueryData);
        else ER.PrintError(RawTokens,index,"INVALID_DATASTORE_QUERY",REPLWIN);
    }
    else if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_DATASTORE_RENAME_QUERY",REPLWIN);
    else{
        if( Tokens[index] == DatastoreRenameStates[State] ){
            if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_DATASTORE_RENAME_QUERY",REPLWIN);
            else DatastoreRenameCmd(State+1,Tokens,index+1);
        }
        else if( DatastoreRenameStates[State] == "NAME"){
            if( TokenKey_KeyList["IDENTIFIERS"].contains( Tokens[index], Qt::CaseInsensitive ) ){
                QueryData["DATASTORE_NAMES"] << RawTokens[index];
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_DATASTORE_RENAME_QUERY",REPLWIN);
                else DatastoreRenameCmd(State+1,Tokens,index+1);
            }
            else ER.PrintError(RawTokens,index,"INVALID_DATASTORE_NAME",REPLWIN);
        }
        else if( DatastoreRenameStates[State] == "NEWNAME"){
            if( TokenKey_KeyList["IDENTIFIERS"].contains( Tokens[index], Qt::CaseInsensitive ) ){
                QueryData["DATASTORE_NAMES"] << RawTokens[index];
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_DATASTORE_RENAME_QUERY",REPLWIN);
                else DatastoreRenameCmd(State+1,Tokens,index+1);
            }
            else ER.PrintError(RawTokens,index,"INVALID_DATASTORE_NAME",REPLWIN);
        }
        else ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
    }
}
void Automata::DatastoreUseCmd(int State, StrList Tokens, int index){
    if( index == Tokens.size() - 1 )  ER.PrintError(RawTokens,index,"INVALID_DATASTORE_QUERY",REPLWIN);
    else if( Tokens[index] == DatastoreUseCommonStates[State] ){
        if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_DATASTORE_DISPLAY_QUERY",REPLWIN);
        else{
            if( Tokens[index+1] == "DISPLAY" ) DatastoreDisplayUseCmd(Tokens,index+1);
            else if( Tokens[index+1] == "DEFAULT" ) DatastoreUseDefaultCmd(Tokens,index+1);
            else if( TokenKey_KeyList["IDENTIFIERS"].contains( Tokens[index+1], Qt::CaseInsensitive )  ) DatastoreUseNameCmd(Tokens,index+1);
            else  DatastoreUseCmd(State+1,Tokens,index+1);
        }
    }
    else ER.PrintError(RawTokens,index,"INVALID_DATASTORE_QUERY",REPLWIN);
}
void Automata::DatastoreUseNameCmd(StrList Tokens, int index){
    QueryData["DATASTORE_NAMES"] << RawTokens[index];
    if( index == Tokens.size() - 1 )  ER.PrintError(RawTokens,index,"INVALID_DATASTORE_QUERY",REPLWIN);
    else{
        if( Tokens[index+1] == ";" ){
            if (index + 1 == Tokens.size() - 1) QE.ChangeCurrentDS(REPLWIN,QueryData);
            else  ER.PrintError(RawTokens,index,"INVALID_DATASTORE_QUERY",REPLWIN);
        }
        else ER.PrintError(RawTokens,index,"INVALID_DATASTORE_QUERY",REPLWIN);
    }
}
void Automata::DatastoreDisplayUseCmd(StrList Tokens, int index){
    if( index == Tokens.size() - 1 )  ER.PrintError(RawTokens,index,"INVALID_DATASTORE_QUERY",REPLWIN);
    else{
        if( Tokens[index+1] == ";" ){
            if (index + 1 == Tokens.size() - 1) QE.DisplayCurrentDS(REPLWIN);
            else  ER.PrintError(RawTokens,index,"INVALID_DATASTORE_QUERY",REPLWIN);
        }
        else ER.PrintError(RawTokens,index,"INVALID_DATASTORE_QUERY",REPLWIN);
    }
}
void Automata::DatastoreUseDefaultCmd(StrList Tokens, int index){
    QueryData["DATASTORE_NAMES"] << FL.DEFAULT_DATASTORE_PATH ;
    if( index == Tokens.size() - 1 )  ER.PrintError(RawTokens,index,"INVALID_DATASTORE_QUERY",REPLWIN);
    else{
        if( Tokens[index+1] == ";" ){
            if (index + 1 == Tokens.size() - 1) QE.ChangeCurrentDS(REPLWIN,QueryData);
            else  ER.PrintError(RawTokens,index,"INVALID_DATASTORE_QUERY",REPLWIN);
        }
        else ER.PrintError(RawTokens,index,"INVALID_DATASTORE_QUERY",REPLWIN);
    }
}
void Automata::DatastoreDisplayCmd(int State, StrList Tokens, int index){
    if( Tokens[index] == DatastoreDisplayCommonStates[State] ){
        if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_DATASTORE_DISPLAY_QUERY",REPLWIN);
        else{
            if( DatastoreDisplayCommonStates[State] == "DISPLAY" ){
                if( Tokens[index+1] == "*" ) DatastoreUseDisplayCmd(Tokens,index+1);
                else if( TokenKey_KeyList["IDENTIFIERS"].contains(Tokens[index+1], Qt::CaseInsensitive) ) DatastoreNameDisplayCmd(State+1,Tokens,index+1);
                else  ER.PrintError(RawTokens,index,"INVALID_DATASTORE_QUERY",REPLWIN);
            }else DatastoreDisplayCmd(State+1,Tokens,index+1);
        }
    }
    else ER.PrintError(RawTokens,index,"INVALID_DATASTORE_QUERY",REPLWIN);
}
void Automata::DatastoreUseDisplayCmd(StrList Tokens, int index){
    QueryData["DATASTORE_NAMES"] << FL.DATASTORE_USE;
    if( index == Tokens.size() - 1 )  ER.PrintError(RawTokens,index,"INCOMPLETE_DATASTORE_DISPLAY_QUERY",REPLWIN);
    else{
        if( Tokens[index+1] == ";" ) QE.DisplayDatstoreAll(REPLWIN,QueryData);
        else if( Tokens[index+1] == "TABLE" ){
            if( index+1 == Tokens.size() - 1 )  ER.PrintError(RawTokens,index,"INCOMPLETE_DATASTORE_DISPLAY_QUERY",REPLWIN);
            else{
                if( Tokens[index+2] == ";" ) QE.DisplayDatstoreTables(REPLWIN,QueryData);
                else ER.PrintError(RawTokens,index,"INCOMPLETE_DATASTORE_DISPLAY_QUERY",REPLWIN);
            }
        }
        else if( Tokens[index+1] == "PIECHART" ){
            if( index+1 == Tokens.size() - 1 )  ER.PrintError(RawTokens,index,"INCOMPLETE_DATASTORE_DISPLAY_QUERY",REPLWIN);
            else{
                if( Tokens[index+2] == ";" ) QE.DisplayDatstorePiecharts(REPLWIN,QueryData);
                else ER.PrintError(RawTokens,index,"INCOMPLETE_DATASTORE_DISPLAY_QUERY",REPLWIN);
            }
        }
        else if( Tokens[index+1] == "LINEGRAPH" ){
            if( index+1 == Tokens.size() - 1 )  ER.PrintError(RawTokens,index,"INCOMPLETE_DATASTORE_DISPLAY_QUERY",REPLWIN);
            else{
                if( Tokens[index+2] == ";" ) QE.DisplayDatstoreLinegraphs(REPLWIN,QueryData);
                else ER.PrintError(RawTokens,index,"INCOMPLETE_DATASTORE_DISPLAY_QUERY",REPLWIN);
            }
        }
        else if( Tokens[index+1] == "BARGRAPH" ){
            if( index+1 == Tokens.size() - 1 )  ER.PrintError(RawTokens,index,"INCOMPLETE_DATASTORE_DISPLAY_QUERY",REPLWIN);
            else{
                if( Tokens[index+2] == ";" ) QE.DisplayDatstoreBargraphs(REPLWIN,QueryData);
                else ER.PrintError(RawTokens,index,"INCOMPLETE_DATASTORE_DISPLAY_QUERY",REPLWIN);
            }
        }
        else  ER.PrintError(RawTokens,index,"INVALID_DATASTORE_QUERY",REPLWIN);
    }
}
void Automata::DatastoreNameDisplayCmd(int State, StrList Tokens, int index){
    if( Tokens[index] == DatastoreNameDisplayCommonStates[State] ){
        if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_DATASTORE_DISPLAY_QUERY",REPLWIN);
        else{
            if( DatastoreNameDisplayCommonStates[State] == "*" ){
                if( Tokens[index+1] == ";" ) DatastoreDisplayAllCmd(Tokens,index+1);
                else if( Tokens[index+1] == "TABLE" ) DatastoreDisplayTablesCmd(Tokens,index+1);
                else if( Tokens[index+1] == "PIECHART" ) DatastoreDisplayPiechartsCmd(Tokens,index+1);
                else if( Tokens[index+1] == "LINEGRPAH" ) DatastoreDisplayLinegraphsCmd(Tokens,index+1);
                else if( Tokens[index+1] == "BARGRAPH" ) DatastoreDisplayBargraphsCmd(Tokens,index+1);
                else  ER.PrintError(RawTokens,index,"INVALID_DATASTORE_QUERY",REPLWIN);
            }else DatastoreNameDisplayCmd(State+1,Tokens,index+1);
        }
    }
    else if( DatastoreNameDisplayCommonStates[State] == "NAME"){
        if( TokenKey_KeyList["IDENTIFIERS"].contains( Tokens[index], Qt::CaseInsensitive ) ){
            QueryData["DATASTORE_NAMES"] << RawTokens[index];
            if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_DATASTORE_DISPLAY_QUERY",REPLWIN);
            else DatastoreNameDisplayCmd(State+1,Tokens,index+1);
        }
        else ER.PrintError(RawTokens,index,"INVALID_DATASTORE_NAME",REPLWIN);
    }
    else ER.PrintError(RawTokens,index,"INVALID_DATASTORE_QUERY",REPLWIN);
}
void Automata::DatastoreDisplayAllCmd(StrList Tokens, int index){
    if( index == Tokens.size() - 1 ) QE.DisplayDatstoreAll(REPLWIN,QueryData);
    else  ER.PrintError(RawTokens,index,"INVALID_DATASTORE_QUERY",REPLWIN);
}
void Automata::DatastoreDisplayTablesCmd(StrList Tokens, int index){
    if( index == Tokens.size() - 1 )  ER.PrintError(RawTokens,index,"INVALID_DATASTORE_QUERY",REPLWIN);
    else{
        if( Tokens[index+1] == ";" ){
            if (index + 1 == Tokens.size() - 1) QE.DisplayDatstoreTables(REPLWIN,QueryData);
            else  ER.PrintError(RawTokens,index,"INVALID_DATASTORE_QUERY",REPLWIN);
        }
    }
}
void Automata::DatastoreDisplayPiechartsCmd(StrList Tokens, int index){
    if( index == Tokens.size() - 1 )  ER.PrintError(RawTokens,index,"INVALID_DATASTORE_QUERY",REPLWIN);
    else{
        if( Tokens[index+1] == ";" ){
            if (index + 1 == Tokens.size() - 1) QE.DisplayDatstorePiecharts(REPLWIN,QueryData);
            else  ER.PrintError(RawTokens,index,"INVALID_DATASTORE_QUERY",REPLWIN);
        }
    }
}
void Automata::DatastoreDisplayLinegraphsCmd(StrList Tokens, int index){
    if( index == Tokens.size() - 1 )  ER.PrintError(RawTokens,index,"INVALID_DATASTORE_QUERY",REPLWIN);
    else{
        if( Tokens[index+1] == ";" ){
            if (index + 1 == Tokens.size() - 1) QE.DisplayDatstoreLinegraphs(REPLWIN,QueryData);
            else  ER.PrintError(RawTokens,index,"INVALID_DATASTORE_QUERY",REPLWIN);
        }
    }
}
void Automata::DatastoreDisplayBargraphsCmd(StrList Tokens, int index){
    if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INVALID_DATASTORE_QUERY",REPLWIN);
    else{
        if( Tokens[index+1] == ";" ){
            if (index + 1 == Tokens.size() - 1) QE.DisplayDatstoreBargraphs(REPLWIN,QueryData);
            else ER.PrintError(RawTokens,index,"INVALID_DATASTORE_QUERY",REPLWIN);
        }
    }
}
void Automata::DatastoreCountCmd(int State, StrList Tokens, int index){
    if( Tokens[index] == DatastoreCountCommonStates[State] ){
        if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_DATASTORE_COUNT_QUERY",REPLWIN);
        else{
            if( DatastoreCountCommonStates[State] == "COUNT" ){
                if( Tokens[index+1] == "*" ) DatastoreUseCountAllCmd(Tokens,index+1);
                else if( Tokens[index+1] == "TABLE" ) DatastoreUseCountTablesCmd(Tokens,index+1);
                else if( Tokens[index+1] == "PIECHART" ) DatastoreUseCountPiechartsCmd(Tokens,index+1);
                else if( Tokens[index+1] == "LINEGRAPH" ) DatastoreUseCountLinegraphsCmd(Tokens,index+1);
                else if( Tokens[index+1] == "BARGRAPH" ) DatastoreUseCountBargraphsCmd(Tokens,index+1);
                else if( TokenKey_KeyList["IDENTIFIERS"].contains(Tokens[index+1], Qt::CaseInsensitive) ) DatastoreNameCountCmd(Tokens,index+1);
                else  ER.PrintError(RawTokens,index,"INVALID_DATASTORE_QUERY",REPLWIN);
            }else DatastoreCountCmd(State+1,Tokens,index+1);
        }
    }
    else ER.PrintError(RawTokens,index,"INVALID_DATASTORE_QUERY",REPLWIN);
}
void Automata::DatastoreUseCountAllCmd( StrList Tokens, int index){
    QueryData["DATASTORE_NAMES"] << FL.DEFAULT_DATASTORE_PATH;
    if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INVALID_DATASTORE_QUERY",REPLWIN);
    else{
        if( Tokens[index+1] == ";" ){
            if (index + 1 == Tokens.size() - 1) QE.DisplayCountStructs(REPLWIN,"CountStructures",QueryData);
            else ER.PrintError(RawTokens,index,"INVALID_DATASTORE_QUERY",REPLWIN);
        }
        else ER.PrintError(RawTokens,index,"INVALID_DATASTORE_QUERY",REPLWIN);
    }
}
void Automata::DatastoreUseCountTablesCmd( StrList Tokens, int index){
    QueryData["DATASTORE_NAMES"] << FL.DEFAULT_DATASTORE_PATH;
    if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INVALID_DATASTORE_QUERY",REPLWIN);
    else{
        if( Tokens[index+1] == ";" ){
            if (index + 1 == Tokens.size() - 1) QE.DisplayCountStructs(REPLWIN,"CountTables",QueryData);
            else ER.PrintError(RawTokens,index,"INVALID_DATASTORE_QUERY",REPLWIN);
        }
        else ER.PrintError(RawTokens,index,"INVALID_DATASTORE_QUERY",REPLWIN);
    }
}
void Automata::DatastoreUseCountPiechartsCmd(StrList Tokens, int index){
    QueryData["DATASTORE_NAMES"] << FL.DEFAULT_DATASTORE_PATH;
    if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INVALID_DATASTORE_QUERY",REPLWIN);
    else{
        if( Tokens[index+1] == ";" ){
            if (index + 1 == Tokens.size() - 1) QE.DisplayCountStructs(REPLWIN,"CountPiecharts",QueryData);
            else ER.PrintError(RawTokens,index,"INVALID_DATASTORE_QUERY",REPLWIN);
        }
        else ER.PrintError(RawTokens,index,"INVALID_DATASTORE_QUERY",REPLWIN);
    }
}
void Automata::DatastoreUseCountLinegraphsCmd(StrList Tokens, int index){
    QueryData["DATASTORE_NAMES"] << FL.DEFAULT_DATASTORE_PATH;
    if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INVALID_DATASTORE_QUERY",REPLWIN);
    else{
        if( Tokens[index+1] == ";" ){
            if (index + 1 == Tokens.size() - 1) QE.DisplayCountStructs(REPLWIN,"CountLinegraphs",QueryData);
            else ER.PrintError(RawTokens,index,"INVALID_DATASTORE_QUERY",REPLWIN);
        }
        else ER.PrintError(RawTokens,index,"INVALID_DATASTORE_QUERY",REPLWIN);
    }
}
void Automata::DatastoreUseCountBargraphsCmd(StrList Tokens, int index){
    QueryData["DATASTORE_NAMES"] << FL.DEFAULT_DATASTORE_PATH;
    if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INVALID_DATASTORE_QUERY",REPLWIN);
    else{
        if( Tokens[index+1] == ";" ){
            if (index + 1 == Tokens.size() - 1) QE.DisplayCountStructs(REPLWIN,"CountBargraphs",QueryData);
            else ER.PrintError(RawTokens,index,"INVALID_DATASTORE_QUERY",REPLWIN);
        }
        else ER.PrintError(RawTokens,index,"INVALID_DATASTORE_QUERY",REPLWIN);
    }
}
void Automata::DatastoreNameCountCmd(StrList Tokens, int index){
    QueryData["DATASTORE_NAMES"] << RawTokens[index];
    if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INVALID_DATASTORE_QUERY",REPLWIN);
    else{
        if( Tokens[index+1] == "*" ) DatastoreCountAllCmd(Tokens,index+1);
        else if( Tokens[index+1] == "TABLE" ) DatastoreCountTablesCmd(Tokens,index+1);
        else if( Tokens[index+1] == "PIECHART" ) DatastoreCountPiechartsCmd(Tokens,index+1);
        else if( Tokens[index+1] == "LINEGRAPH" ) DatastoreCountLinegraphsCmd(Tokens,index+1);
        else if( Tokens[index+1] == "BARGRAPH" ) DatastoreCountBargraphsCmd(Tokens,index+1);
        else ER.PrintError(RawTokens,index,"INVALID_DATASTORE_QUERY",REPLWIN);
    }
}
void Automata::DatastoreCountAllCmd(StrList Tokens, int index){
    if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INVALID_DATASTORE_QUERY",REPLWIN);
    else{
        if( Tokens[index+1] == ";" ){
            if (index + 1 == Tokens.size() - 1)  QE.DisplayCountStructs(REPLWIN,"CountStructures",QueryData);
            else ER.PrintError(RawTokens,index,"INVALID_DATASTORE_QUERY",REPLWIN);
        }
        else ER.PrintError(RawTokens,index,"INVALID_DATASTORE_QUERY",REPLWIN);
    }
}
void Automata::DatastoreCountTablesCmd(StrList Tokens, int index){
    if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INVALID_DATASTORE_QUERY",REPLWIN);
    else{
        if( Tokens[index+1] == ";" ){
            if (index + 1 == Tokens.size() - 1)  QE.DisplayCountStructs(REPLWIN,"CountTables",QueryData);
            else ER.PrintError(RawTokens,index,"INVALID_DATASTORE_QUERY",REPLWIN);
        }
        else ER.PrintError(RawTokens,index,"INVALID_DATASTORE_QUERY",REPLWIN);
    }
}
void Automata::DatastoreCountPiechartsCmd(StrList Tokens, int index){
    if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INVALID_DATASTORE_QUERY",REPLWIN);
    else{
        if( Tokens[index+1] == ";" ){
            if (index + 1 == Tokens.size() - 1)  QE.DisplayCountStructs(REPLWIN,"CountPiecharts",QueryData);
            else ER.PrintError(RawTokens,index,"INVALID_DATASTORE_QUERY",REPLWIN);
        }
        else ER.PrintError(RawTokens,index,"INVALID_DATASTORE_QUERY",REPLWIN);
    }
}
void Automata::DatastoreCountLinegraphsCmd(StrList Tokens, int index){
    if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INVALID_DATASTORE_QUERY",REPLWIN);
    else{
        if( Tokens[index+1] == ";" ){
            if (index + 1 == Tokens.size() - 1)  QE.DisplayCountStructs(REPLWIN,"CountLinegraphs",QueryData);
            else ER.PrintError(RawTokens,index,"INVALID_DATASTORE_QUERY",REPLWIN);
        }
        else ER.PrintError(RawTokens,index,"INVALID_DATASTORE_QUERY",REPLWIN);
    }
}
void Automata::DatastoreCountBargraphsCmd( StrList Tokens, int index){
    if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INVALID_DATASTORE_QUERY",REPLWIN);
    else{
        if( Tokens[index+1] == ";" ){
            if (index + 1 == Tokens.size() - 1)  QE.DisplayCountStructs(REPLWIN,"CountBargraphs",QueryData);
            else ER.PrintError(RawTokens,index,"INVALID_DATASTORE_QUERY",REPLWIN);
        }
        else ER.PrintError(RawTokens,index,"INVALID_DATASTORE_QUERY",REPLWIN);
    }
}

// Table
void Automata::TableCreateCmd(int State, StrList Tokens, int index){
    if( TableCreateStates[State] == ";" && Tokens[index] == ";" ){
        if( index == Tokens.size() - 1 ) QE.CreateTable(REPLWIN,QueryData);
        else ER.PrintError(RawTokens,index,"INVALID_TABLE_QUERY",REPLWIN);
    }
    else if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_TABLE_CREATE_QUERY",REPLWIN);
    else{
        if( Tokens[index] == TableCreateStates[State] ){
            if( TableCreateStates[State] == "," ) TableCreateCmd(4,Tokens,index+1);
            else{
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_TABLE_CREATE_QUERY",REPLWIN);
                else TableCreateCmd(State+1,Tokens,index+1);
            }
        }
        else if( TableCreateStates[State] == "NAME"  ){
            if( TokenKey_KeyList["IDENTIFIERS"].contains(Tokens[index], Qt::CaseInsensitive) ){
                QueryData["TABLE_NAMES"] << RawTokens[index];
                TableCreateCmd(State+1,Tokens,index+1);
            }
            else ER.PrintError(RawTokens,index,"INVALID_TABLE_NAME",REPLWIN);
        }else if( TableCreateStates[State] == "COL"  ){
            if( TokenKey_KeyList["IDENTIFIERS"].contains(Tokens[index], Qt::CaseInsensitive) ){
                QueryData["COL_NAMES"] << RawTokens[index];
                if( Tokens[index+1] == ":" ){
                    if( TokenKey_KeyList["DATATYPES"].contains( Tokens[index+2], Qt::CaseInsensitive ) ){
                        QueryData["DATATYPES"] << RawTokens[index+2];
                        if( Tokens[index+3] == "}" ) TableCreateCmd(8,Tokens,index+3);
                        else TableCreateCmd(7,Tokens,index+3);
                    }
                    else ER.PrintError(RawTokens,index,"EXPECTING_DATATYPE",REPLWIN);
                }
                else if( Tokens[index+1] == "}" ){
                    QueryData["DATATYPES"] << "";
                    TableCreateCmd(8,Tokens,index+1);
                }
                else{
                    QueryData["DATATYPES"] << "";
                    TableCreateCmd(7,Tokens,index+1);
                }
            }
            else ER.PrintError(RawTokens,index,"INVALID_COL_NAME",REPLWIN);
        }
        else if( TableCreateStates[State] == "}" ) TableCreateCmd(State+1,Tokens,index+1);
        else ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
    }
}
void Automata::TableInsertCmd(int State, StrList Tokens, int index){
    if( TableInsertStates[State] == ";" && Tokens[index] == ";" ){
        if( index == Tokens.size() - 1 ) QE.InsertIntoTable(REPLWIN,QueryData);
        else ER.PrintError(RawTokens,index,"INVALID_TABLE_QUERY",REPLWIN);
    }
    else if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_TABLE_INSERT_QUERY",REPLWIN);
    else{
        if( Tokens[index] == TableInsertStates[State] ){
            if( TableInsertStates[State] == "," ) TableInsertCmd(4,Tokens,index+1);
            else{
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_TABLE_INSERT_QUERY",REPLWIN);
                else TableInsertCmd(State+1,Tokens,index+1);
            }
        }
        else if( TableInsertStates[State] == "NAME"  ){
            if( TokenKey_KeyList["IDENTIFIERS"].contains(Tokens[index], Qt::CaseInsensitive) ){
                QueryData["TABLE_NAMES"] << RawTokens[index];
                TableInsertCmd(State+1,Tokens,index+1);
            }
            else ER.PrintError(RawTokens,index,"INVALID_TABLE_NAME",REPLWIN);
        }else if( TableInsertStates[State] == "COL"  ){
            if( TokenKey_KeyList["IDENTIFIERS"].contains(Tokens[index], Qt::CaseInsensitive) ){
                QueryData["COL_NAMES"] << RawTokens[index];
                TableInsertCmd(State+1,Tokens,index+1);
            }
            else ER.PrintError(RawTokens,index,"INVALID_COL_NAME",REPLWIN);
        }
        else if( TableInsertStates[State] == "DATA"  ){
            if( TokenKey_KeyList["DATA"].contains(Tokens[index], Qt::CaseInsensitive) ){
                QueryData["DATA"] << RawTokens[index];
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_TABLE_INSERT_QUERY",REPLWIN);
                else{
                    if( Tokens[index+1] == "}" ) TableInsertCmd(8,Tokens,index+1);
                    else TableInsertCmd(State+1,Tokens,index+1);
                }
            }
            else ER.PrintError(RawTokens,index,"EXPECTING_DATA",REPLWIN);
        }
        else if( TableInsertStates[State] == "}" ) TableInsertCmd(State+1,Tokens,index+1);
        else ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
    }
}
void Automata::TableChangeCmd(int State, StrList Tokens, int index){
   if( TableChangeStates[State] == ";" && Tokens[index] == ";" ){
        if( index == Tokens.size() - 1 ) QE.ChangeTableCol(REPLWIN,QueryData);
        else ER.PrintError(RawTokens,index,"INVALID_TABLE_QUERY",REPLWIN);
    }
    else if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_TABLE_CHANGE_QUERY",REPLWIN);
    else{
        if( Tokens[index] == TableChangeStates[State] ){
            if( TableChangeStates[State] == "," ) TableChangeCmd(4,Tokens,index+1);
            else{
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_TABLE_CHANGE_QUERY",REPLWIN);
                else TableChangeCmd(State+1,Tokens,index+1);
            }
        }
        else if( TableChangeStates[State] == "NAME"  ){
            if( TokenKey_KeyList["IDENTIFIERS"].contains(Tokens[index], Qt::CaseInsensitive) ){
                QueryData["TABLE_NAMES"] << RawTokens[index];
                TableChangeCmd(State+1,Tokens,index+1);
            }
            else ER.PrintError(RawTokens,index,"INVALID_TABLE_NAME",REPLWIN);
        }else if( TableChangeStates[State] == "COL"  ){
            if( TokenKey_KeyList["IDENTIFIERS"].contains(Tokens[index], Qt::CaseInsensitive) ){
                QueryData["COL_NAMES"] << RawTokens[index];
                TableChangeCmd(State+1,Tokens,index+1);
            }
            else ER.PrintError(RawTokens,index,"INVALID_COL_NAME",REPLWIN);
        }else if( TableChangeStates[State] == "DATATYPE"  ){
            if( TokenKey_KeyList["DATATYPES"].contains(Tokens[index], Qt::CaseInsensitive) ){
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_TABLE_CHANGE_QUERY",REPLWIN);
                else{
                    QueryData["DATATYPES"] << RawTokens[index];
                    if( Tokens[index+1] == "}" ) TableChangeCmd(8,Tokens,index+1);
                    else TableChangeCmd(State+1,Tokens,index+1);
                }
            }
            else ER.PrintError(RawTokens,index,"EXPECTING_DATATYPE",REPLWIN);
        }
        else if( TableChangeStates[State] == "}" ) TableChangeCmd(State+1,Tokens,index+1);
        else ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
    }
}
void Automata::TableAddCmd(int State, StrList Tokens, int index){
    if( TableAddStates[State] == ";" && Tokens[index] == ";" ){
        if( index == Tokens.size() - 1 ) QE.AddNewCol(REPLWIN,QueryData);
        else ER.PrintError(RawTokens,index,"INVALID_TABLE_QUERY",REPLWIN);
    }
    else if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_TABLE_ADD_QUERY",REPLWIN);
    else{
        if( Tokens[index] == TableAddStates[State] ){
            if( TableAddStates[State] == "," ) TableAddCmd(4,Tokens,index+1);
            else{
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_TABLE_ADD_QUERY",REPLWIN);
                else TableAddCmd(State+1,Tokens,index+1);
            }
        }
        else if( TableAddStates[State] == "NAME"  ){
            if( TokenKey_KeyList["IDENTIFIERS"].contains(Tokens[index], Qt::CaseInsensitive) ){
                QueryData["TABLE_NAMES"] << RawTokens[index];
                TableAddCmd(State+1,Tokens,index+1);
            }
            else ER.PrintError(RawTokens,index,"INVALID_TABLE_NAME",REPLWIN);
        }else if( TableAddStates[State] == "COL"  ){
            if( TokenKey_KeyList["IDENTIFIERS"].contains(Tokens[index], Qt::CaseInsensitive) ){
                QueryData["COL_NAMES"] << RawTokens[index];
                if( Tokens[index+1] == ":" ){
                    if( TokenKey_KeyList["DATATYPES"].contains( Tokens[index+2], Qt::CaseInsensitive ) ){
                        QueryData["DATATYPES"] <<RawTokens[index];
                        if( Tokens[index+3] == "}" ) TableAddCmd(8,Tokens,index+3);
                        else TableAddCmd(7,Tokens,index+3);
                    }else ER.PrintError(RawTokens,index,"EXPECTING_DATATYPE",REPLWIN);
                }
                else if( Tokens[index+1] == "}" ){
                    QueryData["DATATYPES"] << "";
                    TableAddCmd(8,Tokens,index+1);
                }
                else{
                    QueryData["DATATYPES"] << "";
                    TableAddCmd(7,Tokens,index+1);
                }
            }else ER.PrintError(RawTokens,index,"INVALID_COL_NAME",REPLWIN);
        }else if( TableAddStates[State] == "}" ) TableAddCmd(State+1,Tokens,index+1);
        else ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
    }
}
void Automata::TableRenameCmd(int State, StrList Tokens, int index){
    if( Tokens[index] == TableRenameCommonStates[State] ){
        if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_TABLE_RENAME_QUERY",REPLWIN);
        else TableRenameCmd(State+1,Tokens,index+1);
    }else if( TableRenameCommonStates[State] == "NAME"  ){
        if( TokenKey_KeyList["IDENTIFIERS"].contains(Tokens[index], Qt::CaseInsensitive) ){
            QueryData["TABLE_NAMES"] << RawTokens[index];
            if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_TABLE_RENAME_QUERY",REPLWIN);
            else{
                if( Tokens[index+1] == "TO" ) TableRenameTableCmd(State+1,Tokens,index+1);
                else if( Tokens[index+1] == "{" ) TableRenameColsCmd(State+1,Tokens,index+1);
                else ER.PrintError(RawTokens,index,"INVALID_TABLE_QUERY",REPLWIN);
            }
        }else ER.PrintError(RawTokens,index,"INVALID_TABLE_NAME",REPLWIN);
    }
    else ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
}
void Automata::TableRenameTableCmd(int State, StrList Tokens, int index){
    if( TableRenameStates[State] == ";" && Tokens[index] == ";" ){
        if( index == Tokens.size() - 1 ) QE.ChangeTableName(REPLWIN,QueryData);
        else ER.PrintError(RawTokens,index,"INVALID_TABLE_QUERY",REPLWIN);
    }
    else if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_TABLE_RENAME_QUERY",REPLWIN);
    else{
        if( Tokens[index] == TableRenameStates[State] ){
            if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_TABLE_RENAME_QUERY",REPLWIN);
            else TableRenameTableCmd(State+1,Tokens,index+1);
        }
        else if( TableRenameStates[State] == "NEWNAME"  ){
            if( TokenKey_KeyList["IDENTIFIERS"].contains(Tokens[index], Qt::CaseInsensitive) ){
                QueryData["TABLE_NAMES"] << RawTokens[index];
                TableRenameTableCmd(State+1,Tokens,index+1);
            }
            else ER.PrintError(RawTokens,index,"INVALID_TABLE_NAME",REPLWIN);
        }else ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
    }
}
void Automata::TableRenameColsCmd(int State, StrList Tokens, int index){
    if( TableRenameColStates[State] == ";" && Tokens[index] == ";" ){
        if( index == Tokens.size() - 1 ) QE.ChangeTableColName(REPLWIN,QueryData);
        else ER.PrintError(RawTokens,index,"INVALID_TABLE_QUERY",REPLWIN);
    }
    else if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_TABLE_RENAME_QUERY",REPLWIN);
    else{
        if( Tokens[index] == TableRenameColStates[State] ){
            if( TableRenameColStates[State] == "," ) TableRenameColsCmd(4,Tokens,index+1);
            else{
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_TABLE_RENAME_QUERY",REPLWIN);
                else TableRenameColsCmd(State+1,Tokens,index+1);
            }
        }
        else if( TableRenameColStates[State] == "COL"  ){
            if( TokenKey_KeyList["IDENTIFIERS"].contains(Tokens[index], Qt::CaseInsensitive) ){
                QueryData["COL_NAMES"] << RawTokens[index];
                TableRenameColsCmd(State+1,Tokens,index+1);
            }
            else ER.PrintError(RawTokens,index,"INVALID_COL_NAME",REPLWIN);

        }else if( TableRenameColStates[State] == "NEWCOL"  ){
            if( TokenKey_KeyList["IDENTIFIERS"].contains(Tokens[index], Qt::CaseInsensitive) ){
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_TABLE_RENAME_QUERY",REPLWIN);
                else{
                    QueryData["NEWCOL_NAMES"] << RawTokens[index];
                    if( Tokens[index+1] == "}" ) TableRenameColsCmd(8,Tokens,index+1);
                    else TableRenameColsCmd(State+1,Tokens,index+1);
                }
            }else ER.PrintError(RawTokens,index,"INVALID_COL_NAME",REPLWIN);

        }else if( TableRenameColStates[State] == "}" ) TableRenameColsCmd(State+1,Tokens,index+1);
        else ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
    }
}
void Automata::TableClearCmd(int State, StrList Tokens, int index){
    if( Tokens[index] == TableClearCommonStates[State] ){
        if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_TABLE_CLEAR_QUERY",REPLWIN);
        else TableClearCmd(State+1,Tokens,index+1);
    }else if( TableClearCommonStates[State] == "NAME"  ){
        if( TokenKey_KeyList["IDENTIFIERS"].contains(Tokens[index], Qt::CaseInsensitive) ){
            if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INVALID_TABLE_QUERY",REPLWIN);
            else{
                QueryData["TABLE_NAMES"] << RawTokens[index];
                if( Tokens[index+1] == "(" ) TableClearColsCmd(State+1,Tokens,index+1);
                else if( Tokens[index+1] == ";" ) TableClearTableCmd(Tokens,index+1);
                else ER.PrintError(RawTokens,index,"INVALID_TABLE_QUERY",REPLWIN);
            }
        }else ER.PrintError(RawTokens,index,"INVALID_TABLE_NAME",REPLWIN);
    }
    else ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
}
void Automata::TableClearTableCmd(StrList Tokens, int index){
    if( index == Tokens.size() - 1 ) QE.ClearTable(REPLWIN,QueryData);
    else ER.PrintError(RawTokens,index,"INVALID_TABLE_QUERY",REPLWIN);
}
void Automata::TableClearColsCmd(int State, StrList Tokens, int index){
    if( TableClearColStates[State] == ";" && Tokens[index] == ";" ){
        if( index == Tokens.size() - 1 ) QE.ClearTableCols(REPLWIN,QueryData);
        else ER.PrintError(RawTokens,index,"INVALID_TABLE_QUERY",REPLWIN);
    }
    else if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_TABLE_CLEAR_QUERY",REPLWIN);
    else{
        if( Tokens[index] == TableClearColStates[State] ){
            if( TableClearColStates[State] == "," ) TableClearColsCmd(4,Tokens,index+1);
            else{
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_TABLE_CLEAR_QUERY",REPLWIN);
                else TableClearColsCmd(State+1,Tokens,index+1);
            }
        }
        else if( TableClearColStates[State] == "COL"  ){
            if( TokenKey_KeyList["IDENTIFIERS"].contains(Tokens[index], Qt::CaseInsensitive) ){
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_TABLE_CLEAR_QUERY",REPLWIN);
                else{
                    QueryData["COL_NAMES"] << RawTokens[index];
                    if( Tokens[index+1] == ")" ) TableClearColsCmd(6,Tokens,index+1);
                    else TableClearColsCmd(State+1,Tokens,index+1);
                }
            }else ER.PrintError(RawTokens,index,"INVALID_COL_NAME",REPLWIN);

        }
        else if( TableClearColStates[State] == ")" ) TableClearColsCmd(State+1,Tokens,index+1);
        else ER.PrintError(RawTokens,index,"INVALID_TABLE_QUERY",REPLWIN);
    }
}
void Automata::TableDisplayCmd(int State, StrList Tokens, int index){
    if( Tokens[index] == TableDisplayCommonStates[State] ){
        if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_TABLE_DISPLAY_QUERY",REPLWIN);
        else TableDisplayCmd(State+1,Tokens,index+1);
    }else if( TableDisplayCommonStates[State] == "NAME"  ){
        if( TokenKey_KeyList["IDENTIFIERS"].contains(Tokens[index], Qt::CaseInsensitive) ){
            QueryData["TABLE_NAMES"] << RawTokens[index];
            if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_TABLE_DISPLAY_QUERY",REPLWIN);
            else{
                if( Tokens[index+1] == "(" ) TableDisplayColsCmd(State+1,Tokens,index+1);
                else if( Tokens[index+1] == ";" ) TableDisplayAllCmd(Tokens,index+1);
                else if( Tokens[index+1] == "~" ) TableDisplayStructureCmd(Tokens,index+1);
                else ER.PrintError(RawTokens,index,"INVALID_TABLE_QUERY",REPLWIN);
            }
        }else ER.PrintError(RawTokens,index,"INVALID_TABLE_NAME",REPLWIN);
    }
    else ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
}
void Automata::TableDisplayAllCmd( StrList Tokens, int index){
    if( index == Tokens.size() - 1 ) QE.DisplayTable(REPLWIN,QueryData);
    else ER.PrintError(RawTokens,index,"INVALID_TABLE_QUERY",REPLWIN);
}
void Automata::TableDisplayColsCmd(int State, StrList Tokens, int index){
    if( TableDisplayColsStates[State] == ";" && Tokens[index] == ";" ){
        if( index == Tokens.size() - 1 ) QE.DisplayTableCols(REPLWIN,QueryData);
        else ER.PrintError(RawTokens,index,"INVALID_TABLE_QUERY",REPLWIN);
    }
    else if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_TABLE_DISPLAY_QUERY",REPLWIN);
    else{
        if( Tokens[index] == TableDisplayColsStates[State] ){
            if( TableDisplayColsStates[State] == "," ){
                TableDisplayColsCmd(4,Tokens,index+1);
            }else{
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_TABLE_DISPLAY_QUERY",REPLWIN);
                else TableDisplayColsCmd(State+1,Tokens,index+1);
            }
        }
        else if( TableDisplayColsStates[State] == "COL"  ){
            if( TokenKey_KeyList["IDENTIFIERS"].contains(Tokens[index], Qt::CaseInsensitive) ){
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_TABLE_DISPLAY_QUERY",REPLWIN);
                else{
                    QueryData["COL_NAMES"] << RawTokens[index];
                    if( Tokens[index+1] == ")" ) TableDisplayColsCmd(6,Tokens,index+1);
                    else TableDisplayColsCmd(State+1,Tokens,index+1);
                }
            }else ER.PrintError(RawTokens,index,"INVALID_COL_NAME",REPLWIN);
        }else if( TableDisplayColsStates[State] == ")" ) TableDisplayColsCmd(State+1,Tokens,index+1);
        else ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
    }
}
void Automata::TableDisplayStructureCmd( StrList Tokens, int index){
    if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INVALID_TABLE_QUERY",REPLWIN);
    else{
        if( Tokens[index+1] == ";" ){
            if (index + 1 == Tokens.size() - 1) QE.DisplayTableMetaData(REPLWIN,QueryData);
            else ER.PrintError(RawTokens,index,"INVALID_TABLE_QUERY",REPLWIN);
        }
        else ER.PrintError(RawTokens,index,"INVALID_TABLE_QUERY",REPLWIN);
    }
}
void Automata::TableUpdateCmd(int State, StrList Tokens, int index){
//    "TABLE" , "UPDATE" , "NAME" , "{" , "COL" , "=" , "DATA" , "," , "}" , ";"
    if( TableUpdateStates[State] == ";" && Tokens[index] == ";" ){
        if( index == Tokens.size() - 1 ) qWarning() << "Good";
        else ER.PrintError(RawTokens,index,"INVALID_TABLE_QUERY",REPLWIN);
    }
    else if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_TABLE_UPDATE_QUERY",REPLWIN);
    else{
        if( Tokens[index] == TableUpdateStates[State] ){
            if( TableUpdateStates[State] == "," ) TableUpdateCmd(4,Tokens,index+1);
            else{
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_TABLE_UPDATE_QUERY",REPLWIN);
                else TableUpdateCmd(State+1,Tokens,index+1);
            }
        }
        else if( TableUpdateStates[State] == "NAME"  ){
            if( TokenKey_KeyList["IDENTIFIERS"].contains(Tokens[index], Qt::CaseInsensitive) ) TableUpdateCmd(State+1,Tokens,index+1);
            else ER.PrintError(RawTokens,index,"INVALID_TABLE_NAME",REPLWIN);
        }else if( TableUpdateStates[State] == "COL"  ){
            if( TokenKey_KeyList["IDENTIFIERS"].contains(Tokens[index], Qt::CaseInsensitive) ) TableUpdateCmd(State+1,Tokens,index+1);
            else ER.PrintError(RawTokens,index,"INVALID_COL_NAME",REPLWIN);
        }else if( TableUpdateStates[State] == "DATA"  ){
            if( TokenKey_KeyList["DATA"].contains(Tokens[index], Qt::CaseInsensitive) ){
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_TABLE_UPDATE_QUERY",REPLWIN);
                else{
                    if( Tokens[index+1] == "}" ) TableUpdateCmd(8,Tokens,index+1);
                    else TableUpdateCmd(State+1,Tokens,index+1);
                }
            }else ER.PrintError(RawTokens,index,"EXPECTING_DATA",REPLWIN);

        }else if( TableUpdateStates[State] == "}" ) TableUpdateCmd(State+1,Tokens,index+1);
        else ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
    }
}
void Automata::TableDeleteCmd(int State, StrList Tokens, int index){
    if( Tokens[index] == TableDeleteCommonStates[State] ){
        if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_TABLE_DELETE_QUERY",REPLWIN);
        else TableDeleteCmd(State+1,Tokens,index+1);
    }else if( TableDeleteCommonStates[State] == "NAME"  ){
        if( TokenKey_KeyList["IDENTIFIERS"].contains(Tokens[index], Qt::CaseInsensitive) ){
            if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_TABLE_DELETE_QUERY",REPLWIN);
            else{
                QueryData["TABLE_NAMES"] << RawTokens[index];
                if( Tokens[index+1] == "(" ) TableDeleteColsCmd(State+1,Tokens,index+1);
                else if( Tokens[index+1] == ";" ) TableDeleteTableCmd(Tokens,index+1);
                else ER.PrintError(RawTokens,index,"INVALID_TABLE_QUERY",REPLWIN);
            }
        }else ER.PrintError(RawTokens,index,"INVALID_TABLE_NAME",REPLWIN);
    }
    else ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);

}
void Automata::TableDeleteTableCmd(StrList Tokens, int index){
    if( index == Tokens.size() - 1 ) QE.DeleteTable(REPLWIN,QueryData);
    else ER.PrintError(RawTokens,index,"INVALID_TABLE_QUERY",REPLWIN);
}
void Automata::TableDeleteColsCmd(int State, StrList Tokens, int index){
    if( TableDeleteColStates[State] == ";" && Tokens[index] == ";" ){
        if( index == Tokens.size() - 1 ) QE.DeleteTableCols(REPLWIN,QueryData);
        else ER.PrintError(RawTokens,index,"INVALID_TABLE_QUERY",REPLWIN);
    }
    else if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_TABLE_DELETE_QUERY",REPLWIN);
    else{
        if( Tokens[index] == TableDeleteColStates[State] ){
            if( TableDeleteColStates[State] == "," ){
                TableDeleteColsCmd(4,Tokens,index+1);
            }else{
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_TABLE_DELETE_QUERY",REPLWIN);
                else TableDeleteColsCmd(State+1,Tokens,index+1);
            }
        }
        else if( TableDeleteColStates[State] == "COL"  ){
            if( TokenKey_KeyList["IDENTIFIERS"].contains(Tokens[index], Qt::CaseInsensitive) ){
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_TABLE_DELETE_QUERY",REPLWIN);
                else{
                    QueryData["COL_NAMES"] << RawTokens[index];
                    if( Tokens[index+1] == ")" ) TableDeleteColsCmd(6,Tokens,index+1);
                    else TableDeleteColsCmd(State+1,Tokens,index+1);
                }
            }else{
                ER.PrintError(RawTokens,index,"INVALID_COL_NAME",REPLWIN);
            }
        }else if( TableDeleteColStates[State] == ")" ){
            TableDeleteColsCmd(State+1,Tokens,index+1);
        }else{
            ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
        }
    }
}
void Automata::TableOrderDisplayCmd(int State, StrList Tokens, int index){
//    TABLE ORDER DISPLAY NAME
    if( Tokens[index] == TableOrderDisplayCommonStates[State] ){
        if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_TABLE_DISPLAY_QUERY",REPLWIN);
        else TableOrderDisplayCmd(State+1,Tokens,index+1);
    }else if( TableOrderDisplayCommonStates[State] == "NAME"  ){
        if( TokenKey_KeyList["IDENTIFIERS"].contains(Tokens[index], Qt::CaseInsensitive) ){
            QueryData["TABLE_NAMES"] << RawTokens[index];
            if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_TABLE_DISPLAY_QUERY",REPLWIN);
            else{
                if( Tokens[index+1] == "{" ) TableOrderDisplayTableCmd(State+1,Tokens,index+1);
                else if( Tokens[index+1] == "(" ) TableOrderDisplayColsCmd(State+1,Tokens,index+1);
                else ER.PrintError(RawTokens,index,"INVALID_TABLE_QUERY",REPLWIN);
            }
        }else ER.PrintError(RawTokens,index,"INVALID_TABLE_NAME",REPLWIN);
    }
    else ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
}
void Automata::TableOrderDisplayTableCmd(int State, StrList Tokens, int index){
//    TABLE ORDER DISPLAY NAME { COL : ODR , } ;
    if( TableOrderDisplayStates[State] == ";" && Tokens[index] == ";" ){
        if( index == Tokens.size() - 1 ) QE.TableOrderDisplayTable(REPLWIN,QueryData);
        else ER.PrintError(RawTokens,index,"INVALID_TABLE_QUERY",REPLWIN);
    }
    else if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_TABLE_UPDATE_QUERY",REPLWIN);
    else{
        if( Tokens[index] == TableOrderDisplayStates[State] ){
            if( TableOrderDisplayStates[State] == "," ) TableOrderDisplayTableCmd(5,Tokens,index+1);
            else{
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_TABLE_UPDATE_QUERY",REPLWIN);
                else TableOrderDisplayTableCmd(State+1,Tokens,index+1);
            }
        }else if( TableOrderDisplayStates[State] == "COL"  ){
            QueryData["COL_NAMES"] << RawTokens[index];
            if( TokenKey_KeyList["IDENTIFIERS"].contains(Tokens[index], Qt::CaseInsensitive) ) TableOrderDisplayTableCmd(State+1,Tokens,index+1);
            else ER.PrintError(RawTokens,index,"INVALID_COL_NAME",REPLWIN);
        }else if( TableOrderDisplayStates[State] == "ODR"  ){
            if( Tokens[index].compare("ASC",Qt::CaseInsensitive) == 0 || Tokens[index].compare("DSC",Qt::CaseInsensitive) == 0 ){
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_TABLE_UPDATE_QUERY",REPLWIN);
                else{
                    QueryData["ORDERVALS"] << RawTokens[index];
                    if( Tokens[index+1] == "}" ) TableOrderDisplayTableCmd(9,Tokens,index+1);
                    else TableOrderDisplayTableCmd(State+1,Tokens,index+1);
                }
            }else ER.PrintError(RawTokens,index,"EXPECTING_DATA",REPLWIN);

        }else if( TableOrderDisplayStates[State] == "}" ) TableOrderDisplayTableCmd(State+1,Tokens,index+1);
        else ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
    }
}
char state = '(';
void Automata::TableOrderDisplayColsCmd(int State, StrList Tokens, int index){
//    TABLE ORDER DISPLAY NAME ( COL , ) { COL : ODR , } ;
    if( TableColsOrderDisplayStates[State] == ";" && Tokens[index] == ";" ){
        if( index == Tokens.size() - 1 ) QE.TableOrderDisplayTableCols(REPLWIN,QueryData);
        else ER.PrintError(RawTokens,index,"INVALID_TABLE_QUERY",REPLWIN);
    }
    else if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_TABLE_UPDATE_QUERY",REPLWIN);
    else{
        if( Tokens[index] == TableColsOrderDisplayStates[State] ){
            if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_TABLE_UPDATE_QUERY",REPLWIN);
            else{
                if( TableColsOrderDisplayStates[State] == "," && TableColsOrderDisplayStates[State-1] == "COL" ) TableOrderDisplayColsCmd(5,Tokens,index+1);
                else if( TableColsOrderDisplayStates[State] == "," && TableColsOrderDisplayStates[State-1] == "ODR" ) TableOrderDisplayColsCmd(9,Tokens,index+1);
                else TableOrderDisplayColsCmd(State+1,Tokens,index+1);
            }
        }else if( TableColsOrderDisplayStates[State] == "COL"  ){
            if( TokenKey_KeyList["IDENTIFIERS"].contains(Tokens[index], Qt::CaseInsensitive) ){
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_TABLE_UPDATE_QUERY",REPLWIN);
                else{
                    if( state == '(' ) QueryData["DISPLAY_COL_NAMES"] << RawTokens[index];
                    else QueryData["ORDER_COL_NAMES"] << RawTokens[index];
                    if( Tokens[index+1] == ")" ){
                        state = '{';
                        TableOrderDisplayColsCmd(7,Tokens,index+1);
                    }
                    else TableOrderDisplayColsCmd(State+1,Tokens,index+1);
                }
            }
            else ER.PrintError(RawTokens,index,"INVALID_COL_NAME",REPLWIN);
        }else if( TableColsOrderDisplayStates[State] == "ODR"  ){
            if( Tokens[index].compare("ASC",Qt::CaseInsensitive) == 0 || Tokens[index].compare("DSC",Qt::CaseInsensitive) == 0 ){
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_TABLE_UPDATE_QUERY",REPLWIN);
                else{
                    QueryData["ORDERVALS"] << RawTokens[index];
                    if( Tokens[index+1] == "}" ) TableOrderDisplayColsCmd(13,Tokens,index+1);
                    else TableOrderDisplayColsCmd(State+1,Tokens,index+1);
                }
            }else ER.PrintError(RawTokens,index,"EXPECTING_DATA",REPLWIN);
        }
        else ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
    }
}

void Automata::TableCalCmd( int State, StrList Tokens, int index){
//    TABLE CAL NAME
    if( Tokens[index] == TableCalCommonStates[State] ){
        if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INVALID_TABLE_QUERY",REPLWIN);
        else TableCalCmd(State+1,Tokens,index+1);
    }
    else if( TableCalCommonStates[State] == "NAME"  ){
        if( TokenKey_KeyList["IDENTIFIERS"].contains(Tokens[index], Qt::CaseInsensitive) ){
            if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INVALID_TABLE_QUERY",REPLWIN);
            else{
                QueryData["TABLE_NAMES"] << RawTokens[index];
                if( Tokens[index+1] == "SUM" ) TableCalSumCmd(State+1,Tokens,index+1);
                else if( Tokens[index+1] == "COUNT" ) TableCalCountCmd(State+1,Tokens,index+1);
                else if( Tokens[index+1] == "AVG" ) TableCalAvgCmd(State+1,Tokens,index+1);
                else if( Tokens[index+1] == "MIN" ) TableCalMinCmd(State+1,Tokens,index+1);
                else if( Tokens[index+1] == "MAX" ) TableCalMaxCmd(State+1,Tokens,index+1);
                else if( Tokens[index+1] == "MEAN" ) TableCalMeanCmd(State+1,Tokens,index+1);
                else if( Tokens[index+1] == "MODE" ) TableCalModeCmd(State+1,Tokens,index+1);
                else if( Tokens[index+1] == "MEDIAN" ) TableCalMedianCmd(State+1,Tokens,index+1);
                else if( Tokens[index+1] == "FREQUENCY" ) TableCalFrequencyCmd(State+1,Tokens,index+1);
                else if( Tokens[index+1] == "SD" ) TableCalSDCmd(State+1,Tokens,index+1);
                else if( Tokens[index+1] == "VARIENCE" ) TableCalVarienceCmd(State+1,Tokens,index+1);
                else  ER.PrintError(RawTokens,index,"INVALID_TABLE_QUERY",REPLWIN);
            }
        }
        else ER.PrintError(RawTokens,index,"INVALID_TABLE_NAME",REPLWIN);
    }
    else ER.PrintError(RawTokens,index,"INVALID_TABLE_QUERY",REPLWIN);
}
void Automata::TableCalSumCmd( int State, StrList Tokens, int index){
//    TABLE CAL NAME SUM ( COL ,  ) ;
    if( TableCalSumStates[State] == ";" && Tokens[index] == ";" ){
        if( index == Tokens.size() - 1 ) QE.TableCalculateSum(REPLWIN,QueryData);
        else ER.PrintError(RawTokens,index,"INVALID_TABLE_QUERY",REPLWIN);
    }
    else if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_TABLE_SUM_QUERY",REPLWIN);
    else{
        if( Tokens[index] == TableCalSumStates[State] ){
            if( TableCalSumStates[State] == "," ) TableCalSumCmd(5,Tokens,index+1);
            else{
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_TABLE_SUM_QUERY",REPLWIN);
                else TableCalSumCmd(State+1,Tokens,index+1);
            }
        }else if( TableCalSumStates[State] == "COL"  ){
            if( TokenKey_KeyList["IDENTIFIERS"].contains(Tokens[index], Qt::CaseInsensitive) ){
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_TABLE_SUM_QUERY",REPLWIN);
                else{
                    QueryData["COL_NAMES"] << RawTokens[index];
                    if( Tokens[index+1] == ")" ) TableCalSumCmd(7,Tokens,index+1);
                    else TableCalSumCmd(State+1,Tokens,index+1);
                }
            }
            else ER.PrintError(RawTokens,index,"INVALID_COL_NAME",REPLWIN);
        }
        else ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
    }
}
void Automata::TableCalCountCmd( int State, StrList Tokens, int index){
//    TABLE CAL NAME COUNT ( COL ,  ) ;
    if( TableCalCountStates[State] == ";" && Tokens[index] == ";" ){
        if( index == Tokens.size() - 1 ) QE.TableCalculateCount(REPLWIN,QueryData);
        else ER.PrintError(RawTokens,index,"INVALID_TABLE_QUERY",REPLWIN);
    }
    else if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_TABLE_COUNT_QUERY",REPLWIN);
    else{
        if( Tokens[index] == TableCalCountStates[State] ){
            if( TableCalCountStates[State] == "," ) TableCalCountCmd(5,Tokens,index+1);
            else{
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_TABLE_COUNT_QUERY",REPLWIN);
                else TableCalCountCmd(State+1,Tokens,index+1);
            }
        }else if( TableCalCountStates[State] == "COL"  ){
            if( TokenKey_KeyList["IDENTIFIERS"].contains(Tokens[index], Qt::CaseInsensitive) ){
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_TABLE_COUNT_QUERY",REPLWIN);
                else{
                    QueryData["COL_NAMES"] << RawTokens[index];
                    if( Tokens[index+1] == ")" ) TableCalCountCmd(7,Tokens,index+1);
                    else TableCalCountCmd(State+1,Tokens,index+1);
                }
            }
            else ER.PrintError(RawTokens,index,"INVALID_COL_NAME",REPLWIN);
        }
        else ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
    }
}
void Automata::TableCalAvgCmd( int State, StrList Tokens, int index){
//    TABLE CAL NAME AVG ( COL ,  ) ;
    if( TableCalAvgStates[State] == ";" && Tokens[index] == ";" ){
        if( index == Tokens.size() - 1 ) QE.TableCalculateAvg(REPLWIN,QueryData);
        else ER.PrintError(RawTokens,index,"INVALID_TABLE_QUERY",REPLWIN);
    }
    else if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_TABLE_AVG_QUERY",REPLWIN);
    else{
        if( Tokens[index] == TableCalAvgStates[State] ){
            if( TableCalAvgStates[State] == "," ) TableCalAvgCmd(5,Tokens,index+1);
            else{
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_TABLE_AVG_QUERY",REPLWIN);
                else TableCalAvgCmd(State+1,Tokens,index+1);
            }
        }else if( TableCalAvgStates[State] == "COL"  ){
            if( TokenKey_KeyList["IDENTIFIERS"].contains(Tokens[index], Qt::CaseInsensitive) ){
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_TABLE_AVG_QUERY",REPLWIN);
                else{
                    QueryData["COL_NAMES"] << RawTokens[index];
                    if( Tokens[index+1] == ")" ) TableCalAvgCmd(7,Tokens,index+1);
                    else TableCalAvgCmd(State+1,Tokens,index+1);
                }
            }
            else ER.PrintError(RawTokens,index,"INVALID_COL_NAME",REPLWIN);
        }
        else ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
    }
}
void Automata::TableCalMinCmd( int State, StrList Tokens, int index){
//    TABLE CAL NAME MIN ( COL ,  ) ;
    if( TableCalMinStates[State] == ";" && Tokens[index] == ";" ){
        if( index == Tokens.size() - 1 ) QE.TableCalculateMin(REPLWIN,QueryData);
        else ER.PrintError(RawTokens,index,"INVALID_TABLE_QUERY",REPLWIN);
    }
    else if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_TABLE_MIN_QUERY",REPLWIN);
    else{
        if( Tokens[index] == TableCalMinStates[State] ){
            if( TableCalMinStates[State] == "," ) TableCalMinCmd(5,Tokens,index+1);
            else{
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_TABLE_MIN_QUERY",REPLWIN);
                else TableCalMinCmd(State+1,Tokens,index+1);
            }
        }else if( TableCalMinStates[State] == "COL"  ){
            if( TokenKey_KeyList["IDENTIFIERS"].contains(Tokens[index], Qt::CaseInsensitive) ){
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_TABLE_MIN_QUERY",REPLWIN);
                else{
                    QueryData["COL_NAMES"] << RawTokens[index];
                    if( Tokens[index+1] == ")" ) TableCalMinCmd(7,Tokens,index+1);
                    else TableCalMinCmd(State+1,Tokens,index+1);
                }
            }
            else ER.PrintError(RawTokens,index,"INVALID_COL_NAME",REPLWIN);
        }
        else ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
    }
}
void Automata::TableCalMaxCmd( int State, StrList Tokens, int index){
//    TABLE CAL NAME MAX ( COL ,  ) ;
    if( TableCalMaxStates[State] == ";" && Tokens[index] == ";" ){
        if( index == Tokens.size() - 1 ) QE.TableCalculateMax(REPLWIN,QueryData);
        else ER.PrintError(RawTokens,index,"INVALID_TABLE_QUERY",REPLWIN);
    }
    else if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_TABLE_MAX_QUERY",REPLWIN);
    else{
        if( Tokens[index] == TableCalMaxStates[State] ){
            if( TableCalMaxStates[State] == "," ) TableCalMaxCmd(5,Tokens,index+1);
            else{
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_TABLE_MAX_QUERY",REPLWIN);
                else TableCalMaxCmd(State+1,Tokens,index+1);
            }
        }else if( TableCalMaxStates[State] == "COL"  ){
            if( TokenKey_KeyList["IDENTIFIERS"].contains(Tokens[index], Qt::CaseInsensitive) ){
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_TABLE_MAX_QUERY",REPLWIN);
                else{
                    QueryData["COL_NAMES"] << RawTokens[index];
                    if( Tokens[index+1] == ")" ) TableCalMaxCmd(7,Tokens,index+1);
                    else TableCalMaxCmd(State+1,Tokens,index+1);
                }
            }
            else ER.PrintError(RawTokens,index,"INVALID_COL_NAME",REPLWIN);
        }
        else ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
    }
}
void Automata::TableCalMeanCmd( int State, StrList Tokens, int index){
//    TABLE CAL NAME MEAN ( COL ,  ) ;
    if( TableCalMeanStates[State] == ";" && Tokens[index] == ";" ){
        if( index == Tokens.size() - 1 ) QE.TableCalculateMean(REPLWIN,QueryData);
        else ER.PrintError(RawTokens,index,"INVALID_TABLE_QUERY",REPLWIN);
    }
    else if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_TABLE_MEAN_QUERY",REPLWIN);
    else{
        if( Tokens[index] == TableCalMeanStates[State] ){
            if( TableCalMeanStates[State] == "," ) TableCalMeanCmd(5,Tokens,index+1);
            else{
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_TABLE_MEAN_QUERY",REPLWIN);
                else TableCalMeanCmd(State+1,Tokens,index+1);
            }
        }else if( TableCalMeanStates[State] == "COL"  ){
            if( TokenKey_KeyList["IDENTIFIERS"].contains(Tokens[index], Qt::CaseInsensitive) ){
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_TABLE_MEAN_QUERY",REPLWIN);
                else{
                    QueryData["COL_NAMES"] << RawTokens[index];
                    if( Tokens[index+1] == ")" ) TableCalMeanCmd(7,Tokens,index+1);
                    else TableCalMeanCmd(State+1,Tokens,index+1);
                }
            }
            else ER.PrintError(RawTokens,index,"INVALID_COL_NAME",REPLWIN);
        }
        else ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
    }
}
void Automata::TableCalModeCmd( int State, StrList Tokens, int index){
//    TABLE CAL NAME MODE ( COL ,  ) ;
    if( TableCalModeStates[State] == ";" && Tokens[index] == ";" ){
        if( index == Tokens.size() - 1 ) QE.TableCalculateMode(REPLWIN,QueryData);
        else ER.PrintError(RawTokens,index,"INVALID_TABLE_QUERY",REPLWIN);
    }
    else if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_TABLE_MODE_QUERY",REPLWIN);
    else{
        if( Tokens[index] == TableCalModeStates[State] ){
            if( TableCalModeStates[State] == "," ) TableCalModeCmd(5,Tokens,index+1);
            else{
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_TABLE_MODE_QUERY",REPLWIN);
                else TableCalModeCmd(State+1,Tokens,index+1);
            }
        }else if( TableCalModeStates[State] == "COL"  ){
            if( TokenKey_KeyList["IDENTIFIERS"].contains(Tokens[index], Qt::CaseInsensitive) ){
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_TABLE_MODE_QUERY",REPLWIN);
                else{
                    QueryData["COL_NAMES"] << RawTokens[index];
                    if( Tokens[index+1] == ")" ) TableCalModeCmd(7,Tokens,index+1);
                    else TableCalModeCmd(State+1,Tokens,index+1);
                }
            }
            else ER.PrintError(RawTokens,index,"INVALID_COL_NAME",REPLWIN);
        }
        else ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
    }
}
void Automata::TableCalMedianCmd( int State, StrList Tokens, int index){
//    TABLE CAL NAME MEDIAN ( COL ,  ) ;
    if( TableCalMedianStates[State] == ";" && Tokens[index] == ";" ){
        if( index == Tokens.size() - 1 ) QE.TableCalculateMedian(REPLWIN,QueryData);
        else ER.PrintError(RawTokens,index,"INVALID_TABLE_QUERY",REPLWIN);
    }
    else if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_TABLE_MEDIAN_QUERY",REPLWIN);
    else{
        if( Tokens[index] == TableCalMedianStates[State] ){
            if( TableCalMedianStates[State] == "," ) TableCalMedianCmd(5,Tokens,index+1);
            else{
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_TABLE_MEDIAN_QUERY",REPLWIN);
                else TableCalMedianCmd(State+1,Tokens,index+1);
            }
        }else if( TableCalMedianStates[State] == "COL"  ){
            if( TokenKey_KeyList["IDENTIFIERS"].contains(Tokens[index], Qt::CaseInsensitive) ){
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_TABLE_MEDIAN_QUERY",REPLWIN);
                else{
                    QueryData["COL_NAMES"] << RawTokens[index];
                    if( Tokens[index+1] == ")" ) TableCalMedianCmd(7,Tokens,index+1);
                    else TableCalMedianCmd(State+1,Tokens,index+1);
                }
            }
            else ER.PrintError(RawTokens,index,"INVALID_COL_NAME",REPLWIN);
        }
        else ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
    }
}
void Automata::TableCalFrequencyCmd( int State, StrList Tokens, int index){
//    TABLE CAL NAME FREQUENCY ( COL ,  ) ;
    if( TableCalFrequencyStates[State] == ";" && Tokens[index] == ";" ){
        if( index == Tokens.size() - 1 ) QE.TableCalculateFrequency(REPLWIN,QueryData);
        else ER.PrintError(RawTokens,index,"INVALID_TABLE_QUERY",REPLWIN);
    }
    else if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_TABLE_FREQUENCY_QUERY",REPLWIN);
    else{
        if( Tokens[index] == TableCalFrequencyStates[State] ){
            if( TableCalFrequencyStates[State] == "," ) TableCalFrequencyCmd(5,Tokens,index+1);
            else{
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_TABLE_FREQUENCY_QUERY",REPLWIN);
                else TableCalFrequencyCmd(State+1,Tokens,index+1);
            }
        }else if( TableCalFrequencyStates[State] == "COL"  ){
            if( TokenKey_KeyList["IDENTIFIERS"].contains(Tokens[index], Qt::CaseInsensitive) ){
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_TABLE_FREQUENCY_QUERY",REPLWIN);
                else{
                    QueryData["COL_NAMES"] << RawTokens[index];
                    if( Tokens[index+1] == ")" ) TableCalFrequencyCmd(7,Tokens,index+1);
                    else TableCalFrequencyCmd(State+1,Tokens,index+1);
                }
            }
            else ER.PrintError(RawTokens,index,"INVALID_COL_NAME",REPLWIN);
        }
        else ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
    }
}
void Automata::TableCalSDCmd( int State, StrList Tokens, int index){
//    TABLE CAL NAME SD ( COL , ) ;
    if( TableCalSDStates[State] == ";" && Tokens[index] == ";" ){
        if( index == Tokens.size() - 1 ) QE.TableCalculateSD(REPLWIN,QueryData);
        else ER.PrintError(RawTokens,index,"INVALID_TABLE_QUERY",REPLWIN);
    }
    else if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_TABLE_SD_QUERY",REPLWIN);
    else{
        if( Tokens[index] == TableCalSDStates[State] ){
            if( TableCalSDStates[State] == "," ) TableCalSDCmd(5,Tokens,index+1);
            else{
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_TABLE_SD_QUERY",REPLWIN);
                else TableCalSDCmd(State+1,Tokens,index+1);
            }
        }else if( TableCalSDStates[State] == "COL"  ){
            if( TokenKey_KeyList["IDENTIFIERS"].contains(Tokens[index], Qt::CaseInsensitive) ){
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_TABLE_SD_QUERY",REPLWIN);
                else{
                    QueryData["COL_NAMES"] << RawTokens[index];
                    if( Tokens[index+1] == ")" ) TableCalSDCmd(7,Tokens,index+1);
                    else TableCalSDCmd(State+1,Tokens,index+1);
                }
            }
            else ER.PrintError(RawTokens,index,"INVALID_COL_NAME",REPLWIN);
        }
        else ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
    }
}
void Automata::TableCalVarienceCmd( int State, StrList Tokens, int index){
//    TABLE CAL NAME VARIENCE ( COL , ) ;
    if( TableCalVarienceStates[State] == ";" && Tokens[index] == ";" ){
        if( index == Tokens.size() - 1 ) QE.TableCalculateVarience(REPLWIN,QueryData);
        else ER.PrintError(RawTokens,index,"INVALID_TABLE_QUERY",REPLWIN);
    }
    else if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_TABLE_VARIENCE_QUERY",REPLWIN);
    else{
        if( Tokens[index] == TableCalVarienceStates[State] ){
            if( TableCalVarienceStates[State] == "," ) TableCalVarienceCmd(5,Tokens,index+1);
            else{
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_TABLE_VARIENCE_QUERY",REPLWIN);
                else TableCalVarienceCmd(State+1,Tokens,index+1);
            }
        }else if( TableCalVarienceStates[State] == "COL"  ){
            if( TokenKey_KeyList["IDENTIFIERS"].contains(Tokens[index], Qt::CaseInsensitive) ){
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_TABLE_VARIENCE_QUERY",REPLWIN);
                else{
                    QueryData["COL_NAMES"] << RawTokens[index];
                    if( Tokens[index+1] == ")" ) TableCalVarienceCmd(7,Tokens,index+1);
                    else TableCalVarienceCmd(State+1,Tokens,index+1);
                }
            }
            else ER.PrintError(RawTokens,index,"INVALID_COL_NAME",REPLWIN);
        }
        else ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
    }
}

// Piechart
void Automata::PieCreateCmd(int State, StrList Tokens, int index){
    if( Tokens[index] == PieCreateCommonStates[State] ){
        if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_PIECHART_CREATE_QUERY",REPLWIN);
        else PieCreateCmd(State+1,Tokens,index+1);
    }else if( PieCreateCommonStates[State] == "NAME"  ){
        if( TokenKey_KeyList["IDENTIFIERS"].contains(Tokens[index], Qt::CaseInsensitive) ){
            if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_PIECHART_CREATE_QUERY",REPLWIN);
            else{
                QueryData["PIECHART_NAMES"] << RawTokens[index];
                if( Tokens[index+1] == "FROM" ) PieCreateFromTableCmd(State+1,Tokens,index+1);
                else if( Tokens[index+1] == "{" ) PieCreateFromDataCmd(State+1,Tokens,index+1);
                else ER.PrintError(RawTokens,index,"INVALID_PIECHART_QUERY",REPLWIN);
            }
        }else{
            ER.PrintError(RawTokens,index,"INVALID_PIECHART_NAME",REPLWIN);
        }
    }
    else ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
}
void Automata::PieCreateFromTableCmd(int State, StrList Tokens, int index){
    if( PieFromTableStates[State] == ";" && Tokens[index] == ";" ){
        if( index == Tokens.size() - 1 ) QE.CreatePieFromTable(REPLWIN,QueryData);
        else ER.PrintError(RawTokens,index,"INVALID_PIECHART_QUERY",REPLWIN);
    }
    else if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_PIECHART_CREATE_QUERY",REPLWIN);
    else if( Tokens[index] == PieFromTableStates[State] ){
        if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_PIECHART_CREATE_QUERY",REPLWIN);
        else PieCreateFromTableCmd(State+1,Tokens,index+1);
    }else if( PieFromTableStates[State] == "TABLENAME"  ){
        if( TokenKey_KeyList["IDENTIFIERS"].contains(Tokens[index], Qt::CaseInsensitive) ){
            QueryData["TABLE_NAMES"] << RawTokens[index];
            if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_PIECHART_CREATE_QUERY",REPLWIN);
            else PieCreateFromTableCmd(State+1,Tokens,index+1);
        }else{
            ER.PrintError(RawTokens,index,"INVALID_TABLE_NAME",REPLWIN);
        }
    }
    else ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
}
void Automata::PieCreateFromDataCmd(int State, StrList Tokens, int index){
    if( PieCreateStates[State] == ";" && Tokens[index] == ";" ){
        if( index == Tokens.size() - 1 ) QE.CreatePiechartFromData(REPLWIN,QueryData);
        else ER.PrintError(RawTokens,index,"INVALID_PIECHART_QUERY",REPLWIN);
    }
    else if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_PIECHART_CREATE_QUERY",REPLWIN);
    else{
        if( Tokens[index] == PieCreateStates[State] ){
            if( PieCreateStates[State] == "," ){
                PieCreateFromDataCmd(4,Tokens,index+1);
            }else{
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_PIECHART_CREATE_QUERY",REPLWIN);
                else PieCreateFromDataCmd(State+1,Tokens,index+1);
            }
        }
        else if( PieCreateStates[State] == "DATANAME"  ){
            if( TokenKey_KeyList["IDENTIFIERS"].contains(Tokens[index], Qt::CaseInsensitive) ){
                QueryData["DATANAMES"] << RawTokens[index];
                PieCreateFromDataCmd(State+1,Tokens,index+1);
            }else{
                ER.PrintError(RawTokens,index,"INVALID_DATA_NAME",REPLWIN);
            }
        }else if( PieCreateStates[State] == "NUMERIC"  ){
            if( TokenKey_KeyList["DATA"].contains(Tokens[index], Qt::CaseInsensitive) && Tokens[index].startsWith("NUMERIC") ){
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_PIECHART_CREATE_QUERY",REPLWIN);
                else{
                    QueryData["DATAVALS"] << RawTokens[index];
                    if( Tokens[index+1] == "}" ) PieCreateFromDataCmd(8,Tokens,index+1);
                    else PieCreateFromDataCmd(State+1,Tokens,index+1);
                }
            }else{
                ER.PrintError(RawTokens,index,"EXPECTING_DATA",REPLWIN);
            }
        }else if( PieCreateStates[State] == "}" ){
            PieCreateFromDataCmd(State+1,Tokens,index+1);
        }else{
            ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
        }
    }
}
void Automata::PieDisplayCmd(int State, StrList Tokens, int index){
//     "PIECHART" , "DISPLAY"
    if( Tokens[index] == PieDisplayCommonStates[State] ){
        if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_PIECHART_DISPLAY_QUERY",REPLWIN);
        else{
            if( PieDisplayCommonStates[State] == "DISPLAY" ){
                if( Tokens[index+1] == "PERCENT" ) PieDisplayPercentCmd(State+1,Tokens,index+1);
                else if( TokenKey_KeyList["IDENTIFIERS"].contains(Tokens[index+1], Qt::CaseInsensitive) ) PieDisplayNormalCmd(State+1,Tokens,index+1);
                else ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
            }
            else PieDisplayCmd(State+1,Tokens,index+1);
        }
    }
    else ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
}
void Automata::PieDisplayNormalCmd(int State, StrList Tokens, int index){
    if( PieDisplayStates[State] == ";" && Tokens[index] == ";" ){
        if( index == Tokens.size() - 1 ) QE.DisplayPiechart(REPLWIN,QueryData);
        else ER.PrintError(RawTokens,index,"INVALID_PIECHART_QUERY",REPLWIN);
    }
    else if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_PIECHART_DISPLAY_QUERY",REPLWIN);
    else if( PieDisplayStates[State] == "NAME" ){
        QueryData["PIECHART_NAMES"] << RawTokens[index];
        if( TokenKey_KeyList["IDENTIFIERS"].contains(Tokens[index], Qt::CaseInsensitive) ) PieDisplayNormalCmd(State+1,Tokens,index+1);
        else ER.PrintError(RawTokens,index,"INVALID_PIECHART_NAME",REPLWIN);
    }
    else ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
}
void Automata::PieDisplayPercentCmd(int State, StrList Tokens, int index){
//    "PIECHART" , "DISPLAY" , "PERCENT" , "NAME" , ";"
    if( PieDisplayPercentStates[State] == ";" && Tokens[index] == ";" ){
        if( index == Tokens.size() - 1 ) QE.DisplayPiechart(REPLWIN,QueryData);
        else ER.PrintError(RawTokens,index,"INVALID_PIECHART_QUERY",REPLWIN);
    }
    else if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_PIECHART_DISPLAY_QUERY",REPLWIN);
    else if( Tokens[index] == PieDisplayPercentStates[State] ){
        if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_PIECHART_DISPLAY_QUERY",REPLWIN);
        else PieDisplayPercentCmd(State+1,Tokens,index+1);
    }
    else if( PieDisplayPercentStates[State] == "NAME" ){
        QueryData["PIECHART_NAMES"] << RawTokens[index];
        if( TokenKey_KeyList["IDENTIFIERS"].contains(Tokens[index], Qt::CaseInsensitive) ) PieDisplayPercentCmd(State+1,Tokens,index+1);
        else ER.PrintError(RawTokens,index,"INVALID_PIECHART_NAME",REPLWIN);
    }
    else ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
}
void Automata::PieDeleteCmd(int State, StrList Tokens, int index){
    if( PieDeleteStates[State] == ";" && Tokens[index] == ";" ){
        if( index == Tokens.size() - 1 ) QE.DeletePiechart(REPLWIN,QueryData);
        else ER.PrintError(RawTokens,index,"INVALID_PIECHART_QUERY",REPLWIN);
    }
    else if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_PIECHART_DELETE_QUERY",REPLWIN);
    else{
        if( Tokens[index] == PieDeleteStates[State] ){
            if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_PIECHART_DELETE_QUERY",REPLWIN);
            else PieDeleteCmd(State+1,Tokens,index+1);
        }
        else if( PieDeleteStates[State] == "NAME"){
            if( TokenKey_KeyList["IDENTIFIERS"].contains( Tokens[index], Qt::CaseInsensitive ) ){
                QueryData["TABLE_NAMES"] << RawTokens[index];
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_PIECHART_DELETE_QUERY",REPLWIN);
                else PieDeleteCmd(State+1,Tokens,index+1);
            }else{
                ER.PrintError(RawTokens,index,"INVALID_PIECHART_NAME",REPLWIN);
            }
        }else{
            ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
        }
    }
}
void Automata::PieRenameCmd(int State, StrList Tokens, int index){
    if( PieRenameStates[State] == ";" && Tokens[index] == ";" ){
        if( index == Tokens.size() - 1 ) QE.ChangePiechartName(REPLWIN,QueryData);
        else ER.PrintError(RawTokens,index,"INVALID_PIECHART_QUERY",REPLWIN);
    }
    else if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_PIECHART_RENAME_QUERY",REPLWIN);
    else{
        if( Tokens[index] == PieRenameStates[State] ){
            if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_PIECHART_RENAME_QUERY",REPLWIN);
            else PieRenameCmd(State+1,Tokens,index+1);
        }
        else if( PieRenameStates[State] == "NAME"){
            if( TokenKey_KeyList["IDENTIFIERS"].contains( Tokens[index], Qt::CaseInsensitive ) ){
                QueryData["PIECHART_NAMES"] << RawTokens[index] ;
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_PIECHART_RENAME_QUERY",REPLWIN);
                else PieRenameCmd(State+1,Tokens,index+1);
            }else{
                ER.PrintError(RawTokens,index,"INVALID_PIECHART_NAME",REPLWIN);
            }
        }else if( PieRenameStates[State] == "NEWNAME"){
            if( TokenKey_KeyList["IDENTIFIERS"].contains( Tokens[index], Qt::CaseInsensitive ) ){
                QueryData["PIECHART_NAMES"] << RawTokens[index] ;
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_PIECHART_RENAME_QUERY",REPLWIN);
                else PieRenameCmd(State+1,Tokens,index+1);
            }else{
                ER.PrintError(RawTokens,index,"INVALID_PIECHART_NAME",REPLWIN);
            }
        }else{
            ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
        }
    }
}
void Automata::PieLinkCmd(int State, StrList Tokens, int index){
    if( Tokens[index] == PieLinkCommonStates[State] ){
        if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_PIECHART_LINK_QUERY",REPLWIN);
        else{
            if( PieLinkCommonStates[State] == "LINK" ){
                if( Tokens[index+1] == "REMOVE" ) PieLinkRemoveCmd(State+1,Tokens,index+1);
                else if( TokenKey_KeyList["IDENTIFIERS"].contains(Tokens[index+1], Qt::CaseInsensitive) ) PieLinkTableCmd(State+1,Tokens,index+1);
                else ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
            }
            else PieLinkCmd(State+1,Tokens,index+1);
        }
    }
    else ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
}
void Automata::PieLinkTableCmd(int State, StrList Tokens, int index){
    if( PieLinkTableStates[State] == ";" && Tokens[index] == ";" ){
        if( index == Tokens.size() - 1 ) QE.PieLinkWithTable(REPLWIN,QueryData);
        else ER.PrintError(RawTokens,index,"INVALID_PIECHART_QUERY",REPLWIN);
    }
    else if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_PIECHART_LINK_QUERY",REPLWIN);
    else if( Tokens[index] == PieLinkTableStates[State] ){
        if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_PIECHART_LINK_QUERY",REPLWIN);
        else PieLinkTableCmd(State+1,Tokens,index+1);
    }
    else if( PieLinkTableStates[State] == "PIENAME" ){
        QueryData["PIECHART_NAMES"] << RawTokens[index];
        if( TokenKey_KeyList["IDENTIFIERS"].contains(Tokens[index], Qt::CaseInsensitive) ) PieLinkTableCmd(State+1,Tokens,index+1);
        else ER.PrintError(RawTokens,index,"INVALID_PIECHART_NAME",REPLWIN);
    }
    else if( PieLinkTableStates[State] == "TABLENAME" ){
        QueryData["TABLE_NAMES"] << RawTokens[index];
        if( TokenKey_KeyList["IDENTIFIERS"].contains(Tokens[index], Qt::CaseInsensitive) ) PieLinkTableCmd(State+1,Tokens,index+1);
        else ER.PrintError(RawTokens,index,"INVALID_PIECHART_NAME",REPLWIN);
    }
    else ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
}
void Automata::PieLinkRemoveCmd(int State, StrList Tokens, int index){
    if( PieRemoveLinkTableStates[State] == ";" && Tokens[index] == ";" ){
        if( index == Tokens.size() - 1 ) QE.PieUnlinkWithTable(REPLWIN,QueryData);
        else ER.PrintError(RawTokens,index,"INVALID_PIECHART_QUERY",REPLWIN);
    }
    else if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_PIECHART_LINK_QUERY",REPLWIN);
    else if( Tokens[index] == PieRemoveLinkTableStates[State] ){
        if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_PIECHART_LINK_QUERY",REPLWIN);
        else PieLinkRemoveCmd(State+1,Tokens,index+1);
    }
    else if( PieRemoveLinkTableStates[State] == "PIENAME" ){
        QueryData["PIECHART_NAMES"] << RawTokens[index];
        if( TokenKey_KeyList["IDENTIFIERS"].contains(Tokens[index], Qt::CaseInsensitive) ) PieLinkRemoveCmd(State+1,Tokens,index+1);
        else ER.PrintError(RawTokens,index,"INVALID_PIECHART_NAME",REPLWIN);
    }
    else ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
}

//// Bargraph
void Automata::BarCreateCmd(int State, StrList Tokens, int index){
    if( Tokens[index] == BarCreateCommonStates[State] ){
        if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_BARGRAPH_CREATE_QUERY",REPLWIN);
        else BarCreateCmd(State+1,Tokens,index+1);
    }else if( BarCreateCommonStates[State] == "NAME"  ){
        if( TokenKey_KeyList["IDENTIFIERS"].contains(Tokens[index], Qt::CaseInsensitive) ){
            if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_BARGRAPH_CREATE_QUERY",REPLWIN);
            else{
                QueryData["BARGRAPH_NAMES"] << RawTokens[index];
                if( Tokens[index+1] == "FROM" ) BarCreateFromTableCmd(State+1,Tokens,index+1);
                else if( Tokens[index+1] == "{" ) BarCreateFromDataCmd(State+1,Tokens,index+1);
                else ER.PrintError(RawTokens,index,"INVALID_BARGRAPH_QUERY",REPLWIN);
            }
        }else{
            ER.PrintError(RawTokens,index,"INVALID_BARGRAPH_NAME",REPLWIN);
        }
    }
    else ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
}
void Automata::BarCreateFromTableCmd(int State, StrList Tokens, int index){
    if( BarFromTableStates[State] == ";" && Tokens[index] == ";" ){
        if( index == Tokens.size() - 1 ) QE.CreateBarFromTable(REPLWIN,QueryData);
        else ER.PrintError(RawTokens,index,"INVALID_BARGRAPH_QUERY",REPLWIN);
    }
    else if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_BARGRAPH_CREATE_QUERY",REPLWIN);
    else if( Tokens[index] == BarFromTableStates[State] ){
        if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_BARGRAPH_CREATE_QUERY",REPLWIN);
        else BarCreateFromTableCmd(State+1,Tokens,index+1);
    }else if( BarFromTableStates[State] == "TABLENAME"  ){
        if( TokenKey_KeyList["IDENTIFIERS"].contains(Tokens[index], Qt::CaseInsensitive) ){
            QueryData["TABLE_NAMES"] << RawTokens[index];
            if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_BARGRAPH_CREATE_QUERY",REPLWIN);
            else BarCreateFromTableCmd(State+1,Tokens,index+1);
        }else{
            ER.PrintError(RawTokens,index,"INVALID_TABLE_NAME",REPLWIN);
        }
    }
    else ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
}
void Automata::BarCreateFromDataCmd(int State, StrList Tokens, int index){
    if( BarCreateStates[State] == ";" && Tokens[index] == ";" ){
        if( index == Tokens.size() - 1 ) QE.CreateBargraphFromData(REPLWIN,QueryData);
        else ER.PrintError(RawTokens,index,"INVALID_BARGRAPH_QUERY",REPLWIN);
    }
    else if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_BARGRAPH_CREATE_QUERY",REPLWIN);
    else{
        if( Tokens[index] == BarCreateStates[State] ){
            if( BarCreateStates[State] == "," ){
                BarCreateFromDataCmd(4,Tokens,index+1);
            }else{
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_BARGRAPH_CREATE_QUERY",REPLWIN);
                else BarCreateFromDataCmd(State+1,Tokens,index+1);
            }
        }
        else if( BarCreateStates[State] == "X"  ){
            if( TokenKey_KeyList["IDENTIFIERS"].contains(Tokens[index], Qt::CaseInsensitive) ){
                QueryData["DATANAMES"] << RawTokens[index];
                BarCreateFromDataCmd(State+1,Tokens,index+1);
            }else{
                ER.PrintError(RawTokens,index,"INVALID_DATA_NAME",REPLWIN);
            }
        }else if( BarCreateStates[State] == "Y"  ){
            if( TokenKey_KeyList["DATA"].contains(Tokens[index], Qt::CaseInsensitive) && Tokens[index].startsWith("NUMERIC") ){
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_BARGRAPH_CREATE_QUERY",REPLWIN);
                else{
                    QueryData["DATAVALS"] << RawTokens[index];
                    if( Tokens[index+1] == "}" ) BarCreateFromDataCmd(8,Tokens,index+1);
                    else BarCreateFromDataCmd(State+1,Tokens,index+1);
                }
            }else{
                ER.PrintError(RawTokens,index,"EXPECTING_DATA",REPLWIN);
            }
        }else if( BarCreateStates[State] == "}" ){
            BarCreateFromDataCmd(State+1,Tokens,index+1);
        }else{
            ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
        }
    }
}
void Automata::BarDisplayCmd(int State, StrList Tokens, int index){
    if( BarDisplayStates[State] == ";" && Tokens[index] == ";" ){
        if( index == Tokens.size() - 1 ) QE.DisplayBargraph(REPLWIN,QueryData);
        else ER.PrintError(RawTokens,index,"INVALID_BARGRAPH_QUERY",REPLWIN);
    }
    else if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_BARGRAPH_DISPLAY_QUERY",REPLWIN);
    else{
        if( Tokens[index] == BarDisplayStates[State] ){
            if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_BARGRAPH_DISPLAY_QUERY",REPLWIN);
            else BarDisplayCmd(State+1,Tokens,index+1);
        }
        else if( BarDisplayStates[State] == "NAME"){
            if( TokenKey_KeyList["IDENTIFIERS"].contains( Tokens[index], Qt::CaseInsensitive ) ){
                QueryData["BARGRAPH_NAMES"] << RawTokens[index];
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_BARGRAPH_DISPLAY_QUERY",REPLWIN);
                else BarDisplayCmd(State+1,Tokens,index+1);
            }else{
                ER.PrintError(RawTokens,index,"INVALID_BARGRAPH_NAME",REPLWIN);
            }
        }else{
            ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
        }
    }
}
void Automata::BarDeleteCmd(int State, StrList Tokens, int index){
    if( BarDeleteStates[State] == ";" && Tokens[index] == ";" ){
        if( index == Tokens.size() - 1 ) QE.DeleteBargraph(REPLWIN,QueryData);
        else ER.PrintError(RawTokens,index,"INVALID_BARGRAPH_QUERY",REPLWIN);
    }
    else if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_BARGRAPH_DELETE_QUERY",REPLWIN);
    else{
        if( Tokens[index] == BarDeleteStates[State] ){
            if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_BARGRAPH_DELETE_QUERY",REPLWIN);
            else BarDeleteCmd(State+1,Tokens,index+1);
        }
        else if( BarDeleteStates[State] == "NAME"){
            if( TokenKey_KeyList["IDENTIFIERS"].contains( Tokens[index], Qt::CaseInsensitive ) ){
                QueryData["BARGRAPH_NAMES"] << RawTokens[index];
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_BARGRAPH_DELETE_QUERY",REPLWIN);
                else BarDeleteCmd(State+1,Tokens,index+1);
            }else{
                ER.PrintError(RawTokens,index,"INVALID_BARGRAPH_NAME",REPLWIN);
            }
        }else{
            ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
        }
    }
}
void Automata::BarRenameCmd(int State, StrList Tokens, int index){
    if( BarRenameStates[State] == ";" && Tokens[index] == ";" ){
        if( index == Tokens.size() - 1 ) QE.ChangeBargraphName(REPLWIN,QueryData);
        else ER.PrintError(RawTokens,index,"INCOMPLETE_BARGRAPH_QUERY",REPLWIN);
    }
    else if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_BARGRAPH_RENAME_QUERY",REPLWIN);
    else{
        if( Tokens[index] == BarRenameStates[State] ){
            if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_BARGRAPH_RENAME_QUERY",REPLWIN);
            else BarRenameCmd(State+1,Tokens,index+1);
        }
        else if( BarRenameStates[State] == "NAME"){
            if( TokenKey_KeyList["IDENTIFIERS"].contains( Tokens[index], Qt::CaseInsensitive ) ){
                QueryData["BARGRAPH_NAMES"] << RawTokens[index];
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_BARGRAPH_RENAME_QUERY",REPLWIN);
                else BarRenameCmd(State+1,Tokens,index+1);
            }else{
                ER.PrintError(RawTokens,index,"INVALID_BARGRAPH_NAME",REPLWIN);
            }
        }else if( BarRenameStates[State] == "NEWNAME"){
            if( TokenKey_KeyList["IDENTIFIERS"].contains( Tokens[index], Qt::CaseInsensitive ) ){
                QueryData["BARGRAPH_NAMES"] << RawTokens[index];
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_BARGRAPH_RENAME_QUERY",REPLWIN);
                else BarRenameCmd(State+1,Tokens,index+1);
            }else{
                ER.PrintError(RawTokens,index,"INVALID_BARGRAPH_NAME",REPLWIN);
            }
        }else{
            ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
        }
    }
}
void Automata::BarLinkCmd(int State, StrList Tokens, int index){
    if( Tokens[index] == BarLinkCommonStates[State] ){
        if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_BARGRAPH_LINK_QUERY",REPLWIN);
        else{
            if( BarLinkCommonStates[State] == "LINK" ){
                if( Tokens[index+1] == "REMOVE" ) BarLinkRemoveCmd(State+1,Tokens,index+1);
                else if( TokenKey_KeyList["IDENTIFIERS"].contains(Tokens[index+1], Qt::CaseInsensitive) ) BarLinkTableCmd(State+1,Tokens,index+1);
                else ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
            }
            else BarLinkCmd(State+1,Tokens,index+1);
        }
    }
    else ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
}
void Automata::BarLinkTableCmd(int State, StrList Tokens, int index){
    if( BarLinkTableStates[State] == ";" && Tokens[index] == ";" ){
        if( index == Tokens.size() - 1 ) QE.BarLinkWithTable(REPLWIN,QueryData);
        else ER.PrintError(RawTokens,index,"INVALID_BARGRAPH_QUERY",REPLWIN);
    }
    else if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_BARGRAPH_LINK_QUERY",REPLWIN);
    else if( Tokens[index] == BarLinkTableStates[State] ){
        if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_BARGRAPH_LINK_QUERY",REPLWIN);
        else BarLinkTableCmd(State+1,Tokens,index+1);
    }
    else if( BarLinkTableStates[State] == "BARNAME" ){
        QueryData["BARGRAPH_NAMES"] << RawTokens[index];
        if( TokenKey_KeyList["IDENTIFIERS"].contains(Tokens[index], Qt::CaseInsensitive) ) BarLinkTableCmd(State+1,Tokens,index+1);
        else ER.PrintError(RawTokens,index,"INVALID_BARGRAPH_NAME",REPLWIN);
    }
    else if( BarLinkTableStates[State] == "TABLENAME" ){
        QueryData["TABLE_NAMES"] << RawTokens[index];
        if( TokenKey_KeyList["IDENTIFIERS"].contains(Tokens[index], Qt::CaseInsensitive) ) BarLinkTableCmd(State+1,Tokens,index+1);
        else ER.PrintError(RawTokens,index,"INVALID_TABLE_NAME",REPLWIN);
    }
    else ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
}
void Automata::BarLinkRemoveCmd(int State, StrList Tokens, int index){
    if( BarRemoveLinkTableStates[State] == ";" && Tokens[index] == ";" ){
        if( index == Tokens.size() - 1 ) QE.BarUnlinkWithTable(REPLWIN,QueryData);
        else ER.PrintError(RawTokens,index,"INVALID_BARGRPAH_QUERY",REPLWIN);
    }
    else if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_BARGRAPH_LINK_QUERY",REPLWIN);
    else if( Tokens[index] == BarRemoveLinkTableStates[State] ){
        if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_BARGRAPH_LINK_QUERY",REPLWIN);
        else BarLinkRemoveCmd(State+1,Tokens,index+1);
    }
    else if( BarRemoveLinkTableStates[State] == "BARNAME" ){
        QueryData["BARGRAPH_NAMES"] << RawTokens[index];
        if( TokenKey_KeyList["IDENTIFIERS"].contains(Tokens[index], Qt::CaseInsensitive) ) BarLinkRemoveCmd(State+1,Tokens,index+1);
        else ER.PrintError(RawTokens,index,"INVALID_BAGRAPH_NAME",REPLWIN);
    }
    else ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
}
//// Linegraph
void Automata::LineCreateCmd(int State, StrList Tokens, int index){
    if( Tokens[index] == LineCreateCommonStates[State] ){
        if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_LINEGRAPH_CREATE_QUERY",REPLWIN);
        else LineCreateCmd(State+1,Tokens,index+1);
    }else if( LineCreateCommonStates[State] == "NAME"  ){
        if( TokenKey_KeyList["IDENTIFIERS"].contains(Tokens[index], Qt::CaseInsensitive) ){
            if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_LINEGRAPH_CREATE_QUERY",REPLWIN);
            else{
                QueryData["LINEGRAPH_NAMES"] << RawTokens[index];
                if( Tokens[index+1] == "FROM" ) LineCreateFromTableCmd(State+1,Tokens,index+1);
                else if( Tokens[index+1] == "{" ) LineCreateFromDataCmd(State+1,Tokens,index+1);
                else ER.PrintError(RawTokens,index,"INVALID_LINEGRAPH_QUERY",REPLWIN);
            }
        }else{
            ER.PrintError(RawTokens,index,"INVALID_LINEGRAPH_NAME",REPLWIN);
        }
    }
    else ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
}
void Automata::LineCreateFromTableCmd(int State, StrList Tokens, int index){
    if( LineFromTableStates[State] == ";" && Tokens[index] == ";" ){
        if( index == Tokens.size() - 1 ) QE.CreateLineFromTable(REPLWIN,QueryData);
        else ER.PrintError(RawTokens,index,"INVALID_LINEGRAPH_QUERY",REPLWIN);
    }
    else if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_LINEGRAPH_CREATE_QUERY",REPLWIN);
    else if( Tokens[index] == LineFromTableStates[State] ){
        if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_LINEGRAPH_CREATE_QUERY",REPLWIN);
        else LineCreateFromTableCmd(State+1,Tokens,index+1);
    }else if( LineFromTableStates[State] == "TABLENAME"  ){
        if( TokenKey_KeyList["IDENTIFIERS"].contains(Tokens[index], Qt::CaseInsensitive) ){
            QueryData["TABLE_NAMES"] << RawTokens[index];
            if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_LINEGRAPH_CREATE_QUERY",REPLWIN);
            else LineCreateFromTableCmd(State+1,Tokens,index+1);
        }else{
            ER.PrintError(RawTokens,index,"INVALID_LINEGRAPH_NAME",REPLWIN);
        }
    }
    else ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
}
void Automata::LineCreateFromDataCmd(int State, StrList Tokens, int index){
    if( LineCreateStates[State] == ";" && Tokens[index] == ";" ){
        if( index == Tokens.size() - 1 ) QE.CreateLinegraphFromData(REPLWIN,QueryData);
        else ER.PrintError(RawTokens,index,"INVALID_LINEGRAPH_QUERY",REPLWIN);
    }
    else if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_LINEGRAPH_CREATE_QUERY",REPLWIN);
    else if( Tokens[index] == LineCreateStates[State] ){
        if( LineCreateStates[State] == "," && LineCreateStates[State-1] == ")" ) LineCreateFromDataCmd(4,Tokens,index+1);
        else if( LineCreateStates[State] == ")" && Tokens[index+1] == "}" ) LineCreateFromDataCmd(10,Tokens,index+1);
        else{
            if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_LINEGRAPH_CREATE_QUERY",REPLWIN);
            else LineCreateFromDataCmd(State+1,Tokens,index+1);
        }
    }else if( LineCreateStates[State] == "X"  ){
        if( TokenKey_KeyList["DATA"].contains(Tokens[index], Qt::CaseInsensitive) && Tokens[index].startsWith("NUMERIC") ){
            QueryData["Xs"] << RawTokens[index];
            if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_LINEGRAPH_CREATE_QUERY",REPLWIN);
            else LineCreateFromDataCmd(State+1,Tokens,index+1);
        }else ER.PrintError(RawTokens,index,"EXPECTING_DATA",REPLWIN);
    }
    else if( LineCreateStates[State] == "Y"  ){
        if( TokenKey_KeyList["DATA"].contains(Tokens[index], Qt::CaseInsensitive) && Tokens[index].startsWith("NUMERIC") ){
            QueryData["Ys"] << RawTokens[index];
            if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_LINEGRAPH_CREATE_QUERY",REPLWIN);
            else LineCreateFromDataCmd(State+1,Tokens,index+1);
        }else ER.PrintError(RawTokens,index,"EXPECTING_DATA",REPLWIN);
    }
    else ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
}
void Automata::LineDisplayCmd(int State, StrList Tokens, int index){
//    "LINEGRAPH" , "DISPLAY" , "NAME" , ";"
    if( LineDisplayStates[State] == ";" && Tokens[index] == ";" ){
        if( index == Tokens.size() - 1 ) QE.DisplayLinegraph(REPLWIN,QueryData);
        else ER.PrintError(RawTokens,index,"INVALID_LINEGRAPH_QUERY",REPLWIN);
    }
    else if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_LINEGRAPH_DISPLAY_QUERY",REPLWIN);
    else{
        if( Tokens[index] == LineDisplayStates[State] ){
            if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_LINEGRAPH_DISPLAY_QUERY",REPLWIN);
            else LineDisplayCmd(State+1,Tokens,index+1);
        }
        else if( LineDisplayStates[State] == "NAME"){
            if( TokenKey_KeyList["IDENTIFIERS"].contains( Tokens[index], Qt::CaseInsensitive ) ){
                QueryData["LINEGRAPH_NAMES"] << RawTokens[index];
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_LINEGRAPH_DISPLAY_QUERY",REPLWIN);
                else LineDisplayCmd(State+1,Tokens,index+1);
            }else{
                ER.PrintError(RawTokens,index,"INVALID_LINEGRAPH_NAME",REPLWIN);
            }
        }else{
            ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
        }
    }
}
void Automata::LineDeleteCmd(int State, StrList Tokens, int index){
//    "LINEGRAPH" , "DELETE" , "NAME" ,  ";"
    if( LineDeleteStates[State] == ";" && Tokens[index] == ";" ){
        if( index == Tokens.size() - 1 ) QE.DeleteLinegraph(REPLWIN,QueryData);
        else ER.PrintError(RawTokens,index,"INVALID_LINEGRAPH_QUERY",REPLWIN);
    }
    else if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_LINEGRAPH_DELETE_QUERY",REPLWIN);
    else{
        if( Tokens[index] == LineDeleteStates[State] ){
            if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_LINEGRAPH_DELETE_QUERY",REPLWIN);
            else LineDeleteCmd(State+1,Tokens,index+1);
        }
        else if( LineDeleteStates[State] == "NAME"){
            if( TokenKey_KeyList["IDENTIFIERS"].contains( Tokens[index], Qt::CaseInsensitive ) ){
                QueryData["LINEGRAPH_NAMES"] << RawTokens[index];
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_LINEGRAPH_DELETE_QUERY",REPLWIN);
                else LineDeleteCmd(State+1,Tokens,index+1);
            }else{
                ER.PrintError(RawTokens,index,"INVALID_LINEGRAPH_NAME",REPLWIN);
            }
        }else{
            ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
        }
    }
}
void Automata::LineRenameCmd(int State, StrList Tokens, int index){
    if( LineRenameStates[State] == ";" && Tokens[index] == ";" ){
        if( index == Tokens.size() - 1 ) QE.ChangeLinegraphName(REPLWIN,QueryData);
        else ER.PrintError(RawTokens,index,"INVALID_LINEGRAPH_QUERY",REPLWIN);
    }
    else if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_LINEGRAPH_RENAME_QUERY",REPLWIN);
    else{
        if( Tokens[index] == LineRenameStates[State] ){
            if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_LINEGRAPH_RENAME_QUERY",REPLWIN);
            else LineRenameCmd(State+1,Tokens,index+1);
        }
        else if( LineRenameStates[State] == "NAME"){
            if( TokenKey_KeyList["IDENTIFIERS"].contains( Tokens[index], Qt::CaseInsensitive ) ){
                QueryData["LINEGRAPH_NAMES"] << RawTokens[index];
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_LINEGRAPH_RENAME_QUERY",REPLWIN);
                else LineRenameCmd(State+1,Tokens,index+1);
            }else{
                ER.PrintError(RawTokens,index,"INVALID_LINEGRAPH_NAME",REPLWIN);
            }
        }else if( LineRenameStates[State] == "NEWNAME"){
            if( TokenKey_KeyList["IDENTIFIERS"].contains( Tokens[index], Qt::CaseInsensitive ) ){
                QueryData["LINEGRAPH_NAMES"] << RawTokens[index];
                if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_LINEGRAPH_RENAME_QUERY",REPLWIN);
                else LineRenameCmd(State+1,Tokens,index+1);
            }else{
                ER.PrintError(RawTokens,index,"INVALID_LINEGRAPH_NAME",REPLWIN);
            }
        }else{
            ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
        }
    }
}
void Automata::LineLinkCmd(int State, StrList Tokens, int index){
    if( Tokens[index] == LineLinkCommonStates[State] ){
        if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_LINEGRAPH_LINK_QUERY",REPLWIN);
        else{
            if( LineLinkCommonStates[State] == "LINK" ){
                if( Tokens[index+1] == "REMOVE" ) LineLinkRemoveCmd(State+1,Tokens,index+1);
                else if( TokenKey_KeyList["IDENTIFIERS"].contains(Tokens[index+1], Qt::CaseInsensitive) ) LineLinkTableCmd(State+1,Tokens,index+1);
                else ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
            }
            else LineLinkCmd(State+1,Tokens,index+1);
        }
    }
    else ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
}
void Automata::LineLinkTableCmd(int State, StrList Tokens, int index){
    if( LineLinkTableStates[State] == ";" && Tokens[index] == ";" ){
        if( index == Tokens.size() - 1 ) QE.LineLinkWithTable(REPLWIN,QueryData);
        else ER.PrintError(RawTokens,index,"INVALID_LINEGRAPH_QUERY",REPLWIN);
    }
    else if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_LINEGRAPH_RENAME_QUERY",REPLWIN);
    else if( Tokens[index] == LineLinkTableStates[State] ){
        if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_LINEGRAPH_RENAME_QUERY",REPLWIN);
        else LineLinkTableCmd(State+1,Tokens,index+1);
    }
    else if( LineLinkTableStates[State] == "LINENAME" ){
        QueryData["LINEGRAPH_NAMES"] << RawTokens[index];
        if( TokenKey_KeyList["IDENTIFIERS"].contains(Tokens[index], Qt::CaseInsensitive) ) LineLinkTableCmd(State+1,Tokens,index+1);
        else ER.PrintError(RawTokens,index,"INVALID_LINEGRAPH_NAME",REPLWIN);
    }
    else if( LineLinkTableStates[State] == "TABLENAME" ){
        QueryData["TABLE_NAMES"] << RawTokens[index];
        if( TokenKey_KeyList["IDENTIFIERS"].contains(Tokens[index], Qt::CaseInsensitive) ) LineLinkTableCmd(State+1,Tokens,index+1);
        else ER.PrintError(RawTokens,index,"INVALID_TABLE_NAME",REPLWIN);
    }
    else ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
}
void Automata::LineLinkRemoveCmd(int State, StrList Tokens, int index){
    if( LineRemoveLinkTableStates[State] == ";" && Tokens[index] == ";" ){
        if( index == Tokens.size() - 1 ) QE.LineUnlinkWithTable(REPLWIN,QueryData);
        else ER.PrintError(RawTokens,index,"INVALID_LINEGRAPH_QUERY",REPLWIN);
    }
    else if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_LINEGRAPH_RENAME_QUERY",REPLWIN);
    else if( Tokens[index] == LineRemoveLinkTableStates[State] ){
        if( index == Tokens.size() - 1 ) ER.PrintError(RawTokens,index,"INCOMPLETE_LINEGRAPH_RENAME_QUERY",REPLWIN);
        else LineLinkRemoveCmd(State+1,Tokens,index+1);
    }
    else if( LineRemoveLinkTableStates[State] == "LINENAME" ){
        QueryData["LINEGRAPH_NAMES"] << RawTokens[index];
        if( TokenKey_KeyList["IDENTIFIERS"].contains(Tokens[index], Qt::CaseInsensitive) ) LineLinkRemoveCmd(State+1,Tokens,index+1);
        else ER.PrintError(RawTokens,index,"INVALID_LINEGRAPH_NAME",REPLWIN);
    }
    else ER.PrintError(RawTokens,index,"UNKNOWN_TOKEN",REPLWIN);
}

void Automata::StartAutomata(StrList Tokens, StrList TokensRaw, MapStrStrList TokenKey_KeyList, MapStrStr Key_KeyValue, QTextEdit *REPLWIN, QVector<QString>* CHV ){
    this->REPLWIN = REPLWIN;
    RawTokens = TokensRaw;
    if( Tokens.size() > 1 ){
        this->TokenKey_KeyList = TokenKey_KeyList;
        this->Key_KeyValue = Key_KeyValue;
        if( Tokens[0] == "LANG" ){
            if( !LangCommandStatus ) InitializeQueryStates("LANG");
            if( Tokens[1] == "DISPLAY" ) LangDisplayCmd(0,Tokens,0);
            else if( Tokens[1] == "=" ) ChangeLangCmd(0,Tokens,0);
            else ER.PrintError(RawTokens,0,"INVALID_LANG_QUERY",REPLWIN);
        }
        else if( Tokens[0] == "ENV" ){
            if( !EnvCommandStatus ) InitializeQueryStates("ENV");
            if( Tokens[1] == "SCREEN" ) EnvClearScreenCmd(0,Tokens,0);
            else if( Tokens[1] == "EXIT" ) EnvExitCmd(0,Tokens,0);
            else if( Tokens[1] == "HISTORY" ) EnvClearHistoryCmd(0,Tokens,0,CHV);
            else if( Tokens[1] == "MEAN" ) EnvMeanCmd(0,Tokens,0);
            else if( Tokens[1] == "MODE" ) EnvModeCmd(0,Tokens,0);
            else if( Tokens[1] == "MEDIAN" ) EnvMedianCmd(0,Tokens,0);
            else if( Tokens[1] == "SUM" ) EnvSumCmd(0,Tokens,0);
            else if( Tokens[1] == "MAX" ) EnvMaxCmd(0,Tokens,0);
            else if( Tokens[1] == "MIN" ) EnvMinCmd(0,Tokens,0);
            else if( Tokens[1] == "AVG" ) EnvAvgCmd(0,Tokens,0);
            else if( Tokens[1] == "SD" ) EnvSDCmd(0,Tokens,0);
            else if( Tokens[1] == "VARIENCE" ) EnvVarienceCmd(0,Tokens,0);
            else if( Tokens[1] == "FREQUENCY" ) EnvFrequencyCmd(0,Tokens,0);
            else ER.PrintError(RawTokens,0,"INVALID_ENV_QUERY",REPLWIN);
        }
        else if( Tokens[0] == "DATASTORE" ){
            if( !DatastoreCommandStatus ) InitializeQueryStates("DATASTORE");
            if( Tokens[1] == "LIST" ) DatastoreListCmd(0,Tokens,0);
            else if( Tokens[1] == "CREATE" ) DatastoreCreateCmd(0,Tokens,0);
            else if( Tokens[1] == "DELETE" ) DatastoreDeleteCmd(0,Tokens,0);
            else if( Tokens[1] == "CLEAR" ) DatastoreClearCmd(0,Tokens,0);
            else if( Tokens[1] == "RENAME" ) DatastoreRenameCmd(0,Tokens,0);
            else if( Tokens[1] == "USE" ) DatastoreUseCmd(0,Tokens,0);
            else if( Tokens[1] == "DISPLAY" ) DatastoreDisplayCmd(0,Tokens,0);
            else if( Tokens[1] == "COUNT" ) DatastoreCountCmd(0,Tokens,0);
            else ER.PrintError(RawTokens,0,"INVALID_DATASTORE_QUERY",REPLWIN);
        }
        else if( Tokens[0] == "TABLE" ){
            if( !TableCommandStatus ) InitializeQueryStates("TABLE");
            if( Tokens[1] == "CREATE" ) TableCreateCmd(0,Tokens,0);
            else if( Tokens[1] == "INSERT" ) TableInsertCmd(0,Tokens,0);
            else if( Tokens[1] == "CHANGE" ) TableChangeCmd(0,Tokens,0);
            else if( Tokens[1] == "ADD" ) TableAddCmd(0,Tokens,0);
            else if( Tokens[1] == "RENAME" ) TableRenameCmd(0,Tokens,0);
            else if( Tokens[1] == "CLEAR" ) TableClearCmd(0,Tokens,0);
            else if( Tokens[1] == "DISPLAY" ) TableDisplayCmd(0,Tokens,0);
            else if( Tokens[1] == "ORDER" ) TableOrderDisplayCmd(0,Tokens,0);
            else if( Tokens[1] == "UPDATE" ) TableUpdateCmd(0,Tokens,0);
            else if( Tokens[1] == "DELETE" ) TableDeleteCmd(0,Tokens,0);
            else if( Tokens[1] == "CAL" ) TableCalCmd(0,Tokens,0);
            else ER.PrintError(RawTokens,0,"INVALID_TABLE_QUERY",REPLWIN);
        }
        else if( Tokens[0] == "PIECHART" ){
            if( !PiechartCommandStatus ) InitializeQueryStates("PIECHART");
            if( Tokens[1] == "CREATE" ) PieCreateCmd(0,Tokens,0);
            else if( Tokens[1] == "DISPLAY" ) PieDisplayCmd(0,Tokens,0);
            else if( Tokens[1] == "DELETE" ) PieDeleteCmd(0,Tokens,0);
            else if( Tokens[1] == "RENAME" ) PieRenameCmd(0,Tokens,0);
            else if( Tokens[1] == "LINK" ) PieLinkCmd(0,Tokens,0);
            else ER.PrintError(RawTokens,0,"INVALID_PIECHART_QUERY",REPLWIN);
        }
        else if( Tokens[0] == "BARGRAPH" ){
            if( !BargraphCommandStatus ) InitializeQueryStates("BARGRAPH");
            if( Tokens[1] == "CREATE" ) BarCreateCmd(0,Tokens,0);
            else if( Tokens[1] == "DISPLAY" ) BarDisplayCmd(0,Tokens,0);
            else if( Tokens[1] == "DELETE" ) BarDeleteCmd(0,Tokens,0);
            else if( Tokens[1] == "RENAME" ) BarRenameCmd(0,Tokens,0);
            else if( Tokens[1] == "LINK" ) BarLinkCmd(0,Tokens,0);
            else ER.PrintError(RawTokens,0,"INVALID_BARGRAPH_QUERY",REPLWIN);
        }
        else if( Tokens[0] == "LINEGRAPH" ){
            if( !LinegraphCommandStatus ) InitializeQueryStates("LINEGRAPH");
            if( Tokens[1] == "CREATE" ) LineCreateCmd(0,Tokens,0);
            else if( Tokens[1] == "DISPLAY" ) LineDisplayCmd(0,Tokens,0);
            else if( Tokens[1] == "DELETE" ) LineDeleteCmd(0,Tokens,0);
            else if( Tokens[1] == "RENAME" ) LineRenameCmd(0,Tokens,0);
            else if( Tokens[1] == "LINK" ) LineLinkCmd(0,Tokens,0);
            else ER.PrintError(RawTokens,0,"INVALID_LINEGRAPH_QUERY",REPLWIN);
        }
        else ER.PrintError(RawTokens,0,"UNKNOWN_QUERY",REPLWIN);
        EmptyMaps();
    }else ER.PrintError(RawTokens,0,"UNKNOWN_QUERY",REPLWIN);
}
#endif // AUTOMATA_H
