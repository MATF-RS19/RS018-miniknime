#ifndef MKINPUT_H
#define MKINPUT_H

#include "mkdata.h"
#include <utility>
#include <iostream>

template <typename T> class MKOutput;
class MKNode;
class MKLine;


template <typename T>
class MKInput
{
public:

    MKInput(MKNode* par,int positionIndex)
        : parent (par)
        , connectedTo (nullptr)
        , positionIndex(positionIndex)
    {
    }

    ~MKInput()
    {
    }


    void establishConnection(MKOutput<T>& other, bool isEstablishedOnOtherEnd = false)
    {
        if (connectedTo !=nullptr && false == isEstablishedOnOtherEnd){
            breakConnection();
        }
        connectedTo = &other;
        if (false == isEstablishedOnOtherEnd)
        {            
            other.establishConnection(*this, true);
        }
    }

    void breakConnection(bool isEstablishedOnOtherEnd = false)
    {
        if(connectedTo!=nullptr){
            if (isEstablishedOnOtherEnd==false)
            {
                connectedTo->breakConnection(true);
            }
            connectedTo=nullptr;
            connectedLine=nullptr;
        }
    }


    std::pair<bool, MKData<double>> pullData(){
        if(connectedTo!=nullptr){
            return std::make_pair(true, *(connectedTo->data()));
        }
        auto data=MKData<double>();
        data.data=std::vector<std::vector<double>>(1, std::vector<double>(1));
        return std::make_pair(false, data);
    }



    MKOutput<T>* connectedTo;
    MKNode* parent;
    int positionIndex;
    MKLine* connectedLine=nullptr;
};

#endif // MKINPUT_H
