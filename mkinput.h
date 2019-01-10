#ifndef MKINPUT_H
#define MKINPUT_H

#include "mkdata.h"
#include <utility>

class MKOutput;
class MKNode;


class MKInput
{
public:
    MKInput(MKNode* par);

    ~MKInput();


    void establishConnection(MKOutput& other, bool establishedOnOtherEnd = false);

    MKOutput* connectedTo; // referenca na onog na kojeg je povezan
    MKNode* parent;

    std::pair<bool, MKData<double>> pullData();


};

#endif // MKINPUT_H
