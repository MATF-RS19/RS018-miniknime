#include "mkline.h"


//Draws line from one node to the node that it is connected
MKLine::MKLine(int startX, int startY, int endX, int endY, int positionIndex1,int positionIndex2)
{
    this->startX=startX+MKLine::outputXOffset;
    this->startY=startY+(positionIndex1+1)*MKLine::perIOPositionYOffest;
    this->endX=endX;
    this->endY=endY+(positionIndex2+1)*MKLine::perIOPositionYOffest;
}
