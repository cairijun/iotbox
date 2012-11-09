#ifndef IOTFRAME_H
#define IOTFRAME_H

//#include <QWidget>
#include <QMap>
#include <QString>

class iotFrame
{
public:
    static QMap<char, QString> DEV_TYPE_MAP;//设备类型映射
    static QMap<char, QString> CMD_NAME_MAP;//命令名称映射
    static QMap<char, QString> IOT_EB_TYPE_MAP;//IOT-EB类型映射

    iotFrame();
    iotFrame(const QMap<QString, QString> &device, const QString &command, const QByteArray &data);
    ~iotFrame();
    bool praseFrameData(const QMap<QString, QString> &device, const QString &command, const QByteArray &data);
    bool getFrameData(QMap<QString, QString> &data);
    bool getFrameData(QMap<QString, QString> &data, QString &device);
    bool getFrameData(const QString &key, QString &value);
    bool getDeviceInfo(QMap<QString, QString> &device);
    bool getCommand(QString &command);
};

#endif // IOTFRAME_H
