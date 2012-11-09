#ifndef FRAMEPARSER_H
#define FRAMEPARSER_H

//#include <QWidget>
#include <QMap>
#include <QByteArray>
#include <QString>

#include "iotframe.h"
#include "crc_ccitt.h"

class frameParser
{
public:
    frameParser();
    ~frameParser();
    bool praseFrame(const QByteArray &frame, iotFrame *frameObj);
};

#endif // FRAMEPARSER_H
