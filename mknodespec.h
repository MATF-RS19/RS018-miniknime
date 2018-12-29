#ifndef MKNODESPEC_H
#define MKNODESPEC_H

#include "mknode.h"

class MKNodeSpec : public MKNode
{
public:
    MKNodeSpec();

    virtual bool process_data() override;



};

#endif // MKNODESPEC_H
