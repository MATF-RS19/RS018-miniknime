#ifndef MKLAYOUTCONTROLER_H
#define MKLAYOUTCONTROLER_H

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mknode.h"
#include <iostream>
#include <QtWidgets>
#include <map>

class MKLayoutControler
{
public:
    static std::map<QWidget,MKNode*> allNodes;

    static void initialize();
    MKLayoutControler();
};

#endif // MKLAYOUTCONTROLER_H
