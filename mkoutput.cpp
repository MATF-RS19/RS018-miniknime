#include "mkoutput.h"
#include "mkinput.h"
#include "mkdata.h"

MKOutput::MKOutput(MKNode* par)
{
    //samo za proveru
    std::vector<std::vector<double>> v (4, std::vector<double>(4, 3));
    parent = par;
    auto data=new MKData<double>();
    data->data=std::vector<std::vector<double>>(1, std::vector<double>(1));
    content = data;
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

MKData<double>* MKOutput::data(){
    return content;
}
void MKOutput::pushData(MKData<double>* content){
    isContentValid=true;
    this->content=content;
}



