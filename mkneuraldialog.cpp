#include "mkneuraldialog.h"
#include "ui_mkneuraldialog.h"
#include "secondwindow.h"

mkneuraldialog::mkneuraldialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mkneuraldialog)
{
    ui->setupUi(this);
}

mkneuraldialog::~mkneuraldialog()
{
    delete ui;
}


void mkneuraldialog::on_connectButton_clicked()
{
    UIControler::phase=connecting;
    UIControler::connectionSource=&(node->m_outputs[0]);
    close();
    UIControler::secondWin->drawLines();
}

std::vector<double> mkneuraldialog::on_submitButton_clicked()
{
    double input =  ui->inputValue->text().toDouble();
    double firstHidden = ui->firstHiddenValue->text().toDouble();
    double secondHidden = ui->secondHiddenValue->text().toDouble();
    double output = ui->outputValue->text().toDouble();
    double alpha = ui->alphaValue->text().toDouble();
    double momentum = ui->momentumValue->text().toDouble();

    std::vector<double> tmp;
    tmp.push_back(input);
    tmp.push_back(firstHidden);
    tmp.push_back(secondHidden);
    tmp.push_back(output);
    tmp.push_back(alpha);
    tmp.push_back(momentum);

    return tmp;
}

