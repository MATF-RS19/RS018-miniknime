#ifndef MKLINE_H
#define MKLINE_H

class MKLine
{
public:  
    MKLine(int startX, int startY, int endX, int endY, int positionIndex1,int positionIndex2);
    int startX;
    int startY;
    int endX;
    int endY;
private:
    static const int outputXOffset=155;
    static const int perIOPositionYOffest=5;
};

#endif // MKLINE_H
