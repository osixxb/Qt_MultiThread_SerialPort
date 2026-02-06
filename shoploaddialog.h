#ifndef SHOPLOADDIALOG_H
#define SHOPLOADDIALOG_H

#include <QDialog>
#include <QTranslator>
namespace Ui {
class ShopLoadDialog;
}

class ShopLoadDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ShopLoadDialog(QWidget *parent = nullptr);
    ~ShopLoadDialog();

public slots:
    void setEnLan();
    void setZhLan();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::ShopLoadDialog *ui;

signals:
    void systemIDCMD(const QByteArray result);
    void bookLogCMD(QString bookDataStr);
};

#endif // SHOPLOADDIALOG_H
