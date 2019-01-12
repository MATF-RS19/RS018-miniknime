#include "mkdialog.h"
#include "ui_mkdialog.h"

#include <iostream>

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

void MKDialog::on_outputButton_clicked()
{
    std::cout<<"out"<<std::endl;
}

void MKDialog::on_inputButton_clicked()
{

}
