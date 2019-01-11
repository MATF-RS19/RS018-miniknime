#ifndef MKPARTITION_H
#define MKPARTITION_H

#include "mknode.h"

class MKPartition : public MKNode
{
public:
    MKPartition();

    bool process_data() override;
};

#endif // MKPARTITION_H
