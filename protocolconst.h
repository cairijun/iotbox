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

#endif // PROTOCOLCONST_H
