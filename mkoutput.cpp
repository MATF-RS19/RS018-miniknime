#include "mkoutput.h"
#include "mkinput.h"
#include "mkdata.h"

MKOutput::MKOutput(MKNode* par)
{
    //samo za proveru
    std::vector<std::vector<double>> v (4, std::vector<double>(4, 3));
    parent = par;
    content = new MKData(v);
    connectedTo = nullptr;
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

MKData* MKOutput::data(){
    return content;
}
void MKOutput::pushData(MKData* content){
    isContentValid=true;
    this->content=content;
}



