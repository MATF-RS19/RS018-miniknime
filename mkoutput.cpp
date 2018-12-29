#include "mkoutput.h"
#include "mkinput.h"

MKOutput::MKOutput()
{

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

void MKOutput::passData(int data){
    if(connectedTo!=nullptr){
        connectedTo->setData(data);
    }
}
