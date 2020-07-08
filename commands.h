#ifndef DNA_SEQUENCE_COMMANDS_H
#define DNA_SEQUENCE_COMMANDS_H
#include "iostream"
#include <vector>
#include "ApplicationManager.h"
#include "DNAlist.h"
#include "KBoardWriter.h"
#include "KBoardReader.h"


class commands {

public:
    virtual void run(std::vector<std::string>)=0;
    virtual bool isValid(std::vector<std::string> input)=0;
    static size_t returnId(){return ++m_id;}

protected:
    static DNAlist dnAlist;

private:
    static size_t m_id;
};


#endif //DNA_SEQUENCE_COMMANDS_H