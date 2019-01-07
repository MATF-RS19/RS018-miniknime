#include "mknode.h"
#include <vector>
#include <iostream>
#include <map>


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

bool MKNode::isReady(){
    for (const auto& input : m_inputs) {
        if(input.connectedTo==nullptr){
            return false;
        }
    }
    return true;
}

bool MKNode::process_data()
{
    return false;
}

void MKNode::propagate()
{
    auto visited=std::map<MKNode*,bool>();
    for(const auto &output : m_outputs) {
        if(output.connectedTo!=nullptr){
            auto node=output.connectedTo->parent;
            visited[node]=node->isReady();
        }
    }
    for(auto& node : visited) {
        if(node.second==true){
            node.first->process_data();
        }
    }
}

MKNode::~MKNode()
{
}

