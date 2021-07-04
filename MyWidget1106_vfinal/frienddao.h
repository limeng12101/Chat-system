#ifndef FRIENDDAO_H
#define FRIENDDAO_H
#include "friendentity.h"
#include <vector>
using namespace std;
#include <QSqlQuery>
#include <QSqlRecord>
#include <QVariant>
#include <QDebug>

class FriendDao
{
public:
    FriendDao();
    ~FriendDao();
    bool addFriend(FriendEntity e);
    bool selectFriends(vector<FriendEntity>& s);
    bool isFriendExists(FriendEntity e);
};

#endif // FRIENDDAO_H
