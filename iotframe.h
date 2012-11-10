#ifndef IOTFRAME_H
#define IOTFRAME_H

//#include <QWidget>
#include <QMap>
#include <QString>

#include "protocolconst.h"

class iotFrame
{
public:
    static const QMap<char, QString> DEV_TYPE_MAP;//设备类型映射
    static const QMap<char, QString> CMD_NAME_MAP;//命令名称映射
    static const QMap<char, QString> IOT_EB_TYPE_MAP;//IOT-EB类型映射

    static QMap<char, QString> init(int type);//常量初始化函数

    iotFrame();
    iotFrame(const QMap<QString, QString> &device, const QString &command, const QByteArray &data);
    ~iotFrame();
    bool praseFrameData(const QMap<QString, QString> &device, const QString &command, const QByteArray &data);
    bool getFrameData(QMap<QString, QString> &data) const;
    bool getFrameData(QMap<QString, QString> &data, QString &device) const;
    bool getFrameData(const QString &key, QString &value) const;
    bool getDeviceInfo(QMap<QString, QString> &device) const;
    bool getCommand(QString &command) const;

private:
    QMap<QString, QString> device;
    QString command;
    QMap<QString, QString> data;

    bool parseMainData(const QByteArray &data);

    bool parseIOTEB2(const QByteArray &data);
    bool parseIOTEB3(const QByteArray &data);
    bool parseIOTEB4(const QByteArray &data);
    bool parseIOTEB5(const QByteArray &data);
    bool parseIOTEB6(const QByteArray &data);
    bool parseIOTEB7(const QByteArray &data);
    bool parseIOTEB15(const QByteArray &data);

};

#endif // IOTFRAME_H
