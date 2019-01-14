#include "csvreaderdialog.h"
#include "ui_csvreaderdialog.h"
#include "secondwindow.h"
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

std::string CsvReaderDialog::on_browseButton_clicked()
{
    QString s = QFileDialog::getOpenFileName(this, "Open file", QString(), "All files (*.*)");
    ui->lineEdit->setText(s);
    return s.toStdString();
}


void CsvReaderDialog::on_connectButton_clicked()
{
    UIControler::phase=connecting;
    UIControler::connectionSource=&(node->m_outputs[0]);
    close();
    UIControler::secondWin->drawLines();
}
