#ifndef MKMLPREGRESSION_H
#define MKMLPREGRESSION_H

#include "mknode.h"
#include "dlib-19.16/dlib-19.16/dlib/mlp.h"

using namespace dlib;

class MKMLPRegression : public MKNode
{
public:
    MKMLPRegression();

    bool process_data() override;

    void trainNet(long NodesInInputLayer,
                  long NodesInFirstHiddenLayer,
                  long NodesInSecondHiddenLayer = 0,
                  long NodesInOutputLayer = 1,
                  double alpha = 0.1,
                  double momentum = 0.8);

};
#endif // MKMLPREGRESSION_H
