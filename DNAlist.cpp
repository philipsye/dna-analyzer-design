#include "DNAlist.h"

void DNAlist::addToList(DNA dna) {
    m_DNAlist.push_back(dna);
}


void DNAlist::printOneDna(size_t index) {
    std::cout<<"["<<m_DNAlist[index].getId()<<"] ";
    std::cout<<m_DNAlist[index].getName()<<": ";
    std::cout<<m_DNAlist[index].getSeq().getPackedSequence();


}