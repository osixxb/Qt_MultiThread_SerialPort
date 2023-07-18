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
}

handleResultDelayDialog::~handleResultDelayDialog()
{
    delete ui;
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
