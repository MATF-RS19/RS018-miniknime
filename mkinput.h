#ifndef MKINPUT_H
#define MKINPUT_H

class MKOutput;

class MKNode;

class MKInput
{
public:
    MKInput();

    ~MKInput();


    void establishConnection(MKOutput& other, bool establishedOnOtherEnd = false);

    MKOutput* connectedTo; // referenca na onog na kojeg je povezan
    MKNode* parent;

    int data();
    void setData(int newData);

private:
        int m_data;

};

#endif // MKINPUT_H
