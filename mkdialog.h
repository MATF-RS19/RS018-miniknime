#ifndef MKDIALOG_H
#define MKDIALOG_H

#include <QDialog>

namespace Ui {
class MKDialog;
}

class MKDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MKDialog(QWidget *parent = nullptr);
    ~MKDialog();

private slots:
    void on_outputButton_clicked();

    void on_inputButton_clicked();

private:
    Ui::MKDialog *ui;
};

#endif // MKDIALOG_H
