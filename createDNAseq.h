#ifndef DNA_SEQUENCE_CREATEDNASEQ_H
#define DNA_SEQUENCE_CREATEDNASEQ_H

#include "commands.h"


class createDNAseq : public commands {
public:
    static std::string getNum();

protected:
    static size_t m_numDefaultNane;

};


#endif //DNA_SEQUENCE_CREATEDNASEQ_H
