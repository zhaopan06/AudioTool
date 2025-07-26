#include "mainwindow.h"
#include "Global.h"
#include "qevent.h"
#include <QApplication>
#include <QMessageBox>
#include <Psapi.h>
#include "clientconfig.h"

bool getIsHaveMyselfPoss()
{
    unsigned long aProcesses[1024], cbNeeded, cProcesses;
    if( !EnumProcesses(aProcesses,sizeof(aProcesses),&cbNeeded) )
    {
        qDebug()<<"text01";
    }
    QStringList lprocess;

    cProcesses = cbNeeded / sizeof(unsigned long);
    for(unsigned int i = 0; i < cProcesses; i++)
    {
        if(aProcesses[i] == 0)
        {
            continue;
        }
        //获取已存在的进程对象句柄
        HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, 0, aProcesses[i]);
        wchar_t buffer[50];
        GetModuleBaseName(hProcess, 0, buffer, 50); //获取进程名
        CloseHandle(hProcess);
        if(QString::fromWCharArray(buffer) == "AudioTool.exe")
            lprocess << QString::fromWCharArray(buffer); //Qt开源库
    }
    return lprocess.size() > 1;
}

bool findWindows()
{
    HWND hWnd = ::FindWindow(NULL, L"篮板语音-PC");
    if (hWnd != NULL)
    {
        ::ShowWindow(hWnd, SW_RESTORE );
        ::SetActiveWindow(hWnd);
        ::SetForegroundWindow( hWnd );
        ::SetForegroundWindow(::GetLastActivePopup(hWnd));

        QString command = QString("showAudioTool");
        std::string param = command.toStdString();
        COPYDATASTRUCT data;
        data.dwData = 0;
        data.cbData = param.length();
        data.lpData = &param[0];
        ::SendMessage(hWnd, WM_COPYDATA, NULL, (LPARAM)&data);
        return true;
    }
    else
    {
        return false;
    }
}

int main(int argc, char *argv[])
{
    QGuiApplication::setHighDpiScaleFactorRoundingPolicy(Qt::HighDpiScaleFactorRoundingPolicy::PassThrough);
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
    QApplication a(argc, argv);

    if(getIsHaveMyselfPoss())
    {
        if(findWindows())
        {
            return 0;
        }
    }

    QFile fStyle("app.qss");
    if (!fStyle.open(QIODevice::ReadOnly))
    {
        QMessageBox::warning(0,"open error","error",QMessageBox::Yes);
    }
    a.setStyleSheet(fStyle.readAll());

    CreateDir();

    MainWindow w;

    int x = ClientConfig::getInstance()->readIniFile("CLIENT", "x").toInt();
    int y = ClientConfig::getInstance()->readIniFile("CLIENT", "y").toInt();
    int width = ClientConfig::getInstance()->readIniFile("CLIENT", "width").toInt();
    int height = ClientConfig::getInstance()->readIniFile("CLIENT", "height").toInt();
    if(width > 1000)
    {
        w.resize(width, height);
        w.move(x,y);
    }
    bool isMax = ClientConfig::getInstance()->readIniFile("CLIENT", "isMax").toInt();
    w.initMax(isMax);
    if(isMax)
    {
        w.showMaximized();
    }
    else
        w.show();
    return a.exec();
}
