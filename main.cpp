#include "mainwindow.h"
#include <QApplication>

#include "mknode.h"
#include "mknodespec.h"
#include <vector>
#include <iostream>
#include "QFrame"
#include "QLabel"
#include "QPushButton"
#include "QLayout"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);    
    MainWindow w;    
    w.show();


    MKNodeSpec s1 {};
    MKNodeSpec s2 {};


    s1.m_outputs[0].establishConnection(s2.m_inputs[0]);
    s1.process_data();
    return a.exec();
}
