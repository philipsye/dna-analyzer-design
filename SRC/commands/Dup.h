#ifndef DNA_SEQUENCE_DUP_H
#define DNA_SEQUENCE_DUP_H

#include "../DNA/createDNAseq.h"


class Dup : public createDNAseq{
public:
    bool isValid(std::vector<std::string> input);
    void run(std::vector<std::string>);
};


#endif //DNA_SEQUENCE_DUP_H
