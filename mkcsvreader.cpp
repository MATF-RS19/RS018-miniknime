#include "mkcsvreader.h"

#include <iterator>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

// CSVRow class taken from
// with minor changes
// https://stackoverflow.com/questions/1120140/how-can-i-read-and-parse-csv-files-in-c

class CSVRow
{
public:

    const std::vector<std::string> data() const
    {
       return m_data;
    }

    std::string const& operator[](std::size_t index) const
    {
        return m_data[index];
    }

    std::size_t size() const
    {
        return m_data.size();
    }

    void readNextRow(std::istream& str)
    {
        std::string         line;
        std::getline(str, line);

        std::stringstream   lineStream(line);
        std::string         cell;

        m_data.clear();
        while(std::getline(lineStream, cell, ','))
        {
            m_data.push_back(cell);
        }
        // This checks for a trailing comma with no data after it.
        if (!lineStream && cell.empty())
        {
            // adding zero for trailing comma
            m_data.push_back("0");
        }
    }

private:
    std::vector<std::string>    m_data;
};

std::istream& operator>>(std::istream& str, CSVRow& data)
{
    data.readNextRow(str);
    return str;
}

MKCSVReader::MKCSVReader()
    : MKNode(0, 1)
{
}

bool MKCSVReader::process_data()
{
    return true;
}

bool MKCSVReader::readFromCSV(const std::string path)
{
    CSVRow row;
    std::ifstream file (path);

    if (!file.is_open()) {
        std::cout << "MKCSVREADER FAILED TO OPEN FILE " << path << std::endl;
        return false;
    }

    file >> row;
    std::vector<std::string> local_header (row.data());
    std::vector<std::vector<double>> X; // local instances of dataset

    while (file >> row)
    {
        std::vector<std::string> tmp (row.data());
        std::vector<double> x (row.size());

        std::transform(tmp.begin(),
                       tmp.end(),
                       x.begin(),
                       [] (std::string s) { return std::atof(s.c_str()); });

        X.push_back(x);
    }

    MKData<double> local_data (local_header, X);
    m_outputs[0].pushData(new MKData<double>(local_data));

    propagate();

    return true;
}














