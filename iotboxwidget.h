#ifndef IOTBOXWIDGET_H
#define IOTBOXWIDGET_H

#include <QWidget>

namespace Ui {
class iotboxWidget;
}

class iotboxWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit iotboxWidget(QWidget *parent = 0);
    ~iotboxWidget();
    
private:
    Ui::iotboxWidget *ui;
};

#endif // IOTBOXWIDGET_H
