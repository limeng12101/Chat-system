#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "myform.h"
#include <vector>
#include <QRegExp>
#include <QDebug>
#include <QPoint>
#include <set>
#include "network.h"
#include "browmanager.h"
#include "daofactory.h"
using namespace std;

//Widget 窗口主要是在上面放置布局和控件,可以嵌入到主窗体中

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QString name,QWidget *parent = 0);
    ~Widget();
    void reg_test();

    //初始化网络相关
    void InitNetWork();

private slots:
    void on_toolButton_clicked();
    void dealSignal(QString str);

    void on_pushButton_clicked();

    void on_comboBox_currentTextChanged(const QString &ip);
public:
    void loadFriends();
    void showOfflineFriends();
    void showOnlineFriends();
    void addOfflineFriend(QString name, QString ip);
    void addOnlineFriend(QString name, QString ip);
    void removeOfflineFriend(QString name, QString ip);
    void removeOnlineFriend(QString name, QString ip);

public slots:
    void dealmsgdata(QString nickName, QString ip, QString msg);

    void dealoffline(QString name, QString ip);
    void dealonline(QString name, QString ip);

private:
    Ui::Widget *ui;
    MyForm *pf;//代表表情控件
    bool status;//false
    vector<QString>str;//装表情的路径
    BrowManager *pbrow; //定义一个表情管理类的指针

    /***************1106*****************/
    NetWork *pnet;  //初始化网络相关
    QString nickName;
    QString hostIp;

    set<QString> onlineFriends;  //显示上线好友
    set<QString> offlineFriends; //显示下线好友
};

#endif // WIDGET_H
