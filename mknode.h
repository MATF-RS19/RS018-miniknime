#ifndef MKNODE_H
#define MKNODE_H

#include <vector>
#include "mkinput.h"
#include "mkoutput.h"

class MKNode
{
public:

    MKNode();
    MKNode(int ins, int outs);
    virtual ~MKNode();

    // TODO podici iz podklasa stvari koje se cesto ponavaljaju
        std::vector<MKInput> m_inputs;
        std::vector<MKOutput> m_outputs;

    //returns true if the node is ready to process data, false otherwise based on if all the input nodes are connected
    bool isReady();

protected:
    void propagate();
    virtual bool process_data();
};


#endif // MKNODE_H
