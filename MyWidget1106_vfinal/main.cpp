#include "widget.h"
#include <QApplication>
#include "login.h"
#include "daofactory.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);  /*  初始化窗口系统并且使用在argv中的argc个命令行参数构造一个应用程序对象。
全局指针qApp指向这个应用程序对象。应该只有一个应用程序对象被创建。
这个应用程序对象必须在任何绘制设备（包括窗口部件、像素映射、位图等等）之前被构造。*/

    Login l;
    l.show();

    return a.exec();  
    /*对于线程配置（也就是说当Qt已经被作为线程库建立），应用程序全局互斥量在构造函数中将被锁定并且当使用exec()进入事件循环中时解锁。
    如果你不调用exec()，你必须明显地对这个互斥量解锁，否则你将会在应用程序退出时得到警告。*/
}
