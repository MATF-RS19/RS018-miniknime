#ifndef MKNORMALIZATIONDIALOG_H
#define MKNORMALIZATIONDIALOG_H

#include <mknode.h>

#include <QDialog>

namespace Ui {
class mknormalizationdialog;
}

class mknormalizationdialog : public QDialog
{
    Q_OBJECT

public:
    explicit mknormalizationdialog(QWidget *parent = nullptr);
    ~mknormalizationdialog();
    MKNode* node=nullptr;

private slots:
    void on_connectButton_clicked();

private:
    Ui::mknormalizationdialog *ui;
};

#endif // MKNORMALIZATIONDIALOG_H
