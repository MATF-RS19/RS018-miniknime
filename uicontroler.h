#ifndef UICONTROLER_H
#define UICONTROLER_H

#include <QObject>
#include <QWidget>
#include <mknode.h>
#include <vector>
#include <string>

enum Phase{normal,connecting};

class UIControler
{
public:
    UIControler();

    ~UIControler();

    static void amendNode(QWidget *widget, MKNode *node);
    static void addNode(QWidget *widget, MKNode *node);
    static QWidget* getWidget(MKNode *node);
    static MKNode* getNode(QWidget *widget);
    static void amendOriginNode(QWidget *widget, std::string type);
    static void addOriginNode(QWidget *widget, std::string type);
    static std::string getTypeFromOrigin(QWidget *widget);
    //TODO
    static void initializeConnectingPhase(MKOutput<double>* origin);

    static Phase phase;
    //TODO
    static MKOutput<double>* connectionSource;

private:
    static std::vector<std::pair<QWidget*, MKNode*>> activeNodes;
    static std::vector<std::pair<QWidget*, std::string>> originNodes;
};

#endif // UICONTROLER_H
