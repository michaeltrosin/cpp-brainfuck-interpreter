//
// Created by Michael on 11.05.2021.
//

#pragma once

#include <string>

class BrainfuckInterpreter {
public:
    explicit BrainfuckInterpreter(std::string  source);
    ~BrainfuckInterpreter();

    void run();
private:
    void print_current_cell();

    std::string source_;

    int* brackets_;
    int bracket_indention_ = 0;

    int cell_ptr_ = 0;
    char *cells_;
};
