#ifndef PLAYERTILE_HPP
#define PLAYERTILE_HPP

#include "tile.hpp"

class PlayerTile: public Tile {
public:
    PlayerTile();

    int run(dynArr *playerInv);
    string getDescription();
    string getTileType();
    
    int defeated;
private:

};

#endif
