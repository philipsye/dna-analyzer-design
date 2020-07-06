#include "Load.h"
#include "fileReader.h"


void Load::run(std::vector<std::string> input) {
    std::cout<<"1\n";
    fileReader f(input[1]);
    std::cout<<"2\n";
    std::string dna = f.read();
    std::cout<<"3\n";
    size_t len = dna.length();
    std::cout<<"4\n";
    if(len > 40){
        std::string dna2;
        dna2="";
        for (short i=0 ; i<32 ; i++){
            dna2+=dna[i];
        }
        /*dna2+="...";*/
        dna2+=dna[len-3];
        dna2+=dna[len-2];
        dna2+=dna[len-1];
        dna=dna2;
    }
    DNA* newDn = new DNA(DnaSequence(dna), input[1], commands::returnId());
    newDn->getId();
    dnAlist.addToList(newDn);
    dnAlist.printSingleDna(dnAlist.sizeList());
}