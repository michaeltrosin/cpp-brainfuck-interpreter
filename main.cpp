//
// Created by Michael on 11.05.2021.
//

#include "BrainfuckInterpreter.h"
#include <fstream>
#include <iostream>
#include <streambuf>
#include <string>

int main(int argc, char** argv){
    std::ifstream t("../test.bf");
    std::string str;

    t.seekg(0, std::ios::end);
    str.reserve(t.tellg());
    t.seekg(0, std::ios::beg);

    str.assign((std::istreambuf_iterator<char>(t)),
               std::istreambuf_iterator<char>());

    BrainfuckInterpreter interpreter(str);
    interpreter.run();

    return 0;
}