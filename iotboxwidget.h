#ifndef IOTBOXWIDGET_H
#define IOTBOXWIDGET_H

#include <QWidget>

#include "qextserialport.h"

#include "frameparse.h"
#include "iotframe.h"
#include "iotlog.h"

namespace Ui {
class iotboxWidget;
}

namespace IOTBox {
class frameParse;
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

private:
    Ui::iotboxWidget *ui;
    QextSerialPort *serialPortObj;
};

#endif // IOTBOXWIDGET_H
