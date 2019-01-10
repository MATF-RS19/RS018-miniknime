#ifndef MKOUTPUT_H
#define MKOUTPUT_H

#include "mkdata.h"

class MKInput;
class MKNode;

class MKOutput
{
public:
    MKOutput(MKNode* par);
    ~MKOutput();

    void establishConnection(MKInput& other, bool isEstablishedOnOtherEnd = false);

    MKNode* parent;
    MKInput* connectedTo;    
    bool isContentValid=false;
    MKData<double>* data();
    void pushData(MKData<double>* content);

private:
    MKData<double>* content;
};

#endif // MKOUTPUT_H
