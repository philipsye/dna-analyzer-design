
#include "fileReader.h"
#include "fstream"

fileReader::fileReader(const std::string& fName) {
    std::ifstream dnaFile;
    dnaFile.open(fName.c_str(),std::ios::in);

    if(dnaFile.is_open()){
        getline(dnaFile, m_dna);
        dnaFile.close();
    }

    else{
        std::cout << "File opening error. " << std::endl;
    }
}