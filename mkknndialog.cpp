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
