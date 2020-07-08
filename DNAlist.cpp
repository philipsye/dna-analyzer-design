#include "DNAlist.h"

void DNAlist::addToList(DNA* dna) {
    m_hashWithName.insert(std::pair<std::string , DNA*>(dna->getName(), dna));
    m_hashWithId.insert(std::pair<size_t , std::string>(dna->getId(), dna->getName()));
}


void DNAlist::printSingleDna(size_t index) {
    std::cout<<"["<<(m_hashWithName[m_hashWithId[index]])->getId()<<"] ";
    std::cout<<(m_hashWithName[m_hashWithId[index]])->getName()<<": ";
    std::cout<<(m_hashWithName[m_hashWithId[index]])->getSeq().getPackedSequence();
    std::cout<<std::endl;
}


bool DNAlist::existing(const std::string& s) {
    return !(m_hashWithName.find(s) == m_hashWithName.end());
}

