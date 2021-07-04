#include "myform.h"
#include "ui_myform.h"

MyForm::MyForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyForm)
{
    ui->setupUi(this);
}

MyForm::~MyForm()
{
    delete ui;
}
//#define FROMAT "<@brow%1>"
void MyForm::on_toolButton_clicked()
{
    emit MySignal(QString(FROMAT).arg(1));
   // emit MySignal(QString("<@brow%1>").arg(1));
}

void MyForm::on_toolButton_2_clicked()
{
    emit MySignal(QString(FROMAT).arg(2));
}

void MyForm::on_toolButton_3_clicked()
{
    emit MySignal(QString(FROMAT).arg(3));
}

void MyForm::on_toolButton_4_clicked()
{
     emit MySignal(QString(FROMAT).arg(4));
}

void MyForm::on_toolButton_5_clicked()
{
    emit MySignal(QString(FROMAT).arg(5));
}
