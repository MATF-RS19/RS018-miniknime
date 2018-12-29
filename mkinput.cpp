#include "mkinput.h"
#include "mkoutput.h"
#include "mknode.h"

MKInput::MKInput()
    : m_data (0)
{
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

int MKInput::data(){
    return m_data;
}

void MKInput::setData(int newData){
    m_data=newData;
    //parent->process_data();
}
