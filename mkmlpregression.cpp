#include "mkmlpregression.h"

#include <iostream>

using namespace dlib;

//Two inputs, one for training data, second for test data
MKMLPRegression::MKMLPRegression()
    : MKNode (2, 0)
{
}

bool MKMLPRegression::process_data()
{
    return true;
}

// Trains MLP and outputs predictions
void MKMLPRegression::trainNet(long perceptronsInInputLayer,
                               long perceptronsInFirstHiddenLayer,
                               long perceptronsInSecondHiddenLayer,
                               long perceptronsInOutputLayer,
                               double alpha,
                               double momentum)
{

    MKData<double> local_training_data = m_inputs[0].pullData().second;

    std::vector<std::vector<double>>& X = local_training_data.data;

    if (X[0].size() - 1 != perceptronsInInputLayer ) {
        std::cout << "Number of input perceptrons must be equal to the size of instance." << std::endl;
        return;
    }

    // Column vector
    // one dimension smaller then instance
    matrix<double> m (perceptronsInInputLayer, 1);

    mlp::kernel_1a_c net(perceptronsInInputLayer,
                         perceptronsInFirstHiddenLayer,
                         perceptronsInSecondHiddenLayer,
                         perceptronsInOutputLayer,
                         alpha,
                         momentum);

    // training neural net
    for (const auto& x : X) {
        for (unsigned long i = 1; i < x.size(); ++i) {
            m(i-1) = x[i];
        }
        net.train(m, x[0]);
    }


    MKData<double> local_test_data = m_inputs[1].pullData().second;
    std::vector<std::vector<double>>& testData = local_test_data.data;

    // testing neural net
    for (auto x : testData) {
        for (unsigned long i = 1; i < x.size(); ++i) {
            m(i-1) = x[i];
        }
        std::cout << "Target ";
        std::cout << x[0];

        std::cout << " Predicted as: " << net(m);
    }

}
