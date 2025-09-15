#ifndef GLOBAL_H
#define GLOBAL_H
#include <QApplication>
#include <QDebug>
#include <QDateTime>
#include <QFontDatabase>
#include <QLayout>
#include <mainwindow.h>

extern QString g_downloadImages;
extern QString g_appData;
extern QString g_roomID;
extern QString g_multipleAuthoriation;
extern bool g_isManager;
extern bool g_isHomeowner;
extern MainWindow *g_main;

void cleanupLayout(QLayout *target);
bool deleteDir(const QString &dirName);
int  dirFileSize(const QString &path);
QString getCpuId();
void CreateDir();
qint32 getWebTime();
QString mapDownloadImagePath(QString url);
void showMapTojson(QVariantMap data);
QString replaceEmojiTagsSimple(const QString &text);
QString restoreEmojiTags(const QString &htmlText);
bool isAutoStartEnabled();
void setAutoStart(bool enable);






#endif // !GLOBAL_H
