#include "iotboxwidget.h"
#include "ui_iotboxwidget.h"

iotboxWidget::iotboxWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::iotboxWidget)
{
    ui->setupUi(this);
}

iotboxWidget::~iotboxWidget()
{
    delete ui;
}
