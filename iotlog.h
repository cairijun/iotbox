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
    bool getDeviceCurrentData(QMap<QString, QMap<QString, QString> > &data) const;//注意后面一个空格！
    bool getDeviceCurrentData(const QString &device, QMap<QString, QString> &data) const;
    bool getDeviceCurrentData(const QString &device, const QString &key, QString &value) const;
    bool getDeviceLog(const QString &device, QVector<QMap<QString, QString> > &log) const;//同上！

protected:
    bool updateUI();

private:
    QTreeWidget *uiObj;
    QMap<QString, QVector<iotFrame> > logData;//索引命名为：0x中间设备地址#0x目的设备地址

    QMap<QString, QString> makeDataMap(const iotFrame &frameObj) const;
};

#endif // IOTLOG_H
