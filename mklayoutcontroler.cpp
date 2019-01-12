#include "mklayoutcontroler.h"

MKLayoutControler::MKLayoutControler()
{

}

void MKLayoutControler::initialize(){
    allNodes=std::map<QWidget,MKNode*>();
}
