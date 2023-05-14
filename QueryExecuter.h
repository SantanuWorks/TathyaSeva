#ifndef QUERYEXECUTER_H
#define QUERYEXECUTER_H
#include <QApplication>
#include <QTextEdit>
#include "FileHandler.h"
#include "LanguageUtil.h"

Language LANG;
FileHandler FL;

typedef QMap<QString,QStringList> MapStrStrList ;

class QueryExecuter{
public:
    void DisplayEnvLang(QTextEdit* REPLWIN);
    void DisplayDatastoreList( QTextEdit* REPLWIN );
    void CreateDatastore( QTextEdit* REPLWIN, QString Name);
    void DeleteNormalDatastore( QTextEdit* REPLWIN, QString Name );
    void DeleteForceDatastore( QTextEdit* REPLWIN, QString Name );
    void ClearDatastore( QTextEdit* REPLWIN, QString Name );
    void ClearSelectedDatastore( QTextEdit* REPLWIN, MapStrStrList QueryData );
    void RenameDatastore(QTextEdit* REPLWIN, MapStrStrList QueryData);
    void DisplayDatstoreAll(QTextEdit* REPLWIN, MapStrStrList QueryData);
    void DisplayDatstoreTables(QTextEdit* REPLWIN, MapStrStrList QueryData);
    void DisplayDatstorePiecharts(QTextEdit* REPLWIN, MapStrStrList QueryData);
    void DisplayDatstoreBargraphs(QTextEdit* REPLWIN, MapStrStrList QueryData);
    void DisplayDatstoreLinegraphs(QTextEdit* REPLWIN, MapStrStrList QueryData);
    void ChangeCurrentDS(QTextEdit* REPLWIN, MapStrStrList QueryData);
    void DisplayCurrentDS(QTextEdit* REPLWIN);
    void DisplayCountStructs(QTextEdit* REPLWIN, QString StructName, MapStrStrList QueryData);
    void CloseApp();
    void ClearScreen(QTextEdit* REPLWIN);
    void ClearCHV(QTextEdit* REPLWIN, QVector<QString>* CHV);
    void CreateTable(QTextEdit* REPLWIN, MapStrStrList QueryData);
    void InsertIntoTable(QTextEdit* REPLWIN, MapStrStrList QueryData);
    void ChangeTableCol(QTextEdit* REPLWIN, MapStrStrList QueryData);
    void AddNewCol(QTextEdit* REPLWIN, MapStrStrList QueryData);
    void ChangeTableName(QTextEdit* REPLWIN, MapStrStrList QueryData);
    void ChangeTableColName(QTextEdit* REPLWIN, MapStrStrList QueryData);
    void ClearTable(QTextEdit* REPLWIN, MapStrStrList QueryData);
    void ClearTableCols(QTextEdit* REPLWIN, MapStrStrList QueryData);
    void DisplayTable(QTextEdit* REPLWIN, MapStrStrList QueryData);
    void DisplayTableMetaData(QTextEdit* REPLWIN, MapStrStrList QueryData);
    void DisplayTableMetaStructure(QTextEdit* REPLWIN, MapStrStrList TableData);
    void DisplayTableCols(QTextEdit* REPLWIN, MapStrStrList TableData);
    void DeleteTable(QTextEdit* REPLWIN, MapStrStrList QueryData);
    void DeleteTableCols(QTextEdit* REPLWIN, MapStrStrList QueryData);
    void CreatePieFromTable(QTextEdit* REPLWIN, MapStrStrList QueryData);
    void CreateBarFromTable(QTextEdit* REPLWIN, MapStrStrList QueryData);
    void CreateLineFromTable(QTextEdit* REPLWIN, MapStrStrList QueryData);
    void CreatePiechartFromData(QTextEdit* REPLWIN, MapStrStrList QueryData);
    void CreateBargraphFromData(QTextEdit* REPLWIN, MapStrStrList QueryData);
    void CreateLinegraphFromData(QTextEdit* REPLWIN, MapStrStrList QueryData);
    void ChangePiechartName(QTextEdit* REPLWIN, MapStrStrList QueryData);
    void ChangeBargraphName(QTextEdit* REPLWIN, MapStrStrList QueryData);
    void ChangeLinegraphName(QTextEdit* REPLWIN, MapStrStrList QueryData);
    void DeletePiechart(QTextEdit* REPLWIN, MapStrStrList QueryData);
    void DeleteBargraph(QTextEdit* REPLWIN, MapStrStrList QueryData);
    void DeleteLinegraph(QTextEdit* REPLWIN, MapStrStrList QueryData);
    void PieLinkWithTable(QTextEdit* REPLWIN, MapStrStrList QueryData);
    void BarLinkWithTable(QTextEdit* REPLWIN, MapStrStrList QueryData);
    void LineLinkWithTable(QTextEdit* REPLWIN, MapStrStrList QueryData);
    void PieUnlinkWithTable(QTextEdit* REPLWIN, MapStrStrList QueryData);
    void BarUnlinkWithTable(QTextEdit* REPLWIN, MapStrStrList QueryData);
    void LineUnlinkWithTable(QTextEdit* REPLWIN, MapStrStrList QueryData);
    bool ChartToImage(QChartView *ChartView, QString Name, QString ChartType);
    void DisplayStructImg(QString Sname,QTextEdit* REPLWIN);
    void DisplayPiechart(QTextEdit* REPLWIN, MapStrStrList QueryData);
    void DisplayBargraph(QTextEdit* REPLWIN, MapStrStrList QueryData);
    void DisplayLinegraph(QTextEdit* REPLWIN, MapStrStrList QueryData);

    void EnvCalculateMean(QTextEdit* REPLWIN, MapStrStrList QueryData, QString OPname);
    void EnvCalculateMode(QTextEdit* REPLWIN, MapStrStrList QueryData, QString OPname);
    void EnvCalculateMedian(QTextEdit* REPLWIN, MapStrStrList QueryData, QString OPname);
    void EnvCalculateSum(QTextEdit* REPLWIN, MapStrStrList QueryData, QString OPname);
    void EnvCalculateMin(QTextEdit* REPLWIN, MapStrStrList QueryData, QString OPname);
    void EnvCalculateMax(QTextEdit* REPLWIN, MapStrStrList QueryData, QString OPname);
    void EnvCalculateAvg(QTextEdit* REPLWIN, MapStrStrList QueryData, QString OPname);
    void EnvCalculateSD(QTextEdit* REPLWIN, MapStrStrList QueryData, QString OPname);
    void EnvCalculateVarience(QTextEdit* REPLWIN, MapStrStrList QueryData, QString OPname);
    void EnvCalculateFrequencyData(QTextEdit* REPLWIN, MapStrStrList QueryData, QString OPname);
    void EnvCalculateFrequencyTable(QTextEdit* REPLWIN, MapStrStrList QueryData);
    void EnvCalculateFrequencyTables(QTextEdit* REPLWIN, MapStrStrList QueryData);
    void EnvCalculateCount(QTextEdit* REPLWIN, StrList list, QString OPname );

    void TableOrderDisplayTable(QTextEdit* REPLWIN, MapStrStrList QueryData);
    void TableOrderDisplayTableCols(QTextEdit* REPLWIN, MapStrStrList QueryData);

    void TableCalculateSum(QTextEdit* REPLWIN, MapStrStrList QueryData);
    void TableCalculateCount(QTextEdit* REPLWIN, MapStrStrList QueryData);
    void TableCalculateAvg(QTextEdit* REPLWIN, MapStrStrList QueryData);
    void TableCalculateMin(QTextEdit* REPLWIN, MapStrStrList QueryData);
    void TableCalculateMax(QTextEdit* REPLWIN, MapStrStrList QueryData);
    void TableCalculateMean(QTextEdit* REPLWIN, MapStrStrList QueryData);
    void TableCalculateMode(QTextEdit* REPLWIN, MapStrStrList QueryData);
    void TableCalculateMedian(QTextEdit* REPLWIN, MapStrStrList QueryData);
    void TableCalculateFrequency(QTextEdit* REPLWIN, MapStrStrList QueryData);
    void TableCalculateSD(QTextEdit* REPLWIN, MapStrStrList QueryData);
    void TableCalculateVarience(QTextEdit* REPLWIN, MapStrStrList QueryData);

    void DisplayOP( QString OPname, double ans , QTextEdit* REPLWIN );
    void DisplayOP( QString OPname, QMap<QString,int> ans , QTextEdit* REPLWIN );
    void DisplayOP( QString OPname, int ans , QTextEdit* REPLWIN );
    void DisplayOP(QString OPname, QString ans, QTextEdit* REPLWIN);

