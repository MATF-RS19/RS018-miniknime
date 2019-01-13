#include "mkneuraldialog.h"
#include "ui_mkneuraldialog.h"

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

