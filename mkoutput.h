#ifndef MKOUTPUT_H
#define MKOUTPUT_H

#include "mkdata.h"

template <typename T> class MKInput;
class MKNode;

template <typename T>
class MKOutput
{
public:
    MKOutput(MKNode* par)
    {
        //samo za proveru
        // #TODO azurirati ovaj konstruktor
        std::vector<std::vector<double>> v (4, std::vector<double>(4, 3));
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
        connectedTo = &other;
        if (false == isEstablishedOnOtherEnd)
        {
            other.establishConnection(*this, true);
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
    bool isContentValid=false;

private:
    MKData<T>* content;
};

#endif // MKOUTPUT_H
