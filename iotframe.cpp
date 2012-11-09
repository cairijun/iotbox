#include "iotframe.h"

const QMap<char, QString> iotFrame::DEV_TYPE_MAP = iotFrame::init(0);
const QMap<char, QString> iotFrame::CMD_NAME_MAP = iotFrame::init(1);
const QMap<char, QString> iotFrame::IOT_EB_TYPE_MAP = iotFrame::init(2);

IOTFRAME_INIT_FUN

iotFrame::iotFrame()
{
}

iotFrame::~iotFrame()
{
    delete &device;
    delete &command;
    delete &data;
}

iotFrame::iotFrame(
        const QMap<QString, QString> &device, const QString &command, const QByteArray &data)
{
    iotFrame();
    praseFrameData(device, command, data);
}

bool iotFrame::praseFrameData(
        const QMap<QString, QString> &device, const QString &command, const QByteArray &data)
{
    this->device = device;
    this->command = command;
    return parseMainData(data);
}

bool iotFrame::getFrameData(QMap<QString, QString> &data)
{
    if(!this->data.empty()) {
        data = this->data;
        return true;
    }
    else
        return false;
}

bool iotFrame::getFrameData(QMap<QString, QString> &data, QString &device)
{
    if(!this->data.empty()) {
        device = this->device["MID_ADDR"];
        data = this->data;
        return true;
    }
    else
        return false;
}

bool iotFrame::getFrameData(const QString &key, QString &value)
{
    if(!this->data.empty() && this->data.contains(key)) {
        value = this->data[key];
        return true;
    }
    else
        return false;
}

bool iotFrame::getDeviceInfo(QMap<QString, QString> &device)
{
    if(!this->device.empty()) {
        device = this->device;
        return true;
    }
    else
        return false;
}

bool iotFrame::getCommand(QString &command)
{
    if(this->command.length()) {
        command = this->command;
        return true;
    }
    else
        return false;
}

//有效数据解析函数
bool iotFrame::parseMainData(const QByteArray &data)
{
    this->data["温度"] = QString::number(data[0]);
    this->data["电压"] = QString::number(data[1] / 10.0, 'f', 1) + "V";
    this->data["父节点地址"] = "0x" +
            QString::number(static_cast<uint>(data[2] << 8) + static_cast<uint>(data[3]), 16);
    this->data["节点类型"] = iotFrame::IOT_EB_TYPE_MAP[data[4]];
    bool returnValue = false;
    switch(data[4])
    {
    case 0x02:
        returnValue = parseIOTEB2(data);
        break;
    case 0x03:
        returnValue = parseIOTEB3(data);
        break;
    case 0x04:
        returnValue = parseIOTEB4(data);
        break;
    case 0x05:
        returnValue = parseIOTEB5(data);
        break;
    case 0x06:
        returnValue = parseIOTEB6(data);
        break;
    case 0x07:
        returnValue = parseIOTEB7(data);
        break;
    case 0x0f:
        returnValue = parseIOTEB15(data);
        break;
    }
    return returnValue;
}

bool iotFrame::parseIOTEB2(const QByteArray &data)
{
    if(command == iotFrame::CMD_NAME_MAP[0x23]) {
        this->data["K1状态"] = (data[5] & 0x80) ? "触发" : "正常";
        this->data["K2状态"] = (data[5] & 0x40) ? "触发" : "正常";
        this->data["K3状态"] = (data[5] & 0x20) ? "触发" : "正常";
    }
    else {
        this->data["直流电机转速"] = QString::number(static_cast<uint>(data[5]));
        this->data["转动方向"] = (data[6] & 0x80) ? "逆时针" : "顺时针";
        this->data["继电器状态"] = (data[6] & 0x40) ? "断" : "通";
        this->data["LED1状态"] = (data[6] & 0x20) ? "灭" : "亮";
        this->data["LED2状态"] = (data[6] & 0x10) ? "灭" : "亮";
    }
    return true;
}
bool iotFrame::parseIOTEB3(const QByteArray &data)
{
    this->data["距离长度"] = QString::number(static_cast<uint>(data[5])) + "cm";
    this->data["亮度"] = QString::number(static_cast<uint>(data[6]));
    return true;
}
bool iotFrame::parseIOTEB4(const QByteArray &data)
{
    this->data["可燃气体警报"] = data[5] ? "YES" : "NO";
    this->data["亮度"] = QString::number(static_cast<uint>(data[6]));
    return true;
}
bool iotFrame::parseIOTEB5(const QByteArray &data)
{
    this->data["大气压"] = QString::number(static_cast<uint>(data[5])) + "Kpa";
    this->data["湿度"] = QString::number(static_cast<uint>(data[6])) + "%";
    return true;
}
bool iotFrame::parseIOTEB6(const QByteArray &data)
{
    this->data["人体靠近"] = data[5] ? "YES" : "NO";
    this->data["亮度"] = QString::number(static_cast<uint>(data[6]));
    return true;
}
bool iotFrame::parseIOTEB7(const QByteArray &data)
{
    this->data["是否检测到雨滴"] = data[5] ? "YES" : "NO";
    this->data["亮度"] = QString::number(static_cast<uint>(data[6]));
    return true;
}
bool iotFrame::parseIOTEB15(const QByteArray &data)
{
    this->data["心率数据"] = QString::number(static_cast<uint>(data[5])) + "/min";
    this->data["亮度"] = QString::number(static_cast<uint>(data[6]));
    return true;
}
