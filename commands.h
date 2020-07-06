#ifndef DNA_SEQUENCE_COMMANDS_H
#define DNA_SEQUENCE_COMMANDS_H

#include "iostream"
#include <vector>
#include "ApplicationManager.h"


class commands {

public:
    virtual void
    run(std::vector<std::string>)=0;
    static size_t returnId();

protected:
    static DNAlist dnAlist;

private:
    static size_t m_id;
};


#endif //DNA_SEQUENCE_COMMANDS_H
