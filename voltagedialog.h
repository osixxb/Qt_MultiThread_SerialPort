#ifndef VOLTAGEDIALOG_H
#define VOLTAGEDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QTranslator>
namespace Ui {
class VoltageDialog;
}

class VoltageDialog : public QDialog
{
    Q_OBJECT

public:
    explicit VoltageDialog(QWidget *parent = nullptr);
    ~VoltageDialog();

public slots:
    void setEnLan();
    void setZhLan();
private slots:
    void on_pushButton_clicked();

private:
    Ui::VoltageDialog *ui;
signals:
    void statesChangeCMD(QByteArray result);
};

#endif // VOLTAGEDIALOG_H
