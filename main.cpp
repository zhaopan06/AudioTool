#include "mainwindow.h"
#include "Global.h"
#include "qevent.h"
#include <QApplication>
#include <QMessageBox>
#include <Psapi.h>
#include "clientconfig.h"

#ifdef _DEBUG
#ifdef _WIN32
#pragma comment(lib,"D:/Visual Leak Detector/lib/Win32/vld.lib")
#include "D:/Visual Leak Detector/include/vld.h"
#endif
#endif

bool getIsHaveMyselfPoss()
{
    unsigned long aProcesses[1024], cbNeeded, cProcesses;
    if(!EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded)) {
        qDebug() << "EnumProcesses failed:" << GetLastError();
        return false;
    }

    QStringList lprocess;
    cProcesses = cbNeeded / sizeof(unsigned long);
    const DWORD bufSize = MAX_PATH;

    for(unsigned int i = 0; i < cProcesses; i++)
    {
        if(aProcesses[i] == 0)
            continue;

        HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ,FALSE, aProcesses[i]);
        if(!hProcess)
            continue;

        wchar_t buffer[bufSize] = {0};
        if(GetModuleBaseName(hProcess, nullptr, buffer, bufSize))
        {
            if(QString::fromWCharArray(buffer) == "AudioTool.exe")
            {
                lprocess << QString::fromWCharArray(buffer);
                if(lprocess.size() > 1)
                {
                    CloseHandle(hProcess);
                    return true;
                }
            }
        }
        CloseHandle(hProcess);
    }
    return lprocess.size() > 1;
}

bool findWindows()
{
    HWND hWnd = ::FindWindow(NULL, L"篮伴语音-PC");
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
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);

    QGuiApplication::setHighDpiScaleFactorRoundingPolicy(Qt::HighDpiScaleFactorRoundingPolicy::PassThrough);
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
    QApplication a(argc, argv);

    if(getIsHaveMyselfPoss())
    {
        findWindows();
        return 0;
    }

    QString qssAath = QCoreApplication::applicationDirPath() + "/app.qss";
    QFile fStyle(qssAath);
    if (!fStyle.open(QIODevice::ReadOnly))
    {
        QMessageBox::warning(0,"open error","error",QMessageBox::Yes);
    }
    a.setStyleSheet(fStyle.readAll());

    CreateDir();

    QString powerOn = ClientConfig::getInstance()->readIniFile("CLIENT", "powerOn");
    if(powerOn.isEmpty())
    {
        ClientConfig::getInstance()->writeIniFile("CLIENT", "powerOn", "1");
        setAutoStart(true);
    }

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