    void ReadyAppAttrs(QTextEdit* REPLWIN);
    void ChangeLang(QTextEdit* REPLWIN, MapStrStrList QueryData);
};
void QueryExecuter::DisplayEnvLang(QTextEdit *REPLWIN){
    QString EnvLang = FL.GetEnvLang();
    if( EnvLang == "" ) ER.PrintSysGenError("FILEHANDLER_ERROR",REPLWIN);
    else REPLWIN->append("Environment Language: "+EnvLang);
}
void QueryExecuter::DisplayDatastoreList(QTextEdit *REPLWIN){
    StrList DirNames = FL.GetDirList();
    int count = DirNames.count();
    if( count > 0 ){
        for( auto EachDir : DirNames ) REPLWIN->append(EachDir);
        REPLWIN->append("Datastores Found: "+QString::number(count));
    }
    else REPLWIN->append("Datastores Found: 0");
}
void QueryExecuter::CreateDatastore(QTextEdit *REPLWIN, QString Name){
    if(FL.isDirExits(Name)) ER.PrintError(QStringList(Name),0,"DATASTORE_EXISTS",REPLWIN);
    else{
        if(FL.CreateDir(Name)) REPLWIN->append(Name+" datastore created successfully!");
        else ER.PrintSysGenError("FILEHANDLER_CREATE_ERROR",REPLWIN);
    }
}
void QueryExecuter::DeleteNormalDatastore(QTextEdit *REPLWIN, QString Name){
    if(!FL.isDirExits(Name)) ER.PrintError(QStringList(Name),0,"DATASTORE_NOT_EXISTS",REPLWIN);
    else{
        if(FL.DeleteDir(Name)) REPLWIN->append(Name+" datastore deleted successfully!");
        else{
            ER.PrintSysGenError("FILEHANDLER_REMOVE_ERROR",REPLWIN);
            ER.DatastoreDeleteSuggestionMessage(REPLWIN);
        }
    }
}
void QueryExecuter::DeleteForceDatastore(QTextEdit *REPLWIN, QString Name){
    if(!FL.isDirExits(Name)) ER.PrintError(QStringList(Name),0,"DATASTORE_NOT_EXISTS",REPLWIN);
    else{
        if(FL.DeleteForceDir(Name)) REPLWIN->append(Name+" datastore deleted successfully!");
        else ER.PrintSysGenError("FILEHANDLER_REMOVE_ERROR",REPLWIN);
    }
}
void QueryExecuter::ClearDatastore(QTextEdit *REPLWIN, QString Name){
    if(!FL.isDirExits(Name)) ER.PrintError(QStringList(Name),0,"DATASTORE_NOT_EXISTS",REPLWIN);
    else{
        if(FL.isEmptyDir(Name)){
            REPLWIN->append(Name+" datastore is empty!");
        }
        else{
            if(FL.ClearDir(Name)) REPLWIN->append(Name+" datastore cleared successfully!");
            else ER.PrintSysGenError("FILEHANDLER_REMOVE_ERROR",REPLWIN);
        }
    }
}
void QueryExecuter::ClearSelectedDatastore(QTextEdit *REPLWIN, MapStrStrList QueryData){
    QString DirName = QueryData["DATASTORE_NAMES"][0];
    QStringList StructList = QueryData["STRUCTURE_NAMES"];
    if(!FL.isDirExits(DirName)) ER.PrintError(QStringList(DirName),0,"DATASTORE_NOT_EXISTS",REPLWIN);
    else{
        if(FL.isEmptyDir(DirName)) REPLWIN->append(DirName+" datastore is empty!");
        else{
            for( auto Struct: StructList ){
                if(FL.ClearDirContent(DirName,Struct)) REPLWIN->append(Struct+" structure deleted successfully!");
                else ER.PrintSysGenError("FILEHANDLER_REMOVE_ERROR",REPLWIN);
            }
        }
    }
}
void QueryExecuter::RenameDatastore(QTextEdit *REPLWIN, MapStrStrList QueryData){
    QString OldDirName = QueryData["DATASTORE_NAMES"][0];
    QString NewDirName = QueryData["DATASTORE_NAMES"][1];
    if(FL.isDirExits(NewDirName)) ER.PrintError(QStringList(NewDirName),0,"DATASTORE_EXISTS",REPLWIN);
    else{
        if(FL.RenameDir(OldDirName,NewDirName)) REPLWIN->append(OldDirName+" renamed to "+NewDirName+"!");
        else ER.PrintSysGenError("FILEHANDLER_RENAME_ERROR",REPLWIN);
    }
}
void QueryExecuter::DisplayDatstoreAll(QTextEdit *REPLWIN, MapStrStrList QueryData){
    QString DirName = QueryData["DATASTORE_NAMES"][0];
    if(!FL.isDirExits(DirName)) ER.PrintError(QStringList(DirName),0,"DATASTORE_NOT_EXISTS",REPLWIN);
    else{
        StrList List = FL.GetDatastoreAll(DirName);
        if( List.isEmpty() ) REPLWIN->append(DirName+" is empty!");
        else{
            REPLWIN->append("Structures are");
            for( auto E:List ) REPLWIN->append(E);
            REPLWIN->append("Structues Found: "+QString::number(List.count()));
        }
    }
}
void QueryExecuter::DisplayDatstoreTables(QTextEdit *REPLWIN, MapStrStrList QueryData){
    QString DirName = QueryData["DATASTORE_NAMES"][0];
    if(!FL.isDirExits(DirName)) ER.PrintError(QStringList(DirName),0,"DATASTORE_NOT_EXISTS",REPLWIN);
    else{
        StrList List = FL.GetDatastoreTables(DirName);
        if( List.isEmpty() ) REPLWIN->append(DirName+" is empty!");
        else{
            REPLWIN->append("Tables are");
            for( auto E:List ) REPLWIN->append(E);
            REPLWIN->append("Tables Found: "+QString::number(List.count()));
        }
    }
}
void QueryExecuter::DisplayDatstorePiecharts(QTextEdit *REPLWIN, MapStrStrList QueryData){
    QString DirName = QueryData["DATASTORE_NAMES"][0];
    if(!FL.isDirExits(DirName)) ER.PrintError(QStringList(DirName),0,"DATASTORE_NOT_EXISTS",REPLWIN);
    else{
        StrList List = FL.GetDatastorePiecharts(DirName);
        if( List.isEmpty() ) REPLWIN->append(DirName+" is empty!");
        else{
            REPLWIN->append("Piecharts are");
            for( auto E:List ) REPLWIN->append(E);
            REPLWIN->append("Piecharts Found: "+QString::number(List.count()));
        }
    }
}
void QueryExecuter::DisplayDatstoreBargraphs(QTextEdit *REPLWIN, MapStrStrList QueryData){
    QString DirName = QueryData["DATASTORE_NAMES"][0];
    if(!FL.isDirExits(DirName)) ER.PrintError(QStringList(DirName),0,"DATASTORE_NOT_EXISTS",REPLWIN);
    else{
        StrList List = FL.GetDatastoreBargraphs(DirName);
        if( List.isEmpty() ) REPLWIN->append(DirName+" is empty!");
        else{
            REPLWIN->append("Bargraphs are");
            for( auto E:List ) REPLWIN->append(E);
            REPLWIN->append("Bargraphs Found: "+QString::number(List.count()));
        }
    }
}
void QueryExecuter::DisplayDatstoreLinegraphs(QTextEdit *REPLWIN, MapStrStrList QueryData){
    QString DirName = QueryData["DATASTORE_NAMES"][0];
    if(!FL.isDirExits(DirName)) ER.PrintError(QStringList(DirName),0,"DATASTORE_NOT_EXISTS",REPLWIN);
    else{
        StrList List = FL.GetDatastoreLinegraphs(DirName);
        if( List.isEmpty() ) REPLWIN->append(DirName+" is empty!");
        else{
            REPLWIN->append("Linegraphs are");
            for( auto E:List ) REPLWIN->append(E);
            REPLWIN->append("Linegraphs Found: "+QString::number(List.count()));
        }
    }
}
void QueryExecuter::ChangeCurrentDS(QTextEdit *REPLWIN, MapStrStrList QueryData){
    QString DirName = QueryData["DATASTORE_NAMES"][0];
    if(!FL.isDirExits(DirName)) ER.PrintError(QStringList(DirName),0,"DATASTORE_NOT_EXISTS",REPLWIN);
    else{
        if( FL.ChangeCurDS(DirName) ) REPLWIN->append("Datastore "+DirName+" is using!");
        else REPLWIN->append(DirName+" is already in use!");
    }
}
void QueryExecuter::DisplayCurrentDS(QTextEdit *REPLWIN){
    QString DirName = FL.GetCurrentDS();
    REPLWIN->append(DirName+" is in use!");
}
void QueryExecuter::DisplayCountStructs(QTextEdit *REPLWIN, QString StructName, MapStrStrList QueryData){
    QString DirName = QueryData["DATASTORE_NAMES"][0];
    int count = FL.CountDSStructs(DirName,StructName);
    REPLWIN->append(StructName+": "+QString::number(count));
}
void QueryExecuter::CloseApp(){
    exit(1);
}
void QueryExecuter::ClearScreen(QTextEdit *REPLWIN){
    REPLWIN->clear();
}
void QueryExecuter::ClearCHV(QTextEdit *REPLWIN, QVector<QString> *CHV){
    if( (*CHV).isEmpty() ) REPLWIN->append("Code history vector is empty!");
    else{
        (*CHV).clear();
        REPLWIN->append("Code history is cleared!");
    }
}
void QueryExecuter::CreateTable(QTextEdit *REPLWIN, MapStrStrList QueryData){
    QString TableName = QueryData["TABLE_NAMES"][0];
    StrList TableCols = QueryData["COL_NAMES"];
    StrList TableDtypes = QueryData["DATATYPES"];
    for( auto C:TableCols ){
        if( TableCols.count(C) > 1 ){
            REPLWIN->append(C+" duplicate column !");
            return;
        }
    }
    if( FL.isTableExist(TableName) ) ER.PrintError(QStringList(TableName),0,"TABLE_EXISTS",REPLWIN);
    else{
        FL.CreateTableFile(TableName,TableCols,TableDtypes);
        REPLWIN->append(TableName+" table created!");
    }
}
void QueryExecuter::InsertIntoTable(QTextEdit *REPLWIN, MapStrStrList QueryData){
    QString TableName = QueryData["TABLE_NAMES"][0];
    StrList Cols = QueryData["COL_NAMES"];
    StrList Values = QueryData["DATA"];
    for( auto C:Cols ){
        if( Cols.count(C) > 1 ){
            REPLWIN->append(C+" duplicate column !");
            return;
        }
    }
    StrList InvalidCols = FL.MatchColumns(TableName,Cols);
    if( !FL.isTableExist(TableName) ) ER.PrintError(QStringList(TableName),0,"TABLE_NOT_EXISTS",REPLWIN);
    else{
        if( FL.CountRows(TableName) != Cols.size()) ER.PrintError(QStringList(TableName),0,"INVALID_COUNT_ROW",REPLWIN);
        else if( !InvalidCols.isEmpty() ) ER.PrintError(QStringList(InvalidCols.join(" , ")),0,"INVALID_ROW",REPLWIN);
        else{
            StrList DefectedData = FL.SetTableDatatypes(TableName,Cols,Values);
            if( DefectedData.isEmpty() ) REPLWIN->append("Data inserted into table!");
            else ER.PrintError(QStringList(DefectedData.join(" , ")),0,"INVALID_ROW_DATA",REPLWIN);
        }
    }
}
void QueryExecuter::ChangeTableCol(QTextEdit *REPLWIN, MapStrStrList QueryData){
    QString Tname = QueryData["TABLE_NAMES"][0];
    StrList Cols = QueryData["COL_NAMES"];
    StrList DTypes = QueryData["DATATYPES"];
    for( auto C:Cols ){
        if( Cols.count(C) > 1 ){
            REPLWIN->append(C+" duplicate column !");
            return;
        }
    }
    StrList InvalidCols = FL.MatchColumns(Tname,Cols);
    if( !FL.isTableExist(Tname) ) ER.PrintError(QStringList(Tname),0,"TABLE_NOT_EXISTS",REPLWIN);
    else{
        if( !InvalidCols.isEmpty() ) ER.PrintError(QStringList(InvalidCols.join(" , ")),0,"INVALID_ROW",REPLWIN);
        else{
            FL.ChangeTableDatatypes(Tname,Cols,DTypes);
            REPLWIN->append("Table column types changed successfully!");
        }
    }
}
void QueryExecuter::AddNewCol(QTextEdit *REPLWIN, MapStrStrList QueryData){
    QString Tname = QueryData["TABLE_NAMES"][0];
    StrList Cols = QueryData["COL_NAMES"] ;
    StrList Types = QueryData["DATATYPES"] ;
    for( auto C:Cols ){
        if( Cols.count(C) > 1 ){
            REPLWIN->append(C+" duplicate column !");
            return;
        }
    }
    if( !FL.isTableExist(Tname) ) ER.PrintError(QStringList(Tname),0,"TABLE_NOT_EXISTS",REPLWIN);
    else{
        StrList RepeatCols = FL.FindRepeatCols(Tname,Cols);
        if( !RepeatCols.isEmpty()) ER.PrintError(RepeatCols,0,"DUPLICATE_COL",REPLWIN);
        else{
            FL.AddToTableFile(Tname,Cols,Types);
            REPLWIN->append("columns are added!");
        }
    }

}
void QueryExecuter::ChangeTableName(QTextEdit *REPLWIN, MapStrStrList QueryData){
    QString Old = QueryData["TABLE_NAMES"][0];
    QString New = QueryData["TABLE_NAMES"][1];
    if( !FL.isPiechartExist(Old) ) ER.PrintError(QStringList(Old),0,"TABLE_NOT_EXISTS",REPLWIN);
    else{
        if( FL.isTableExist(New) ) ER.PrintError(QStringList(New),0,"TABLE_EXISTS",REPLWIN);
        else{
            if( FL.RenameTable(Old,New) ) REPLWIN->append(Old+" changed to "+New+"!");
            else ER.PrintSysGenError("FILEHANDLER_RENAME_ERROR",REPLWIN);
        }
    }
}
void QueryExecuter::ChangeTableColName(QTextEdit *REPLWIN, MapStrStrList QueryData){
    QString Tname = QueryData["TABLE_NAMES"][0];
    StrList OldCols = QueryData["COL_NAMES"];
    StrList NewCols = QueryData["NEWCOL_NAMES"];
    StrList DuplicateCols = FL.FindRepeatCols(Tname,NewCols);
    if( !DuplicateCols.isEmpty() ) ER.PrintError(DuplicateCols,0,"DUPLICATE_COL",REPLWIN);
    else{
        FL.RenameTableCols(Tname,OldCols,NewCols);
        REPLWIN->append("column names are changed!");
    }
}
void QueryExecuter::ClearTable(QTextEdit *REPLWIN, MapStrStrList QueryData){
    QString Tname = QueryData["TABLE_NAMES"][0];
    if( !FL.isTableExist(Tname) ) ER.PrintError(QStringList(Tname),0,"TABLE_NOT_EXISTS",REPLWIN);
    else{
        if( FL.isEmptyTable(Tname) ) REPLWIN->append(Tname+" is empty!");
        else{
            FL.EmptyTableData(Tname);
            REPLWIN->append(Tname+" cleared successfully!");
        }
    }
}
void QueryExecuter::ClearTableCols(QTextEdit *REPLWIN, MapStrStrList QueryData){
    QString Tname = QueryData["TABLE_NAMES"][0];
    StrList Cols = QueryData["COL_NAMES"];
    if( !FL.isTableExist(Tname) ) ER.PrintError(QStringList(Tname),0,"TABLE_NOT_EXISTS",REPLWIN);
    else{
        StrList EmptyCols = FL.GetEmptyCols(Tname,Cols);
        if( !EmptyCols.isEmpty() ) REPLWIN->append(EmptyCols.join(" , ")+" empty column(s)!");
        else{
            FL.ClearColData(Tname,Cols);
            REPLWIN->append("column(s) cleared successfully!");
        }
    }
}

