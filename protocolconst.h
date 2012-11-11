#ifndef PROTOCOLCONST_H
#define PROTOCOLCONST_H

//帧标志
#ifndef FRA_SGN_STX
#define FRA_SGN_STX 0xC0
#endif

#ifndef FRA_SGN_ETX
#define FRA_SGN_ETX 0xC1
#endif

//设备类型
#ifndef DEV_TYPE_ARM
#define DEV_TYPE_ARM 0x01
#endif

#ifndef DEV_TYPE_433M
#define DEV_TYPE_433M 0x02
#endif

#ifndef DEV_TYPE_2DOT4G
#define DEV_TYPE_2DOT4G 0x03
#endif

#ifndef DEV_TYPE_ZIGBEE
#define DEV_TYPE_ZIGBEE 0x04
#endif

#ifndef DEV_TYPE_BLUETOOTH
#define DEV_TYPE_BLUETOOTH 0x05
#endif

#ifndef DEV_TYPE_HF
#define DEV_TYPE_HF 0x06
#endif

#ifndef DEV_TYPE_UHF
#define DEV_TYPE_UHF 0x07
#endif

//命令状态
#ifndef CMD_STA_REQ
#define CMD_STA_REQ 0xFF
#endif

#ifndef CMD_STA_ACK
#define CMD_STA_ACK 0x00
#endif

//类静态成员常量初始化函数
#ifndef IOTFRAME_INIT_FUN
#define IOTFRAME_INIT_FUN \
QMap<char, QString> iotFrame::init(int type) \
{ \
    QMap<char, QString> rObj; \
    switch(type) \
    { \
    case 0:/* 设备类型定义 */ \
        rObj[0x01] = "ARM"; \
        rObj[0x02] = "433Mhz"; \
        rObj[0x03] = "2.4G"; \
        rObj[0x04] = "Zigbee"; \
        rObj[0x05] = "Bluetooth"; \
        rObj[0x06] = "HF"; \
        rObj[0x07] = "UHF"; \
        break;\
    case 1:/* 命令描述定义 */ \
        rObj[0x21] = "应答"; \
        rObj[0x22] = "定时上传"; \
        rObj[0x23] = "按键突发上传"; \
        break;\
    case 2:/* IOT-EB类型定义 */ \
        rObj[0x02] = "IOT-EB2"; \
        rObj[0x03] = "IOT-EB3"; \
        rObj[0x04] = "IOT-EB4"; \
        rObj[0x05] = "IOT-EB5"; \
        rObj[0x06] = "IOT-EB6"; \
        rObj[0x07] = "IOT-EB7(雨滴传感器)"; \
        rObj[0x0F] = "IOT-EB15(心率检测传感器)"; \
        break;\
    } \
    return rObj; \
}
#endif

#endif // PROTOCOLCONST_H
