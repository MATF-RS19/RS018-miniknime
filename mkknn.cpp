#include "mkknn.h"
#include "ui_mkknn.h"

mkknn::mkknn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mkknn)
{
    ui->setupUi(this);
}

mkknn::~mkknn()
{
    delete ui;
}

void mkknn::on_connectButton_clicked()
{

}
