#include "LoginPage.h"
#include "CommonTool.h"
#include "WebEngView.h"
#include "qjsonobject.h"
#include "qvalidator.h"
#include "ui_LoginPage.h"
#include "HttpInterFace.h"
#include "HttpUserInfo.h"
#include "MsgBox.h"
#include "clientconfig.h"
#include <QWebEngineView>
#include <QProcess>

LoginPage::LoginPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginPage)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground, true);

    ui->lineEdit->setMaxLength(1);
    ui->lineEdit_2->setMaxLength(1);
    ui->lineEdit_3->setMaxLength(1);
    ui->lineEdit_4->setMaxLength(1);
    ui->lineEdit_5->setMaxLength(1);
    ui->lineEdit_6->setMaxLength(1);
    ui->cap_mobile->setMaxLength(11);

    ui->lineEdit_2->installEventFilter(this);
    ui->lineEdit_3->installEventFilter(this);
    ui->lineEdit_4->installEventFilter(this);
    ui->lineEdit_5->installEventFilter(this);
    ui->lineEdit_6->installEventFilter(this);


    QIntValidator *validatorWithRange = new QIntValidator(this);
    ui->lineEdit->setValidator(validatorWithRange);
    ui->lineEdit_2->setValidator(validatorWithRange);
    ui->lineEdit_3->setValidator(validatorWithRange);
    ui->lineEdit_4->setValidator(validatorWithRange);
    ui->lineEdit_5->setValidator(validatorWithRange);
    ui->lineEdit_6->setValidator(validatorWithRange);
    QDoubleValidator *validator = new QDoubleValidator(this);
    ui->cap_mobile->setValidator(validator);

    ui->stackedWidget_2->setCurrentIndex(0);
    ui->code_label_click->setVisible(false);
    m_time = 60;

    QString isrememberpasswd = ClientConfig::getInstance()->readIniFile("CLIENT", "isrememberpasswd");
    if(isrememberpasswd == "1")
    {
        ui->login_status->setChecked(true);
        QString strUserName = ClientConfig::getInstance()->readIniFile("CLIENT", "userName");
        ui->cap_mobile->setText(strUserName);
    }
    else
    {
        ui->login_status->setChecked(false);
    }

    connect(&m_timer, &QTimer::timeout, this, &LoginPage::onTimeout);

    connect(HttpInterFace::getInstance(), &HttpInterFace::error_msg_box_text, this,[&](QString msg, int code){

        if(0 == code)
        {
            ClientConfig::getInstance()->setLoginData(QVariantMap());
            rebootExe();
        }
        else if(356 == code)
        {
            MsgBox::showMsg(this,tr("提示"), msg + " code=" + QString::number(code) );
            ClientConfig::getInstance()->setLoginData(QVariantMap());
            rebootExe();
        }
        else
        {
            MsgBox::showMsg(this,tr("提示"), msg + " code=" + QString::number(code) );
        }
    });
}

LoginPage::~LoginPage()
{
    delete ui;
}

void LoginPage::onTimeout()
{
    m_time--;
    QString label = QString::number(m_time) + tr("秒后可重新获取验证码");
    ui->code_label->setText(label);
    if(m_time<= 0)
    {
        m_timer.stop();
        ui->code_label->setVisible(false);
        ui->code_label_click->setVisible(true);
    }
}

void LoginPage::mouseMoveEvent(QMouseEvent* event)
{
    QPoint distance = event->globalPos() - mouseStartPoint;
    if (distance.manhattanLength() > QApplication::startDragDistance())
    {
        this->move(windowTopLeftPoint + distance);
    }
}

void LoginPage::mousePressEvent(QMouseEvent* event)
{
    if(event->button() == Qt::LeftButton)
    {
        mouseStartPoint = event->globalPos();
        windowTopLeftPoint = this->frameGeometry().topLeft();
    }
}

bool LoginPage::eventFilter(QObject *watched, QEvent *event)
{
    if(event->type() == QEvent::KeyPress)
    {
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
        if (keyEvent->key() == Qt::Key_Backspace)
        {
            if (watched == ui->lineEdit_6)
            {
                ui->lineEdit_5->setFocus();
                ui->lineEdit_5->selectAll();
            }
            else if (watched == ui->lineEdit_5)
            {
                ui->lineEdit_4->setFocus();
                ui->lineEdit_4->selectAll();
            }
            else if (watched == ui->lineEdit_4)
            {
                ui->lineEdit_3->setFocus();
                ui->lineEdit_3->selectAll();
            }
            else if (watched == ui->lineEdit_3)
            {
                ui->lineEdit_2->setFocus();
                ui->lineEdit_2->selectAll();
            }
            else if (watched == ui->lineEdit_2)
            {
                ui->lineEdit->setFocus();
                ui->lineEdit->selectAll();
            }
            return false;
        }
    }

    return QDialog::eventFilter(watched, event);
}

void LoginPage::on_back_btn_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}

