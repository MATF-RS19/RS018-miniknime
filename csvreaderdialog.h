#ifndef CSVREADERDIALOG_H
#define CSVREADERDIALOG_H

#include <mknode.h>

#include <QDialog>

namespace Ui {
class CsvReaderDialog;
}

class CsvReaderDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CsvReaderDialog(QWidget *parent = nullptr);
    ~CsvReaderDialog();
    MKNode* node=nullptr;

private slots:

    void on_browseButton_clicked();

    void on_connectButton_clicked();

private:
    Ui::CsvReaderDialog *ui;
};

#endif // CSVREADERDIALOG_H
