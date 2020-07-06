#include <iostream>
#include "ApplicationManager.h"
#include "StrToArr.h"
#include "CommandFactory.h"


void ApplicationManager::runApplication() {

    std::cout<<"Enter execution orders for the DNA system\n"
               "Tap quit to exit the application";
    while (true){
        std::string s;
        std::cout << "> cmd >>> ";
        getline(std::cin, s);

        if(s == "quit"){
            break;
        }
        std::vector<std::string> v = StrToArr::returnArr(s);
        commands* command = CommandFactory::returnCommand(v[0]);
        command->run(v);
    }
}