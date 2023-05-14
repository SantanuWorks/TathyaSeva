#include "createuser.h"
#include "ui_createuser.h"

createUser::createUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::createUser)
{
    ui->setupUi(this);
}

createUser::~createUser()
{
    delete ui;
}
