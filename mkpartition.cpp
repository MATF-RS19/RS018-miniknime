#include "mkpartition.h"

#include <algorithm>
#include <iterator>
#include <cmath>
#include <random>

MKPartition::MKPartition()
    : MKNode (1, 2)
{

}

bool MKPartition::process_data()
{
    MKData<double> local_data = m_inputs[0].pullData().second;

    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(local_data.data.begin(), local_data.data.end(), g);

    // dividing data into to two partitions where one has 70% of local_data.data data
    int cross_point = std::rint((7.0 / 10) * local_data.data.size());
    auto cross_iter = local_data.data.begin() + cross_point;

    MKData<double> partition1 (std::vector<std::vector<double>> (local_data.data.begin(), cross_iter));
    MKData<double> partition2 (std::vector<std::vector<double>> (cross_iter, local_data.data.end()));


    m_outputs[0].pushData(&partition1);
    m_outputs[1].pushData(&partition2);

    propagate();

    return true;

}
