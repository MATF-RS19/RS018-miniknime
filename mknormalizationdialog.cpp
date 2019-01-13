#include "mknormalizationdialog.h"
#include "ui_mknormalizationdialog.h"

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

