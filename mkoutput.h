#ifndef MKOUTPUT_H
#define MKOUTPUT_H

class MKInput;

class MKOutput
{
public:
    MKOutput();
    ~MKOutput();

    void establishConnection(MKInput& other, bool isEstablishedOnOtherEnd = false);
    void passData(int data);

    MKInput* connectedTo;
};

#endif // MKOUTPUT_H
