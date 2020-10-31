#ifndef DNA_SEQUENCE_NEW_H
#define DNA_SEQUENCE_NEW_H

#include "../DNA/createDNAseq.h"


class New : public createDNAseq {
public:
    bool isValid(std::vector<std::string> input);
    void run(std::vector<std::string>);

private:
    static bool isValidDna(const std::string&);
};


#endif //DNA_SEQUENCE_NEW_H
