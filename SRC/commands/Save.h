//
// Created by a on 7/7/20.
//

#ifndef DNA_SEQUENCE_SAVE_H
#define DNA_SEQUENCE_SAVE_H

#include "../manager/SeqManagement.h"


class Save : public SeqManagement {
public:
    bool isValid(std::vector<std::string> input);
    void run(std::vector<std::string>);
};


#endif //DNA_SEQUENCE_SAVE_H
