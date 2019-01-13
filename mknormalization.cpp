#include "mknormalization.h"


std::vector<double> columnMax(std::vector<std::vector<double>>& X)
{
    // ad-hoc solution
    std::vector<double> maxs (X.size(), -1);

    for (auto& x : X) {
        for (unsigned long i = 0; i < x.size(); ++i) {
            if ( x[i] > maxs[i])
                maxs[i] = x[i];
        }
    }

    return maxs;
}


MKNormalization::MKNormalization()
    : MKNode (1, 1)
{
}

bool MKNormalization::process_data()
{
    MKData<double> local_data = m_inputs[0].pullData().second;

    std::vector<double> maxs = columnMax(local_data.data);

    for (auto& x : local_data.data) {
        for (unsigned long i = 0; i < x.size(); ++i) {
            if ( maxs[i] == 0.0 ) {
                x[i] = maxs[i];
            }
            x[i] /= maxs[i];
        }
    }

    m_outputs[0].pushData(new MKData<double>(local_data));

    propagate();

    return true;
}

