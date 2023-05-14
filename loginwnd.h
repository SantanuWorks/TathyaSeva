 #ifndef LOGINWND_H
#define LOGINWND_H

#include <QDialog>
#include <QResource>

QT_BEGIN_NAMESPACE
namespace Ui { class LoginWnd; }
QT_END_NAMESPACE

class LoginWnd : public QDialog
{
    Q_OBJECT

public:
    LoginWnd(QWidget *parent = nullptr);
    void login();
    ~LoginWnd();

private slots:
    void on_pushButton_2_clicked();
private:
    Ui::LoginWnd *ui;
};
#endif // LOGINWND_H
