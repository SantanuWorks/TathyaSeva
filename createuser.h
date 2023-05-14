#ifndef CREATEUSER_H
#define CREATEUSER_H

#include <QDialog>

namespace Ui {
class createUser;
}

class createUser : public QDialog
{
    Q_OBJECT

public:
    explicit createUser(QWidget *parent = nullptr);
    ~createUser();

private:
    Ui::createUser *ui;
};

#endif // CREATEUSER_H
