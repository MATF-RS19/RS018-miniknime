#ifndef MKCSVREADER_H
#define MKCSVREADER_H

#include "mknode.h"

#include <iostream>
#include <string>

/*
 * MKNode specialization for reading data from csv files
*/

class MKCSVReader : public MKNode
{
public:

    MKCSVReader();
    bool process_data() override;

    bool readFromCSV(const std::string path);


};



#endif // MKCSVREADER_H
