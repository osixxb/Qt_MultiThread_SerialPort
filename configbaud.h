#ifndef CONFIGBAUD_H
#define CONFIGBAUD_H

#include <QDialog>
#include <QByteArray>
#include <QTime>
#include <QMessageBox>
namespace Ui {
class configBaud;
}

class configBaud : public QDialog
{
    Q_OBJECT

public:
    explicit configBaud(QWidget *parent = nullptr);
    ~configBaud();

    //QString appendChecksum(const std::string &input);
    QString appendChecksum(const QString& input);
public slots:
    void updateComboBox2BasedOnBaudrate();
private slots:
    void on_pushButton_clicked();

signals:
    void statesChangeCMD(QByteArray result);
    void bookLogCMD(QString bookDataStr);
private:
    Ui::configBaud *ui;
};

#endif // CONFIGBAUD_H
