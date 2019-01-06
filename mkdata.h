#ifndef MKDATA_H
#define MKDATA_H

#include <vector>


class MKData
{
public:
    MKData(std::vector<std::vector<double>> data);
    std::vector<std::vector<double>> data;
};

#endif // MKDATA_H
