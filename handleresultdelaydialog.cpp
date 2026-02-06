#include "handleresultdelaydialog.h"
#include "ui_handleresultdelaydialog.h"

int handleResultDelay2;

handleResultDelayDialog::handleResultDelayDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::handleResultDelayDialog)
{
    ui->setupUi(this);

    ui->lineEdit->setText("200");
    on_pushButton_2_clicked();
    connect(parent,SIGNAL(F1en()),this,SLOT(setEnLan()));
    connect(parent,SIGNAL(F2zh()),this,SLOT(setZhLan()));
}

handleResultDelayDialog::~handleResultDelayDialog()
{
    delete ui;
}
void handleResultDelayDialog::setEnLan()
{
    QTranslator trans;
    QString buff = QCoreApplication::applicationDirPath()+ "/";
    trans.load(buff+"en.qm");
    qApp->installTranslator(&trans);
    ui->retranslateUi(this);
}
void handleResultDelayDialog::setZhLan()
{
    QTranslator trans;
    QString buff = QCoreApplication::applicationDirPath()+ "/";
    trans.load(buff+"zh.qm");
    qApp->installTranslator(&trans);
    ui->retranslateUi(this);
}
void handleResultDelayDialog::on_pushButton_2_clicked()
{
    handleResultDelay2 = ui->lineEdit->text().toInt();
    this->close();
}

void handleResultDelayDialog::on_pushButton_clicked()
{
    //QString buff = ui->lineEdit->text();
    ui->lineEdit->setText(QString::number(handleResultDelay2,10));
    this->close();
}
