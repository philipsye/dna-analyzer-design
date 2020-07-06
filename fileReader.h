#ifndef DNA_SEQUENCE_FILEREADER_H
#define DNA_SEQUENCE_FILEREADER_H

#include "Reader.h"


class fileReader : Reader{
public:
    explicit fileReader(const std::string& fName);
    std::string read()const { return m_dna;}
};


#endif //DNA_SEQUENCE_FILEREADER_H
