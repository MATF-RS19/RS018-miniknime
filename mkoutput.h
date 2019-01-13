#ifndef MKOUTPUT_H
#define MKOUTPUT_H

#include "mkdata.h"
#include <iostream>

template <typename T> class MKInput;
class MKNode;

template <typename T>
class MKOutput
{
public:
    MKOutput(MKNode* par, int positionIndex)
    {
        this->positionIndex=positionIndex;
        parent = par;
        auto data=new MKData<double>();
        data->data=std::vector<std::vector<double>>(1, std::vector<double>(1));
        content = data;
        connectedTo = nullptr;
    }

    ~MKOutput()
    {
    }

    void establishConnection(MKInput<T>& other, bool isEstablishedOnOtherEnd = false)
    {
        if (false == isEstablishedOnOtherEnd){
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
        }
    }

    const MKData<T>* data() const {
        return content;
    }

    void pushData(MKData<double>* content) {
        isContentValid=true;
        this->content=content;
    }



    MKNode* parent;
    MKInput<T>* connectedTo;
    int positionIndex;
    bool isContentValid=false;

private:
    MKData<T>* content;
};

#endif // MKOUTPUT_H
