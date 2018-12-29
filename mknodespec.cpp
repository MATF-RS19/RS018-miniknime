#include "mknodespec.h"
#include <utility>
#include <iostream>


MKNodeSpec::MKNodeSpec()
    : MKNode(std::vector<MKInput>(1), std::vector<MKOutput> (1))
{
}


bool MKNodeSpec::process_data()
{
    // vidi da li je prethodni zavrsio
    int local_data = m_inputs[0].data();
    ++local_data;


    std::cout << local_data << std::endl;

    // data propagation
    m_outputs[0].connectedTo->setData(local_data);
    return true;
}

