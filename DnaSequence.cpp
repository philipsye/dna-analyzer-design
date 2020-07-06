#include "DnaSequence.h"
#include "DNAcreateBits.h"
#include "iostream"
#include "exception"
#include "string.h"
#include "fstream"

#define placingValue1InBit(place,bit) (place) |= 1 << (bit)
#define placingValue0InBit(place,bit) (place) &= ~(1<< (bit))
#define operatorAndInBits(place,bit) ((place) & (1 << bit))?'1':'0'


DnaSequence::DnaSequence(const char* dnaToBits):m_lenDnaBits(strlen(dnaToBits)*2){
    try {
        m_packedBits = (returnDnaToBits(dnaToBits, m_lenDnaBits));
    }
   catch (std::exception& e){
       std::cout<<e.what();
   }
}


DnaSequence::DnaSequence(const std::string &dnaToBits):m_lenDnaBits(strlen(dnaToBits.c_str())*2) {
    try {
    m_packedBits = (returnDnaToBits(const_cast<char *>(dnaToBits.c_str()),m_lenDnaBits));
    }
    catch (std::exception& e){
        std::cout<<e.what();
    }
}


DnaSequence::DnaSequence(const DnaSequence & dnaSequence):m_lenDnaBits(dnaSequence.m_lenDnaBits ) {
    m_packedBits = new unsigned char[dnaSequence.m_lenDnaBits / 4];
    for (int i = 0; i < dnaSequence.m_lenDnaBits / 4; i++) {
        m_packedBits[i] = dnaSequence.m_packedBits[i];
    }
}


/*DnaSequence::DnaSequence(const Reader &reader){

}
*/

DnaSequence::~DnaSequence() {
    delete[] m_packedBits;
}


const DnaSequence& DnaSequence::operator=(const DnaSequence &dnaSequence) {

    if(*this != dnaSequence) {
        m_lenDnaBits=dnaSequence.m_lenDnaBits;
        delete[] m_packedBits;
        m_packedBits=new unsigned char[dnaSequence.m_lenDnaBits/4];
        for(int i=0 ; i<dnaSequence.m_lenDnaBits/4 ; i++ ){
            m_packedBits[i] = dnaSequence.m_packedBits[i];
        }
    }
    return *this;
}


char DnaSequence::operator[](size_t index) const {

    bool bit1 = m_packedBits[index/4] & (1 << (index*2)%8);
    bool bit2 = m_packedBits[index/4] & (1 << (index*2+1)%8);
    char flag = (bit2 << 1) | bit1;

    switch(flag)
    {
        case 0:
            return  'A';
        case 1:
            return  'G';
        case 2:
            return 'C';
        case 3:
            return 'T';
    }
}


char* DnaSequence::getDnaBits()const {
    return returnDnaBits(m_packedBits,m_lenDnaBits);
}


char* DnaSequence::getPackedSequence() const {
    return switchToGetChar(m_packedBits , m_lenDnaBits,0);
}


std::ostream& operator<<(std::ostream &stream, const DnaSequence &dnaSequence) {
   stream<<"Binary representation: "<<dnaSequence.getDnaBits()<<std::endl
   << "Unpacked DNA: " << dnaSequence.getPackedSequence()<<std::endl;
    return stream;
}


bool operator==(const DnaSequence &dnaSequence1 , const DnaSequence& dnaSequence2) {
    if(dnaSequence1.getLenDnaBits()!=dnaSequence2.getLenDnaBits()){
        return false;
    }

    char *DnaSequence1 = dnaSequence1.getPackedSequence();
    char *DnaSequence2 = dnaSequence1.getPackedSequence();

    for(int i=0 ; i++ ; i < dnaSequence1.getLenDnaBits()){
        if(DnaSequence1[i]!=DnaSequence2[i]){
            return false;
        }
    }
    return true;
}


bool operator!=(const DnaSequence &dnaSequence1 , const DnaSequence& dnaSequence2) {
    return !operator==(dnaSequence1,dnaSequence2);
}


unsigned short lengthDna(const DnaSequence& dnaSequence){
    return dnaSequence.getLenDnaBits()/2;
}


size_t DnaSequence::getLenDnaBits() const {
    return m_lenDnaBits;
}


void DnaSequence::setNucleotide(char nucleotide , size_t indexChange) {

    if(indexChange >= m_lenDnaBits/2)
        throw std::invalid_argument("Function DnaSequence::setNucleotide ===> Index no match:(");

    size_t indexOfDnaBitsArr = indexChange/4;
    char indexOfFirstBit = (indexChange*2)%8;

    switch(nucleotide){

        case 'A':
            placingValue0InBit(m_packedBits[indexOfDnaBitsArr],indexOfFirstBit);
            placingValue0InBit(m_packedBits[indexOfDnaBitsArr],indexOfFirstBit+1);
            break;

        case 'G':
            placingValue0InBit(m_packedBits[indexOfDnaBitsArr],indexOfFirstBit);
            placingValue1InBit(m_packedBits[indexOfDnaBitsArr], indexOfFirstBit+1);

            break;

        case 'C':
            placingValue1InBit(m_packedBits[indexOfDnaBitsArr], indexOfFirstBit);
            placingValue0InBit(m_packedBits[indexOfDnaBitsArr],indexOfFirstBit+1);

            break;

        case 'T':
            placingValue1InBit(m_packedBits[indexOfDnaBitsArr], indexOfFirstBit);
            placingValue1InBit(m_packedBits[indexOfDnaBitsArr], indexOfFirstBit+1);
            break;

        default:
            throw std::invalid_argument("Function DnaSequence::setNucleotide ===> Unknown character:(");
    }
}