void QueryExecuter::DisplayTable(QTextEdit *REPLWIN, MapStrStrList QueryData){
    QString TableName = QueryData["TABLE_NAMES"][0];
    if( !FL.isTableExist(TableName) ) ER.PrintError(QStringList(TableName),0,"TABLE_NOT_EXISTS",REPLWIN);
    else{
        int CountRow = FL.GetRowCount(TableName);
        MapStrStrList TableData = FL.GetTableFileData(TableName);
        int CountCol = TableData.keys().size();
        QString A = "<br><table cellspacing='0' border='1' style='border-style:dashed;' ><tr><th style='padding:5px;' colspan='"+QString::number(CountCol)+"'>"+TableName+"</th></tr>" ;
        QString B ;
        QString C,Ci ;
        for( auto Col:TableData.keys() ) B = B + "<td style='padding:5px;'>"+Col+"</td>";
        QString D = "</table><br>";
        for( int i = 0 ; i < CountRow ; i++ ){
            for( auto Col:TableData.keys() ) Ci = Ci + "<td style='padding:5px;'>"+TableData[Col][i]+"</td>";
            C = C + "<tr>"+Ci+"</tr>";
            Ci = "";
        }
        REPLWIN->insertHtml(A+"<tr>"+B+"</tr>"+C+D);
    }
}
void QueryExecuter::DisplayTableMetaStructure(QTextEdit *REPLWIN, MapStrStrList TableData){
    QString ColHTML ;
    QString TypeHTML;
    QString Tname = TableData["TABLE_NAME"][0];
    QString Datastore = TableData["DATASTORE"][0];
    if( Datastore == FL.DEFAULT_DATASTORE_PATH ) Datastore = "Default";
    int Count = TableData["COUNT_COLS"][0].toInt();
    for( int i = 0 ; i < Count ; i ++ ) ColHTML = ColHTML + "<td style='padding:5px;'>"+TableData["COL_NAMES"][i]+"</td>";
    for( int i = 0 ; i < Count ; i ++ ) TypeHTML = TypeHTML + "<td style='padding:5px;'>"+TableData["DATATYPES"][i]+"</td>";
    QString A = "<br><table cellspacing='0' border='1' style='border-style:dashed;' ><tr><th style='padding:5px;' colspan='"+TableData["COUNT_COLS"][0]+"'>"+Tname+"</th></tr>" ;
    QString B = "<tr>"+ColHTML+"</tr>" ;
    QString C = "<tr>"+TypeHTML+"</tr>" ;
    QString D = "<tr><td style='padding:5px' colspan='"+TableData["COUNT_COLS"][0]+"' >Total Rows : "+TableData["COUNT_ROWS"][0]+"</td></tr>" ;
    QString E = "<tr><td style='padding:5px' colspan='"+TableData["COUNT_COLS"][0]+"' >Total Columns : "+TableData["COUNT_COLS"][0]+"</td></tr>" ;
    QString F = "<tr><td style='padding:5px' colspan='"+TableData["COUNT_COLS"][0]+"' >Creation Date : "+TableData["DOC"][0]+"</td></tr>" ;
    QString G = "<tr><td style='padding:5px' colspan='"+TableData["COUNT_COLS"][0]+"' >Datastore : "+Datastore+"</td></tr>" ;
    QString H = "</table><br>" ;
    REPLWIN->insertHtml(A+B+C+D+E+F+G+H);
}
void QueryExecuter::DisplayTableMetaData(QTextEdit *REPLWIN, MapStrStrList QueryData){
    QString Tname = QueryData["TABLE_NAMES"][0];
    if( !FL.isTableExist(Tname) ) ER.PrintError(QStringList(Tname),0,"TABLE_NOT_EXISTS",REPLWIN);
    else{
        MapStrStrList TableData = FL.GetTableData(Tname);
        DisplayTableMetaStructure(REPLWIN,TableData);
    }
}
void QueryExecuter::DisplayTableCols(QTextEdit *REPLWIN, MapStrStrList QueryData){
    QString Tname = QueryData["TABLE_NAMES"][0];
    StrList Cols = QueryData["COL_NAMES"];
    if( !FL.isTableExist(Tname) ) ER.PrintError(QStringList(Tname),0,"TABLE_NOT_EXISTS",REPLWIN);
    else{
        MapStrStrList TableData = FL.GetTableColData(Tname,Cols);
        int CountRow = FL.GetRowCount(Tname);
        int CountCol = TableData.keys().size();
        QString A = "<table cellspacing='0' border='1' style='border-style:dashed;' ><tr><th style='padding:5px;' colspan='"+QString::number(CountCol)+"'>"+Tname+"</th></tr>" ;
        QString B ;
        QString C,Ci ;
        for( auto Col:TableData.keys() ) B = B + "<td style='padding:5px;'>"+Col+"</td>";
        QString D = "</table>";
        for( int i = 0 ; i < CountRow ; i++ ){
            for( auto Col:TableData.keys() ) Ci = Ci + "<td style='padding:5px;'>"+TableData[Col][i]+"</td>";
            C = C + "<tr>"+Ci+"</tr>";
            Ci = "";
        }
        REPLWIN->insertHtml(A+"<tr>"+B+"</tr>"+C+D);
    }
}

