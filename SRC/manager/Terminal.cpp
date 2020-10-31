#include "Terminal.h"
#include "../DNA/StrToArr.h"
#include "../commands/CommandFactory.h"
#include "../read/KBoardReader.h"
#include "../write/KBoardWriter.h"
#include "../DNA/DNAlist.h"
#include <iostream>


void Terminal::terminal() {
    KBoardWriter message;
    message.write("Enter execution orders for the DNA system\nTap quit to exit the application\n");

    while (true){
        KBoardWriter w;
        w.write("> cmd >>> ");
        KBoardReader k;

        if(k.read() == "quit"){
            break;
        }
        std::vector<std::string> v = StrToArr::returnArr(k.read());
        commands* command = CommandFactory::returnCommand(v[0]);
        if(command->isValid(v)){
            command->run(v);
        }
    }
}