#include "mknormalizationdialog.h"
#include "uicontroler.h"
#include "ui_mknormalizationdialog.h"
#include "secondwindow.h"

mknormalizationdialog::mknormalizationdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mknormalizationdialog)
{
    ui->setupUi(this);
}

mknormalizationdialog::~mknormalizationdialog()
{
    delete ui;
}


void mknormalizationdialog::on_connectButton_clicked()
{
    UIControler::phase=connecting;
    UIControler::connectionSource=&(node->m_outputs[0]);
    close();
    UIControler::secondWin->drawLines();
}