void QueryExecuter::DeleteTable(QTextEdit *REPLWIN, MapStrStrList QueryData){
    QString Tname = QueryData["TABLE_NAMES"][0];
    if( !FL.isTableExist(Tname) ) ER.PrintError(QStringList(Tname),0,"TABLE_NOT_EXISTS",REPLWIN);
    else{
        if( FL.RemoveTable(Tname) ) REPLWIN->append(Tname+" deleted successfully!");
        else ER.PrintSysGenError("FILEHANDLER_REMOVE_ERROR",REPLWIN);
    }
}
void QueryExecuter::DeleteTableCols(QTextEdit *REPLWIN, MapStrStrList QueryData){
    QString Tname = QueryData["TABLE_NAMES"][0];
    StrList Cols = QueryData["COL_NAMES"];
    if( !FL.isTableExist(Tname) ) ER.PrintError(QStringList(Tname),0,"TABLE_NOT_EXISTS",REPLWIN);
    else{
        StrList NotPresentCols = FL.FindNotPresentCols(Tname,Cols);
        if( NotPresentCols.isEmpty() ){
            FL.RemoveTableCols(Tname,Cols);
            REPLWIN->append(Cols.join(" , ")+" column(s) deleted!");
        }else ER.PrintError(QStringList(NotPresentCols),0,"COL_NOT_EXISTS",REPLWIN);
    }
}
void QueryExecuter::CreatePieFromTable(QTextEdit *REPLWIN, MapStrStrList QueryData){
    QString Pname = QueryData["PIECHART_NAMES"][0];
    QString Tname = QueryData["TABLE_NAMES"][0];
    if( !FL.isTableExist(Tname) ) ER.PrintError(QStringList(Tname),0,"TABLE_NOT_EXISTS",REPLWIN);
    else{
        if( FL.isPiechartExist(Pname) ) ER.PrintError(QStringList(Pname),0,"PIECHART_EXISTS",REPLWIN);
        else{
            if( FL.GetColCount(Tname) != 2 ) ER.PrintError(QStringList(Tname),0,"NOT_BINARY_TABLE",REPLWIN);
            else{
                if( !FL.AtleastOneNumericCol(Tname) ) ER.PrintError(QStringList(Tname),0,"NUMERIC_COLUMN_NOT_EXIST",REPLWIN);
                else{
                    if( !FL.CreatePieFileFromTable(Pname,Tname) ) ER.PrintSysGenError("FILEHANDLER_REMOVE_ERROR",REPLWIN);
                    else REPLWIN->append(Pname+" piechart created successfully!");
                }
            }
        }
    }
}
void QueryExecuter::CreateBarFromTable(QTextEdit *REPLWIN, MapStrStrList QueryData){
    QString Bname = QueryData["BARGRAPH_NAMES"][0];
    QString Tname = QueryData["TABLE_NAMES"][0];
    if( !FL.isTableExist(Tname) ) ER.PrintError(QStringList(Tname),0,"TABLE_NOT_EXISTS",REPLWIN);
    else{
        if( FL.isBargraphExist(Bname) ) ER.PrintError(QStringList(Bname),0,"BARGRAPH_EXISTS",REPLWIN);
        else{
            if( FL.GetColCount(Tname) != 2 ) ER.PrintError(QStringList(Tname),0,"NOT_BINARY_TABLE",REPLWIN);
            else{
                if( !FL.AtleastOneNumericCol(Tname) ) ER.PrintError(QStringList(Tname),0,"NUMERIC_COLUMN_NOT_EXIST",REPLWIN);
                else{
                    if( !FL.CreateBarFileFromTable(Bname,Tname) ) ER.PrintSysGenError("FILEHANDLER_REMOVE_ERROR",REPLWIN);
                    else REPLWIN->append(Bname+" bargraph created successfully!");
                }
            }
        }
    }
}
void QueryExecuter::CreateLineFromTable(QTextEdit *REPLWIN, MapStrStrList QueryData){
    QString Lname = QueryData["LINEGRAPH_NAMES"][0];
    QString Tname = QueryData["TABLE_NAMES"][0];
    if( !FL.isTableExist(Tname) ) ER.PrintError(QStringList(Tname),0,"TABLE_NOT_EXISTS",REPLWIN);
    else{
        if( FL.isLinegraphExist(Lname) ) ER.PrintError(QStringList(Lname),0,"LINEGRAPH_EXISTS",REPLWIN);
        else{
            if( FL.GetColCount(Tname) != 2 ) ER.PrintError(QStringList(Tname),0,"NOT_BINARY_TABLE",REPLWIN);
            else{
                if( !FL.TwoNumericCol(Tname) ) ER.PrintError(QStringList(Tname),0,"NUMERIC_COLUMN_NOT_EXIST",REPLWIN);
                else{
                    if( !FL.CreateLineFileFromTable(Lname,Tname) ) ER.PrintSysGenError("FILEHANDLER_REMOVE_ERROR",REPLWIN);
                    else REPLWIN->append(Lname+" linegraph created successfully!");
                }
            }
        }
    }
}
void QueryExecuter::CreatePiechartFromData(QTextEdit *REPLWIN, MapStrStrList QueryData){
    QString Pname = QueryData["PIECHART_NAMES"][0];
    StrList Datanames = QueryData["DATANAMES"];
    StrList Datavaluess = QueryData["DATAVALS"];
    if( FL.isPiechartExist(Pname) ) ER.PrintError(QStringList(Pname),0,"PIECHART_EXISTS",REPLWIN);
    else{
        if( !FL.CreatePieFromData(Pname,Datanames,Datavaluess) ) ER.PrintSysGenError("FILEHANDLER_CREATE_ERROR",REPLWIN);
        else REPLWIN->append(Pname+" piechart created successfully!");
    }
}
void QueryExecuter::CreateBargraphFromData(QTextEdit *REPLWIN, MapStrStrList QueryData){
    QString Bname = QueryData["BARGRAPH_NAMES"][0];
    StrList Datanames = QueryData["DATANAMES"];
    StrList Datavaluess = QueryData["DATAVALS"];
    if( FL.isBargraphExist(Bname) ) ER.PrintError(QStringList(Bname),0,"BARGRAPH_EXISTS",REPLWIN);
    else{
        if( !FL.CreateBarFromData(Bname,Datanames,Datavaluess) ) ER.PrintSysGenError("FILEHANDLER_CREATE_ERROR",REPLWIN);
        else REPLWIN->append(Bname+" bargraph created successfully!");
    }
}
void QueryExecuter::CreateLinegraphFromData(QTextEdit *REPLWIN, MapStrStrList QueryData){
    QString Lname = QueryData["LINEGRAPH_NAMES"][0];
    StrList Datanames = QueryData["Xs"];
    StrList Datavaluess = QueryData["Ys"];
    if( FL.isLinegraphExist(Lname) ) ER.PrintError(QStringList(Lname),0,"LINEGRAPH_EXISTS",REPLWIN);
    else{
        if( !FL.CreateLineFromData(Lname,Datanames,Datavaluess) ) ER.PrintSysGenError("FILEHANDLER_CREATE_ERROR",REPLWIN);
        else REPLWIN->append(Lname+" linegraph created successfully!");
    }
}
void QueryExecuter::ChangePiechartName(QTextEdit *REPLWIN, MapStrStrList QueryData){
    QString Old = QueryData["PIECHART_NAMES"][0];
    QString New = QueryData["PIECHART_NAMES"][1];
    if( !FL.isPiechartExist(Old) ) ER.PrintError(QStringList(Old),0,"PIECHART_NOT_EXISTS",REPLWIN);
    else{
        if( FL.isPiechartExist(New) ) ER.PrintError(QStringList(New),0,"PIECHART_EXISTS",REPLWIN);
        else{
            if( FL.RenamePiechart(Old,New) ) REPLWIN->append(Old+" changed to "+New+"!");
            else ER.PrintSysGenError("FILEHANDLER_RENAME_ERROR",REPLWIN);
        }
    }
}
void QueryExecuter::ChangeBargraphName(QTextEdit *REPLWIN, MapStrStrList QueryData){
    QString Old = QueryData["BARGRAPH_NAMES"][0];
    QString New = QueryData["BARGRAPH_NAMES"][1];
    if( !FL.isBargraphExist(Old) ) ER.PrintError(QStringList(Old),0,"BARGRAPH_NOT_EXISTS",REPLWIN);
    else{
        if( FL.isBargraphExist(New) ) ER.PrintError(QStringList(New),0,"BARGRAPH_EXISTS",REPLWIN);
        else{
            if( FL.RenameBargraph(Old,New) ) REPLWIN->append(Old+" changed to "+New+"!");
            else ER.PrintSysGenError("FILEHANDLER_RENAME_ERROR",REPLWIN);
        }
    }
}
void QueryExecuter::ChangeLinegraphName(QTextEdit *REPLWIN, MapStrStrList QueryData){
    QString Old = QueryData["LINEGRAPH_NAMES"][0];
    QString New = QueryData["LINEGRAPH_NAMES"][1];
    if( !FL.isLinegraphExist(Old) ) ER.PrintError(QStringList(Old),0,"LINEGRAPH_NOT_EXISTS",REPLWIN);
    else{
        if( FL.isLinegraphExist(New) ) ER.PrintError(QStringList(New),0,"LINEGRAPH_EXISTS",REPLWIN);
        else{
            if( FL.RenameLinegraph(Old,New) ) REPLWIN->append(Old+" changed to "+New+"!");
            else ER.PrintSysGenError("FILEHANDLER_RENAME_ERROR",REPLWIN);
        }
    }
}
void QueryExecuter::DeletePiechart(QTextEdit *REPLWIN, MapStrStrList QueryData){
    QString Pname = QueryData["TABLE_NAMES"][0];
    if( !FL.isPiechartExist(Pname) ) ER.PrintError(QStringList(Pname),0,"PIECHART_NOT_EXISTS",REPLWIN);
    else{
        if( FL.RemovePiechart(Pname) ) REPLWIN->append(Pname+" deleted successfully!");
        else ER.PrintSysGenError("FILEHANDLER_REMOVE_ERROR",REPLWIN);
    }
}
void QueryExecuter::DeleteBargraph(QTextEdit *REPLWIN, MapStrStrList QueryData){
    QString Bname = QueryData["TABLE_NAMES"][0];
    if( !FL.isBargraphExist(Bname) ) ER.PrintError(QStringList(Bname),0,"BARGRAPH_NOT_EXISTS",REPLWIN);
    else{
        if( FL.RemoveBargraph(Bname) ) REPLWIN->append(Bname+" deleted successfully!");
        else ER.PrintSysGenError("FILEHANDLER_REMOVE_ERROR",REPLWIN);
    }
}
void QueryExecuter::DeleteLinegraph(QTextEdit *REPLWIN, MapStrStrList QueryData){
    QString Lname = QueryData["TABLE_NAMES"][0];
    if( !FL.isLinegraphExist(Lname) ) ER.PrintError(QStringList(Lname),0,"LINEGRAPH_NOT_EXISTS",REPLWIN);
    else{
        if( FL.RemoveLinegraph(Lname) ) REPLWIN->append(Lname+" deleted successfully!");
        else ER.PrintSysGenError("FILEHANDLER_REMOVE_ERROR",REPLWIN);
    }
}
void QueryExecuter::PieLinkWithTable(QTextEdit *REPLWIN, MapStrStrList QueryData){
    QString Pname = QueryData["PIECHART_NAMES"][0];
    QString Tname = QueryData["TABLE_NAMES"][0];
    if( !FL.isTableExist(Tname) ) ER.PrintError(QStringList(Tname),0,"TABLE_NOT_EXISTS",REPLWIN);
    else{
        if( !FL.isPiechartExist(Pname) ) ER.PrintError(QStringList(Pname),0,"PIECHART_NOT_EXISTS",REPLWIN);
        else{
            if( FL.GetColCount(Tname) != 2 ) ER.PrintError(QStringList(Tname),0,"NOT_BINARY_TABLE",REPLWIN);
            else{
                if( !FL.AtleastOneNumericCol(Tname) ) ER.PrintError(QStringList(Tname),0,"NUMERIC_COLUMN_NOT_EXIST",REPLWIN);
                else{
                    FL.StructLinkWithTable(Pname,Tname,"Piechart",REPLWIN);
                    REPLWIN->append(Pname+" linked with "+Tname);
                }
            }
        }
    }
}
void QueryExecuter::BarLinkWithTable(QTextEdit *REPLWIN, MapStrStrList QueryData){
    QString Bname = QueryData["BARGRAPH_NAMES"][0];
    QString Tname = QueryData["TABLE_NAMES"][0];
    if( !FL.isTableExist(Tname) ) ER.PrintError(QStringList(Tname),0,"TABLE_NOT_EXISTS",REPLWIN);
    else{
        if( !FL.isBargraphExist(Bname) ) ER.PrintError(QStringList(Bname),0,"BARGRAPH_NOT_EXISTS",REPLWIN);
        else{
            if( FL.GetColCount(Tname) != 2 ) ER.PrintError(QStringList(Tname),0,"NOT_BINARY_TABLE",REPLWIN);
            else{
                if( !FL.AtleastOneNumericCol(Tname) ) ER.PrintError(QStringList(Tname),0,"NUMERIC_COLUMN_NOT_EXIST",REPLWIN);
                else{
                    FL.StructLinkWithTable(Bname,Tname,"Bargraph",REPLWIN);
                    REPLWIN->append(Bname+" linked with "+Tname);
                }
            }
        }
    }
}
void QueryExecuter::LineLinkWithTable(QTextEdit *REPLWIN, MapStrStrList QueryData){
    QString Lname = QueryData["LINEGRAPH_NAMES"][0];
    QString Tname = QueryData["TABLE_NAMES"][0];
    if( !FL.isTableExist(Tname) ) ER.PrintError(QStringList(Tname),0,"TABLE_NOT_EXISTS",REPLWIN);
    else{
        if( !FL.isLinegraphExist(Lname) ) ER.PrintError(QStringList(Lname),0,"LINEGRAPH_NOT_EXISTS",REPLWIN);
        else{
            if( FL.GetColCount(Tname) != 2 ) ER.PrintError(QStringList(Tname),0,"NOT_BINARY_TABLE",REPLWIN);
            else{
                if( !FL.AtleastOneNumericCol(Tname) ) ER.PrintError(QStringList(Tname),0,"NUMERIC_COLUMN_NOT_EXIST",REPLWIN);
                else{
                    FL.StructLinkWithTable(Lname,Tname,"Linegraph",REPLWIN);
                    REPLWIN->append(Lname+" linked with "+Tname);
                }
            }
        }
    }
}
void QueryExecuter::PieUnlinkWithTable(QTextEdit *REPLWIN, MapStrStrList QueryData){
    QString Pname = QueryData["PIECHART_NAMES"][0];
    if( !FL.isPiechartExist(Pname) ) ER.PrintError(QStringList(Pname),0,"PIECHART_NOT_EXISTS",REPLWIN);
    else{
        FL.StructLinkWithTable(Pname,"","Piechart",REPLWIN);
        REPLWIN->append(Pname+" unlinked table!");
    }
}
void QueryExecuter::BarUnlinkWithTable(QTextEdit *REPLWIN, MapStrStrList QueryData){
    QString Bname = QueryData["BARGRAPH_NAMES"][0];
    if( !FL.isBargraphExist(Bname) ) ER.PrintError(QStringList(Bname),0,"BARGRAPH_NOT_EXISTS",REPLWIN);
    else{
        FL.StructLinkWithTable(Bname,"","Bargraph",REPLWIN);
        REPLWIN->append(Bname+" unlinked table!");
    }
}
void QueryExecuter::LineUnlinkWithTable(QTextEdit *REPLWIN, MapStrStrList QueryData){
    QString Lname = QueryData["LINEGRAPH_NAMES"][0];
    if( !FL.isLinegraphExist(Lname) ) ER.PrintError(QStringList(Lname),0,"LINEGRAPH_NOT_EXISTS",REPLWIN);
    else{
        FL.StructLinkWithTable(Lname,"","Linegraph",REPLWIN);
        REPLWIN->append(Lname+" unlinked table!");
    }
}
bool QueryExecuter::ChartToImage(QChartView *ChartView, QString Name, QString ChartType){
    QPixmap PixelMap = ChartView->grab();
    QOpenGLWidget *OpenGLW = ChartView->findChild<QOpenGLWidget *>();
    if( OpenGLW ){
        QPainter Painter(&PixelMap);
        QPoint Point = OpenGLW->mapToGlobal(QPoint()) - ChartView->mapToGlobal(QPoint());
        Painter.setCompositionMode(QPainter::CompositionMode_SourceAtop);
        Painter.drawImage(Point,OpenGLW->grabFramebuffer());
        Painter.end();
    }
    return PixelMap.save(ChartType+"___"+Name,"PNG");
}
void QueryExecuter::DisplayStructImg(QString SName,QTextEdit* REPLWIN){
    QString HtmlImg = "<br><img src='"+SName+"'><br>";
    REPLWIN->insertHtml(HtmlImg);
}
void QueryExecuter:: DisplayPiechart(QTextEdit* REPLWIN, MapStrStrList QueryData){
    QString Pname = QueryData["PIECHART_NAMES"][0];
    QString ChartType = "Piechart";
    QDir().remove(ChartType+"___"+Pname);
    if( !FL.isPiechartExist(Pname) ) ER.PrintError(QStringList(Pname),0,"PIECHART_NOT_EXISTS",REPLWIN);
    else{
        MapStrStr PieData = FL.GetStructData(Pname,"Piechart");
        if(!ChartToImage(FL.CreatePiechartView(Pname,PieData),Pname,"Piechart")) ER.PrintSysGenError("FILEHANDLER_REMOVE_ERROR",REPLWIN);
        else DisplayStructImg(ChartType+"___"+Pname,REPLWIN);
    }
}
void QueryExecuter:: DisplayBargraph(QTextEdit* REPLWIN, MapStrStrList QueryData){
    QString Bname = QueryData["BARGRAPH_NAMES"][0];
    QString ChartType = "Bargraph";
    QDir().remove(ChartType+"___"+Bname);
    if( !FL.isBargraphExist(Bname) ) ER.PrintError(QStringList(Bname),0,"BARGRAPH_NOT_EXISTS",REPLWIN);
    else{
        MapStrStr BarData = FL.GetStructData(Bname,ChartType);
        if(!ChartToImage(FL.CreateBargraphView(Bname,BarData),Bname,"Bargraph")) ER.PrintSysGenError("FILEHANDLER_REMOVE_ERROR",REPLWIN);
        else DisplayStructImg(ChartType+"___"+Bname,REPLWIN);
    }
}
void QueryExecuter::DisplayLinegraph(QTextEdit* REPLWIN, MapStrStrList QueryData){
    QString Lname = QueryData["LINEGRAPH_NAMES"][0];
    QString ChartType = "Linegraph";
    QDir().remove(ChartType+"___"+Lname);
    if( !FL.isLinegraphExist(Lname) ) ER.PrintError(QStringList(Lname),0,"LINEGRAPH_NOT_EXISTS",REPLWIN);
    else{
        MapStrStr LineData = FL.GetStructData(Lname,ChartType);
        if(!ChartToImage(FL.CreateLinegraphView(Lname,LineData),Lname,"Linegraph")) ER.PrintSysGenError("FILEHANDLER_REMOVE_ERROR",REPLWIN);
        else DisplayStructImg(ChartType+"___"+Lname,REPLWIN);
    }
}
void QueryExecuter::DisplayOP(QString OPname, double ans, QTextEdit* REPLWIN){
    QString A = "<br><table cellspacing='0' border='1' style='border-style:dashed;' ><tr><th style='padding:5px;'>"+OPname+"</th></tr>" ;
    QString B = "<tr><td style='padding:5px;'>"+QString::number(ans)+"</td></tr>" ;
    QString C = "</table><br>";
    REPLWIN->insertHtml(A+B+C);
}
void QueryExecuter::DisplayOP(QString OPname, QString ans, QTextEdit* REPLWIN){
    QString A = "<br><table cellspacing='0' border='1' style='border-style:dashed;' ><tr><th style='padding:5px;'>"+OPname+"</th></tr>" ;
    QString B = "<tr><td style='padding:5px;'>"+ans+"</td></tr>" ;
    QString C = "</table><br>";
    REPLWIN->insertHtml(A+B+C);
}
void QueryExecuter::DisplayOP( QString OPname, QMap<QString,int> ans , QTextEdit* REPLWIN ){
    QString A = "<br><table cellspacing='0' border='1' style='border-style:dashed;' ><tr><th style='padding:5px; colspan='2' '>"+OPname+"</th></tr><tr><th style='padding:5px;'>Data</th><th style='padding:5px;'>Frequency</th></tr></tr>" ;
    QString B = "" ;
    for( auto Da: ans.keys()) B = B + "<tr><td style='padding:5px;'>"+Da+"</td><td style='padding:5px;'>"+QString::number(ans[Da])+"</td></tr>";
    QString C = "</table><br>";
    REPLWIN->insertHtml(A+B+C);
}
void QueryExecuter::DisplayOP(QString OPname, int ans, QTextEdit* REPLWIN){
    QString A = "<br><table cellspacing='0' border='1' style='border-style:dashed;' ><tr><th style='padding:5px;'>"+OPname+"</th></tr>" ;
    QString B = "<tr><td style='padding:5px;'>"+QString::number(ans)+"</td></tr>" ;
    QString C = "</table><br>";
    REPLWIN->insertHtml(A+B+C);
}
void QueryExecuter::EnvCalculateMean(QTextEdit* REPLWIN, MapStrStrList QueryData, QString OPname = "MEAN"){
    StrList Datavals = QueryData["DATAVALS"] ;
    double Mean = FL.CalMean(Datavals);
    DisplayOP(OPname,Mean,REPLWIN);
}
void QueryExecuter::EnvCalculateMode(QTextEdit* REPLWIN, MapStrStrList QueryData,QString OPname = "MODE"){
    StrList Datavals = QueryData["DATAVALS"] ;
    double Mode = FL.CalMode(Datavals);
    if( Mode < 0 ) DisplayOP(OPname,"No Mode",REPLWIN);
    else DisplayOP(OPname,Mode,REPLWIN);
}
void QueryExecuter::EnvCalculateMedian(QTextEdit* REPLWIN, MapStrStrList QueryData, QString OPname = "MEDIAN"){
    StrList Datavals = QueryData["DATAVALS"] ;
    double Median = FL.CalMedian(Datavals);
    DisplayOP(OPname,Median,REPLWIN);
}
void QueryExecuter::EnvCalculateSum(QTextEdit* REPLWIN, MapStrStrList QueryData, QString OPname = "SUM"){
    StrList Datavals = QueryData["DATAVALS"] ;
    double Sum = FL.CalSum(Datavals);
    DisplayOP(OPname,Sum,REPLWIN);
}
void QueryExecuter::EnvCalculateMin(QTextEdit* REPLWIN, MapStrStrList QueryData, QString OPname = "MIN"){
    StrList Datavals = QueryData["DATAVALS"] ;
    double Min = FL.CalMin(Datavals);
    DisplayOP(OPname,Min,REPLWIN);
}
void QueryExecuter::EnvCalculateMax(QTextEdit* REPLWIN, MapStrStrList QueryData, QString OPname = "MAX"){
    StrList Datavals = QueryData["DATAVALS"] ;
    double Max = FL.CalMax(Datavals);
    DisplayOP(OPname,Max,REPLWIN);
}
void QueryExecuter::EnvCalculateAvg(QTextEdit* REPLWIN, MapStrStrList QueryData, QString OPname = "AVERAGE"){
    StrList Datavals = QueryData["DATAVALS"] ;
    double Avg = FL.CalAvg(Datavals);
    DisplayOP(OPname,Avg,REPLWIN);
}
void QueryExecuter::EnvCalculateSD(QTextEdit* REPLWIN, MapStrStrList QueryData, QString OPname = "STANDARD DEVIATION"){
    StrList Datavals = QueryData["DATAVALS"] ;
    double SD = FL.CalSD(Datavals);
    DisplayOP(OPname,SD,REPLWIN);
}
void QueryExecuter::EnvCalculateVarience(QTextEdit* REPLWIN, MapStrStrList QueryData, QString OPname = "VARIENCE"){
    StrList Datavals = QueryData["DATAVALS"] ;
    double Varience = FL.CalVarience(Datavals);
    DisplayOP(OPname,Varience,REPLWIN);
}
void QueryExecuter::EnvCalculateFrequencyData(QTextEdit* REPLWIN, MapStrStrList QueryData, QString OPname = "FREQUENCY"){
    StrList Datavals = QueryData["DATAVALS"] ;
    QMap<QString,int> DataFreq = FL.CalFrequency(Datavals);
    DisplayOP(OPname,DataFreq,REPLWIN);
}
void QueryExecuter::EnvCalculateCount(QTextEdit* REPLWIN, StrList list, QString OPname ){
    int count = list.size() ;
    DisplayOP(OPname,count,REPLWIN);
}
void QueryExecuter::EnvCalculateFrequencyTable(QTextEdit* REPLWIN, MapStrStrList QueryData){
    StrList Datavals = QueryData["DATAVALS"] ;
    QString Tname = QueryData["TABLE_NAMES"][0] ;
    if( FL.isTableExist(Tname) ) ER.PrintError(QStringList(Tname),0,"TABLE_EXISTS",REPLWIN);
    else{
        QMap<QString,int> DataFreq = FL.CalFrequency(Datavals);
        MapStrStrList QueryData;
        QueryData["TABLE_NAMES"] << Tname;
        QueryData["COL_NAMES"] << "Data" << "Frequency" ;
        QueryData["DATATYPES"] << "string" << "int";
        CreateTable(REPLWIN,QueryData);
        for( auto Key:DataFreq.keys() ){
            QueryData["DATA"] << "\""+Key+"\"" << (QString::number(DataFreq[Key])) ;
            InsertIntoTable(REPLWIN,QueryData);
            QueryData["DATA"] = {} ;
        }
    }
}
void QueryExecuter::EnvCalculateFrequencyTables(QTextEdit* REPLWIN, MapStrStrList QueryData){
    StrList Cols = QueryData["COL_NAMES"] ;
    StrList Tnames = QueryData["TABLE_NAMES"] ;
    QString Tname = QueryData["TABLENAME"][0] ;
    for( auto T:Tnames ){
        if( FL.isTableExist(T) ){
            ER.PrintError(QStringList(T),0,"TABLE_EXISTS",REPLWIN);
            return;
        }
    }
    if( !FL.isTableExist(Tname) ) ER.PrintError(QStringList(Tname),0,"TABLE_NOT_EXISTS",REPLWIN);
    else{
        MapStrStrList QueryData;
        MapStrStrList Col_Vals = FL.GetColsVals(Tname,Cols);
        for( int i = 0 ; i < Cols.size() ; i ++ ){
            QueryData["DATAVALS"] = Col_Vals[Cols[i]];
            QueryData["TABLE_NAMES"] << Tnames[i];
            EnvCalculateFrequencyTable(REPLWIN,QueryData);
            QueryData["DATAVALS"] = {};
            QueryData["TABLE_NAMES"] = {};
        }
    }
}

