#include "SetTingPage.h"
#include "ui_SetTingPage.h"
#include "Global.h"
#include <QFileDialog>
#include "clientconfig.h"

SetTingPage::SetTingPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SetTingPage)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_TranslucentBackground, true);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
}

SetTingPage::~SetTingPage()
{
    delete ui;
}

void SetTingPage::init()
{
    bool isChecked = isAutoStartEnabled();
    ui->pushButton->setChecked(isChecked);

    QString AudioMsg = ClientConfig::getInstance()->readIniFile("CLIENT", "AudioMsg");
    if(AudioMsg.isEmpty())
    {
        ui->audioMsg->setChecked(false);
    }
    else
    {
        ui->audioMsg->setChecked(AudioMsg.toInt());
    }
    QString DownFileDir = ClientConfig::getInstance()->readIniFile("CLIENT", "DownFileDir");
    if(!DownFileDir.isEmpty())
    {
        ui->directory->setText(DownFileDir);
    }
}

void SetTingPage::on_pushButton_2_clicked()
{
    QString directory = QFileDialog::getExistingDirectory(this,  tr("选择文件夹"),  QDir::homePath(),
                                                          QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    ui->directory->setText(directory);
    ClientConfig::getInstance()->writeIniFile("CLIENT", "DownFileDir", directory);
}


void SetTingPage::on_closeBtn_clicked()
{
    close();
}


void SetTingPage::on_pushButton_clicked()
{
    bool isChecked = ui->pushButton->isChecked();
    setAutoStart(isChecked);
    int powerOn = isChecked? 1:0;
    ClientConfig::getInstance()->writeIniFile("CLIENT", "powerOn", QString::number(powerOn));
}

void SetTingPage::on_audioMsg_clicked()
{
    bool isChecked = ui->audioMsg->isChecked();
    int AudioMsg = isChecked? 1:0;
    ClientConfig::getInstance()->writeIniFile("CLIENT", "AudioMsg", QString::number(AudioMsg));
}

