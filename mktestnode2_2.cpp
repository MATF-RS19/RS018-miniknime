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
    MKData local_data1 = m_inputs[0].pullData().second;
    MKData local_data2 = m_inputs[1].pullData().second;
    size_t n0 = local_data1.data.size();
    size_t m0 = local_data1.data[0].size();
    size_t n1 = local_data2.data.size();
    size_t m1 = local_data2.data[0].size();

    size_t n = n0<n1?n0:n1;
    size_t m = m0<m1?m0:m1;

    for(size_t i = 0; i < n; i++){
        for(size_t j = 0; j < m; j++)
        {
           local_data1.data[i][j]+=local_data2.data[i][j];
        }
    }

    for(size_t i = 0; i < n; i++)
    {
        for(size_t j = 0; j < m; j++)
        {
            std::cout << "("<<i<<","<<j<<") "<< local_data1.data[i][j] << std::endl;
        }
    }

    m_outputs[0].pushData(new MKData(local_data1));
    m_outputs[1].pushData(new MKData(local_data1));

    propagate();
    return true;
}

