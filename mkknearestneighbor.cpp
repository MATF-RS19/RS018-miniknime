#include "mkknearestneighbor.h"

#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <cmath>

bool comparsion(const std::pair<double, double>& a,
                const std::pair<double, double>& b)
{
    return a.second < b.second;
}

MKKNearestNeighbor::MKKNearestNeighbor()
    : MKNode (2, 0)
{
}

bool MKKNearestNeighbor::process_data()
{

    return true;
}

bool MKKNearestNeighbor::classify(unsigned int k,
                                  unsigned long labelIndex,
                                  double x,
                                  double y)
{

    std::vector<double> p (2);
    p.push_back(x);
    p.push_back(y);

    MKData<double> local_data = m_inputs[0].pullData().second;

    std::vector<std::vector<double>>& X = local_data.data;
    std::vector<std::pair<double, double>> distances;

    for (const auto& x : X) {
        double distance = 1;
        for (int i = 0; i < x.size(); ++i) {
            if ( i == labelIndex )      // trenutno resenje, losa struktura za cuvanje podataka
                continue;               // potrebno naci bolju strukturu, npr pair<X, y>

            distance += (x[i] - p[i]) * (x[i] - p[i]);
        }
        distances.push_back(std::make_pair(x[labelIndex], std::sqrt(distance)));
    }
    std::sort(distances.begin(), distances.end(), comparsion);

    std::map<double, double> closestNeighbors;
    for (int i = 0; i < k; ++i) {
        if (closestNeighbors.find(distances[i].first) == closestNeighbors.end()) {
            closestNeighbors[distances[i].first] = 1;
        } else {
            closestNeighbors[distances[i].first] += 1;
        }
    }


    for (unsigned long i = 0; i < p.size(); ++i) {
       std::cout << p[i] << " ";
    }

    std::cout << "   : predicted class ";
    auto maxIt = std::max_element(closestNeighbors.begin(), closestNeighbors.end(), comparsion);
    std::cout << maxIt->first << std::endl;


}
