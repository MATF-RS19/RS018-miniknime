#include "mkknn.h"
#include "ui_mkknn.h"
#include "secondwindow.h"

MKKnn::MKKnn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MKKnn)
{
    ui->setupUi(this);
}

MKKnn::~MKKnn()
{
    delete ui;
}

void MKKnn::on_connectButton_clicked()
{
    UIControler::phase=connecting;
    UIControler::connectionSource=&(node->m_outputs[0]);
    close();
    UIControler::secondWin->drawLines();

}
