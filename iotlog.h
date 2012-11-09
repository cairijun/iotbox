#ifndef IOTLOG_H
#define IOTLOG_H

#include <QMap>
#include <QString>
#include <QVector>
#include <QTreeWidget>

#include "iotframe.h"

class iotLog
{
public:
    iotLog();
    iotLog(QTreeWidget *uiObj);
    ~iotLog();
    bool update(const iotFrame &frameObj);
    bool getDeviceCurrentData(QMap<QString, QMap<QString, QString> >);//注意后面一个空格！
    bool getDeviceCurrentData(const QString &device, QMap<QString, QString>);
    bool getDeviceCurrentData(const QString &device, const QString &key, QString &value);
    bool getDeviceLog(const QString &device, QVector<QMap<QString, QString> >);//同上！
};

#endif // IOTLOG_H
