#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <cstdlib>
#include "Item.h"
#include "Player.h"

class Room {
public:
    int rows;
    int cols;
    char** grid;
    Player* player;

    Room(int r, int c, Player* p) {
        rows = r;
        cols = c;
        player = p;
        grid = new char*[rows];
        for (int i = 0; i < rows; i++) {
            grid[i] = new char[cols];
            for (int j = 0; j < cols; j++) {
                if (i == 0 || j == 0 || i == rows - 1 || j == cols - 1 || rand() % 5 == 0) {
                    grid[i][j] = '#';
                } else {
                    grid[i][j] = ' ';
                }
            }
        }
        grid[1][1] = ' ';
    }

    ~Room() {
        for (int i = 0; i < rows; i++) {
            delete[] grid[i];
        }
        delete[] grid;
    }

    bool isWall(int r, int c) {
        return grid[r][c] == '#';
    }

    void placeItem(Item* item) {
        int r = rand() % rows;
        int c = rand() % cols;
        while (grid[r][c] != ' ' || (r == player->row && c == player->col)) {
            r = rand() % rows;
            c = rand() % cols;
        }
        grid[r][c] = item->id;
    }

    char takeItem(int r, int c) {
        if (grid[r][c] == '#' || grid[r][c] == ' ') {
            return 0;
        }
        char letter = grid[r][c];
        grid[r][c] = ' ';
        return letter;
    }

    void draw() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (i == player->row && j == player->col) {
                    std::cout << "@";
                } else {
                    std::cout << grid[i][j];
                }
            }
            std::cout << std::endl;
        }
    }
};

inline void Player::move(char key, Room& room) {
    int newRow = row;
    int newCol = col;

    if (key == 'w') newRow = row - 1;
    if (key == 's') newRow = row + 1;
    if (key == 'a') newCol = col - 1;
    if (key == 'd') newCol = col + 1;

    if (!room.isWall(newRow, newCol)) {
        row = newRow;
        col = newCol;
        char letter = room.takeItem(row, col);
        if (letter != 0) {
            inventory.add(new Item(letter));
        }
    }
}

#endif
