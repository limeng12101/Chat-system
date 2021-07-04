#ifndef MYFORM_H
#define MYFORM_H

#include <QWidget>
#include "browmanager.h"


namespace Ui {
class MyForm;
}

class MyForm : public QWidget
{
    Q_OBJECT

public:
    explicit MyForm(QWidget *parent = 0);
    ~MyForm();

private slots:
    void on_toolButton_clicked();

    void on_toolButton_2_clicked();

    void on_toolButton_3_clicked();

    void on_toolButton_4_clicked();

    void on_toolButton_5_clicked();

signals:
    void MySignal(QString str);
private:
    Ui::MyForm *ui;
};

#endif // MYFORM_H
