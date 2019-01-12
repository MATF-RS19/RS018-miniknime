#ifndef UICONTROLER_H
#define UICONTROLER_H

#include <QObject>
#include <QWidget>
#include <mknode.h>
#include <vector>

class UIControler
{
public:
    UIControler();

    ~UIControler();

    static void addNode(QWidget *widget, MKNode *node);
    static MKNode* getNode(QWidget *widget);
    static std::vector<std::pair<QWidget*, MKNode*>> activeNodes;

private:


    int count = 0;
};

#endif // UICONTROLER_H
