#ifndef CHIP_H
#define CHIP_H

#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

const int RED_TOTAL = 328, GOLD_TOTAL = 284;
const int TOTAL_SPACES = 42;
const int ROWS = 6, COLUMNS = 7;
const char BLANK = 'X', RED = 'R', GOLD = 'G';

class Chip {
   private:
    char color;

   public:
    Chip() {
        color = BLANK;
    }
    Chip(char color) {
        this->color = color;
    }
    void setColor(char color) {
        this->color = color;
    }
    int getColor() const {
        return color;
    }
    string toString() {
        stringstream stream;
        stream << color;

        string returnStr = stream.str();

        return returnStr;
    }
};

#endif