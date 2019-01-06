#include "mkoutput.h"
#include "mkinput.h"
#include "mkdata.h"

MKOutput::MKOutput(MKNode* par)
{
    //samo za proveru
    std::vector<std::vector<double>> v (5, std::vector<double>(5 ,1));
    parent=par;
    content=new MKData(v);
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


