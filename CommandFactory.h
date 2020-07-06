#ifndef DNA_SEQUENCE_COMMANDFACTORY_H
#define DNA_SEQUENCE_COMMANDFACTORY_H

#include "New.h"



class CommandFactory {

public:
    static commands* returnCommand(const std::string& command);
};


#endif //DNA_SEQUENCE_COMMANDFACTORY_H
