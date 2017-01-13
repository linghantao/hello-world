#ifndef DARKTILE_HPP
#define DARKTILE_HPP

#include "tile.hpp"

class DeathTile: public Tile {
public:
    DeathTile();

    int run(dynArr *playerInv);
    string getDescription();
    string getTileType();
private:

};

#endif
