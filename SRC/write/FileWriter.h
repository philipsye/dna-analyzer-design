//
// Created by a on 7/8/20.
//

#ifndef DNA_SEQUENCE_FILEWRITER_H
#define DNA_SEQUENCE_FILEWRITER_H

#include "Writer.h"


class FileWriter {
public:
    FileWriter(const char* name);
    void write(std::string seq);

private:
    std::string m_fileName;
};


#endif //DNA_SEQUENCE_FILEWRITER_H
