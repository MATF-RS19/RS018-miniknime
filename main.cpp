#include "mainwindow.h"
#include <QApplication>
#include "mknode.h"
#include "mknodespec.h"
#include "mktestnode2_2.h"
#include <vector>
#include <iostream>
#include "dlib-19.16/dlib-19.16/dlib/any/any.h"
#include "QFrame"
#include "QLabel"
#include "QPushButton"
#include "QLayout"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);    
    MainWindow w;    
    w.show();    

    std::cout<<dlib::pi<<std::endl;

    MKTestNode2_2 double1 {};
    MKTestNode1_1 single1 {};
    MKTestNode1_1 single2 {};
    MKTestNode2_2 double2 {};

    //    ->s1->
    // d1        d2
    //    ->s2->

    double1.m_outputs[0].establishConnection(single1.m_inputs[0]);
    double1.m_outputs[1].establishConnection(single2.m_inputs[0]);
    single1.m_outputs[0].establishConnection(double2.m_inputs[0]);
    single2.m_outputs[0].establishConnection(double2.m_inputs[1]);
    //s1.m_outputs[1].establishConnection(s2.m_inputs[1]);
    double1.sendInvalidationPulse();
    double1.process_data();
    return a.exec();
}
