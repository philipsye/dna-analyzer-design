#include "Save.h"
#include "FileWriter.h"
#include <sstream>

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
        std::cout<<(input[2]+".rawdna");
        FileWriter f(((input[2]+".rawdna").c_str()));
        f.write(dnAlist.getSeqWithId(id));
    }
}