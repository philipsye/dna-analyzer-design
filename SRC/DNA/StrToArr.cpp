#include "StrToArr.h"
#include "iostream"
#include "vector"


std::vector<std::string> StrToArr::returnArr(const std::string& input) {

    std::vector<std::string> vecOfInput;
    std::string word;

    for (size_t i=0 ; i< input.length() ; ++i){

        if (input[i] == ' '){
            vecOfInput.push_back(word);
            word = "";
        }
        else{
            word += input[i];
        }
    }
    vecOfInput.push_back(word);
    return vecOfInput;
}