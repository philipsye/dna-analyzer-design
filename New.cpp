#include "New.h"
#include "DNA.h"


void New::run(std::vector<std::string> input) {


    if (input.size() < 3) {
        input.push_back(createDNAseq::getNum());
    }

    else{
        const char* temp = input[2].c_str();
        input[2] = temp+1;
    }

    DNA* newDn = new DNA(DnaSequence(input[1]), input[2], commands::returnId());
    dnAlist.addToList(newDn);

    dnAlist.printSingleDna(dnAlist.sizeList());
}


