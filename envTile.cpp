#include "envTile.hpp"

//Constructor
EnvTile::EnvTile() {
}

//Function to run the actions of the room
int EnvTile::run(dynArr *playerInv) {
    int choice, rmv;
    //Print out the description of the room
    cout << this->getDescription();
    cin >> choice;
    //If the user chooses to pick up a rock
    if (choice == 1) {
        //If the bag is full
        if (playerInv->getSize() >= 3) {
            cout << "\nYour bag is full! Please pick an item to remove.\n(1) " << playerInv->items[0] << "\n(2) " << playerInv->items[1] << "\n(3) " << playerInv->items[2] << "\n(4) Cancel\nEnter a number 1-4 and press [Enter]: ";
            cin >> rmv;
            if (rmv == 1) {
                playerInv->remove(playerInv->items[0]);
            } else if (rmv == 2) {
                playerInv->remove(playerInv->items[1]);
            } else if (rmv == 3) {
                playerInv->remove(playerInv->items[2]);
            } else if (rmv == 4) {
                
            }
        }
        //Add a rock to the bag
        playerInv->add("Rock");
        cout << endl;
    //If the user chooses to pick up a paper
    } else if (choice == 2) {
        //If the bag is full
        if (playerInv->getSize() >= 3) {
            cout << "\nYour bag is full! Please pick an item to remove.\n(1) " << playerInv->items[0] << "\n(2) " << playerInv->items[1] << "\n(3) " << playerInv->items[2] << "\n(4) Cancel\nEnter a number 1-4 and press [Enter]: ";
            cin >> rmv;
            if (rmv == 1) {
                playerInv->remove(playerInv->items[0]);
            } else if (rmv == 2) {
                playerInv->remove(playerInv->items[1]);
            } else if (rmv == 3) {
                playerInv->remove(playerInv->items[2]);
            } else if (rmv == 4) {
                
            }
        }
        //Add paper to the bag
        playerInv->add("Paper");
        cout << endl;
    //If the user chooses to pick up a scissors
    } else if (choice == 3) {
        //If the bag is full
        if (playerInv->getSize() >= 3) {
            cout << "\nYour bag is full! Please pick an item to remove.\n(1) " << playerInv->items[0] << "\n(2) " << playerInv->items[1] << "\n(3) " << playerInv->items[2] << "\n(4) Cancel\nEnter a number 1-4 and press [Enter]: ";
            cin >> rmv;
            if (rmv == 1) {
                playerInv->remove(playerInv->items[0]);
            } else if (rmv == 2) {
                playerInv->remove(playerInv->items[1]);
            } else if (rmv == 3) {
                playerInv->remove(playerInv->items[2]);
            } else if (rmv == 4) {
                
            }
        }
        //Add scissors to the bag
        playerInv->add("Scissors");
        cout << endl;
    } else if (choice == 4) {
        
    }
    return 1;
}

//Room description
string EnvTile::getDescription() {
    return "You have walked into a Supply Room. There are rocks, paper, and scissors littered on the ground. You can pick up any one of these items and add it to your bag. If your bag is full, you will have to drop another item before adding a new one. What do you want to do?\n\n(1) Pick up a rock.\n(2) Pick up a piece of paper.\n(3) Pick up a pair of scissors.\nEnter a number 1-3 and press [Enter]: ";
}

//Get the tile type
string EnvTile::getTileType() {
    return "environment";
}
