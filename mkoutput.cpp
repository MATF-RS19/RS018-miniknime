#include "mkoutput.h"
#include "mkinput.h"
#include "mkdata.h"

MKOutput::MKOutput(MKNode* par)
{
    parent=par;
    content=new MKData(0);
    connectedTo=nullptr;
}

MKOutput::~MKOutput()
{
}

void MKOutput::establishConnection(MKInput& other, bool isEstablishedOnOtherEnd)
{
    connectedTo = &other;
    if (false == isEstablishedOnOtherEnd)
    {
        other.establishConnection(*this, true);
    }
}


