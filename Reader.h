#ifndef DNA_SEQUENCE_READER_H
#define DNA_SEQUENCE_READER_H

#include "IReader.h"

class Reader: public IReader {
protected:
    std::string m_dna;
};


#endif //DNA_SEQUENCE_READER_H
