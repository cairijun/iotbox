#include "frameparser.h"

frameParser::frameParser()
{
}

bool frameParser::praseFrame(const QByteArray &frame, iotFrame *frameObj) const
{
    if(crc(frame.constData(), frame.length() - 1))
        return false;//CRC校验失败
    if(frame.length() < 13)
        return false;//长度非法
    if(frame.at(7) < 0x21 || frame.at(7) > 0x23)
        return false;//未知命令

    QMap<QString, QString> device;
    QString tmpStr;
    QString cmdStr;

    device["MID_TYPE"] = iotFrame::DEV_TYPE_MAP[frame[1]];

    //tmpStr.setNum((frame[2] << 8) + frame[3], 16);
    tmpStr = QString("0x%1%2")
            .arg(static_cast<uint>(frame[2]), 2, 16, QLatin1Char('0'))
            .arg(static_cast<uint>(frame[3]), 2, 16, QLatin1Char('0'));
    device["MID_ADDR"] = tmpStr;

    device["DST_TYPE"] = iotFrame::DEV_TYPE_MAP[frame[4]];

    //tmpStr.setNum((frame[5] << 8) + frame[6], 16);
    tmpStr = QString("0x%1%2")
            .arg(static_cast<uint>(frame[5]), 2, 16, QLatin1Char('0'))
            .arg(static_cast<uint>(frame[6]), 2, 16, QLatin1Char('0'));
    device["DST_ADDR"] = tmpStr;

    cmdStr = iotFrame::CMD_NAME_MAP[frame[7]];
    //没有对命令状态进行处理

    QByteArray dataByteArray = frame.mid(10, frame[9]);

    return frameObj->praseFrameData(device, cmdStr, dataByteArray);
}
