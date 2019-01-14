#include "mkknndialog.h"
#include "ui_mkknndialog.h"
#include "secondwindow.h"

mkknndialog::mkknndialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mkknndialog)
{
    ui->setupUi(this);
}

mkknndialog::~mkknndialog()
{
    delete ui;
}

void mkknndialog::on_connectButton_clicked()
{
    UIControler::phase=connecting;
    UIControler::connectionSource=&(node->m_outputs[0]);
    close();
    UIControler::secondWin->drawLines();
}

std::vector<double> mkknndialog::on_submitButton_clicked()
{
    std::vector<double> tmp;

    double number =  ui->numberValue->text().toDouble();
    double label = ui->labelValue->text().toDouble();
    double x = ui->valueX->text().toDouble();
    double y = ui->valueY->text().toDouble();

    tmp.push_back(number);
    tmp.push_back(label);
    tmp.push_back(x);
    tmp.push_back(y);

    return tmp;
}
