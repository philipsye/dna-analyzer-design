#include "Load.h"
#include "fileReader.h"


void Load::run(std::vector<std::string> input) {

    fileReader f(input[1]);
    std::string dna = f.read();
    size_t len = dna.length();

    if (input.size() < 3) {

        if ( (dnAlist.existing(input[1]))) {
            input.push_back(createDNAseq::getNum());
        }

        else{
            input.push_back(input[1]);
        }
    }

    else{
        const char* temp = input[2].c_str();
        input[2] = temp+1;
    }
    DNA* newDn = new DNA(DnaSequence(dna), input[2], commands::returnId());
    dnAlist.addToList(newDn);
    print(newDn->getSeq().getPackedSequence(), input[2], newDn->getId(), len);
}


void Load::print(const std::string& seq, const std::string& name, size_t id, size_t len) {
    std::cout<<"["<<id<<"] ";
    std::cout<<name<<" ";

    std::string s = seq;

    if(len > 40){
        std::string dna2;
        for (short i=0 ; i<32 ; i++){
            dna2+=s[i];
        }
        dna2+="...";
        dna2+=s[len-3];
        dna2+=s[len-2];
        dna2+=s[len-1];
        s=dna2;
        std::cout<<s<<std::endl;
    }

    else{
        std::cout<<seq<<std::endl;
    }
}