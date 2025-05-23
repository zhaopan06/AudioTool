#ifndef CLIENTCONFIG_H
#define CLIENTCONFIG_H

#include <QObject>
#include <QSettings>

class ClientConfig : public QObject
{
    Q_OBJECT
public:
    static ClientConfig* getInstance();

public:
    /**
     * @brief 写文件
     * @param strKey 键
     * @param strValue 键对应的值
     * @date 18-03-15
     * @author zjj
     */
    void writeIniFile(QString strGroup, QString strKey, QString strValue);

    /**
     * @brief 读文件
     * @param strKey 键
     * @param strValue 键对应的值
     * @date 18-03-15
     * @author zjj
     */
    QString readIniFile(QString strGroup, QString strKey);

signals:

public slots:

private:
    explicit ClientConfig(QObject *parent = nullptr);

private:
    static ClientConfig* pClientConfig;
};

#endif // CLIENTCONFIG_H
