#ifndef DNA_SEQUENCE_DNALIST_H
#define DNA_SEQUENCE_DNALIST_H

#include <map>
#include "ApplicationManager.h"
#include "DNA.h"


class DNAlist {
public:
    void addToList(DNA* dna);
    void printSingleDna(size_t index);
    size_t sizeList(){ return m_hashWithName.size();}

private:
    std::map<std::string , DNA*> m_hashWithName;
    std::map<size_t , std::string> m_hashWithId;
};


#endif //DNA_SEQUENCE_DNALIST_H
