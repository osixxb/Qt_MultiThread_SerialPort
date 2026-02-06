#include "voltagedialog.h"
#include "ui_voltagedialog.h"

VoltageDialog::VoltageDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VoltageDialog)
{
    ui->setupUi(this);
    connect(parent,SIGNAL(F1en()),this,SLOT(setEnLan()));
    connect(parent,SIGNAL(F2zh()),this,SLOT(setZhLan()));
}

VoltageDialog::~VoltageDialog()
{
    delete ui;
}
void VoltageDialog::setEnLan()
{
    QTranslator trans;
    QString buff = QCoreApplication::applicationDirPath()+ "/";
    trans.load(buff+"en.qm");
    qApp->installTranslator(&trans);
    ui->retranslateUi(this);
}
void VoltageDialog::setZhLan()
{
    QTranslator trans;
    QString buff = QCoreApplication::applicationDirPath()+ "/";
    trans.load(buff+"zh.qm");
    qApp->installTranslator(&trans);
    ui->retranslateUi(this);
}
void VoltageDialog::on_pushButton_clicked()
{
    // 从 UI 控件获取数据
    bool isok1;
    bool isok2;
    bool isok3;
    bool isok4;
    bool isok5;
    bool isok6;
    quint8 xAxisParamSeq = ui->comboBox->currentIndex() + 1;  // 假设是从0开始的索引
    float xAxisTempFloat = ui->lineEdit->text().toFloat(&isok1);  // 获取浮动温度
    qint16 xAxisTemp = qRound(xAxisTempFloat * 100);  // 乘以100后取整
    quint16 xAxisVoltage = qRound(ui->lineEdit_2->text().toFloat(&isok2));  // 稳频电压
    quint8 xAxisFreqEn = ui->checkBox->isChecked() ? 0x01 : 0x00;

    quint8 yAxisParamSeq = xAxisParamSeq;
    float yAxisTempFloat = ui->lineEdit_4->text().toFloat(&isok3);
    qint16 yAxisTemp = qRound(yAxisTempFloat * 100);  // 乘以100后取整
    quint16 yAxisVoltage = qRound(ui->lineEdit_3->text().toFloat(&isok4));
    quint8 yAxisFreqEn = ui->checkBox_2->isChecked() ? 0x01 : 0x00;

    quint8 zAxisParamSeq = xAxisParamSeq;
    float zAxisTempFloat = ui->lineEdit_5->text().toFloat(&isok5);
    qint16 zAxisTemp = qRound(zAxisTempFloat * 100);  // 乘以100后取整
    quint16 zAxisVoltage = qRound(ui->lineEdit_6->text().toFloat(&isok6));
    quint8 zAxisFreqEn = ui->checkBox_3->isChecked() ? 0x01 : 0x00;

    if(isok1 && isok2 && isok3 && isok4 && isok5 && isok6)
    {
        // 生成报文（报文为 QByteArray 类型）
        QByteArray message;

        // 头字节和命令标识
        message.append(QByteArray::fromHex("EB90"));
        message.append(0x18);  // 命令标识

        // X轴陀螺数据 (使用 Little Endian 格式)
        message.append(static_cast<quint8>(xAxisParamSeq));
        message.append(static_cast<quint8>(xAxisTemp & 0xFF)); // 低字节
        message.append(static_cast<quint8>((xAxisTemp >> 8) & 0xFF)); // 高字节
        message.append(static_cast<quint8>(xAxisVoltage & 0xFF)); // 低字节
        message.append(static_cast<quint8>((xAxisVoltage >> 8) & 0xFF)); // 高字节
        message.append(xAxisFreqEn);

        // Y轴陀螺数据 (使用 Little Endian 格式)
        message.append(static_cast<quint8>(yAxisParamSeq));
        message.append(static_cast<quint8>(yAxisTemp & 0xFF)); // 低字节
        message.append(static_cast<quint8>((yAxisTemp >> 8) & 0xFF)); // 高字节
        message.append(static_cast<quint8>(yAxisVoltage & 0xFF)); // 低字节
        message.append(static_cast<quint8>((yAxisVoltage >> 8) & 0xFF)); // 高字节
        message.append(yAxisFreqEn);

        // Z轴陀螺数据 (使用 Little Endian 格式)
        message.append(static_cast<quint8>(zAxisParamSeq));
        message.append(static_cast<quint8>(zAxisTemp & 0xFF)); // 低字节
        message.append(static_cast<quint8>((zAxisTemp >> 8) & 0xFF)); // 高字节
        message.append(static_cast<quint8>(zAxisVoltage & 0xFF)); // 低字节
        message.append(static_cast<quint8>((zAxisVoltage >> 8) & 0xFF)); // 高字节
        message.append(zAxisFreqEn);

        // 计算校验和（从字节 2 到字节 20）
        quint8 checksum = 0;
        for (int i = 2; i < message.size(); ++i) {
            checksum += static_cast<quint8>(message[i]);
        }

        // 校验和（字节 21）
        message.append(checksum);

        // 输出完整的报文

        // 发射信号（发送指令）
        emit statesChangeCMD(message);
    }
    else
    {
        QMessageBox::warning(this, tr("错误"), tr("输入数据格式错误"));
        return;
    }

}
