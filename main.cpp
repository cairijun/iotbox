#include <QApplication>
#include "iotboxwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    iotboxWidget w;
    w.show();
    
    return a.exec();
}