void QueryExecuter::TableOrderDisplayTable(QTextEdit* REPLWIN, MapStrStrList QueryData){
}
//    QString Tname = QueryData["TABLE_NAMES"][0] ;
//    StrList Cols = QueryData["COL_NAMES"] ;
//    StrList Odrs = QueryData["ORDERVALS"] ;
//    for( auto C:Cols ){
//        if( Cols.count(C) > 1 ){
//            REPLWIN->append(C+" duplicate column !");
//            return;
//        }
//    }
//    if( !FL.isTableExist(Tname) ) ER.PrintError(QStringList(Tname),0,"TABLE_NOT_EXISTS",REPLWIN);
//    else{
//        StrList InvalidCols = FL.MatchColumns(Tname,Cols);
//        if( !InvalidCols.isEmpty() ) ER.PrintError(QStringList(InvalidCols.join(" , ")),0,"INVALID_ROW",REPLWIN);
//        else{
//            MapStrStrList TableData = FL.GetTableFileData(Tname);
//            MapStrStrList SortedTableData = FL.SortBy(TableData,Cols,Odrs);
//        }
//    }
//}
void QueryExecuter::TableOrderDisplayTableCols(QTextEdit* REPLWIN, MapStrStrList QueryData){
//    QString Tname = QueryData["TABLE_NAMES"][0] ;
//    StrList DisCols = QueryData["DISPLAY_COL_NAMES"] ;
//    StrList OdrCols = QueryData["ORDER_COL_NAMES"] ;
//    StrList AllCols = DisCols ;
//    for( auto Col:OdrCols ) AllCols << Col ;
//    StrList Odrs = QueryData["ORDERVALS"] ;
//    for( auto C:DisCols ){
//        if( DisCols.count(C) > 1 ){
//            REPLWIN->append(C+" duplicate column !");
//            return;
//        }
//    }
//    for( auto C:OdrCols ){
//        if( OdrCols.count(C) > 1 ){
//            REPLWIN->append(C+" duplicate column !");
//            return;
//        }
//    }
//    if( !FL.isTableExist(Tname) ) ER.PrintError(QStringList(Tname),0,"TABLE_NOT_EXISTS",REPLWIN);
//    else{
//        StrList InvalidCols = FL.MatchColumns(Tname,AllCols);
//        if( !InvalidCols.isEmpty() ) ER.PrintError(QStringList(InvalidCols.join(" , ")),0,"INVALID_ROW",REPLWIN);
//        else ;
//    }
}

