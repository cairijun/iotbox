#include "iotlog.h"

iotLog::iotLog()
{
}

iotLog::iotLog(QTreeWidget &uiObj)
{
}

iotLog::~iotLog()
{
}

bool iotLog::update(const iotFrame &frameObj)
{
}

bool iotLog::getDeviceCurrentData(QMap<QString, QMap<QString, QString> >)
{
}

bool iotLog::getDeviceCurrentData(const QString &device, QMap<QString, QString>)
{
}

bool iotLog::getDeviceCurrentData(const QString &device, const QString &key, QString &value)
{
}

bool iotLog::getDeviceLog(const QString &device, QVector<QMap<QString, QString> >)
{
}
