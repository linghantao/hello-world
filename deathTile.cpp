#include "deathTile.hpp"

//Constructor
DeathTile::DeathTile() {
}

//Function to run the actions that happen in the room
int DeathTile::run(dynArr *playerInv) {
    int guess, actual;
    //Print out description
    cout << this->getDescription();
    cin >> guess;
    actual = rand() % 10 + 1;
    cout << "\nMy number is " << actual << ".\n";
    //If you guess correctly, survive and continue
    if (guess == actual) {
        cout << "\nWOW! You managed to keep your footing and live another step.\n";
        return 1;
    //Signal game over
    } else {
        return 17;
    }
}

//Function to get description of room
string DeathTile::getDescription() {
    return "You have walked into the Death Room. You will lose your footing and fall to your death unless you can guess my number between 1-10. Pick a number and I'll tell you mine.\n\nEnter a number 1-10 and press [Enter]: ";
}

//Function to get the type of tile
string DeathTile::getTileType() {
    return "death";
}
