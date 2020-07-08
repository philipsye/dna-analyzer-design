#include "Dup.h"
#include <sstream>


void Dup::run(std::vector<std::string> input) {
    const char* temp = input[1].c_str();
    std::string name;
    size_t id = 0;

    if (input.size() < 3) {
        if(input[1][0]=='#'){
            std::istringstream ( temp + 1 ) >> id;
            name = dnAlist.getNameById(id);
        }

        else{
            name = temp+1;
        }
        size_t num=0;
        std::string sNum;

        while (dnAlist.existing(name+sNum)){
            ++num;
            std::ostringstream tempNum;
            tempNum << num;
            sNum = "_"+tempNum.str();
        }
        input.push_back("@"+name+sNum);
    }
    const char* temp2 = input[2].c_str();

    if(input[1][0]=='@'){
        DNA* newDn = new DNA(DnaSequence(dnAlist.getSeqWithName(temp+1)), temp2+1, commands::returnId());
        dnAlist.addToList(newDn);
    }

    if(input[1][0]=='#'){
        DNA* newDn = new DNA(DnaSequence(dnAlist.getSeqWithId(id)), temp2+1, commands::returnId());
        dnAlist.addToList(newDn);
    }
    dnAlist.printSingleDna(dnAlist.sizeList());
}