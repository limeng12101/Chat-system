#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "widget.h"
#include "daofactory.h"
#include <QMessageBox>

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();

private slots:


    void on_pushButton_regist_clicked();

    void on_pushButton_login_clicked();

private:
    Ui::Login *ui;
    Widget *widget;
};

#endif // LOGIN_H
