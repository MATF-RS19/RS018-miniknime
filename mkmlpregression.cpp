#include "mkmlpregression.h"

#include <iostream>

using namespace dlib;

MKMLPRegression::MKMLPRegression()
    : MKNode (2, 1)
{
}

bool MKMLPRegression::process_data()
{
    return true;
}

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
        std::cout << "Broj ulaznih perceptrona mora da odgovara velicini instance" << std::endl;
        return;
    }

    // vektor kolona
    // za dimenziju manji od instance
    matrix<double> m (perceptronsInInputLayer, 1);

    mlp::kernel_1a_c net(perceptronsInInputLayer,
                         perceptronsInFirstHiddenLayer,
                         perceptronsInSecondHiddenLayer,
                         perceptronsInOutputLayer,
                         alpha,
                         momentum);

    // training neural net
    for (auto x : X) {
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
