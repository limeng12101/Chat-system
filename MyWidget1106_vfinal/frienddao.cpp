#include "frienddao.h"

FriendDao::FriendDao()
{
    QSqlQuery query;
    bool successFriend =
            query.exec("create table if not exists friend(\
                              f_id integer primary key autoincrement,\
                              f_name char(20),\
                              f_ip char(20)\
                              )");

    if(successFriend)
        qDebug()<<"创建friend表成功";
    else
        qDebug()<<"创建friend表失败";
}

FriendDao::~FriendDao()
{

}

bool FriendDao::addFriend(FriendEntity e)
{
    if(isFriendExists(e)){
        return false;
    }
    QSqlQuery query;
    query.prepare("insert into friend(f_name,f_ip) values(?,?)");
    query.bindValue(0,e.m_name);
    query.bindValue(1,e.m_ip);
    return query.exec();
}

bool FriendDao::selectFriends(vector<FriendEntity> &s)
{
    QSqlQuery query;
    query.exec("select * from friend");
    while(query.next())
    {
        FriendEntity e(
                    query.record().value("f_name").toString(),
                    query.record().value("f_ip").toString(),
                    query.record().value("f_id").toInt()
                    );
        s.push_back(e);
//        qDebug()<< e.m_name << e.m_id << e.m_ip << endl;
    }
    return true;

}

bool FriendDao::isFriendExists(FriendEntity e)
{
    QSqlQuery query;
    query.prepare("select count(*) from friend where f_name=? and f_ip=?");
    query.bindValue(0,e.m_name);
    query.bindValue(1,e.m_ip);
    query.exec();
    while(query.next())
    {
        int count = query.record().value(0).toInt();
        if(count>0)
            return true;
        else
            return false;
    }
    return false;
}

