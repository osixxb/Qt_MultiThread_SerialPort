#ifndef QUERYDIALOG_H
#define QUERYDIALOG_H

#include <QDialog>
#include <QTranslator>
namespace Ui {
class QueryDialog;
}

class QueryDialog : public QDialog
{
    Q_OBJECT

public:
    explicit QueryDialog(QWidget *parent = nullptr);
    ~QueryDialog();

public slots:
    void setEnLan();
    void setZhLan();
private slots:
    void on_pushButton_7_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();


signals:
    void statesChangeCMD(QByteArray result);
    void bookLogCMD(QString bookDataStr);
private:
    Ui::QueryDialog *ui;
};

#endif // QUERYDIALOG_H
