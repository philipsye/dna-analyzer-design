#ifndef DNA_SEQUENCE_IREADER_H
#define DNA_SEQUENCE_IREADER_H

#include "iostream"

class IReader {
    virtual std::string read() const =0;
};


#endif //DNA_SEQUENCE_IREADER_H
