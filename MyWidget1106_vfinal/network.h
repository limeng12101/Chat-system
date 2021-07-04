#ifndef NETWORK_H
#define NETWORK_H

#include <QObject>
#include <QUdpSocket>
#include <QHostInfo>

class NetWork : public QObject
{
    Q_OBJECT
    /*************单例模式******************/
public:
    static NetWork* getInstance();
    static void releaseInstance();//释放Instance
    ~NetWork();
private:
    explicit NetWork(QObject *parent = 0);
    NetWork(const NetWork& /*other*/){}
    static NetWork* Instance;
    /*************单例模式******************/

public:
    enum STATUS
    {
        OFFLINE, //报文 STATUS#ip#name
        ONLINE , //报文 STATUS#ip#name
        MSGDATA  //报文 STATUS#ip#name#msg
    };
    void sendData(STATUS status, QString data = QString());//发送数据
    QStringList getIps();//获得本机所有ipv4 的ip地址
    void setIp(QString ip);//设置本机的ip 此ip用在发送数据的数据报中
    void setNickName(QString nickName);//设置本机的昵称 此昵称用在发送数据的数据报中
    void dealMsg(QString str);  // emit msgdata(nickName, ip, msg);

    void dealOffline(QString str);//报文 STATUS#ip#name
    void dealOnline(QString str);//报文 STATUS#ip#name

signals:
    void offline(QString name, QString ip);
    void online(QString name, QString ip);
    void msgdata(QString name, QString ip, QString data);

public slots:
    void recviveData();//参数待定
private:
    QUdpSocket *udpsocket;//定义一个QUdpSocket的类指针
    QString hostIP;
    QString nickName;
};

#endif // NETWORK_H
