#ifndef MKTESTNODE2_2_H
#define MKTESTNODE2_2_H

#include "mknode.h"

//A node with 2 inputs and 2 outputs
class MKTestNode2_2: public MKNode
{
public:
    MKTestNode2_2();

    virtual bool process_data() override;
};

#endif // MKTESTNODE2_2_H
