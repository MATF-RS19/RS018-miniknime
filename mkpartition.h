#ifndef MKPARTITION_H
#define MKPARTITION_H

#include "mknode.h"


/*
 * Specialization of MKNode class that performs dataset partitioning
 * i.e partitions data into training and test data
 *
*/
class MKPartition : public MKNode
{
public:
    MKPartition();

    bool process_data() override;
    bool partition(double ratio);
};

#endif // MKPARTITION_H
