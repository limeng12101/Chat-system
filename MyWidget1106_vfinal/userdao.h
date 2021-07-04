#ifndef userDao_H
#define userDao_H

#include "userentity.h"
#include <QSqlQuery>
#include <QDebug>
#include <QSqlRecord>



class userDao
{
public:
    userDao();//创建数据表 用户信息表user
    bool addUser(userEntity e);
    bool isUserExists(userEntity e);
    bool isUserNameExists(QString name);
    bool isPassOK(QString pass);
    ~userDao();
};

#endif // userDao_H
