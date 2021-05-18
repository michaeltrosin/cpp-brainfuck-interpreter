//
// Created by Michael on 13.05.2021.
//

#pragma once

#include <sstream>
#include <string>

class BrainfuckInterpreter {
public:
    explicit BrainfuckInterpreter(std::string src);
    ~BrainfuckInterpreter();

    void run();

private:
    void dump(size_t index);

    std::stringstream output_;

    int bracket_count_ = 0;
    int *brackets_;

    int *cells_;
    int *first_cell_;
    int *last_cell_;

    std::string src_;
    void print_current_cell();
};
