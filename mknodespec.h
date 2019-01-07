#ifndef MKNODESPEC_H
#define MKNODESPEC_H

#include "mknode.h"

class MKTestNode1_1 : public MKNode
{
public:
    MKTestNode1_1();

    virtual bool process_data() override;

};

#endif // MKNODESPEC_H
