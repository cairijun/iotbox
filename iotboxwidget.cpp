#include <QTreeWidgetItem>
#include <QTreeWidget>
#include <QTime>

#include "iotboxwidget.h"
#include "ui_iotboxwidget.h"

iotboxWidget::iotboxWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::iotboxWidget)
{
    ui->setupUi(this);

    //UI初始化
    ui->rateBox->addItem(QString("115200"), BAUD115200);
    ui->rateBox->addItem(QString("38400"), BAUD38400);
    ui->rateBox->addItem(QString("19200"), BAUD19200);
    ui->rateBox->addItem(QString("9600"), BAUD9600);

    ui->portBox->addItem(QString("ttySAC1"), QString("/dev/ttySAC1"));
    ui->portBox->addItem(QString("ttySAC2"), QString("/dev/ttySAC2"));

    //初始化各对象
    serialPortObj = new QextSerialPort(QextSerialPort::EventDriven, this);
    connect(serialPortObj, SIGNAL(readyRead()), this, SLOT(data_arrived()));

    mainBuffer = new QByteArray();
    parseObj = new frameParser();
    logObj = new iotLog(ui->dataTree);
}

iotboxWidget::~iotboxWidget()
{
    delete ui;
}

void iotboxWidget::on_openButton_clicked()
{
    if(serialPortObj->isOpen()) {
        serialPortObj->close();
        ui->openButton->setText("打开");
        ui->logList->addItem(
                    QTime::currentTime().toString() + "关闭串口。");
    }
    else {
        QString portName = ui->portBox->itemData(ui->portBox->currentIndex()).toString();
        int rateBoxIndex = ui->rateBox->currentIndex();
        serialPortObj->setPortName(portName);
        serialPortObj->setBaudRate(
                    static_cast<BaudRateType>(ui->rateBox->itemData(rateBoxIndex).toInt()));
        if(!serialPortObj->open(QIODevice::ReadWrite))
            ui->logList->addItem(
                        QTime::currentTime().toString()
                        + "打开串口失败：" + serialPortObj->errorString());
        else {
            ui->openButton->setText("关闭");
            ui->logList->addItem(
                        QTime::currentTime().toString() + "打开串口成功。");
        }
    }
}

void iotboxWidget::data_arrived()
{
    QByteArray receivedBuffer = serialPortObj->readAll();
    for(int i = 0 ; i < receivedBuffer.length() ; i++)
        parseAByte(receivedBuffer[i]);
}

void iotboxWidget::parseAByte(unsigned char aByte)
{
    static int dataRemain = 0;//记录有效数据长度
    if(mainBuffer->isEmpty()) {
        if(aByte == FRA_SGN_STX)
            mainBuffer->append(aByte);
    }
    else {
        mainBuffer->append(aByte);
        if(dataRemain)
            dataRemain--;
        if(mainBuffer->length() == 10)
            dataRemain = aByte;
        if(aByte == FRA_SGN_ETX && (!dataRemain)) {//排除有效数据区出现的帧结束标志
            iotFrame *frameObj = new iotFrame();
            if(parseObj->praseFrame(*mainBuffer, frameObj)) {
                ui->logList->addItem(
                            QTime::currentTime().toString() + "接收到数据帧。");
            }
            else {
                ui->logList->addItem(
                            QTime::currentTime().toString() + "接收到数据帧，但数据帧无效。");
            }
            logObj->update(*frameObj);

            mainBuffer->clear();
        }
    }
}
