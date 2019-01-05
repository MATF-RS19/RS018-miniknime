#include "mknode.h"
#include <vector>
#include <iostream>


MKNode::MKNode()
{
}

MKNode::MKNode(int ins, int outs)
{
    m_inputs=std::vector<MKInput>();
    for(int i=0; i<ins;i++){
        m_inputs.push_back(MKInput(this));
    }
    m_outputs=std::vector<MKOutput>();
    for(int i=0; i<outs;i++){
        m_outputs.push_back(MKOutput(this));
    }
}

bool MKNode::process_data()
{
    return false;
}

void MKNode::propagate()
{
}

MKNode::~MKNode()
{
}

