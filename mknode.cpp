#include "mknode.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>


MKNode::MKNode()
{
}

MKNode::MKNode(int ins, int outs)
{
    for(int i=0; i<ins;i++){
        m_inputs.push_back(MKInput<double>(this));
    }
    for(int i=0; i<outs;i++){
        m_outputs.push_back(MKOutput<double>(this));
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

void MKNode::requestProcess(){
    for (const auto& input : m_inputs) {
        if(input.connectedTo==nullptr || !input.connectedTo->isContentValid){
            return;
        }
    }
    process_data();
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
            node.first->sendInvalidationPulse();
            node.first->requestProcess();
        }
    }
}

void MKNode::sendInvalidationPulse(std::set<MKNode*>* marked){
    marked->insert(this);

//    for(const auto n : *marked){
//        std::cout<<n<<"_";
//    }
//    std::cout<<std::endl;

    auto visited=std::set<MKNode*>();
    for(auto &output : m_outputs) {
        if(output.connectedTo!=nullptr){
            auto node=output.connectedTo->parent;
            if(marked->find(node) == marked->end()){
                output.isContentValid=false;
                visited.insert(node);
            }
        }
    }
    for(auto& node : visited) {
            node->sendInvalidationPulse(marked);
    }
}

MKNode::~MKNode()
{
}

