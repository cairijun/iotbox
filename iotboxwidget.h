#ifndef IOTBOXWIDGET_H
#define IOTBOXWIDGET_H

#include <QWidget>

#include "qextserialport.h"

#include "frameparser.h"
#include "iotframe.h"
#include "iotlog.h"

#include "protocolconst.h"

namespace Ui {
class iotboxWidget;
}

namespace IOTBox {
class frameParser;
class iotFrame;
class iotLog;
}

class iotboxWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit iotboxWidget(QWidget *parent = 0);
    ~iotboxWidget();

private slots:
    void data_arrived();
    
    void on_openButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::iotboxWidget *ui;
    QextSerialPort *serialPortObj;
    frameParser *parseObj;
    iotLog *logObj;
    QByteArray *mainBuffer;

    void parseAByte(unsigned char aByte);
};

#endif // IOTBOXWIDGET_H
