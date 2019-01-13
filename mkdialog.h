#ifndef MKDIALOG_H
#define MKDIALOG_H

#include <QDialog>

namespace Ui {
class MKDialog;
}

class MKNode;

class MKDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MKDialog(QWidget *parent = nullptr);
    ~MKDialog();
    MKNode* node=nullptr;

private slots:

    void on_connectButton_clicked();

private:
    Ui::MKDialog *ui;

};

#endif // MKDIALOG_H
