#include "iotlog.h"

iotLog::iotLog()
{
}

iotLog::iotLog(QTreeWidget *uiObj)
{
    iotLog();
    this->uiObj = uiObj;
}

iotLog::~iotLog()
{
}

bool iotLog::update(const iotFrame &frameObj)
{
    QMap<QString, QString> deviceInfo;
    if(!frameObj.getDeviceInfo(deviceInfo))
        return false;
    QString deviceFullAddress = deviceInfo["MID_ADDR"] + "#" + deviceInfo["DST_ADDR"];
    if(logData.contains(deviceFullAddress)) {
        logData[deviceFullAddress].push_back(frameObj);
    }
    else {
        logData[deviceFullAddress] = QVector<iotFrame>(1, frameObj);
    }
    updateUI();
    return true;
}

bool iotLog::getDeviceCurrentData(QMap<QString, QMap<QString, QString> > &data) const
{
    QMap<QString, QVector<iotFrame> >::const_iterator i = logData.constBegin();
    while(i != logData.constEnd()) {
        data[i.key()] = makeDataMap(i.value().last());
        i++;
    }
    return true;
}

bool iotLog::getDeviceCurrentData(const QString &device, QMap<QString, QString> &data) const
{
    data = makeDataMap(logData[device].last());
    return true;
}

bool iotLog::getDeviceCurrentData(const QString &device, const QString &key, QString &value) const
{
    value = makeDataMap(logData[device].last())[key];
    return true;
}

bool iotLog::getDeviceLog(const QString &device, QVector<QMap<QString, QString> > &log) const
{
    const QVector<iotFrame> &frameObjVec = logData[device];
    for(int i = 0 ; i < frameObjVec.count() ; i++) {
        log.push_back(makeDataMap(frameObjVec[i]));
    }
    return true;
}


bool iotLog::updateUI()
{
    QMap<QString, QMap<QString, QString> > data;
    if(!getDeviceCurrentData(data))
        return false;
    uiObj->clear();
    QMap<QString, QMap<QString, QString> >::const_iterator i = data.constBegin();
    while(i != data.constEnd()) {
        QTreeWidgetItem aTopItem(QStringList() << i.key() << i.value()["节点类型"]);
        QMap<QString, QString>::const_iterator j = i.value().constBegin();
        while(j != i.value().constEnd()) {
            aTopItem.addChild(new QTreeWidgetItem(
                                  QStringList(j.key() + "：" + j.value())));
            j++;
        }
        i++;
        uiObj->addTopLevelItem(&aTopItem);
    }
    return true;
}


QMap<QString, QString> iotLog::makeDataMap(const iotFrame &frameObj) const
{
    QMap<QString, QString> returnData, deviceInfo;
    frameObj.getFrameData(returnData);
    frameObj.getDeviceInfo(deviceInfo);
    returnData["设备地址"] = deviceInfo["MID_ADDR"] + "#" + deviceInfo["DST_ADDR"];
    QString command;
    frameObj.getCommand(command);
    returnData["来源指令"] = command;
    returnData["更新时间"] = QTime::currentTime().toString();
    return returnData;
}
