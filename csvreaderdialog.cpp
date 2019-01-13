#include "csvreaderdialog.h"
#include "ui_csvreaderdialog.h"
#include <QFileDialog>

CsvReaderDialog::CsvReaderDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CsvReaderDialog)
{
    ui->setupUi(this);
}

CsvReaderDialog::~CsvReaderDialog()
{
    delete ui;
}

void CsvReaderDialog::on_browseButton_clicked()
{
    QString s = QFileDialog::getOpenFileName(this, "Open file", QString(), "All files (*.*)");
    ui->lineEdit->setText(s);
}



void CsvReaderDialog::on_connectButton_clicked()
{

}
