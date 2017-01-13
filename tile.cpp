#include "tile.hpp"

//Constructor
Tile::Tile() {
    this->discovered = 0;
}

//Abstract run function
int Tile::run(dynArr *playerInv) {
    cout << "Can't run, uninitialized tile.\n";
    return 0;
}

//Abstract getDescription function
string Tile::getDescription() {
    return "This is an uninitialized tile.";
}

//Abstract getTileType function
string Tile::getTileType() {
    return "Uninitialized tile.";
}
