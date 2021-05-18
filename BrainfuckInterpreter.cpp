//
// Created by Michael on 13.05.2021.
//

#include "BrainfuckInterpreter.h"

#include <iostream>
#include <utility>

#define print(str) std::cout << str << "\n"

#define THRESHOLD 30000
#define SIZE      255

BrainfuckInterpreter::BrainfuckInterpreter(std::string src) : src_(std::move(src)) {
    cells_ = new int[THRESHOLD]{0};
    first_cell_ = cells_;
    last_cell_ = (cells_ + THRESHOLD);

    brackets_ = new int[THRESHOLD]{0};
}

BrainfuckInterpreter::~BrainfuckInterpreter() {
    delete[] cells_;
    delete[] brackets_;

    //std::cout << "Output: "
    //          << "\n"
    //          << output_.str() << std::endl;
}

void BrainfuckInterpreter::run() {
    for (size_t i = 0; i < src_.length(); i++) {
        //
        char current = src_[i];
        switch (current) {
            case '+':
                (*cells_)++;
                if (*cells_ > SIZE) *cells_ = 0;
                break;
            case '-':
                (*cells_)--;
                if (*cells_ < 0) *cells_ = SIZE;
                break;
            case '.': print_current_cell(); break;
            case '>':
                cells_++;
                if (cells_ > last_cell_) cells_ = first_cell_;
                break;
            case '<':
                cells_--;
                if (cells_ < first_cell_) cells_ = last_cell_;
                break;
            case '[':
                //
                if ((*cells_) == 0) {
                    int diff = 1;
                    i++;

                    while (diff != 0) {
                        current = src_[i];
                        i++;

                        if (current == '[') {
                            diff++;
                        } else if (current == ']') {
                            diff--;
                        }
                    }
                    i--;
                    break;
                }

                bracket_count_++;
                brackets_[bracket_count_] = (int) i;
                break;
            case ']':
                if ((*cells_) == 0) {
                    //
                    bracket_count_--;
                    break;
                }
                //print(i << " : " << src_[i] << " : " << *cells_);
                i = brackets_[bracket_count_];
                break;
            default: break;
        }
        //        dump(i);
    }

    //print(bracket_count_);
}

void BrainfuckInterpreter::dump(size_t index) { std::cout << std::string(src_).replace(index, 1, {'(', src_[index], ')'}) << std::endl; }
void BrainfuckInterpreter::print_current_cell() {
    std::cout << (char) (*cells_);
    //    output_ << (char) (*cells_);
}
