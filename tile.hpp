#ifndef TILE_HPP
#define TILE_HPP

#include <string>
using std::string;
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <stdlib.h>
#include <time.h>
#include "dynArr.hpp"

class Tile {
public:
    Tile();
    //Run the tile
    virtual int run(dynArr *playerInv);
    virtual string getDescription();
    virtual string getTileType();
    //void tileIsDiscovered();

    int discovered;
    Tile *above;
    Tile *right;
    Tile *below;
    Tile *left;
private:
};

#endif
