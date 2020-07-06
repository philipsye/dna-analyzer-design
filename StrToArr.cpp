#include "StrToArr.h"
#include "iostream"
#include "vector"


std::vector<std::string> StrToArr::returnArr(std::string input) {

    std::vector<std::string> vecOfInput;
    std::string word = "";
    for (char i : input){
        if (i == ' ')
        {
            vecOfInput.push_back(word);
            word = "";
        }
        else
        {
            word = word + i;
        }
    }
    vecOfInput.push_back(word);
    return vecOfInput;
}