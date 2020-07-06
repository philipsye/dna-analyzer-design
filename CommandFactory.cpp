//
// Created by a on 7/5/20.
//
#include "iostream"
#include "CommandFactory.h"
#include "New.h"
#include "Load.h"

commands* CommandFactory::returnCommand(const std::string& command) {

    if(command == "new"){
        commands* command = new New ;
        return command;
    }


    if(command == "load"){
        commands* command = new Load ;
        return command;
    }

    else{
        std::cout<<"Error, command not found\n";
        return NULL;
    }

}