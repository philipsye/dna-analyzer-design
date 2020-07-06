#include "createDNAseq.h"
#include <string>
#include <sstream>

size_t createDNAseq::m_numDefaultNane = 0;


std::string createDNAseq::getNum() {
    ++m_numDefaultNane;
    std::string sNum;
    std::ostringstream temp;
    temp << m_numDefaultNane;
    sNum = temp.str();
    return "seq"+sNum;
}
