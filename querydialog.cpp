#include "querydialog.h"
#include "ui_querydialog.h"
#include <QByteArray>
#include <QTime>
QueryDialog::QueryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QueryDialog)
{
    ui->setupUi(this);
    connect(parent,SIGNAL(F1en()),this,SLOT(setEnLan()));
    connect(parent,SIGNAL(F2zh()),this,SLOT(setZhLan()));
}

QueryDialog::~QueryDialog()
{
    delete ui;
}
void QueryDialog::setEnLan()
{
    QTranslator trans;
    QString buff = QCoreApplication::applicationDirPath()+ "/";
    trans.load(buff+"en.qm");
    qApp->installTranslator(&trans);
    ui->retranslateUi(this);
}
void QueryDialog::setZhLan()
{
    QTranslator trans;
    QString buff = QCoreApplication::applicationDirPath()+ "/";
    trans.load(buff+"zh.qm");
    qApp->installTranslator(&trans);
    ui->retranslateUi(this);
}
void QueryDialog::on_pushButton_7_clicked()
{
    this->close();
}

void QueryDialog::on_pushButton_clicked()
{
    QByteArray data;
    if(ui->comboBox->currentIndex() == 0)
    {
         data = QByteArray::fromHex("EB900F010010");

    }
    else if(ui->comboBox->currentIndex() == 1)
    {
         data = QByteArray::fromHex("EB900F010111");

    }
    else if(ui->comboBox->currentIndex() == 2)
    {
         data = QByteArray::fromHex("EB900F010212");

    }
    else if(ui->comboBox->currentIndex() == 3)
    {
         data = QByteArray::fromHex("EB900F010313");

    }
    else if(ui->comboBox->currentIndex() == 4)
    {
         data = QByteArray::fromHex("EB900F010414");

    }
    else if(ui->comboBox->currentIndex() == 5)
    {
         data = QByteArray::fromHex("EB900F011424");

    }
    else if(ui->comboBox->currentIndex() == 6)
    {
         data = QByteArray::fromHex("EB900F012434");

    }
    else if(ui->comboBox->currentIndex() == 7)
    {
         data = QByteArray::fromHex("EB900F010515");

    }
    else if(ui->comboBox->currentIndex() == 8)
    {
         data = QByteArray::fromHex("EB900F010616");

    }
    else if(ui->comboBox->currentIndex() == 9)
    {
         data = QByteArray::fromHex("EB900F010717");

    }
    else if(ui->comboBox->currentIndex() == 10)
    {
         data = QByteArray::fromHex("EB900F012838");

    }
    else if(ui->comboBox->currentIndex() == 11)
    {
         data = QByteArray::fromHex("EB900F011626");

    }
    else if(ui->comboBox->currentIndex() == 12)
    {
         data = QByteArray::fromHex("EB900F010818");

    }
    else if(ui->comboBox->currentIndex() == 13)
    {
         data = QByteArray::fromHex("EB900F011828");

    }


    //输入日志
    // 获取当前时间字符串
    QDateTime current_date_time =QDateTime::currentDateTime();
    QString dateStr =current_date_time.toString("[yyyy-MM-dd hh:mm:ss]");
    QString dateTimeStr = dateStr + "\n";
    QString bookDataStr = tr("状态切换命令：") + tr("导航状态=")+ ui->comboBox->currentIndex() + "\n";
    QString sendBookDataStr = dateTimeStr+bookDataStr;
    emit bookLogCMD(sendBookDataStr);

    emit statesChangeCMD(data);
}

void QueryDialog::on_pushButton_2_clicked()
{
    QByteArray data;
    if(ui->comboBox_2->currentIndex() == 0)
    {
         data = QByteArray::fromHex("EB900F020011");

    }
    else if(ui->comboBox_2->currentIndex() == 1)
    {
         data = QByteArray::fromHex("EB900F024051");

    }

    //输入日志
    // 获取当前时间字符串
    QDateTime current_date_time =QDateTime::currentDateTime();
    QString dateStr =current_date_time.toString("[yyyy-MM-dd hh:mm:ss]");
    QString dateTimeStr = dateStr + "\n";
    QString bookDataStr = tr("状态切换命令：") + tr("工作地点=")+ ui->comboBox_2->currentIndex() + "\n";
    QString sendBookDataStr = dateTimeStr+bookDataStr;
    emit bookLogCMD(sendBookDataStr);

    emit statesChangeCMD(data);
}

