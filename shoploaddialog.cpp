#include "shoploaddialog.h"
#include "ui_shoploaddialog.h"
#include "common.h"
#include <qdebug.h>
#include <QTime>
ShopLoadDialog::ShopLoadDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShopLoadDialog)
{
    ui->setupUi(this);
    connect(parent,SIGNAL(F1en()),this,SLOT(setEnLan()));
    connect(parent,SIGNAL(F2zh()),this,SLOT(setZhLan()));
}

ShopLoadDialog::~ShopLoadDialog()
{
    delete ui;
}
void ShopLoadDialog::setEnLan()
{
    QTranslator trans;
    QString buff = QCoreApplication::applicationDirPath()+ "/";
    trans.load(buff+"en.qm");
    qApp->installTranslator(&trans);
    ui->retranslateUi(this);
}
void ShopLoadDialog::setZhLan()
{
    QTranslator trans;
    QString buff = QCoreApplication::applicationDirPath()+ "/";
    trans.load(buff+"zh.qm");
    qApp->installTranslator(&trans);
    ui->retranslateUi(this);
}
void ShopLoadDialog::on_pushButton_clicked()
{
    QByteArray Sdata;

    //系统编号
    QString systemIDStr = ui->lineEdit->text();
    quint32 systemID = systemIDStr.toInt();

    QString systemIDUnint32_str = QString::number(systemID,16);
    QString systemID_hex = systemIDUnint32_str.rightJustified(8,QLatin1Char('0'));
    //QString float_str = QString("%1").arg(i,8,16,0);
    QString systemIDdataStr = systemID_hex.mid(6,2)+" "+systemID_hex.mid(4,2)+" "+systemID_hex.mid(2,2)+" "+systemID_hex.mid(0,2)+" ";
    int systemIDCheckSumInt = systemID_hex.mid(6,2).toInt(nullptr,16) + systemID_hex.mid(4,2).toInt(nullptr,16)+systemID_hex.mid(2,2).toInt(nullptr,16)+systemID_hex.mid(0,2).toInt(nullptr,16);

    //校验和
    int SdataCheckSum = systemIDCheckSumInt + 4;

    QString SdataCheckSumHexStr= QString::number(SdataCheckSum,16).right(2);

    QString  SdataStr= "EB 90 04 "+systemIDdataStr+SdataCheckSumHexStr;

     Sdata = HexStringToByteArray(SdataStr);

     //输入日志
     // 获取当前时间字符串
     QDateTime current_date_time =QDateTime::currentDateTime();
     QString dateStr =current_date_time.toString("[yyyy-MM-dd hh:mm:ss]");
     QString dateTimeStr = dateStr + "\n";
     QString bookDataStr = tr("装订系统编号：") + tr("系统编号=")+ systemIDStr +"\n";
     QString sendBookDataStr = dateTimeStr+bookDataStr;
     emit bookLogCMD(sendBookDataStr);

    emit systemIDCMD(Sdata);
}

void ShopLoadDialog::on_pushButton_4_clicked()
{
    this->close();
}

void ShopLoadDialog::on_pushButton_2_clicked()
{

}

void ShopLoadDialog::on_pushButton_3_clicked()
{

}
