#include "daofactory.h"
Daofactory* Daofactory::Instance = NULL;
Daofactory::Daofactory():p_userDao(NULL)
{
    //负责数据库的初始化
    database = QSqlDatabase::addDatabase(DRIVER);
    database.setDatabaseName(MYDB);//设置数据库的名字

    //打开数据库
    if(database.open()==true){
        qDebug() << "database open succ";
    }
    else{
        qDebug() << "database open fail";
    }

    //初始化用户信息类
    p_userDao = new userDao;
    p_friendDao = new FriendDao;
}

Daofactory *Daofactory::getInstance()
{
    if(NULL == Instance){
        Instance = new Daofactory;
    }
    return Instance;
}

void Daofactory::releaseInstance()
{
    if(Instance != NULL){
        delete Instance;
        Instance = NULL;
    }
}

Daofactory::~Daofactory()
{
    if(NULL != p_userDao){
        delete p_userDao;
        p_userDao = NULL;
    }
}