void QueryDialog::on_pushButton_3_clicked()
{
    QByteArray data;
    if(ui->comboBox_3->currentIndex() == 0)
    {
         data = QByteArray::fromHex("EB900F030012");

    }
    else if(ui->comboBox_3->currentIndex() == 1)
    {
         data = QByteArray::fromHex("EB900F038092");

    }
    //输入日志
    // 获取当前时间字符串
    QDateTime current_date_time =QDateTime::currentDateTime();
    QString dateStr =current_date_time.toString("[yyyy-MM-dd hh:mm:ss]");
    QString dateTimeStr = dateStr + "\n";
    QString bookDataStr = tr("状态切换命令：") + tr("操作模式=")+ ui->comboBox_3->currentIndex() + "\n";
    QString sendBookDataStr = dateTimeStr+bookDataStr;
    emit bookLogCMD(sendBookDataStr);
    emit statesChangeCMD(data);
}

void QueryDialog::on_pushButton_4_clicked()
{
    QByteArray data;
    if(ui->comboBox_4->currentIndex() == 0)
    {
         data = QByteArray::fromHex("EB900F041023");

    }
    else if(ui->comboBox_4->currentIndex() == 1)
    {
         data = QByteArray::fromHex("EB900F041124");

    }
    else if(ui->comboBox_4->currentIndex() == 2)
    {
         data = QByteArray::fromHex("EB900F041225");

    }
    else if(ui->comboBox_4->currentIndex() == 3)
    {
         data = QByteArray::fromHex("EB900F041326");

    }
    else if(ui->comboBox_4->currentIndex() == 4)
    {
         data = QByteArray::fromHex("EB900F042033");

    }
    else if(ui->comboBox_4->currentIndex() == 5)
    {
         data = QByteArray::fromHex("EB900F042134");

    }
    else if(ui->comboBox_4->currentIndex() == 6)
    {
         data = QByteArray::fromHex("EB900F042235");

    }
    else if(ui->comboBox_4->currentIndex() == 7)
    {
         data = QByteArray::fromHex("EB900F042336");

    }
    else if(ui->comboBox_4->currentIndex() == 8)
    {
         data = QByteArray::fromHex("EB900F043043");

    }
    else if(ui->comboBox_4->currentIndex() == 9)
    {
         data = QByteArray::fromHex("EB900F043144");

    }
    else if(ui->comboBox_4->currentIndex() == 10)
    {
         data = QByteArray::fromHex("EB900F043245");

    }
    else if(ui->comboBox_4->currentIndex() == 11)
    {
         data = QByteArray::fromHex("EB900F043346");

    }
    else if(ui->comboBox_4->currentIndex() == 12)
    {
         data = QByteArray::fromHex("EB900F044053");

    }
    else if(ui->comboBox_4->currentIndex() == 13)
    {
         data = QByteArray::fromHex("EB900F044154");

    }
    else if(ui->comboBox_4->currentIndex() == 14)
    {
         data = QByteArray::fromHex("EB900F044255");

    }
    else if(ui->comboBox_4->currentIndex() == 15)
    {
         data = QByteArray::fromHex("EB900F044356");

    }
    else if(ui->comboBox_4->currentIndex() == 16)
    {
         data = QByteArray::fromHex("EB900F045063");

    }
    else if(ui->comboBox_4->currentIndex() == 17)
    {
         data = QByteArray::fromHex("EB900F045164");

    }
    else if(ui->comboBox_4->currentIndex() == 18)
    {
         data = QByteArray::fromHex("EB900F045265");

    }
    else if(ui->comboBox_4->currentIndex() == 19)
    {
         data = QByteArray::fromHex("EB900F045366");

    }
    else if(ui->comboBox_4->currentIndex() == 20)
    {
         data = QByteArray::fromHex("EB900F046073");

    }
    else if(ui->comboBox_4->currentIndex() == 21)
    {
         data = QByteArray::fromHex("EB900F046174");

    }
    else if(ui->comboBox_4->currentIndex() == 22)
    {
         data = QByteArray::fromHex("EB900F046275");

    }
    else if(ui->comboBox_4->currentIndex() == 23)
    {
         data = QByteArray::fromHex("EB900F046376");

    }
    //输入日志
    // 获取当前时间字符串
    QDateTime current_date_time =QDateTime::currentDateTime();
    QString dateStr =current_date_time.toString("[yyyy-MM-dd hh:mm:ss]");
    QString dateTimeStr = dateStr + "\n";
    QString bookDataStr = tr("状态切换命令：") + tr("坐标系切换=")+ ui->comboBox_4->currentIndex() + "\n";
    QString sendBookDataStr = dateTimeStr+bookDataStr;
    emit bookLogCMD(sendBookDataStr);
    emit statesChangeCMD(data);
}

