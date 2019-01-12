#ifndef MKNODE_H
#define MKNODE_H

#include <vector>
#include <set>
#include <string>
#include "mkinput.h"
#include "mkoutput.h"

class MKNode
{
public:

    MKNode();
    MKNode(int ins, int outs);
    virtual ~MKNode();

    std::string type="";

    std::vector<MKInput<double>> m_inputs;
    std::vector<MKOutput<double>> m_outputs;

    //returns true if the node is ready to process data, false otherwise based on if all the input nodes are connected
    bool isReady();
    void sendInvalidationPulse(std::set<MKNode*>* marked=new std::set<MKNode*>());
    void requestProcess();
    MKInput<double>* getFirstFreeInput();

protected:
    void propagate();
    virtual bool process_data() = 0;
};


#endif // MKNODE_H
