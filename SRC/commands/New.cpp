#include "New.h"
#include "../DNA/DNA.h"



bool New::isValid(std::vector<std::string> input) {
    size_t sizeInput = input.size();
    KBoardWriter k;

    if(sizeInput>3 || sizeInput<2){
        k.write("    Invalid number of values\n"
                "    For a new command ,you must tap:\n"
                "        new <#id or @name>\n"
                "        or:\n"
                "        new <#id or @name> @<sequence_name>\n");
        return false;
    }

    if(!New::isValidDna(input[1])){
        std::cout<<"The DNA you entered is incorrect.\n";
        return false;
    }
    else{
        return true;
    }
}


void New::run(std::vector<std::string> input) {
    if (input.size() < 3) {
        std::string name = createDNAseq::getNum();

        while(dnAlist.existing(name)){
            name = createDNAseq::getNum();
        }
        input.push_back(name);
    }

    else{
        const char* temp = input[2].c_str();

        while(dnAlist.existing(temp+1)){
            KBoardWriter k;
            k.write("The name you entered is already in the system,\n"
                    " please enter a different name: ");
            KBoardReader readName;
            input[2] = readName.read();
            temp = input[2].c_str();

        }

        while (input[2][0] != '@'){
            KBoardWriter k;
            k.write("Invalid argument, Before you type a sequence name, you must type @\n"
                    " please enter a different name: ");
            KBoardReader readName;
            input[2] = readName.read();
        }
        input[2] = temp+1;
    }
    DNA* newDn = new DNA(DnaSequence(input[1]), input[2], commands::returnId());
    dnAlist.addToList(newDn);
    dnAlist.printSingleDna(dnAlist.sizeList());
}


bool New::isValidDna(const std::string& dna) {

    for(size_t i=0 ; i<dna.size() ; ++i){
        char letter = dna[i];
        if(letter!='A' && letter!='C' && letter!='G' &&letter!='T'){
            return false;
        }
    }
    return true;
}