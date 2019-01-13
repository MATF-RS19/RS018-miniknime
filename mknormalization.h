#ifndef MKNORMALIZATION_H
#define MKNORMALIZATION_H

#include "mknode.h"

class MKNormalization : public MKNode
{
public:
    MKNormalization();

    bool process_data() override;
};

#endif // MKNORMALIZATION_H
