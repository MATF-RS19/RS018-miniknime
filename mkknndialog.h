#ifndef MKKNNDIALOG_H
#define MKKNNDIALOG_H

#include <mknode.h>

#include <QDialog>

namespace Ui {
class mkknndialog;
}

class mkknndialog : public QDialog
{
    Q_OBJECT

public:
    explicit mkknndialog(QWidget *parent = nullptr);
    ~mkknndialog();
    MKNode* node=nullptr;

private slots:
    void on_connectButton_clicked();

public slots:
    std::vector<double> on_submitButton_clicked();

private:
    Ui::mkknndialog *ui;
};

#endif // MKKNNDIALOG_H
