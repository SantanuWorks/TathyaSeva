#include "loginwnd.h"
#include "ui_loginwnd.h"
#include "createuser.h"

LoginWnd::LoginWnd(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWnd)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->centralwidget);
}

LoginWnd::~LoginWnd()
{
    delete ui;
}
void LoginWnd::on_pushButton_2_clicked()
{
    this->hide();
    createUser cu;
    cu.setModal(true);
    cu.exec();
}
