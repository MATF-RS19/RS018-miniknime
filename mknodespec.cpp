#include "mknodespec.h"
#include "mkdata.h"
#include <utility>
#include <iostream>


MKNodeSpec::MKNodeSpec()
    : MKNode(1,1)
{
}


bool MKNodeSpec::process_data()
{
    std::cout << "enter"<< std::endl;
    int local_data = m_inputs[0].pullData().data;
    ++local_data;

    std::cout << local_data << std::endl;

    //prep outputs
    m_outputs[0].content=new MKData(local_data);

    propagate();
    return true;
}

//ovo ne bi trbalo da se overriduje jer je isto svuda ali to ne znam da uradim
void MKNodeSpec::propagate(){
    for(const auto &output : m_outputs) {
        if(output.connectedTo!=nullptr){
            output.connectedTo->parent->process_data();
        }
    }
}



