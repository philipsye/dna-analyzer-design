/*#include "Nucleotide.h"

Nucleotide::Nucleotide(char* ptrDna, size_t indexToDna , unsigned char* packedBits):
        m_nucleotide(ptrDna[indexToDna]),m_index(indexToDna),m_packedBitsN(packedBits) {}


Nucleotide& Nucleotide::operator=(char c) {
    switch(c) {

        case 'A':
            m_packedBitsN[0] &= ~(1UL << (m_index * 2));
            m_packedBitsN[0] &= ~(1UL << (m_index * 2) % 8);
            break;

        case 'C':
            m_packedBitsN[4 / m_index] &= ~(1UL << (m_index * 2) % 8);
            m_packedBitsN[4 / m_index] |= 1UL << (m_index * 2) % 8;
            break;

        case 'G':
            m_packedBitsN[4 / m_index] |= 1UL << (m_index * 2) % 8;
            m_packedBitsN[4 / m_index] &= ~(1UL << (m_index * 2) % 8);
            break;

        case 'T':
            *m_packedBitsN=1;
            break;

        default:
            throw std::invalid_argument("Unknown character.");
    }
    return *this;
}*/