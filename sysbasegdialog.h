#ifndef SYSBASEGDIALOG_H
#define SYSBASEGDIALOG_H

#include <QDialog>
#include <QTranslator>
namespace Ui {
class sysBaseGDialog;
}

class sysBaseGDialog : public QDialog
{
    Q_OBJECT

public:
    explicit sysBaseGDialog(QWidget *parent = nullptr);
    ~sysBaseGDialog();
public slots:
    void setEnLan();
    void setZhLan();
signals:
    void sysBaseGDataCMD(const QByteArray result);
    void bookLogCMD(QString bookDataStr);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::sysBaseGDialog *ui;
};

#endif // SYSBASEGDIALOG_H
