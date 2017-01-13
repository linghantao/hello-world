#ifndef ENVTILE_HPP
#define ENVTILE_HPP

#include "tile.hpp"

class EnvTile: public Tile {
public:
    EnvTile();

    int run(dynArr *playerInv);
    string getDescription();
    string getTileType();
private:

};

#endif
