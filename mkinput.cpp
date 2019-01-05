#include "mkinput.h"
#include "mkoutput.h"
#include "mknode.h"
#include "mkdata.h"
#include <iostream>

MKInput::MKInput(MKNode* par)
{
    parent= par;
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
MKData MKInput::pullData(){
    if(connectedTo!=nullptr){
        return *(connectedTo->content);
    }
    return MKData(0);
}


