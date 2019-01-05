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


    virtual bool process_data();

    virtual void propagate();
// TODO podici iz podklasa stvari koje se cesto ponavaljaju



    std::vector<MKInput> m_inputs;
    std::vector<MKOutput> m_outputs;

};


#endif // MKNODE_H
