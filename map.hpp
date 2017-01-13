#ifndef MAP_HPP
#define MAP_HPP

#include "tile.hpp"
#include "playerTile.hpp"
#include "envTile.hpp"
#include "deathTile.hpp"
#include <string>
using std::string;
#include <iostream>
using std::cout;
using std::endl;

class Map {
public:
    Map();

    void playMap();
    void printMap();
    int *startLocs(int num);
    int playerRow;
    int playerCol;
    int defeatedBosses;
private:
    //2D array of the states of the map
    Tile *map_state[3][3];
    void tileIsDiscovered(Tile *t);
    void movePlayer();

};

#endif
/*
-------------
| P | E | P |
-------------
| X | P | E |
-------------
| E | E | E |
-------------*/
