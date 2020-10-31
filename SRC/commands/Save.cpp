#include "Save.h"
#include "../write/FileWriter.h"
#include <sstream>


bool Save::isValid(std::vector<std::string> input) {
    size_t sizeInput = input.size();
    KBoardWriter k;

    if(sizeInput>3 || sizeInput<2){
        k.write("    Invalid number of values\n"
                "    For a save command ,you must tap:\n"
                "        save <#id or @name>\n"
                "        or:\n"
                "        save <#id or @name> <file_name>\n");
        return false;
    }
    return true;
}


void Save::run(std::vector<std::string> input) {
    const char* temp = input[1].c_str();
    if(input[1][0]=='@'){
        if (input.size() < 3) {
            input.push_back(temp+1);
        }
        FileWriter f((input[2]+".rawdna").c_str());
        f.write(dnAlist.getSeqWithName(temp+1));
    }

    if(input[1][0]=='#'){
        size_t id = 0;
        std::istringstream ( temp + 1 ) >> id;

        if (input.size() < 3) {
            input.push_back(dnAlist.getNameById(id));
        }
        std::cout<<(input[2]+".rawdna") << std::endl;
        FileWriter f(((input[2]+".rawdna").c_str()));
        f.write(dnAlist.getSeqWithId(id));
    }
}