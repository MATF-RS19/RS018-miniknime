#ifndef MKDATA_H
#define MKDATA_H

#include <vector>
#include <utility>

template <class T>
class MKData
{
public:

    MKData ()
    {
    }

    ~MKData()
    {
    }

    MKData(std::vector<std::vector<T>> data)
        : data (std::move(data))
    {
    }

    MKData(const MKData& other)
        : data (other.data)
    {
    }

    MKData(MKData&& other)
        : data (std::move(other.data))
    {
    }

    MKData& operator= (MKData other)
    {
        std::swap(other.data, data);
        return *this;
    }


    std::vector<std::vector<T>> data;
};

#endif // MKDATA_H
