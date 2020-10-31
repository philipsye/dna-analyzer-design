#ifndef DNA_SEQUENCE_DNALIST_H
#define DNA_SEQUENCE_DNALIST_H

#include <map>
#include "../manager/ApplicationManager.h"
#include "DNA.h"


class DNAlist {
public:
    void addToList(DNA* dna);
    void printSingleDna(size_t index);
    size_t sizeList(){ return m_hashWithName.size();}
    bool existing(const std::string&);
    std::string getSeqWithName(const std::string& name){return m_hashWithName[name]->getSeq().getPackedSequence();}
    std::string getSeqWithId(size_t id){return getSeqWithName(m_hashWithId[id]);}
    std::string getNameById(size_t id){return m_hashWithId[id];}

private:
    std::map<std::string , DNA*> m_hashWithName;
    std::map<size_t , std::string> m_hashWithId;
};


#endif //DNA_SEQUENCE_DNALIST_H