void QueryDialog::on_pushButton_5_clicked()
{
    QByteArray data;
    if(ui->comboBox_5->currentIndex() ==0)
    {
         data = QByteArray::fromHex("EB900FAAA15A");

    }
    else if(ui->comboBox_5->currentIndex() ==1)
    {
         data = QByteArray::fromHex("EB900FAAA25B");

    }
    else if(ui->comboBox_5->currentIndex() ==2)
    {
         data = QByteArray::fromHex("EB900FAAA35C");

    }
    else if(ui->comboBox_5->currentIndex() ==3)
    {
         data = QByteArray::fromHex("EB900FAAAF68");
    }
    else if(ui->comboBox_5->currentIndex() ==4)
    {
         data = QByteArray::fromHex("EB900FAAA059");
    }
    else if(ui->comboBox_5->currentIndex() ==5)
    {
         data = QByteArray::fromHex("EB900FAAA45D");

    }
    else if(ui->comboBox_5->currentIndex() ==6)
    {
         data = QByteArray::fromHex("EB900FAAA55E");

    }
    else if(ui->comboBox_5->currentIndex() ==7)
    {
         data = QByteArray::fromHex("EB900FAAA65F");

    }
    else if(ui->comboBox_5->currentIndex() ==8)
    {
         data = QByteArray::fromHex("EB900FAAA760");

    }
    else if(ui->comboBox_5->currentIndex() ==9)
    {
         data = QByteArray::fromHex("EB900FAAA861");

    }
    else if(ui->comboBox_5->currentIndex() ==10)
    {
         data = QByteArray::fromHex("EB900FAAA962");

    }
//    else if(ui->comboBox_5->currentIndex() ==X-Y-Z)
//    {
//         data = QByteArray::fromHex("EB900F042235);

//    }
    else if(ui->comboBox_5->currentIndex() ==11)
    {
         data = QByteArray::fromHex("EB900FAAAA63");

    }
    else if(ui->comboBox_5->currentIndex() ==12)
    {
         data = QByteArray::fromHex("EB900FAAAB64");

    }
    else if(ui->comboBox_5->currentIndex() ==13)
    {
         data = QByteArray::fromHex("EB900FAAAC65");

    }
    else if(ui->comboBox_5->currentIndex() ==14)
    {
         data = QByteArray::fromHex("EB900FAAAD66");

    }
    else if(ui->comboBox_5->currentIndex() ==15)
    {
         data = QByteArray::fromHex("EB900FAAAE67");
    }


    else if(ui->comboBox_5->currentIndex() ==16)
    {
         data = QByteArray::fromHex("EB900FAAB069");
    }
    else if(ui->comboBox_5->currentIndex() ==17)
    {
         data = QByteArray::fromHex("EB900FAAB16A");
    }
    else if(ui->comboBox_5->currentIndex() ==18)
    {
         data = QByteArray::fromHex("EB900FAAB36C");
    }
    else if(ui->comboBox_5->currentIndex() ==19)
    {
         data = QByteArray::fromHex("EB900FAAB46D");
    }
    else if(ui->comboBox_5->currentIndex() ==20)
    {
         data = QByteArray::fromHex("EB900FAAB56E");
    }
    //输入日志
    // 获取当前时间字符串
    QDateTime current_date_time =QDateTime::currentDateTime();
    QString dateStr =current_date_time.toString("[yyyy-MM-dd hh:mm:ss]");
    QString dateTimeStr = dateStr + "\n";
    QString bookDataStr = tr("状态切换命令：") + tr("参数查询=")+ ui->comboBox_5->currentIndex() + "\n";
    QString sendBookDataStr = dateTimeStr+bookDataStr;
    emit bookLogCMD(sendBookDataStr);
    emit statesChangeCMD(data);

}

void QueryDialog::on_pushButton_6_clicked()
{
    QByteArray data = QByteArray::fromHex("EB900F6666DB");
    //输入日志
    // 获取当前时间字符串
    QDateTime current_date_time =QDateTime::currentDateTime();
    QString dateStr =current_date_time.toString("[yyyy-MM-dd hh:mm:ss]");
    QString dateTimeStr = dateStr + "\n";
    QString bookDataStr = tr("状态切换命令：") + tr("FLASH烧写") + "\n";
    QString sendBookDataStr = dateTimeStr+bookDataStr;
    emit bookLogCMD(sendBookDataStr);
    emit statesChangeCMD(data);
}

