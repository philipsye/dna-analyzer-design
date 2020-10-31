#include <fstream>
#include "FileWriter.h"


FileWriter::FileWriter(const char* name) : m_fileName(name) {std::cout<<"****"<<m_fileName<<"****\n";}

void FileWriter::write(std::string seq) {
    std::cout<<"----"<<m_fileName<<"----\n";
    std::ofstream outFile;
    outFile.open(m_fileName.c_str());

    if( !outFile ) {
        std::cout << "No File" << std::endl;
    }

    if(outFile.is_open()) {
        outFile << seq;
        std::cout << "Succeeded!!!" << std::endl;
    }
    outFile.close();
}