void QueryExecuter::TableCalculateSum(QTextEdit* REPLWIN, MapStrStrList QueryData){
    QString Tname = QueryData["TABLE_NAMES"][0] ;
    StrList Cols = QueryData["COL_NAMES"] ;
    if( !FL.isTableExist(Tname) ) ER.PrintError(QStringList(Tname),0,"TABLE_NOT_EXISTS",REPLWIN);
    else{
        StrList InvalidCols = FL.MatchColumns(Tname,Cols);
        StrList NonNumCols = FL.FindNonNumericCols(Tname,Cols);
        if( !InvalidCols.isEmpty() ) ER.PrintError(QStringList(InvalidCols.join(" , ")),0,"INVALID_ROW",REPLWIN);
        else{
            if( !NonNumCols.isEmpty() ) ER.PrintError(NonNumCols,0,"NUMERIC_COLUMN_NOT_EXIST",REPLWIN);
            else{
                MapStrStrList Col_Vals = FL.GetColsVals(Tname,Cols);
                MapStrStrList QueryData;
                for( auto Col:Cols ){
                    QueryData["DATAVALS"] = Col_Vals[Col];
                    EnvCalculateSum(REPLWIN,QueryData,"SUM - "+Col);
                    QueryData["DATAVALS"] = {};
                }
            }
        }
    }
}
void QueryExecuter::TableCalculateCount(QTextEdit* REPLWIN, MapStrStrList QueryData){
    QString Tname = QueryData["TABLE_NAMES"][0] ;
    StrList Cols = QueryData["COL_NAMES"] ;
    if( !FL.isTableExist(Tname) ) ER.PrintError(QStringList(Tname),0,"TABLE_NOT_EXISTS",REPLWIN);
    else{
        StrList InvalidCols = FL.MatchColumns(Tname,Cols);
        StrList NonNumCols = FL.FindNonNumericCols(Tname,Cols);
        if( !InvalidCols.isEmpty() ) ER.PrintError(QStringList(InvalidCols.join(" , ")),0,"INVALID_ROW",REPLWIN);
        else{
            MapStrStrList Col_Vals = FL.GetColsVals(Tname,Cols);
            for( auto Col:Cols ) EnvCalculateCount(REPLWIN,Col_Vals[Col],"COUNT - "+Col);
        }
    }
}
void QueryExecuter::TableCalculateAvg(QTextEdit* REPLWIN, MapStrStrList QueryData){
    QString Tname = QueryData["TABLE_NAMES"][0] ;
    StrList Cols = QueryData["COL_NAMES"] ;
    if( !FL.isTableExist(Tname) ) ER.PrintError(QStringList(Tname),0,"TABLE_NOT_EXISTS",REPLWIN);
    else{
        StrList InvalidCols = FL.MatchColumns(Tname,Cols);
        StrList NonNumCols = FL.FindNonNumericCols(Tname,Cols);
        if( !InvalidCols.isEmpty() ) ER.PrintError(QStringList(InvalidCols.join(" , ")),0,"INVALID_ROW",REPLWIN);
        else{
            if( !NonNumCols.isEmpty() ) ER.PrintError(NonNumCols,0,"NUMERIC_COLUMN_NOT_EXIST",REPLWIN);
            else{
                MapStrStrList Col_Vals = FL.GetColsVals(Tname,Cols);
                MapStrStrList QueryData;
                for( auto Col:Cols ){
                    QueryData["DATAVALS"] = Col_Vals[Col];
                    EnvCalculateAvg(REPLWIN,QueryData,"AVERAGE - "+Col);
                    QueryData["DATAVALS"] = {};
                }
            }
        }
    }
}
void QueryExecuter::TableCalculateMin(QTextEdit* REPLWIN, MapStrStrList QueryData){
    QString Tname = QueryData["TABLE_NAMES"][0] ;
    StrList Cols = QueryData["COL_NAMES"] ;
    if( !FL.isTableExist(Tname) ) ER.PrintError(QStringList(Tname),0,"TABLE_NOT_EXISTS",REPLWIN);
    else{
        StrList InvalidCols = FL.MatchColumns(Tname,Cols);
        StrList NonNumCols = FL.FindNonNumericCols(Tname,Cols);
        if( !InvalidCols.isEmpty() ) ER.PrintError(QStringList(InvalidCols.join(" , ")),0,"INVALID_ROW",REPLWIN);
        else{
            if( !NonNumCols.isEmpty() ) ER.PrintError(NonNumCols,0,"NUMERIC_COLUMN_NOT_EXIST",REPLWIN);
            else{
                MapStrStrList Col_Vals = FL.GetColsVals(Tname,Cols);
                MapStrStrList QueryData;
                for( auto Col:Cols ){
                    QueryData["DATAVALS"] = Col_Vals[Col];
                    EnvCalculateMin(REPLWIN,QueryData,"MIN - "+Col);
                    QueryData["DATAVALS"] = {};
                }
            }
        }
    }
}
void QueryExecuter::TableCalculateMax(QTextEdit* REPLWIN, MapStrStrList QueryData){
    QString Tname = QueryData["TABLE_NAMES"][0] ;
    StrList Cols = QueryData["COL_NAMES"] ;
    if( !FL.isTableExist(Tname) ) ER.PrintError(QStringList(Tname),0,"TABLE_NOT_EXISTS",REPLWIN);
    else{
        StrList InvalidCols = FL.MatchColumns(Tname,Cols);
        StrList NonNumCols = FL.FindNonNumericCols(Tname,Cols);
        if( !InvalidCols.isEmpty() ) ER.PrintError(QStringList(InvalidCols.join(" , ")),0,"INVALID_ROW",REPLWIN);
        else{
            if( !NonNumCols.isEmpty() ) ER.PrintError(NonNumCols,0,"NUMERIC_COLUMN_NOT_EXIST",REPLWIN);
            else{
                MapStrStrList Col_Vals = FL.GetColsVals(Tname,Cols);
                MapStrStrList QueryData;
                for( auto Col:Cols ){
                    QueryData["DATAVALS"] = Col_Vals[Col];
                    EnvCalculateMax(REPLWIN,QueryData,"MAX - "+Col);
                    QueryData["DATAVALS"] = {};
                }
            }
        }
    }
}
void QueryExecuter::TableCalculateMean(QTextEdit* REPLWIN, MapStrStrList QueryData){
    QString Tname = QueryData["TABLE_NAMES"][0] ;
    StrList Cols = QueryData["COL_NAMES"] ;
    if( !FL.isTableExist(Tname) ) ER.PrintError(QStringList(Tname),0,"TABLE_NOT_EXISTS",REPLWIN);
    else{
        StrList InvalidCols = FL.MatchColumns(Tname,Cols);
        StrList NonNumCols = FL.FindNonNumericCols(Tname,Cols);
        if( !InvalidCols.isEmpty() ) ER.PrintError(QStringList(InvalidCols.join(" , ")),0,"INVALID_ROW",REPLWIN);
        else{
            if( !NonNumCols.isEmpty() ) ER.PrintError(NonNumCols,0,"NUMERIC_COLUMN_NOT_EXIST",REPLWIN);
            else{
                MapStrStrList Col_Vals = FL.GetColsVals(Tname,Cols);
                MapStrStrList QueryData;
                for( auto Col:Cols ){
                    QueryData["DATAVALS"] = Col_Vals[Col];
                    EnvCalculateMean(REPLWIN,QueryData,"MEAN - "+Col);
                    QueryData["DATAVALS"] = {};
                }
            }
        }
    }
}
void QueryExecuter::TableCalculateMode(QTextEdit* REPLWIN, MapStrStrList QueryData){
    QString Tname = QueryData["TABLE_NAMES"][0] ;
    StrList Cols = QueryData["COL_NAMES"] ;
    if( !FL.isTableExist(Tname) ) ER.PrintError(QStringList(Tname),0,"TABLE_NOT_EXISTS",REPLWIN);
    else{
        StrList InvalidCols = FL.MatchColumns(Tname,Cols);
        StrList NonNumCols = FL.FindNonNumericCols(Tname,Cols);
        if( !InvalidCols.isEmpty() ) ER.PrintError(QStringList(InvalidCols.join(" , ")),0,"INVALID_ROW",REPLWIN);
        else{
            if( !NonNumCols.isEmpty() ) ER.PrintError(NonNumCols,0,"NUMERIC_COLUMN_NOT_EXIST",REPLWIN);
            else{
                MapStrStrList Col_Vals = FL.GetColsVals(Tname,Cols);
                MapStrStrList QueryData;
                for( auto Col:Cols ){
                    QueryData["DATAVALS"] = Col_Vals[Col];
                    EnvCalculateMode(REPLWIN,QueryData,"MODE - "+Col);
                    QueryData["DATAVALS"] = {};
                }
            }
        }
    }
}
void QueryExecuter::TableCalculateMedian(QTextEdit* REPLWIN, MapStrStrList QueryData){
    QString Tname = QueryData["TABLE_NAMES"][0] ;
    StrList Cols = QueryData["COL_NAMES"] ;
    if( !FL.isTableExist(Tname) ) ER.PrintError(QStringList(Tname),0,"TABLE_NOT_EXISTS",REPLWIN);
    else{
        StrList InvalidCols = FL.MatchColumns(Tname,Cols);
        StrList NonNumCols = FL.FindNonNumericCols(Tname,Cols);
        if( !InvalidCols.isEmpty() ) ER.PrintError(QStringList(InvalidCols.join(" , ")),0,"INVALID_ROW",REPLWIN);
        else{
            if( !NonNumCols.isEmpty() ) ER.PrintError(NonNumCols,0,"NUMERIC_COLUMN_NOT_EXIST",REPLWIN);
            else{
                MapStrStrList Col_Vals = FL.GetColsVals(Tname,Cols);
                MapStrStrList QueryData;
                for( auto Col:Cols ){
                    QueryData["DATAVALS"] = Col_Vals[Col];
                    EnvCalculateMedian(REPLWIN,QueryData,"MEDIAN - "+Col);
                    QueryData["DATAVALS"] = {};
                }
            }
        }
    }
}
void QueryExecuter::TableCalculateFrequency(QTextEdit* REPLWIN, MapStrStrList QueryData){
    QString Tname = QueryData["TABLE_NAMES"][0] ;
    StrList Cols = QueryData["COL_NAMES"] ;
    if( !FL.isTableExist(Tname) ) ER.PrintError(QStringList(Tname),0,"TABLE_NOT_EXISTS",REPLWIN);
    else{
        StrList InvalidCols = FL.MatchColumns(Tname,Cols);
        if( !InvalidCols.isEmpty() ) ER.PrintError(QStringList(InvalidCols.join(" , ")),0,"INVALID_ROW",REPLWIN);
        else{
            MapStrStrList Col_Vals = FL.GetColsVals(Tname,Cols);
            MapStrStrList QueryData;
            for( auto Col:Cols ){
                QueryData["DATAVALS"] = Col_Vals[Col];
                EnvCalculateFrequencyData(REPLWIN,QueryData,"FREQUENCY - "+Col);
                QueryData["DATAVALS"] = {};
            }
        }
    }
}
void QueryExecuter::TableCalculateSD(QTextEdit* REPLWIN, MapStrStrList QueryData){
    QString Tname = QueryData["TABLE_NAMES"][0] ;
    StrList Cols = QueryData["COL_NAMES"] ;
    if( !FL.isTableExist(Tname) ) ER.PrintError(QStringList(Tname),0,"TABLE_NOT_EXISTS",REPLWIN);
    else{
        StrList InvalidCols = FL.MatchColumns(Tname,Cols);
        StrList NonNumCols = FL.FindNonNumericCols(Tname,Cols);
        if( !InvalidCols.isEmpty() ) ER.PrintError(QStringList(InvalidCols.join(" , ")),0,"INVALID_ROW",REPLWIN);
        else{
            if( !NonNumCols.isEmpty() ) ER.PrintError(NonNumCols,0,"NUMERIC_COLUMN_NOT_EXIST",REPLWIN);
            else{
                MapStrStrList Col_Vals = FL.GetColsVals(Tname,Cols);
                MapStrStrList QueryData;
                for( auto Col:Cols ){
                    QueryData["DATAVALS"] = Col_Vals[Col];
                    EnvCalculateSD(REPLWIN,QueryData,"STANDARD DEVIATION - "+Col);
                    QueryData["DATAVALS"] = {};
                }
            }
        }
    }
}
void QueryExecuter::TableCalculateVarience(QTextEdit* REPLWIN, MapStrStrList QueryData){
    QString Tname = QueryData["TABLE_NAMES"][0] ;
    StrList Cols = QueryData["COL_NAMES"] ;
    if( !FL.isTableExist(Tname) ) ER.PrintError(QStringList(Tname),0,"TABLE_NOT_EXISTS",REPLWIN);
    else{
        StrList InvalidCols = FL.MatchColumns(Tname,Cols);
        StrList NonNumCols = FL.FindNonNumericCols(Tname,Cols);
        if( !InvalidCols.isEmpty() ) ER.PrintError(QStringList(InvalidCols.join(" , ")),0,"INVALID_ROW",REPLWIN);
        else{
            if( !NonNumCols.isEmpty() ) ER.PrintError(NonNumCols,0,"NUMERIC_COLUMN_NOT_EXIST",REPLWIN);
            else{
                MapStrStrList Col_Vals = FL.GetColsVals(Tname,Cols);
                MapStrStrList QueryData;
                for( auto Col:Cols ){
                    QueryData["DATAVALS"] = Col_Vals[Col];
                    EnvCalculateVarience(REPLWIN,QueryData,"VARIENCE - "+Col);
                    QueryData["DATAVALS"] = {};
                }
            }
        }
    }
}
void QueryExecuter::ReadyAppAttrs(QTextEdit* REPLWIN){
    qApp->setApplicationDisplayName(LANG.Title);
    QString stylesheet = REPLWIN->styleSheet();
    REPLWIN->setStyleSheet(stylesheet+"background-color:"+LANG.BGCOLOR+";color:"+LANG.TEXTCOLOR);
}
void QueryExecuter::ChangeLang(QTextEdit* REPLWIN, MapStrStrList QueryData){
    QString lang = QueryData["LANGS"][0];
    if( lang.compare(LANG.EnvLangName,Qt::CaseInsensitive) == 0 ) REPLWIN->append(lang+" is already using!");
    else{
        FL.ChangeEnvLang(lang);
        REPLWIN->append("Environment language changed to "+lang+"!");
        LANG.InitiateLangVars();
    }
}
#endif // QUERYEXECUTER_H
