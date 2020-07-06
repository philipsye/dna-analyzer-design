#include <iostream>
#include "ApplicationManager.h"
#include "StrToArr.h"
#include "CommandFactory.h"




void ApplicationManager::runApplication() {


    while (true){
        std::string a;
        std::string s;

        std::cout << "> cmd >>> ";
        getline(std::cin, s);
        std::vector<std::string> v = StrToArr::returnArr(s);
        commands* command = CommandFactory::returnCommand(v[0]);
        command->run(v);
        break;
    }
}