#ifndef UICONTROLER_H
#define UICONTROLER_H

#include <QObject>
#include <QWidget>
#include <mknode.h>
#include <vector>

class UIControler
{
public:
    UIControler(std::vector<std::pair<QWidget*, MKNode*>>, int count);

    ~UIControler();

    void addToMap(QWidget *widget, MKNode *node);

private:

    std::vector<std::pair<QWidget*, MKNode*>> map;
    int count = 0;
};

#endif // UICONTROLER_H
