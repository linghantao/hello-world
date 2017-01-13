#include "playerTile.hpp"

//Constructor
PlayerTile::PlayerTile() {
    this->defeated = 0;
}

//Function to run the actions of the room
int PlayerTile::run(dynArr *playerInv) {
    //Check if the boss has already been defeated
    if (this->defeated) {
        cout << "You have walked into a Boss Room. However, it's empty, and you have a vague memory of scaring someone away from here\n\n";
    } else {
    //Initialize and declare variables
    int choice, rdm;
    //Determine what object the intruder will throw
    rdm = rand()%3;
    string pick[3] = {"a rock", "a piece of paper", "a pair of scissors"};
    cout << this->getDescription() << endl;
    cout << "The mean looking man threw " << pick[rdm] << " at you!\nYou have to make a decision QUICKLY. Use an item from your bag!\n";
    //If the user has no items in their bag...
    if (playerInv->getSize() == 0) {
        cout << "\nYou don't have any items in your bag! The mean looking man threw " << pick[rdm] << " at you and is forcing you to run!\n\n";
    //If there are objects in the bag
    } else {
        //Let user choose which object they want to use
        playerInv->dispItems();
        cout << "Enter a valid number and press [Enter]: ";
        cin >> choice;
        choice = choice-1;
        //Based on which object was chosen and which object was thrown by the intruder, determine if the user wins or loses
        if (pick[rdm] == "a rock") {
            if (playerInv->items[choice] == "Rock") {
                cout << "\nYou threw " << pick[0] << " back at him! The two rocks collide and nothing happens.\n\n";
                playerInv->remove("Rock");
                //User picks direction to go
                return 60;
            } else if (playerInv->items[choice] == "Paper") {
                cout << "\nYou threw " << pick[1] << " back at him! You covered his rock and he runs away defeated!\n\n";
                playerInv->remove("Paper");
                //Boss is defeated
                this->defeated = 1;
                return 16;
            } else if (playerInv->items[choice] == "Scissors") {
                cout << "\nYou threw " << pick[2] << " back at him! His rock broke your scissors and now you're wondering what to do.\n\n";
                playerInv->remove("Scissors");
                //User picks direction to go
                return 60;
            }
        } else if (pick[rdm] == "a piece of paper") {
            if (playerInv->items[choice] == "Rock") {
                cout << "\nYou threw " << pick[0] << " back at him! His paper covers your rock and now you're wondering what to do.\n\n";
                playerInv->remove("Rock");
                //User picks direction to go
                return 60;
            } else if (playerInv->items[choice] == "Paper") {
                cout << "\nYou threw " << pick[1] << " back at him! The two pieces of paper gently float to the ground and nothing happens.\n\n";
                playerInv->remove("Paper");
                //User picks direction to go
                return 60;
            } else if (playerInv->items[choice] == "Scissors") {
                cout << "\nYou threw " << pick[2] << " back at him! The scissors cut up the paper and he runs away defeated!\n\n";
                playerInv->remove("Scissors");
                //Boss is defeated
                this->defeated = 1;
                return 16;
            }
        } else if (pick[rdm] == "a pair of scissors") {
            if (playerInv->items[choice] == "Rock") {
                cout << "\nYou threw " << pick[0] << " back at him! The rock crushes the scissors and he runs away defeated!\n\n";
                playerInv->remove("Rock");
                //Boss is defeated
                this->defeated = 1;
                return 16;
            } else if (playerInv->items[choice] == "Paper") {
                cout << "\nYou threw " << pick[1] << " back at him! His scissors cut up your paper and now you're wondering what to do.\n\n";
                playerInv->remove("Paper");
                //User picks direction to go
                return 60;
            } else if (playerInv->items[choice] == "Scissors") {
                cout << "\nYou threw " << pick[2] << " back at him! The two scissors clash in midair, fall to the ground, and nothing happens.\n\n";
                playerInv->remove("Scissors");
                //User picks direction to go
                return 60;
            }
        }
    }
    }
    return 0;
}

//Get the description for the room
string PlayerTile::getDescription() {
    return "You have walked into a Boss Room. There is a mean looking man glaring at you.";
}

//Get the tile type
string PlayerTile::getTileType() {
    return "player";
}
