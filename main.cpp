#include "mainwindow.h"
#include <QApplication>

#include "mknode.h"
#include "mknodespec.h"
#include "mktestnode2_2.h"
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


    MKTestNode2_2 s1 {};
    MKTestNode2_2 s2 {};

    s1.m_outputs[0].establishConnection(s2.m_inputs[0]);
    //s1.m_outputs[1].establishConnection(s2.m_inputs[1]);
    s1.process_data();
    return a.exec();
}
