#include "mkdialog.h"
#include "ui_mkdialog.h"

MKDialog::MKDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MKDialog)
{
    ui->setupUi(this);
}

MKDialog::~MKDialog()
{
    delete ui;
}
