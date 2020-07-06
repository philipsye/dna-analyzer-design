//
// Created by a on 7/5/20.
//
#include "iostream"
#include "CommandFactory.h"
#include "New.h"
#include "Load.h"

commands* CommandFactory::returnCommand(const std::string& c) {

    if(c == "new"){

        commands* command = new New ;

        return command;
    }


    if(c == "load"){
        commands* command = new Load ;
        return command;
    }

    else{
        std::cout<<"Error, command not found\n";
        return NULL;
    }

}