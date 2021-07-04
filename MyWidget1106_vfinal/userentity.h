#ifndef USERENTITY_H
#define USERENTITY_H
#include <QString>
//userEntity 代表一条user数据：用户ID 用户姓名 用户密码
struct userEntity
{
    userEntity(QString name,QString pass,int id = 0);
    ~userEntity();

    int id;
    QString name;
    QString pass;

};

#endif // USERENTITY_H
