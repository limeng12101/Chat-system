#include "userdao.h"

userDao::userDao()
{
    //创建数据表 用户信息表user
    QSqlQuery query;
    QString sql = QString("create table IF NOT EXISTS user("
                          "u_id integer primary key autoincrement,"
                          "u_name varchar(20),"
                          "u_pass varchar(20));");
    if(query.exec(sql)==true){
        qDebug() << "create table succ";
    }else{
        qDebug() << "create table fail";
    }

}
userDao::~userDao()
{

}
//注册的时候需要添加用户
bool userDao::addUser(userEntity e){//UserEntity("zhangsan","123")
    //先判断有这个人吗 有的话返回false
    if(isUserExists(e)==true){
        return false;
    }
    //否则将用户插入数据库
    QSqlQuery query;
    query.prepare("insert into user(u_name,u_pass) values(?,?)");
    query.bindValue(0,e.name);
    query.bindValue(1,e.pass);
    return query.exec();
}

bool userDao::isUserExists(userEntity e)
{
    QSqlQuery query;
    QString sql = QString("select count(*) from user "
                          "where u_name = ? and u_pass = ?;");
    query.prepare(sql);
    query.bindValue(0,e.name);
    query.bindValue(1,e.pass);
    query.exec();

    while(query.next()){
        int count = query.record().value(0).toInt();
        if(count!=0){
            return true; //此人存在
        }
        else{
            return false;//此人不存在
        }
    }
    return false;
}

bool userDao::isUserNameExists(QString name)
{
    QSqlQuery query;
    QString sql = QString("select count(*) from user "
                          "where u_name = ?;");
    query.prepare(sql);
    query.bindValue(0,name);

    query.exec();

    while(query.next()){
        int count = query.record().value(0).toInt();
        if(count!=0){
            return true; //此人存在
        }
        else{
            return false;//此人不存在
        }
    }
    return false;
}

bool userDao::isPassOK(QString pass)
{
    QSqlQuery query;
    QString sql = QString("select count(*) from user "
                          "where u_pass = ?;");
    query.prepare(sql);
    query.bindValue(0,pass);

    query.exec();

    while(query.next()){
        int count = query.record().value(0).toInt();
        if(count!=0){
            return true; //此人存在
        }
        else{
            return false;//此人不存在
        }
    }
    return false;

}
