#include "mkdropdown.h"
#include "ui_mkdropdown.h"

MKDropDown::MKDropDown(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MKDropDown)
{
    ui->setupUi(this);
}

MKDropDown::~MKDropDown()
{
    delete ui;
}
