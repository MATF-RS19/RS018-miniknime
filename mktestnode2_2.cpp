#include "mktestnode2_2.h"
#include "mkdata.h"
#include <utility>
#include <iostream>



MKTestNode2_2::MKTestNode2_2()
    : MKNode(2,2)
{
}


bool MKTestNode2_2::process_data()
{
    std::cout << "enter"<< std::endl;
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
        std::cout << "data after process: "<< std::endl;
        for(size_t j = 0; j < m; j++)
        {
           std::cout << local_data.data[i][j] << std::endl;
        }
    }

    //prep outputs
    m_outputs[0].content=new MKData(local_data);
    m_outputs[1].content=new MKData(local_data);

    propagate();
    return true;
}

