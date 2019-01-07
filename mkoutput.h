#ifndef MKOUTPUT_H
#define MKOUTPUT_H

class MKInput;
class MKData;
class MKNode;

class MKOutput
{
public:
    MKOutput(MKNode* par);
    ~MKOutput();

    void establishConnection(MKInput& other, bool isEstablishedOnOtherEnd = false);

    MKNode* parent;
    MKInput* connectedTo;    
    bool isContentValid=false;
    MKData* data();
    void pushData(MKData* content);

private:
    MKData* content;
};

#endif // MKOUTPUT_H
