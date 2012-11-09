#include "iotframe.h"

QMap<char, QString> iotFrame::DEV_TYPE_MAP;
QMap<char, QString> iotFrame::CMD_NAME_MAP;
QMap<char, QString> iotFrame::IOT_EB_TYPE_MAP;

iotFrame::iotFrame()
{
}

iotFrame::~iotFrame()
{
}

iotFrame::iotFrame(
        const QMap<QString, QString> &device, const QString &command, const QByteArray &data)
{
}

bool iotFrame::praseFrameData(
        const QMap<QString, QString> &device, const QString &command, const QByteArray &data)
{
}

bool iotFrame::getFrameData(QMap<QString, QString> &data)
{
}

bool iotFrame::getFrameData(QMap<QString, QString> &data, QString &device)
{
}

bool iotFrame::getFrameData(const QString &key, QString &value)
{
}

bool iotFrame::getDeviceInfo(QMap<QString, QString> &device)
{
}

bool iotFrame::getCommand(QString &command)
{
}
