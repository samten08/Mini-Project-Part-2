#ifndef PLAYER_H
#define PLAYER_H

#include "Inventory.h"

class Room;

class Player {
public:
    int row;
    int col;
    Inventory inventory;

    Player() {
        row = 1;
        col = 1;
    }

    void move(char key, Room& room);   // body is at the bottom of Room.h
};

#endif
