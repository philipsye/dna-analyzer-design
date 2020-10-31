#ifndef DNA_SEQUENCE_WRITER_H
#define DNA_SEQUENCE_WRITER_H

#include "iostream"


class Writer {
public:
    virtual void write(std::string)=0;
};


#endif //DNA_SEQUENCE_WRITER_H
