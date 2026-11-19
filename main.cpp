#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Item.h"
#include "Player.h"
#include "Room.h"
using namespace std;

int main() {
    srand(time(0));

    int rows;
    cout << "How many rows? ";
    cin >> rows;

    int cols;
    cout << "How many cols? ";
    cin >> cols;

    Player player;
    Room room(rows, cols, &player);

    Item key('k');
    Item coin('c');
    Item gem('g');
    room.placeItem(&key);
    room.placeItem(&coin);
    room.placeItem(&gem);

    room.draw();
    player.inventory.print();

    char input;
    cin >> input;
    while (input != 'q') {
        player.move(input, room);
        room.draw();
        player.inventory.print();
        cin >> input;
    }

    return 0;
}
