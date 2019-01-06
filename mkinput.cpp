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

//nisam siguran da ovako treba da kopiramo vrednost
std::pair<bool, MKData> MKInput::pullData(){
    if(connectedTo!=nullptr){
        return std::make_pair(true, *(connectedTo->content));
    }
    return std::make_pair(false, MKData(std::vector<std::vector<double>> (1, std::vector<double>(1, 0))));
}


