#include <iostream>
#include "ApplicationManager.h"
#include "StrToArr.h"
#include "CommandFactory.h"




void ApplicationManager::runApplication() {

    std::string a;
    while (a!="1"){
        std::cout<<">cmd>>> ";
        std::getline(std::cin, a);
        std::vector<std::string> v = StrToArr::returnArr(a);
        commands* command = CommandFactory::returnCommand(v[0]);
        command->run(v);
    }
}