void LoginPage::on_lineEdit_textEdited(const QString &arg1)
{
    if(arg1.isEmpty())
    {
        if(m_count > 0)
            m_count--;
        ui->lineEdit->setStyleSheet("background: rgba(0,0,0,0.2);"
                                    "border-radius: 8px;"
                                    "border: 1px solid #7B5AE4;"
                                    "font-family: \"微软雅黑\";"
                                    "font-size: 26px;"
                                    "color: #FFFFFF;");       
    }
    else
    {
        m_count++;
        ui->lineEdit->setStyleSheet("background: #7B5AE4;"
                                    "border-radius: 8px;"
                                    "border: 1px solid #7B5AE4;"
                                    "font-family: \"微软雅黑\";"
                                    "font-size: 26px;"
                                    "color: #FFFFFF;");
        ui->lineEdit_2->setFocus();
        ui->lineEdit_2->selectAll();
    }

    updateBtnStyle();
}


void LoginPage::on_lineEdit_2_textEdited(const QString &arg1)
{
    if(arg1.isEmpty())
    {
        if(m_count > 0)
            m_count--;
        ui->lineEdit_2->setStyleSheet("background: rgba(0,0,0,0.2);"
                                      "border-radius: 8px;"
                                      "border: 1px solid #7B5AE4;"
                                      "font-family: \"微软雅黑\";"
                                      "font-size: 26px;"
                                      "color: #FFFFFF;");       
    }
    else
    {
        m_count++;
        ui->lineEdit_2->setStyleSheet("background: #7B5AE4;"
                                      "border-radius: 8px;"
                                      "border: 1px solid #7B5AE4;"
                                      "font-family: \"微软雅黑\";"
                                      "font-size: 26px;"
                                      "color: #FFFFFF;");
        ui->lineEdit_3->setFocus();
        ui->lineEdit_3->selectAll();
    }

    updateBtnStyle();
}


void LoginPage::on_lineEdit_3_textEdited(const QString &arg1)
{
    if(arg1.isEmpty())
    {
        if(m_count > 0)
            m_count--;
        ui->lineEdit_3->setStyleSheet("background: rgba(0,0,0,0.2);"
                                      "border-radius: 8px;"
                                      "border: 1px solid #7B5AE4;"
                                      "font-family: \"微软雅黑\";"
                                      "font-size: 26px;"
                                      "color: #FFFFFF;");        
    }
    else
    {
        m_count++;
        ui->lineEdit_3->setStyleSheet("background: #7B5AE4;"
                                      "border-radius: 8px;"
                                      "border: 1px solid #7B5AE4;"
                                      "font-family: \"微软雅黑\";"
                                      "font-size: 26px;"
                                      "color: #FFFFFF;");
        ui->lineEdit_4->setFocus();
        ui->lineEdit_4->selectAll();
    }

    updateBtnStyle();
}


void LoginPage::on_lineEdit_4_textEdited(const QString &arg1)
{
    if(arg1.isEmpty())
    {
        if(m_count > 0)
            m_count--;
        ui->lineEdit_4->setStyleSheet("background: rgba(0,0,0,0.2);"
                                      "border-radius: 8px;"
                                      "border: 1px solid #7B5AE4;"
                                      "font-family: \"微软雅黑\";"
                                      "font-size: 26px;"
                                      "color: #FFFFFF;");
    }
    else
    {
        m_count ++;
        ui->lineEdit_4->setStyleSheet("background: #7B5AE4;"
                                      "border-radius: 8px;"
                                      "border: 1px solid #7B5AE4;"
                                      "font-family: \"微软雅黑\";"
                                      "font-size: 26px;"
                                      "color: #FFFFFF;");
        ui->lineEdit_5->setFocus();
        ui->lineEdit_5->selectAll();
    }

    updateBtnStyle();
}


void LoginPage::on_lineEdit_5_textEdited(const QString &arg1)
{
    if(arg1.isEmpty())
    {
        if(m_count > 0)
            m_count--;
        ui->lineEdit_5->setStyleSheet("background: rgba(0,0,0,0.2);"
                                      "border-radius: 8px;"
                                      "border: 1px solid #7B5AE4;"
                                      "font-family: \"微软雅黑\";"
                                      "font-size: 26px;"
                                      "color: #FFFFFF;");
    }
    else
    {
        m_count++;
        ui->lineEdit_5->setStyleSheet("background: #7B5AE4;"
                                      "border-radius: 8px;"
                                      "border: 1px solid #7B5AE4;"
                                      "font-family: \"微软雅黑\";"
                                      "font-size: 26px;"
                                      "color: #FFFFFF;");
        ui->lineEdit_6->setFocus();
        ui->lineEdit_6->selectAll();
    }

    updateBtnStyle();

}


