#include "serialinterfacedialog.h"
#include "ui_serialinterfacedialog.h"
#include "common.h"
SerialInterfaceDialog::SerialInterfaceDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SerialInterfaceDialog)
{
    ui->setupUi(this);
    connect(parent,SIGNAL(F1en()),this,SLOT(setEnLan()));
    connect(parent,SIGNAL(F2zh()),this,SLOT(setZhLan()));
}

SerialInterfaceDialog::~SerialInterfaceDialog()
{
    delete ui;
}

void SerialInterfaceDialog::on_pushButton_2_clicked()
{
    this->close();
}
void SerialInterfaceDialog::setEnLan()
{
    QTranslator trans;
    QString buff = QCoreApplication::applicationDirPath()+ "/";
    trans.load(buff+"en.qm");
    qApp->installTranslator(&trans);
    ui->retranslateUi(this);
}
void SerialInterfaceDialog::setZhLan()
{
    QTranslator trans;
    QString buff = QCoreApplication::applicationDirPath()+ "/";
    trans.load(buff+"zh.qm");
    qApp->installTranslator(&trans);
    ui->retranslateUi(this);
}
void SerialInterfaceDialog::on_pushButton_clicked()
{
    QByteArray Sdata;
    QString byte3;
    QString byte4;
    QString byte5;
    int byte5int = 0;
    QString byte6;
    QString dataStr;
    int SerialInterFaceCheckSum = 0;
    if(ui->comboBox->currentText() == "COMA" && ui->comboBox_4->currentIndex() == 0)
    {
         byte3 = "01";

    }
    else if(ui->comboBox->currentText() == "COMB" && ui->comboBox_4->currentIndex() == 0)
    {
         byte3 = "02";

    }
    else if(ui->comboBox->currentText() == "COMC" && ui->comboBox_4->currentIndex() == 0)
    {
         byte3 = "04";

    }
    else if(ui->comboBox->currentText() == "COMD" && ui->comboBox_4->currentIndex() == 0)
    {
         byte3 = "08";

    }
    else if(ui->comboBox->currentText() == "COME" && ui->comboBox_4->currentIndex() == 0)
    {
         byte3 = "10";

    }
    else if(ui->comboBox->currentText() == "COMF" && ui->comboBox_4->currentIndex() == 0)
    {
         byte3 = "20";

    }
    else if(ui->comboBox->currentText() == "COMG" && ui->comboBox_4->currentIndex() == 0)
    {
         byte3 = "40";

    }
    else if(ui->comboBox->currentText() == "COMA" && ui->comboBox_4->currentIndex() == 0)
    {
         byte3 = "81";

    }
    else if(ui->comboBox->currentText() == "COMB" && ui->comboBox_4->currentIndex() == 1)
    {
         byte3 = "82";

    }
    else if(ui->comboBox->currentText() == "COMC" && ui->comboBox_4->currentIndex() == 1)
    {
         byte3 = "84";

    }
    else if(ui->comboBox->currentText() == "COMD" && ui->comboBox_4->currentIndex() == 1)
    {
         byte3 = "88";

    }
    else if(ui->comboBox->currentText() == "COME" && ui->comboBox_4->currentIndex() == 1)
    {
         byte3 = "90";

    }
    else if(ui->comboBox->currentText() == "COMF" && ui->comboBox_4->currentIndex() == 1)
    {
         byte3 = "A0";

    }
    else if(ui->comboBox->currentText() == "COMG" && ui->comboBox_4->currentIndex() == 1)
    {
         byte3 = "C0";

    }

    if(ui->comboBox_2->currentText() == "2400")
    {
         byte4 = "00";
    }
    else if(ui->comboBox_2->currentText() == "4800")
    {
         byte4 = "01";
    }
    else if(ui->comboBox_2->currentText() == "9600")
    {
         byte4 = "02";
    }
    else if(ui->comboBox_2->currentText() == "19200")
    {
         byte4 = "03";
    }
    else if(ui->comboBox_2->currentText() == "38400")
    {
         byte4 = "04";
    }
    else if(ui->comboBox_2->currentText() == "57600")
    {
         byte4 = "05";
    }
    else if(ui->comboBox_2->currentText() == "115200")
    {
         byte4 = "06";
    }
    else if(ui->comboBox_2->currentText() == "230400")
    {
         byte4 = "07";
    }
    else if(ui->comboBox_2->currentText() == "384000")
    {
         byte4 = "08";
    }
    else if(ui->comboBox_2->currentText() == "460800")
    {
         byte4 = "09";
    }

    if(ui->comboBox_6->currentIndex() == 1)
    {
         byte5int = byte5int+1;

    }
    else if(ui->comboBox_6->currentIndex() == 0)
    {
         byte5int = byte5int+0;
    }

    if(ui->comboBox_7->currentIndex() == 1)
    {
         byte5int = byte5int+2;

    }
    else if(ui->comboBox_7->currentIndex() == 0)
    {
         byte5int = byte5int+0;
    }
    if(ui->comboBox_3->currentIndex() == 1)
    {
         byte5int = byte5int+4;

    }
    else if(ui->comboBox_3->currentIndex() == 0)
    {
         byte5int = byte5int+0;
    }
    if(ui->comboBox_8->currentIndex() == 1)
    {
         byte5int = byte5int+8;

    }
    else if(ui->comboBox_8->currentIndex() == 0)
    {
         byte5int = byte5int+0;
    }
    byte5 = QString::number(byte5int,16).rightJustified(2,QLatin1Char('0'));

    if(ui->comboBox_5->currentIndex() == 0)
    {
         byte6 = "00";

    }
    else if(ui->comboBox_5->currentIndex() == 1)
    {
         byte6 = "01";
    }
    SerialInterFaceCheckSum = byte3.toInt(nullptr,16) + byte4.toInt(nullptr,16) +byte5.toInt(nullptr,16) + byte6.toInt(nullptr,16) + 16;
    QString SdataCheckSumHexStr = QString::number(SerialInterFaceCheckSum,16).right(2);
    dataStr = "EB 90 10 "+byte3+" "+byte4 + " " + byte5 + " " +byte6+" "+ SdataCheckSumHexStr;
    Sdata = HexStringToByteArray(dataStr);
    emit serialInterCMD(Sdata);
}

