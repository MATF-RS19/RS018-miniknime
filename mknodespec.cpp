#include "mknodespec.h"
#include "mkdata.h"
#include <utility>
#include <iostream>


MKTestNode1_1::MKTestNode1_1()
    : MKNode(1,1)
{
}


bool MKTestNode1_1::process_data()
{
    std::cout << "enter single"<< std::endl;
    MKData local_data = m_inputs[0].pullData().second;
    size_t n = local_data.data.size();
    size_t m = local_data.data[0].size();


    for(size_t i = 0; i < n; i++)
        for(size_t j = 0; j < m; j++)
        {
           ++local_data.data[i][j];
        }

    for(size_t i = 0; i < n; i++)
    {       
        for(size_t j = 0; j < m; j++)
        {
           std::cout << "("<<i<<","<<j<<") "<< local_data.data[i][j] << std::endl;
        }
    }

    //prep outputs
    m_outputs[0].pushData(new MKData(local_data));

    propagate();
    return true;
}



