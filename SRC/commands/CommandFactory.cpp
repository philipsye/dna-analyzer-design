#include "iostream"
#include "CommandFactory.h"
#include "New.h"
#include "Load.h"
#include "Save.h"
#include "Dup.h"


commands* CommandFactory::returnCommand(const std::string& c) {

    if(c == "new"){
        commands* command = new New ;
        return command;
    }

    if(c == "load"){
        commands* command = new Load ;
        return command;
    }

    if(c == "save"){
        commands* command = new Save;
        return command;
    }

    if(c == "dup"){
        commands* command = new Dup;
        return command;
    }

    else{
        std::cout<<"Error, command not found\n";
        return NULL;
    }
}