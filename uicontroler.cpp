#include "uicontroler.h"
#include <mknode.h>
#include <QWidget>
#include <vector>

std::vector<std::pair<QWidget*, MKNode*>> UIControler::activeNodes=std::vector<std::pair<QWidget*, MKNode*>>();

UIControler::UIControler(){}

UIControler::~UIControler(){}

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



