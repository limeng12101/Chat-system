#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    ui->lineEdit_pass->setEchoMode(QLineEdit::Password);
    //设置成密文
    ui->lineEdit_pass->setMaxLength(6);
    //设置成密码长度最大是6


}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_regist_clicked()   //regist 注册
{
    //获取输入的用户名和密码
    QString name = ui->lineEdit_name->text();
    QString pass = ui->lineEdit_pass->text();

    //数据库中有此人
    if(Daofactory::getInstance()->getUserDao()    //Daofactory *Instance
            ->isUserNameExists(name) == true){
        QMessageBox::warning(this,"warn","此人已存在");
    }else{
        if(Daofactory::getInstance()->getUserDao()
                ->addUser(userEntity(name,pass))==true){
            QMessageBox::warning(this,"warn","注册成功，请登录");
        }
        ui->lineEdit_pass->clear();//清空密码
    }
}

void Login::on_pushButton_login_clicked()
{
    //获取用户名和密码
    QString name = ui->lineEdit_name->text();
    QString pass = ui->lineEdit_pass->text();

    if(name == NULL){
        QMessageBox::warning(this,"警告","用户名不能为空！");
    }
    else if(pass == NULL){
        QMessageBox::warning(this,"警告","密码不能为空！");
    }

    if(Daofactory::getInstance()->getUserDao()->isUserExists(userEntity(name, pass)))
    {
        widget = new Widget(ui->lineEdit_name->text());
        widget->setWindowTitle("I am "+ui->lineEdit_name->text());    //???
        //设置窗口名称
        widget->show();
        this->close();
    }
    else if(Daofactory::getInstance()->getUserDao()->isUserNameExists(name) == true)
    {
        if(Daofactory::getInstance()->getUserDao()->isPassOK(pass) == false){
            QMessageBox::warning(this,"登录失败","密码错误");
            ui->lineEdit_pass->clear();
        }

    }else{
        QMessageBox::warning(this,"登录失败","用户名错误");
        ui->lineEdit_pass->clear();
    }
}
