#ifndef HANDLERESULTDELAYDIALOG_H
#define HANDLERESULTDELAYDIALOG_H
extern int handleResultDelay2;
#include <QDialog>

namespace Ui {
class handleResultDelayDialog;
}

class handleResultDelayDialog : public QDialog
{
    Q_OBJECT

public:
    explicit handleResultDelayDialog(QWidget *parent = nullptr);
    ~handleResultDelayDialog();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::handleResultDelayDialog *ui;
};

#endif // HANDLERESULTDELAYDIALOG_H
