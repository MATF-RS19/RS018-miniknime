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
