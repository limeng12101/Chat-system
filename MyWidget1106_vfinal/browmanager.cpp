#include "browmanager.h"
//static BrowManager* Instance;
BrowManager* BrowManager::Instance = NULL;

BrowManager::BrowManager()
{
    regExp = QRegExp("<@brow\\d+>");
    // \d+ ：匹配1个或更多连续的数字
}

BrowManager *BrowManager::getInstance()
{
    if(NULL == Instance){
        Instance = new BrowManager;
    }
    return Instance;
}

BrowManager::~BrowManager()
{

}
//#define FROMAT "<@brow%1>"
//#define HTML_PATH "<img src=:/new/prefix1/imgs/brow%1.jpg>"
void BrowManager::BrowManagerMap(){
    for(int i=1;i<=COUNT;i++){
        QString format = QString(FROMAT).arg(i);
        QString html_path = QString(HTML_PATH).arg(i);
        browMap.insert(pair<QString,QString>(
                           format,html_path));
    }
}
//info ---> 床前明月光<@brow1> <@brow2>  <@brow\\d+>
//将特定<@brow1>字符串转成HTML字符串格式
//床前明月光<img src=:/new/prefix1/imgs/brow%1.jpg>

QString BrowManager::StringtoHtml(QString info){
    int pos = 0;//起始位置0
    int len = 0;
    vector<QString>vec;
    while((pos = regExp.indexIn(info,pos))!=-1){
        vec.push_back(regExp.cap(0));
        pos+=regExp.matchedLength();
    }

    //完成替换  将<@brow%1>  ---> <img src=:/new/prefix1/imgs/brow%1.jpg>
    for(vector<QString>::iterator it  = vec.begin();
        it!=vec.end();it++){
        info.replace(*it,browMap[*it]);
    }
    return info;
}
//？你好
//<img src=:/new/prefix1/imgs/brow1.jpg>你好<img src=:/new/prefix1/imgs/brow1.jpg>
QString BrowManager::addBrowsAsHtml(QString plainText){
    //如果没有特定的符号表情 不处理
    if(inputBrows.size()==0){
        return plainText;
    }else{
        QString toSend;
        int index = 0;
    //否则需要将特定的符号表情转成html
        qDebug() << plainText.size();
        for(int i=0;i<plainText.size();i++)
        {
            //如果是表情 你好?  ---> inputBrows[index++] <@brow1>
            //你好<img src=:/new/prefix1/imgs/brow1.jpg>
            if(plainText[i].unicode() == 65532){
                toSend += browMap[inputBrows[index++]];
            }else{
                toSend += plainText[i];
            }
        }
        //追加当前的表情
        toSend+=browMap[inputBrows.last()];
        return toSend;
    }
}

// (2)
QString BrowManager::addBrows(QString plainText)
{
    if(inputBrows.size()==0)
        return plainText;
    QString toSend = "";
    int browIndex = 0;
    for(int i = 0;i < plainText.size();i++)
    {
        if(plainText.at(i).unicode() == 65532)//表情位插入表情符号
        {
            toSend+=inputBrows[browIndex++];
            //<@brow1><@brow2>
        }
        else
        {
            toSend+=plainText.at(i);
        }
    }
    return toSend;
}
void BrowManager::releaseInstance(){

    if(Instance != NULL)
    {
        delete Instance;
        Instance = NULL;
    }
}
