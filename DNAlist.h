#ifndef DNA_SEQUENCE_DNALIST_H
#define DNA_SEQUENCE_DNALIST_H

#include "ApplicationManager.h"
#include "DNA.h"

class DNAlist {
public:
    void addToList(DNA dna);
    void printOneDna(size_t index);
    size_t sizeList(){ return m_DNAlist.size();}
private:
    std::vector<DNA> m_DNAlist;
};


#endif //DNA_SEQUENCE_DNALIST_H
