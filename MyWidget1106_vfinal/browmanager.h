#ifndef BROWMANAGER_H
#define BROWMANAGER_H
#include <iostream>
using namespace std;
#include <map>
#include <QString>
#include <QRegExp>
#include <vector>
#include <QStringList>
#include <QDebug>

/***********宏常量***********/
#define COUNT  5   //5张图片
#define FROMAT "<@brow%1>"
#define HTML_PATH "<img src=:/new/prefix1/imgs/brow%1.jpg>"


//单例模式
class BrowManager
{
public:
    static BrowManager* getInstance();
    ~BrowManager();

    /*****************************/
    void BrowManagerMap();
    //创建map容器  key：<@brow1>  value:HTML_PATH

    QString StringtoHtml(QString info);
    //床前的明月光<@brow1>
    //将特定<@brow1>字符串转成HTML字符串格式
    //床前明月光HTML_PATH

    QString addBrowsAsHtml(QString plainText);
    //插入html表情
    //床前明月光？
    //床前明月光<img src=:/new/prefix1/imgs/brow1.jpg>

    inline void addInputBrows(QString brow){
        inputBrows.append(brow);
    }
    //添加输入的表情到StringList中

    inline void clearInputBrows(){
        inputBrows.clear();
    }
    //清空StringList

    QString addBrows(QString plainText);
    //插入符号表情，输入的参数是从QTextEdit中获得的字符串，

    /*****************************/

    static void releaseInstance();
private:
    BrowManager();
    BrowManager(const BrowManager& /*other*/){

    }
    static BrowManager* Instance;
    /*****************************/
    map<QString,QString>browMap;//key：<@brow1>  value:HTML_PATH
    QRegExp regExp;
    QStringList inputBrows;//用于存放表情符号
};

#endif // BROWMANAGER_H
