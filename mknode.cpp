#include "mknode.h"
#include <vector>
#include <iostream>


MKNode::MKNode()
{
}

MKNode::MKNode(std::vector<MKInput> inputs, std::vector<MKOutput> outputs)
    : m_inputs  (inputs)
    , m_outputs (outputs)
{

    for(auto input : inputs){
        std::cout<<this<<std::endl;
        input.parent=this;
    }
}

bool MKNode::process_data()
{
    return false;
}

MKNode::~MKNode()
{
}

