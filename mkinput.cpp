#include "mkinput.h"
#include "mkoutput.h"
#include "mknode.h"
#include "mkdata.h"
#include <iostream>


MKInput::MKInput(MKNode* par)
{
    parent = par;
    connectedTo=nullptr;
}

MKInput::~MKInput()
{
}

void MKInput::establishConnection(MKOutput& other, bool isEstablishedOnOtherEnd)
{
    connectedTo = &other;
    if (false == isEstablishedOnOtherEnd)
    {
        other.establishConnection(*this, true);
    }
}

std::pair<bool, MKData<double>> MKInput::pullData(){
    if(connectedTo!=nullptr){
        return std::make_pair(true, *(connectedTo->data()));
    }
    auto data=MKData<double>();
    data.data=std::vector<std::vector<double>>(1, std::vector<double>(1));
    return std::make_pair(false, data);
}



