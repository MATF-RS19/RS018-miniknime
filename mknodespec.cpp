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
    MKData local_data = m_inputs[0].pullData().second;
    size_t n = local_data.data.size();
    size_t m = local_data.data[0].size();

    std::cout << n << " " << m << std::endl;

    for(size_t i = 0; i < n; i++)
        for(size_t j = 0; j < m; j++)
        {
           ++local_data.data[i][j];
        }


    for(size_t i = 0; i < n; i++)
        for(size_t j = 0; j < m; j++)
        {
           std::cout << local_data.data[i][j] << std::endl;
        }

    //prep outputs
    m_outputs[0].content=new MKData(local_data);

    propagate();
    return true;
}

//ovo ne bi trebalo da se overriduje jer je isto svuda ali to ne znam da uradim
void MKNodeSpec::propagate(){
    for(const auto &output : m_outputs) {
        if(output.connectedTo!=nullptr){
            output.connectedTo->parent->process_data();
        }
    }
}



