//
// Created by a on 7/5/20.
//

#include "Load.h"
#include "fileReader.h"

void Load::run(std::vector<std::string> input) {
    fileReader f(input[1]);
    std::string dna = f.read();
    size_t len = dna.length();
    if(len <= 40){
        input[1] = dna;
    }

    else{
        input[1] = "";
        for (short i=0 ; i<32 ; i++){
            input[1]+=dna[i];
        }
        input[1]+="...";
        input[1]+=dna[len-3];
        input[1]+=dna[len-2];
        input[1]+=dna[len-1];

    }

    DNA newDna(DnaSequence(input[1]), input[2], commands::returnId());
    dnAlist.addToList(newDna);

    dnAlist.printOneDna(dnAlist.sizeList());
}