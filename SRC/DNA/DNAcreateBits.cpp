#include "DNAcreateBits.h"
#include "iostream"
#define placingValue1InBit(place,bit) (place) |= 1 << (bit)


unsigned char* returnDnaToBits(const char *dnaToBits, int lenDnaBits) {
    unsigned char* packed_bits = new unsigned char[lenDnaBits/8];
    unsigned char* PTRpacked_bits=packed_bits;
    char* dnaPtr = const_cast<char *>(dnaToBits);
    int index=0;
    int indexDna = 0;
    while(dnaPtr[index]){

        switch (dnaPtr[index]) {
            case 'A':
                indexDna ++;
                index ++;
                indexDna++;
                if (indexDna != 0 && indexDna % 8 == 0)
                    PTRpacked_bits++;
                break;

            case 'C':
                indexDna++;
                placingValue1InBit(*PTRpacked_bits, indexDna % 8);
                index++;
                indexDna++;
                if (indexDna != 0 && indexDna % 8 == 0)
                    PTRpacked_bits++;
                break;

            case 'G':
                placingValue1InBit(*PTRpacked_bits, indexDna % 8);
                indexDna++;
                index++;
                indexDna++;
                if (indexDna != 0 && indexDna % 8 == 0)
                    PTRpacked_bits++;
                break;

            case 'T':
                placingValue1InBit(*PTRpacked_bits, indexDna % 8);
                indexDna++;
                index++;
                placingValue1InBit(*PTRpacked_bits, indexDna % 8);
                indexDna++;
                if (indexDna != 0 && indexDna % 8 == 0)
                    PTRpacked_bits++;
                break;

            default:
                throw std::invalid_argument("Unknown character.");
        }

    }
    PTRpacked_bits[lenDnaBits/8+1]='\0';
    return packed_bits;
}