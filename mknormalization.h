#ifndef MKNORMALIZATION_H
#define MKNORMALIZATION_H

#include "mknode.h"

/*
 * Specialization of MKNode that normalize data
 * i.e divides data with maximum value for each attribute
 */

class MKNormalization : public MKNode
{
public:
    MKNormalization();

    bool process_data() override;
};

#endif // MKNORMALIZATION_H
