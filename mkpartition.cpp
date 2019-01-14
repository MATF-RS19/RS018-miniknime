#include "mkpartition.h"

#include <algorithm>
#include <iterator>
#include <cmath>
#include <random>



/*
 * Default constructor creates MKPartition instance
 * with 1 MKInput and 2 MKOutputs
 *
*/
MKPartition::MKPartition()
    : MKNode (1, 2)
{

}




bool MKPartition::partition(double ratio)
{
    if (ratio < 0 || ratio > 100) {
        std::cout << "ratio has to be in range [0, 100] ";
        return false;
    }

    MKData<double> local_data = m_inputs[0].pullData().second;

    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(local_data.data.begin(), local_data.data.end(), g);

    // dividing data into to two partitions where one has ratio% of local_data.data data
    int cross_point = std::rint((ratio / 100) * local_data.data.size());
    auto cross_iter = local_data.data.begin() + cross_point;

    MKData<double> partition1 (std::vector<std::vector<double>> (local_data.data.begin(), cross_iter));
    MKData<double> partition2 (std::vector<std::vector<double>> (cross_iter, local_data.data.end()));

    m_outputs[0].pushData(new MKData<double>(partition1));
    m_outputs[1].pushData(new MKData<double>(partition2));

    propagate();
    return true;

}

bool MKPartition::process_data()
{
    return true;

}
