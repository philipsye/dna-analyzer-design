/*#ifndef DNA_SEQUENCE_NUCLEOTIDE_H
#define DNA_SEQUENCE_NUCLEOTIDE_H

#include "iostream"

class Nucleotide {

    public:
        Nucleotide(char* ,size_t indexToDna,unsigned char*);

        Nucleotide &operator=(char);

    private:
        char m_nucleotide;
        unsigned char* m_packedBitsN;
        size_t m_index;
};


#endif //DNA_SEQUENCE_NUCLEOTIDE_H
*/