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
    connect(serialPortObj, SIGNAL(readyRead()), this, SLOT(data_arrived());
}

iotboxWidget::~iotboxWidget()
{
    delete ui;
}

void iotboxWidget::on_openButton_clicked()
{

}
