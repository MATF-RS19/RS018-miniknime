#include "mkdialog.h"
#include "secondwindow.h"
#include "ui_mkdialog.h"
#include "uicontroler.h"

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
    UIControler::phase=connecting;
    UIControler::connectionSource=&(node->m_outputs[0]);    
    close();
    UIControler::secondWin->drawLines();
}

void MKDialog::on_inputButton_clicked()
{

}
