#ifndef DAOFACTORY_H
#define DAOFACTORY_H

#include "userdao.h"
#include "frienddao.h"
#include <QSqlDatabase>
#include <QDebug>

#define DRIVER "QSQLITE"   //支持的数据库驱动
#define MYDB "myDB"        //本地数据库的名字

//单例模式
class Daofactory
{
public:
    static Daofactory* getInstance();//初始化Instance
    static void releaseInstance();//释放Instance
    ~Daofactory();
    //内联函数 空间换时间
    inline userDao* getUserDao(){
        return p_userDao;
    }
    inline FriendDao* getFriendDao(){
        return p_friendDao;
    }
private:
    Daofactory();
    Daofactory(const Daofactory&/* other*/){}
    static Daofactory *Instance;

    //定义用户信息表的类指针
    userDao *p_userDao;
    //定义一个好友信息表的类指针
    FriendDao *p_friendDao;
    //定义数据库操作的类对象
    QSqlDatabase database;
};

#endif // DAOFACTORY_H
