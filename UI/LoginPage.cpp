#include "LoginPage.h"
#include "qdebug.h"
#include "qjsondocument.h"
#include "qjsonobject.h"
#include "ui_LoginPage.h"
#include "HttpInterFace.h"
#include "HttpUserInfo.h"

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

    ui->stackedWidget_2->setCurrentIndex(0);
    ui->code_label_click->setVisible(false);
    m_time = 60;

    connect(&m_timer, &QTimer::timeout, this, &LoginPage::onTimeout);
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

//记录登录状态
void LoginPage::on_login_status_clicked(bool checked)
{

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

void LoginPage::mouseReleaseEvent(QMouseEvent *event)
{

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
    QVariantMap data = HttpInterFace::getInstance()->loginToServer("13333333333", "654321");
    if(data["code"].toInt() == 1)
    {
        QJsonObject jsonObject = QJsonObject::fromVariantMap(data);        
        HttpUserInfo::instance()->setLoginInfo(data["data"].toMap());
        accept();
    }
    else
    {
        qDebug()<<"login message ---"<<data["message"].toInt();
    }
}

void LoginPage::on_next_page_btn_clicked()
{    
    QVariantMap Captchadata =  HttpInterFace::getInstance()->getCaptcha("13333333333","+86");
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
        qDebug()<<"Captchadata message ---"<<Captchadata;
    }
}

//获取帮助
void LoginPage::on_help_btn_clicked()
{

}


void LoginPage::on_closeBtn_clicked()
{
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

