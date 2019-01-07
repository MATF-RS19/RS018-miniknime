#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->listWidget->addItem("Linear regression");
    ui->listWidget->addItem("Kernel K-Means Clustering");
    ui->listWidget->addItem("Kernel Centroid");
    ui->listWidget->addItem("Neural Network");
    ui->listWidget->addItem("SVM Rank");
    ui->listWidget->addItem("KRR Classification");

}

MainWindow::~MainWindow()
{
    delete ui;
}
