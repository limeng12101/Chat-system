#include "network.h"
NetWork* NetWork::Instance = NULL;
NetWork::NetWork(QObject *parent) : QObject(parent)
{
    udpsocket = new QUdpSocket(this);//创建套接字
    udpsocket->bind(QHostAddress::Any,
                    5555,
                    QUdpSocket::ShareAddress|
                    QAbstractSocket::ReuseAddressHint);

    QHostAddress addr(QString("192.168.30.245"));
    udpsocket->bind(addr,
                    5555,
                    QUdpSocket::ShareAddress|
                    QAbstractSocket::ReuseAddressHint);

    //绑定端口号

    connect(udpsocket,&QUdpSocket::readyRead,
            this,&NetWork::recviveData);

}

NetWork::~NetWork()
{

}

NetWork* NetWork::getInstance(){
    if(NULL == Instance){
        Instance = new NetWork;
    }
    return Instance;
}
void NetWork::releaseInstance()//释放Instance
{
    if(Instance!=NULL){
        delete Instance;
        Instance = NULL;
    }
}

// MSGDATA <@brow1>
void NetWork::sendData(STATUS status, QString data ){
    QString tosendstr;
    //分析status 有如下三种可能性
    switch(status){
    case ONLINE:
    case OFFLINE:
        tosendstr = QString::number(status)+"#"
                +hostIP+"#"+nickName;
        break;
    case MSGDATA://发送真实的聊天数据的时候 满足status = MSGDATA
        //拼接报文
        //tosendstr = MSGDATA#IP#name#data
        tosendstr = QString::number(status)+"#"
                +hostIP+"#"+nickName+"#"+data;
        break;
    default:
        break;
    }
    //发送数据
    udpsocket->writeDatagram(tosendstr.toLocal8Bit()
                             ,QHostAddress::Broadcast,
                             5555);


    return ;
}
//split 返回的是stringList
void NetWork::dealMsg(QString str){
    //截取 MSGDATA#ip#nickName#msg
     QString ip = str.split("#").at(1);
     QString nickName = str.split("#").at(2);
     QString msg = str.split("#").at(3);

     emit msgdata(nickName, ip, msg);
}

void NetWork::dealOnline(QString str){
    //截取 ip nickName
    QString ip = str.split("#").at(1);
    QString nickName = str.split("#").at(2);
    qDebug()<< "------online------";
    emit online(nickName, ip);
}

void NetWork::dealOffline(QString str){
    //截取 ip nickName
    QString ip = str.split("#").at(1);
    QString nickName = str.split("#").at(2);
    qDebug()<< "------offline------";
    emit offline(nickName, ip);
}

void NetWork::recviveData(){
    //读取数据

    while(udpsocket->hasPendingDatagrams()){
        QByteArray buff;//接收发送端的数据内容
        buff.resize(udpsocket->pendingDatagramSize());
        //申请空间 = 发送过来的内容的size
        QHostAddress addr;//代表对方的IP地址
        quint16 port;//代表对方的端口号

        udpsocket->readDatagram(buff.data(),buff.size(),&addr,&port);

        //分离第一个字符 status
        //static_cast 所有c语言中的隐式类型转换都支持
        STATUS flag = static_cast<STATUS>(buff.at(0)-48);
        //取得的数据报内容
        QString msg = QString::fromLocal8Bit(buff);
        //分析status 有如下三种可能性

        switch(flag){
        case ONLINE:
            dealOnline(msg);
            break;
        case OFFLINE:
            qDebug()<< "---offline----" ;
            dealOffline(msg);
            break;
        case MSGDATA:
            dealMsg(msg);
            break;
        }
    }
}

QStringList NetWork::getIps()
{
    QStringList ips;
    QString localHostName = QHostInfo::localHostName();//获得主机的名称

    QHostInfo info = QHostInfo::fromName(localHostName);//获得主机的信息

    QList<QHostAddress> list = info.addresses();//获得本地主机的所有ip地址
    for(int i = 0;i < list.size();i++)
    {
        if(list[i].protocol() == QAbstractSocket::IPv4Protocol)//判断ip地址是不是ipv4
        {
            ips.append(list[i].toString());//将ip地址转换为字符串
            qDebug()<< list[i].toString();
        }
    }
    return ips;
}
void NetWork::setNickName(QString nickName)
{
    this->nickName = nickName;
}

void NetWork::setIp(QString ip)
{
    this->hostIP = ip;//192.168.30.245
}
