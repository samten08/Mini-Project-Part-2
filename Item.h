#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
public:
    char id;
    std::string name;

    Item(char letter) {
        id = letter;
        name = getNameFromId(letter);
    }

    static std::string getNameFromId(char letter) {
        if (letter == 'k') return "key";
        if (letter == 'c') return "coin";
        if (letter == 'g') return "gem";
        if (letter == 'p') return "potion";
        return "thing";
    }
};

#endif
