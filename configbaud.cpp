#include "configbaud.h"
#include "ui_configbaud.h"
#define MINBYTE 2400
using namespace std;
configBaud::configBaud(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::configBaud)
{
    ui->setupUi(this);
    // 在构造函数或者初始化函数中，连接信号和槽
    connect(ui->comboBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(updateComboBox2BasedOnBaudrate()));
}

configBaud::~configBaud()
{
    delete ui;
}

void configBaud::on_pushButton_clicked()
{
    QByteArray data;
    QString sBuff;
     if(ui->comboBox->currentText() == "2400")
    {

          sBuff = "EB901701";

    }
    else if(ui->comboBox->currentText() == "3600")
    {
          sBuff = "EB901702";

    }
    else if(ui->comboBox->currentText() == "4800")
    {
          sBuff = "EB901703";

    }
    else if(ui->comboBox->currentText() == "7200")
    {
          sBuff = "EB901704";

    }
    else if(ui->comboBox->currentText() == "9600")
    {
          sBuff = "EB901705";

    }
    else if(ui->comboBox->currentText() == "14400")
    {
          sBuff = "EB901706";

    }
    else if(ui->comboBox->currentText() == "19200")
    {
          sBuff = "EB901707";

    }
    else if(ui->comboBox->currentText() == "28800")
    {
          sBuff = "EB901708";

    }
    else if(ui->comboBox->currentText() == "38400")
    {
          sBuff = "EB901709";

    }
    else if(ui->comboBox->currentText() == "57600")
    {
          sBuff = "EB90170A";

    }
    else if(ui->comboBox->currentText() == "115200")
    {
          sBuff = "EB90170B";

    }
    else if(ui->comboBox->currentText() == "230400")
    {
          sBuff = "EB90170C";

    }
    else if(ui->comboBox->currentText() == "460800")
    {
          sBuff = "EB90170D";

    }
    else if(ui->comboBox->currentText() == "921600")
    {
          sBuff = "EB90170E";

    }

    int iBaud = ui->comboBox->currentText().toInt();
     float fHz;
    if(ui->comboBox_2->currentText() == "0.1Hz")
    {
          fHz = 0.1;
          sBuff = sBuff+"01";

    }
    else if(ui->comboBox_2->currentText() == "0.5Hz")
    {
        fHz = 0.5;
        sBuff = sBuff+"02";

    }
    else if(ui->comboBox_2->currentText() == "1Hz")
    {
         fHz = 1.0;
         sBuff = sBuff+"03";

    }
    else if(ui->comboBox_2->currentText() == "5Hz")
    {
         fHz = 5.0;
         sBuff = sBuff+"04";

    }
    else if(ui->comboBox_2->currentText() == "10Hz")
    {
         fHz = 10.0;
         sBuff = sBuff+"05";

    }
    else if(ui->comboBox_2->currentText() == "50Hz")
    {
         fHz = 50;
         sBuff = sBuff+"06";

    }
    else if(ui->comboBox_2->currentText() == "100Hz")
    {
         fHz = 100.0;
         sBuff = sBuff+"07";

    }
    else if(ui->comboBox_2->currentText() == "250Hz")
    {
         fHz = 250.0;
         sBuff = sBuff+"08";

    }
    else if(ui->comboBox_2->currentText() == "500Hz")
    {
         fHz = 500.0;
         sBuff = sBuff+"09";

    }
    else if(ui->comboBox_2->currentText() == "1000Hz")
    {
         fHz = 1000.0;
         sBuff = sBuff+"0A";
    }   
    sBuff = appendChecksum(sBuff);
    data = QByteArray::fromHex(sBuff.toUtf8());
    if(iBaud/(8*fHz)>2400)
    {
        //输入日志
        // 获取当前时间字符串
        QDateTime current_date_time =QDateTime::currentDateTime();
        QString dateStr =current_date_time.toString("[yyyy-MM-dd hh:mm:ss]");
        QString dateTimeStr = dateStr + "\n";
        QString bookDataStr = tr("配置波特率和输出频率命令：") + tr("波特率=")+ ui->comboBox->currentText() +tr("；输出频率=")+ ui->comboBox_2->currentText() + "\n";
        QString sendBookDataStr = dateTimeStr+bookDataStr;
        emit bookLogCMD(sendBookDataStr);

        emit statesChangeCMD(data);
    }
    else
    {
        QMessageBox::about(NULL, "提示", "配置失败,波特率÷8÷输出频率>2400字节");
        return;
    }


}

QString configBaud::appendChecksum(const QString& input) {
    if (input.length() < 4 || input.length() % 2 != 0) {
        // 不是有效的16进制字符串
        return "";
    }

    int sum = 0;
    QByteArray byteArray = QByteArray::fromHex(input.toUtf8());

    // 从第3个字节开始计算
    for (int i = 2; i < byteArray.size(); ++i) {
        sum += static_cast<unsigned char>(byteArray.at(i));
    }

    // 取低8位
    sum &= 0xFF;

    // 将校验和转换为16进制字符串并附加到输入的末尾
    return input + QString("%1").arg(sum, 2, 16, QChar('0')).toUpper();
}
void configBaud::updateComboBox2BasedOnBaudrate()
{
    // 保存当前的选择，如果可能的话。
    QString currentSelection = ui->comboBox_2->currentText();

    ui->comboBox_2->clear();  // 清除当前comboBox_2的所有条目

    int baudrate = ui->comboBox->currentText().toInt();  // 获取comboBox的当前选定的波特率

    QStringList frequencies = {"0.1", "0.5", "1", "5", "10", "50", "100", "250", "500", "1000"};

    for(const QString &freqStr : frequencies)
    {
        double frequency = freqStr.toDouble();
        if((baudrate / 8.0 / frequency) > 2400.0)
        {
            ui->comboBox_2->addItem(freqStr + "Hz");
        }
    }

    int index = ui->comboBox_2->findText(currentSelection);
    if(index != -1)
    {
        ui->comboBox_2->setCurrentIndex(index);  // 如果可能的话，恢复之前的选择
    }
    else
    {
        ui->comboBox_2->setCurrentIndex(0);  // 或者默认选择第一项
    }
}

