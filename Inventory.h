#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include "Item.h"

class Inventory {
public:
    Item** items;
    int count;
    int capacity;

    Inventory() {
        capacity = 2;
        count = 0;
        items = new Item*[capacity];
    }

    Inventory(const Inventory&) = delete;
    Inventory& operator=(const Inventory&) = delete;

    ~Inventory() {
        for (int i = 0; i < count; i++) {
            delete items[i];
        }
        delete[] items;
    }

    void add(Item* item) {
        if (count == capacity) {
            Item** bigger = new Item*[capacity * 2];
            for (int i = 0; i < count; i++) {
                bigger[i] = items[i];
            }
            delete[] items;
            items = bigger;
            capacity = capacity * 2;
        }
        items[count] = item;
        count = count + 1;
    }

    bool hasItem(char id) {
        for (int i = 0; i < count; i++) {
            if (items[i]->id == id) {
                return true;
            }
        }
        return false;
    }

    void removeItem(char id) {
        for (int i = 0; i < count; i++) {
            if (items[i]->id == id) {
                delete items[i];
                for (int j = i; j < count - 1; j++) {
                    items[j] = items[j + 1];
                }
                count = count - 1;
                return;
            }
        }
    }

    void print() {
        std::cout << "Carrying:";
        if (count == 0) {
            std::cout << " nothing";
        }
        for (int i = 0; i < count; i++) {
            std::cout << " " << items[i]->name;
        }
        std::cout << std::endl;
    }
};

#endif
