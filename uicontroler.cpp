#include "uicontroler.h"
#include <mknode.h>
#include <QWidget>
#include <vector>
#include <iostream>

std::vector<std::pair<QWidget*, MKNode*>> UIControler::activeNodes=std::vector<std::pair<QWidget*, MKNode*>>();

UIControler::UIControler(){}

UIControler::~UIControler(){}

void UIControler::amendNode(QWidget *widget, MKNode *node){
    for (auto& element : UIControler::activeNodes) {
        if(element.second==node){
            element.first=widget;
            return;
        }
    }
    std::cout<<"error trying to amend node"<<std::endl;
}

void UIControler::addNode(QWidget *widget, MKNode *node)
{
    UIControler::activeNodes.push_back(std::make_pair(widget, node));
}

//should be bsearch
MKNode* UIControler::getNode(QWidget *widget){
    for (auto& element : UIControler::activeNodes) {
        if(element.first==widget){
            return element.second;
        }
    }
    return nullptr;
}



