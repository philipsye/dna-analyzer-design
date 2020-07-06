  //
// Created by a on 7/5/20.
//

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

    std::cout<<"5\n";
std::cout<<dna<<"\n";
    std::cout<<"6\n";
    DNA* newDn = new DNA(DnaSequence(dna), input[1], commands::returnId());
    std::cout<<"7\n";


    newDn->getId();
    dnAlist.addToList(newDn);
    std::cout<<"8\n";
    dnAlist.printSingleDna(dnAlist.sizeList());
}