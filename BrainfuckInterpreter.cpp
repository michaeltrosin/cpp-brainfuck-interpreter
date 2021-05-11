//
// Created by Michael on 11.05.2021.
//

#include "BrainfuckInterpreter.h"

#include <cstdio>
#include <utility>

#define THRESHOLD 30000

BrainfuckInterpreter::BrainfuckInterpreter(std::string source) : source_(std::move(source)) {
    cells_ = new char[THRESHOLD]{0};
    brackets_ = new int[THRESHOLD]{-1};
}

BrainfuckInterpreter::~BrainfuckInterpreter() {
    delete[] cells_;
    delete[] brackets_;
}

void BrainfuckInterpreter::run() {
    for (int i = 0; i < source_.length(); i++) {
        char c = source_[i];

        switch (c) {
            case '+': cells_[cell_ptr_]++; break;
            case '-': cells_[cell_ptr_]--; break;
            case '>':
                cell_ptr_++;
                if (cell_ptr_ > THRESHOLD) cell_ptr_ = THRESHOLD;
                break;
            case '<':
                cell_ptr_--;
                if (cell_ptr_ < 0) cell_ptr_ = 0;
                break;
            case '[': {
                bracket_indention_++;
                brackets_[cell_ptr_] = i;
                break;
            }
            case ']':
                if (cells_[cell_ptr_] == 0) {
                    bracket_indention_--;
                    break;
                } else {
                    i = brackets_[cell_ptr_];
                    break;
                }
            case '.': print_current_cell(); break;
            default: break;
        }
    }
}

void BrainfuckInterpreter::print_current_cell() { std::printf("%c", cells_[cell_ptr_]); }
