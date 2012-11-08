iotbox
======

物联网实验箱项目

主要类
------

###iotFrame类

有效数据段解析器。同时有数据帧储存功能。

    iotFrame()
    iotFrame(const QMap<QString, QString> &device, const QString &command, const QByteArray &data)
    ~iotFrame()
    bool praseFrameData(const QMap<QString, QString> &device, const QString &command, const QByteArray &data)
    bool getFrameData(QMap<QString, QString> &data)
    bool getFrameData(QMap<QString, QString> &data, QString &device)
    bool getFrameData(const QString &key, QString &value)
    bool getDeviceInfo(QMap<QString, QString> &device)
    bool getCommand(QString &command)

###frameParser类

数据帧解析器。

对数据帧进行初步分解，通过指令确认为IOT扩展版指令（0x21~0x23，0x24待定）后，
创建iotFrame对象进行有效数据处理并把该对象返回。

    frameParser()
    ~frameParser()
    bool praseFrame(const QByteArray &frame, iotFrame &frameObj)

###iotLog类

IOT数据记录器。

传入iotFrame对象后根据设备地址进行分类存储，同时存储每台设备的最新数据。
通过实现updateUI方法（private或protected）对UI进行更新。

    iotLog()
    iotLog(QTreeWidget &uiObj)
    ~iotLog()
    bool update(const iotFrame &frameObj)
    bool getDeviceCurrentData(QMap<QString, QMap<QString, QString>>)
    bool getDeviceCurrentData(const QString &device, QMap<QString, QString>)
    bool getDeviceCurrentData(const QString &device, const QString &key, QString &value)
    bool getDeviceLog(const QString &device, QVector<QMap<QString, QString>>)

