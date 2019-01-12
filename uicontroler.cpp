#include "uicontroler.h"
#include <mknode.h>
#include <QWidget>
#include <vector>

UIControler::UIControler(std::vector<std::pair<QWidget*, MKNode*>> map, int count)
        :map(map), count(count)
{

}

UIControler::~UIControler(){}

void UIControler::addToMap(QWidget *widget, MKNode *node)
{
    map.push_back(std::make_pair(widget, node));
    count++;
}
