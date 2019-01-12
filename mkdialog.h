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

private:
    Ui::MKDialog *ui;
};

#endif // MKDIALOG_H
