#ifndef DNA_SEQUENCE_LOAD_H
#define DNA_SEQUENCE_LOAD_H


#include "../DNA/createDNAseq.h"


class Load : public createDNAseq{
public:
    bool isValid(std::vector<std::string> input);
    void run(std::vector<std::string>);
    void print(const std::string& seq, const std::string& name, size_t id, size_t len);
};


#endif //DNA_SEQUENCE_LOAD_H
