#ifndef DNA_SEQUENCE_DNASEQUENCE_H
#define DNA_SEQUENCE_DNASEQUENCE_H
#include <vector>
#include "iostream"
#include "../read/Reader.h"

class DnaSequence {

public:

    DnaSequence(){}
    DnaSequence(const std::string&);

    DnaSequence(const char*);

    DnaSequence(const DnaSequence&);

    /*DnaSequence(const Reader& reader);*/

    ~DnaSequence();

    char operator[](size_t index) const;

    const DnaSequence& operator = (const DnaSequence &);

    char* getDnaBits()const ;

    char* returnDnaBits(unsigned char*, size_t)const ;

    char* getPackedSequence() const;

    size_t getLenDnaBits()const ;

    friend std::ostream& operator << (std::ostream& stream, const DnaSequence&);

    void setNucleotide(char nucleotide , size_t indexChange);

    DnaSequence slicing(size_t, size_t);

    char* switchToGetChar(unsigned char*, size_t,int)const ;

    size_t find(const DnaSequence&, size_t indexFrom = 0);

    std::vector<size_t> findAll(const DnaSequence& , size_t indexFrom=0);

    size_t count(const DnaSequence&);

    DnaSequence& pairing();

    void findConsensus(std::vector<size_t>&,std::vector<size_t>&,std::vector<DnaSequence>&);

    std::vector<DnaSequence> findConsensusSequences();

    void writeToFile( const char*);


private:
    unsigned char* m_packedBits;
    size_t m_lenDnaBits;
};


bool operator == (const DnaSequence& , const DnaSequence&);

bool operator != (const DnaSequence& , const DnaSequence&);

unsigned short lengthDna(const DnaSequence&);


#endif //DNA_SEQUENCE_DNASEQUENCE_H
