#ifndef PLAYER_H
#define PLAYER_H

#include "BoardGame.h"
#include "Chip.h"

class Player {
   private:
    string name;
    char color;

   public:
    Player() {
        name = "Nguoi choi X";
        color = RED;
    }

    string getName() const {
        return this->name;
    }
    char getColor() const {
        return this->color;
    }

    void setName(string input) {
        this->name = input;
    }
    void setColor(char input) {
        this->color = input;
    }

    // Return name and color of the player in string
    string toString() {
        string res;
        res = name + " (" + color + ") ";

        return res;
    }
};

#endif