DnaSequence DnaSequence::slicing(size_t indexFrom, size_t indexTo) {
    if(indexTo>m_lenDnaBits/2+1 || indexFrom>indexTo)
        throw std::invalid_argument("Function DnaSequence::slicing ===> Index no match!!!");

    DnaSequence dna(DnaSequence(switchToGetChar(&(m_packedBits[indexFrom/4]),(indexTo - indexFrom)*2+1,indexFrom*2)));
    return dna;
}


char* DnaSequence::switchToGetChar(unsigned char* packedBitsArr, size_t lenDnaBits,int indexi) const {

    unsigned char* packedBits=packedBitsArr;
    char* packedSequence = new char[lenDnaBits/2+1];
    packedSequence[lenDnaBits/2]=NULL;
    packedSequence[lenDnaBits/2+1]='\0';
    int n = lenDnaBits;
    int indexDnaSequence=0;
    for(int i=indexi%8; i<n; i++)
    {
        if(i != 0 && i % 8 == 0)
            packedBits++;

        bool bit1 = *packedBits & (1 << (i)%8);
        bool bit2 = *packedBits & (1 << (i+1)%8);
        i++;
        char flag = (bit2 << 1) | bit1;

        switch(flag)
        {
            case 0:
                packedSequence[indexDnaSequence++] = 'A';
                break;
            case 1:
                packedSequence[indexDnaSequence++] = 'G';
                break;
            case 2:
                packedSequence[indexDnaSequence++] = 'C';
                break;
            case 3:
                packedSequence[indexDnaSequence++] = 'T';
                break;
        }
    }
    return packedSequence;
}


char* DnaSequence::returnDnaBits(unsigned char* packedBitsArr, size_t lenDnaBits) const {

    unsigned char* packedBits=packedBitsArr;
    char *DnaBits=new char[sizeof(unsigned char)*lenDnaBits/8];
    int n = lenDnaBits;

    for(int i=0; i<n; i++){
        if(i != 0 && i % 8 == 0)
            packedBits++;
        DnaBits[i]= operatorAndInBits(*packedBits,i%8);
    }
    return DnaBits;
}


size_t DnaSequence::find(const DnaSequence& dnaSubString , size_t indexFrom) {

    if(indexFrom>m_lenDnaBits/2)
        throw std::invalid_argument("Function DnaSequence::find ===> Index no match!!!");

    return std::string(getPackedSequence()).find(dnaSubString.getPackedSequence(),indexFrom);
}


std::vector<size_t> DnaSequence::findAll(const DnaSequence& dnaSubString, size_t indexFrom) {
    if(indexFrom>m_lenDnaBits/2)
        throw std::invalid_argument("Function DnaSequence::findAll ===> Index no match!!!");

    std::vector<size_t > vectorOfAllSubString;
    size_t i=find(dnaSubString);

    while (i!=-1) {
        vectorOfAllSubString.push_back(i);
        i = find(dnaSubString, i + 1);

    }
    return vectorOfAllSubString;
}


size_t DnaSequence::count(const DnaSequence& sub) {
    size_t i=find(sub);
    size_t count = 0;

    while (i!=-1) {
        i = find(sub, i + 1);
        count++;
    }
    return count;
}


DnaSequence& DnaSequence::pairing() {

    char *sequenceToPairing = getPackedSequence();
    size_t lenSequence = strlen(sequenceToPairing);
    char newSequenceToPairing[lenSequence];
    char nucleotide;
    int inewdna = lenSequence-1;
    newSequenceToPairing[lenSequence]=NULL;

    for(int idnaToPairing=0 ; idnaToPairing<lenSequence ; idnaToPairing++,inewdna--){
        nucleotide=sequenceToPairing[idnaToPairing];
        switch(nucleotide) {
            case 'A':
                newSequenceToPairing[inewdna]= 'T';
                break;

            case 'C':
                newSequenceToPairing[inewdna]= 'G';
                break;

            case 'G':
                newSequenceToPairing[inewdna]= 'C';
                break;

            case 'T':
                newSequenceToPairing[inewdna]= 'A';
                break;
        }
    }
    return *this;
}


void DnaSequence::findConsensus(std::vector<size_t>& start, std::vector<size_t>& end, std::vector<DnaSequence>& findConsensusSeq) {

    for (std::vector<size_t >::iterator itStart = start.begin(); itStart != start.end(); itStart++) {

        for (std::vector<size_t >::iterator itEnd = end.begin(); itEnd != end.end(); itEnd++) {
            if(((*itEnd-*itStart)%3 == 0) && (*itStart < *itEnd)){
                std::cout<<slicing(*itStart,(*itEnd+4));
                findConsensusSeq.push_back(slicing(*itStart,*itEnd+4));
            }
        }
    }
}


std::vector<DnaSequence> DnaSequence::findConsensusSequences() {

    std::vector<size_t> findAllAVG = findAll("ATG");
    std::vector<size_t> findAllTAG = findAll("TAG");
    std::vector<size_t> findAllTTA = findAll("TTA");
    std::vector<size_t> findAllTGA = findAll("TGA");

    std::vector<DnaSequence> findConsensusSeq;

    findConsensus(findAllAVG,findAllTAG,findConsensusSeq);
    findConsensus(findAllAVG,findAllTTA,findConsensusSeq);
    findConsensus(findAllAVG,findAllTGA,findConsensusSeq);

    return findConsensusSeq;
}


void DnaSequence::writeToFile(const char* fileName){
    std::ofstream outFile;
    outFile.open(fileName);

    if( !outFile ) {
        std::cout << "No File" << std::endl;
    }
    if(outFile.is_open()) {
        outFile << getPackedSequence();
        std::cout << "Succeeded!!!" << std::endl;
    }
    outFile.close();
}