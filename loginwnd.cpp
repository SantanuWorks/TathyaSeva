#include "loginwnd.h"
#include "ui_loginwnd.h"
#include "createuser.h"

LoginWnd::LoginWnd(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginWnd)
{
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
void LoginWnd::login(){
    qWarning() <<  ui->Username->text();
    qWarning() << ui->Password->text();
}
