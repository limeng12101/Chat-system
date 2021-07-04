#ifndef FRIENDENTITY_H
#define FRIENDENTITY_H
#include <QString>

struct FriendEntity
{
public:
    ~FriendEntity();

    FriendEntity(QString name,QString ip,int id = 0);

    QString m_name;
    QString m_ip;
    int m_id;
};

#endif // FRIENDENTITY_H
