#include "repl.h"
#include "loginwnd.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    REPL rWnd;
//    LoginWnd LW ;
//    LW.show();
    rWnd.show();
    return a.exec();
}