void LoginPage::on_lineEdit_6_textEdited(const QString &arg1)
{
    if(arg1.isEmpty())
    {
        if(m_count > 0)
            m_count--;

        ui->lineEdit_6->setStyleSheet("background: rgba(0,0,0,0.2);"
                                      "border-radius: 8px;"
                                      "border: 1px solid #7B5AE4;"
                                      "font-family: \"微软雅黑\";"
                                      "font-size: 26px;"
                                      "color: #FFFFFF;");
    }
    else
    {
        m_count++;
        ui->lineEdit_6->setStyleSheet("background: #7B5AE4;"
                                      "border-radius: 8px;"
                                      "border: 1px solid #7B5AE4;"
                                      "font-family: \"微软雅黑\";"
                                      "font-size: 26px;"
                                      "color: #FFFFFF;");
    }
    updateBtnStyle();

    if(6 == m_count)
    {
        on_login_btn_clicked();
    }
}

void LoginPage::updateBtnStyle()
{
    if(m_count >=6)
    {
        ui->login_btn->setEnabled(true);
        m_count = 6;
    }
    else
    {
        ui->login_btn->setEnabled(false);
    }
}

void LoginPage::on_back_label_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}


void LoginPage::on_login_btn_clicked()
{
    QString pass = ui->lineEdit->text();
    pass.append(ui->lineEdit_2->text());
    pass.append(ui->lineEdit_3->text());
    pass.append(ui->lineEdit_4->text());
    pass.append(ui->lineEdit_5->text());
    pass.append(ui->lineEdit_6->text());

    ui->login_btn->setEnabled(false);
    QString acc =  ui->cap_mobile->text();
    HttpInterFace::getInstance()->loginToServer(acc, pass, [&,acc](const QVariant &vart){
        QVariantMap data = vart.toMap();
        if(data["code"].toInt() == 1)
        {
            HttpUserInfo::instance()->setLoginInfo(data["data"].toMap());
            ClientConfig::getInstance()->setLoginData(data["data"].toMap());

            if(ui->login_status->isChecked())
            {
                ClientConfig::getInstance()->writeIniFile("CLIENT", "isrememberpasswd", "1" );
                ClientConfig::getInstance()->writeIniFile("CLIENT", "userName", acc);
            }
            else
            {
                ClientConfig::getInstance()->writeIniFile("CLIENT", "isrememberpasswd", "0" );
            }
            ui->login_btn->setEnabled(true);
            accept();
        }
        else
        {
            ui->login_btn->setEnabled(true);
        }
    }, [=](int code, const QString& errorStr){       
        ui->login_btn->setEnabled(true);
    },this);
}

void LoginPage::on_next_page_btn_clicked()
{    
    QString acc =  ui->cap_mobile->text();
    if (acc.isEmpty())
    {
        MsgBox::showMsg(this, QStringLiteral("提示"), QStringLiteral("请输入手机号"));
        return;
    }
    QRegularExpression regex("^1[3-9]\\d{9}$");
    if(!regex.match(acc).hasMatch())
    {
        MsgBox::showMsg(this, QStringLiteral("提示"), QStringLiteral("请输入正确的手机号"));
        return;
    }

    if(!ui->radioButton->isChecked())
    {
        MsgBox::showMsg(this, QStringLiteral("提示"), QStringLiteral("请勾选用户协议"));
        return;
    }
    ui->next_page_btn->setEnabled(false);

    HttpInterFace::getInstance()->getCaptcha(acc,"+86", [&](const QVariant &data){

        QVariantMap Captchadata = data.toMap();
        if(Captchadata["code"].toInt() == 1)
        {
            QString str = ui->cap_mobile->text();
            str = "+86" + str.left(3) + "***" + str.right(2);
            ui->label_9->setText(str);
            ui->stackedWidget_2->setCurrentIndex(1);

            m_time = 60;
            m_timer.start(1000);
            ui->code_label->setVisible(true);
            QString label = QString::number(m_time) + tr("秒后可重新获取验证码");
            ui->code_label->setText(label);

            ui->code_label_click->setVisible(false);
            ui->lineEdit->setFocus();
        }
        else
        {
            QString code = Captchadata["code"].toString();
            if(code.isEmpty())
                MsgBox::showMsg(this, tr("提示"),tr("网络连接失败，请重新登录"));
            else
                MsgBox::showMsg(this, tr("提示"), Captchadata["code"].toString());
        }
        ui->next_page_btn->setEnabled(true);

    }, [&](int code, const QString& str){
           ui->next_page_btn->setEnabled(true);
        },this);
}

//获取帮助
void LoginPage::on_help_btn_clicked()
{

}


void LoginPage::on_closeBtn_clicked()
{
    rejected();
    exit(0);
}


void LoginPage::on_minBtn_clicked()
{
    this->showMinimized();
}

//帮助
void LoginPage::on_help_Btn_1_clicked()
{

}

//重新获取验证码
void LoginPage::on_code_label_click_clicked()
{
    on_next_page_btn_clicked();
}


void LoginPage::on_Btn_clicked()
{
    WebEngView page;
    page.setWindowTitle(QStringLiteral("用户服务协议"));
    page.init(H5Test + QString("Agreements/ServiceAgreement"));
    page.exec();
}

void LoginPage::on_btn1_clicked()
{
    WebEngView page;
    page.setWindowTitle(QStringLiteral("隐私协议"));
    page.init(H5Test + QString("Agreements/PrivacyPolicy"));
    page.exec();
}

