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
    connect(parent,SIGNAL(F1en()),this,SLOT(setEnLan()));
    connect(parent,SIGNAL(F2zh()),this,SLOT(setZhLan()));
}

configBaud::~configBaud()
{
    delete ui;
}
void configBaud::setEnLan()
{
    QTranslator trans;
    QString buff = QCoreApplication::applicationDirPath()+ "/";
    trans.load(buff+"en.qm");
    qApp->installTranslator(&trans);
    ui->retranslateUi(this);
}
void configBaud::setZhLan()
{
    QTranslator trans;
    QString buff = QCoreApplication::applicationDirPath()+ "/";
    trans.load(buff+"zh.qm");
    qApp->installTranslator(&trans);
    ui->retranslateUi(this);
}
void configBaud::on_pushButton_clicked()
{
    QByteArray data;

        // 固定头字节
        data.append(0xEB);  // 头字节1
        data.append(0x90);  // 头字节2
        data.append(0x17);  // 命令标识

        // 从 UI 获取串口号
        int comPort = ui->comboBox_3->currentIndex(); // 获取选中的串口号索引 (COM1 = 0, COM2 = 1, ...)
        if (comPort < 0 || comPort > 5) {
            //qDebug() << "Invalid COM port selection!";
            return;
        }

        // 从 UI 获取发送/接收模式
        int mode = ui->comboBox_4->currentIndex(); // 0：发送，1：接收
        if (mode != 0 && mode != 1) {
           // qDebug() << "Invalid mode selection!";
            return;
        }

        // 配置串口号 (Bit8 | COM port)
        uint8_t comPortConfig = (mode << 7) | (1<<comPort);
        data.append(comPortConfig);

        // 从 UI 获取波特率
        int baudRateIndex = ui->comboBox->currentIndex(); // 波特率对应的索引 (0x01 到 0x0E)
        if (baudRateIndex < 0 || baudRateIndex > 13) {
            //qDebug() << "Invalid baud rate selection!";
            return;
        }
        uint8_t baudRate = static_cast<uint8_t>(baudRateIndex + 1); // 索引 0 对应 0x01，依次递增
        data.append(baudRate);

        // 从 UI 获取输出频率
        int outputFreqIndex = ui->comboBox_2->currentIndex(); // 输出频率对应的索引 (0x01 到 0x0A)
        if (outputFreqIndex < 0 || outputFreqIndex > 9) {
           // qDebug() << "Invalid output frequency selection!";
            return;
        }
        uint8_t outputFrequency = static_cast<uint8_t>(outputFreqIndex + 1); // 索引 0 对应 0x01，依次递增
        data.append(outputFrequency);

        // 计算校验和（从字节2到字节5的累加和）
        uint8_t checksum = 0;
        for (int i = 2; i < data.size(); ++i) {
            checksum += static_cast<uint8_t>(data[i]);
        }
        data.append(checksum);

        // 调试输出生成的数据帧
       // qDebug() << "Generated Data Frame:" << data.toHex();

        // 发射信号（发送指令）
        emit statesChangeCMD(data);


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

