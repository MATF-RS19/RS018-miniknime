#include "uicontroler.h"
#include <mknode.h>
#include <QWidget>
#include <vector>
#include <iostream>

std::vector<std::pair<QWidget*, MKNode*>> UIControler::activeNodes=std::vector<std::pair<QWidget*, MKNode*>>();
std::vector<std::pair<QWidget*, std::string>> UIControler::originNodes=std::vector<std::pair<QWidget*, std::string>>();
std::set<MKLine*> UIControler::activeLines=std::set<MKLine*>();
secondwindow* UIControler::secondWin=nullptr;

Phase UIControler::phase=normal;
MKOutput<double>* UIControler::connectionSource=nullptr;

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

QWidget* UIControler::getWidget(MKNode *node){
    for (auto& element : UIControler::activeNodes) {
        if(element.second==node){
            return element.first;
        }
    }
    return nullptr;
}


void UIControler::amendOriginNode(QWidget *widget, std::string type){
    for (auto& element : UIControler::originNodes) {
        if(element.second==type){
            element.first=widget;
            return;
        }
    }
    std::cout<<"error trying to amend origin node"<<std::endl;
}

void UIControler::addOriginNode(QWidget *widget, std::string type){
    UIControler::originNodes.push_back(std::make_pair(widget, type));
}

std::string UIControler::getTypeFromOrigin(QWidget *widget){
    for (auto& element : UIControler::originNodes) {
        if(element.first==widget){
            return element.second;
        }
    }
    std::cout<<"error looking for origin node (not found)"<<std::endl;
    return "";
}

void UIControler::initializeConnectingPhase(MKOutput<double>* origin){
    UIControler::phase=connecting;
    UIControler::connectionSource=origin;
}

void UIControler::addLine(MKLine* line){
    activeLines.insert(line);
}

void UIControler::destroyLine(MKLine* line){
    activeLines.erase(line);
}


void UIControler::setSecondWindow(secondwindow* sw){
    secondWin=sw;
}


