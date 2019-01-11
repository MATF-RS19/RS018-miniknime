#ifndef MKINPUT_H
#define MKINPUT_H

#include "mkdata.h"
#include <utility>

template <typename T> class MKOutput;
class MKNode;


template <typename T>
class MKInput
{
public:

    MKInput(MKNode* par)
        : parent (par)
        , connectedTo (nullptr)
    {
    }

    ~MKInput()
    {
    }


    void establishConnection(MKOutput<T>& other, bool isEstablishedOnOtherEnd = false)
    {
        connectedTo = &other;
        if (false == isEstablishedOnOtherEnd)
        {
            other.establishConnection(*this, true);
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


};

#endif // MKINPUT_H
