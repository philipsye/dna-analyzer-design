#ifndef DNA_SEQUENCE_KBOARDREADER_H
#define DNA_SEQUENCE_KBOARDREADER_H

#include "Reader.h"


class KBoardReader : public Reader {
public:
    KBoardReader();
    std::string read()const { return m_dna;}
};


#endif //DNA_SEQUENCE_KBOARDREADER_H
