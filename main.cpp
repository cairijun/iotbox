#include <QApplication>
#include <QTextCodec>
#include "iotboxwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //网上找的解决乱码的代码
    QTextCodec *codec = QTextCodec::codecForName("system");
    QTextCodec::setCodecForTr(codec);
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);

    iotboxWidget w;
    w.show();
    
    return a.exec();
}
