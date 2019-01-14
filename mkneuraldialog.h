#ifndef MKNEURALDIALOG_H
#define MKNEURALDIALOG_H

#include <mknode.h>
#include <QDialog>

namespace Ui {
class mkneuraldialog;
}

class mkneuraldialog : public QDialog
{
    Q_OBJECT

public:
    explicit mkneuraldialog(QWidget *parent = nullptr);
    ~mkneuraldialog();
    MKNode* node=nullptr;

private slots:
    void on_connectButton_clicked();

public slots:
    std::vector<double> on_submitButton_clicked();

private:
    Ui::mkneuraldialog *ui;
};

#endif // MKNEURALDIALOG_H
