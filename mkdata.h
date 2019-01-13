#ifndef MKDATA_H
#define MKDATA_H

#include <vector>
#include <string>
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

    // backward compatibility
    MKData(std::vector<std::vector<T>> data)
        : data (data)
    {
    }

    MKData(std::vector<std::string> header, std::vector<std::vector<T>> data)
        : data (data)
        , m_header (header)
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


    std::vector<std::string> m_header; // head of dataset i.e vector of attribute names
    std::vector<std::vector<T>> data;
};

#endif // MKDATA_H
