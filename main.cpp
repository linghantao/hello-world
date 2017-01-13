#include "dynArr.hpp"
#include "map.hpp"

int main() {
    //Seed the random number generator
    srand(time(NULL));
    //Declare and initialize a map object
    Map m;
    //Play the map
    m.playMap();

    return 0;
}
