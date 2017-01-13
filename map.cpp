#include "map.hpp"

Map::Map() { 
    //Place the different tiles in the map
    this->map_state[0][0] = new PlayerTile;
    this->map_state[0][1] = new EnvTile;
    this->map_state[0][2] = new PlayerTile;
    this->map_state[1][0] = new DeathTile;
    this->map_state[1][1] = new PlayerTile;
    this->map_state[1][2] = new EnvTile;
    this->map_state[2][0] = new EnvTile;
    this->map_state[2][1] = new EnvTile;
    this->map_state[2][2] = new EnvTile;

    //Set player starting location
    this->playerRow = 2;
    this->playerCol = 1;

    //Set adjacent rooms for 0, 0
    this->map_state[0][0]->above = NULL;
    this->map_state[0][0]->right = this->map_state[0][1];
    this->map_state[0][0]->below = this->map_state[1][0];
    this->map_state[0][0]->left = NULL;

    //Set adjacent rooms for 0, 1
    this->map_state[0][1]->above = NULL;
    this->map_state[0][1]->right = this->map_state[0][2];
    this->map_state[0][1]->below = this->map_state[1][1];
    this->map_state[0][1]->left = this->map_state[0][0];

    //Set adjacent rooms for 0, 2
    this->map_state[0][2]->above = NULL;
    this->map_state[0][2]->right = NULL;
    this->map_state[0][2]->below = this->map_state[1][2];
    this->map_state[0][2]->left = this->map_state[0][1];

    //Set adjacent rooms for 1, 0
    this->map_state[1][0]->above = this->map_state[0][0];
    this->map_state[1][0]->right = this->map_state[1][1];
    this->map_state[1][0]->below = this->map_state[2][0];
    this->map_state[1][0]->left = NULL;

    //Set adjacent rooms for 1, 1
    this->map_state[1][1]->above = this->map_state[0][1];
    this->map_state[1][1]->right = this->map_state[1][2];
    this->map_state[1][1]->below = this->map_state[2][1];
    this->map_state[1][1]->left = this->map_state[1][0];

    //Set adjacent rooms for 1, 2
    this->map_state[1][2]->above = this->map_state[0][2];
    this->map_state[1][2]->right = NULL;
    this->map_state[1][2]->below = this->map_state[2][2];
    this->map_state[1][2]->left = this->map_state[1][1];

    //Set adjacent rooms for 2, 0
    this->map_state[2][0]->above = this->map_state[1][0];
    this->map_state[2][0]->right = this->map_state[2][1];
    this->map_state[2][0]->below = NULL;
    this->map_state[2][0]->left = NULL;

    //Set adjacent rooms for 2, 1
    this->map_state[2][1]->above = this->map_state[1][1];
    this->map_state[2][1]->right = this->map_state[2][2];
    this->map_state[2][1]->below = NULL;
    this->map_state[2][1]->left = this->map_state[2][0];

    //Set adjacent rooms for 2, 2
    this->map_state[2][2]->above = this->map_state[1][2];
    this->map_state[2][2]->right = NULL;
    this->map_state[2][2]->below = NULL;
    this->map_state[2][2]->left = this->map_state[2][1];
    
    //Set the number of defeated bosses to 0
    this->defeatedBosses = 0;
}

//Function to run the program
void Map::playMap() {
    //Declare and initialize variables
    int counter = 0;
    int lose = 1;
    int choice, outcome;
    dynArr playerInv;
    //Setup the game
    cout << "\n****************************************************************************\nWelcome to the game of stones, cardboard, and cutters. You will explore different rooms of a 3x3 room house until all the intruders are defeated. But be careful! This is a fragile house that will collapse after you take 30 steps, so step carefully.\n\nYou see that you have a backpack on. You take it off and look inside. It's empty, but you see that it could hold about 3 items. In a side pocket, you find a map of the house, which you pull out and examine.\n";
    this->printMap();
    cout << "You notice that you are at the bottom center of the house (row 3, col 2). You look around and check your surroundings.\n\n";
    this->tileIsDiscovered(this->map_state[2][1]);
    this->map_state[this->playerRow][this->playerCol]->run(&playerInv);
    //Run the game for a max of 30 turns
    while (counter < 30) {
        //Allow user to choose what to do
        cout << "What would you like to do next?\n(1) View Map\n(2) Move to a different room\n(3) View bag contents\n(4) Leave the house\nEnter a number 1-4 and press [Enter]: ";
        cin >> choice;
        //View map
        if (choice == 1) {
            this->printMap();
        //Move to a different room
        } else if (choice == 2) {
            this->movePlayer();
            outcome = this->map_state[this->playerRow][this->playerCol]->run(&playerInv);
            //A boss was defeated this turn
            if (outcome == 16) {
                this->defeatedBosses++;
                cout << "There are " << 3 - this->defeatedBosses << " intruders remaining!\n\n";
                if (this->defeatedBosses == 3) {
                    cout << "\n**********WAY TO GO! YOU'VE DEFEATED ALL OF THE INTRUDERS AND WON THE GAME!**********\n\n";
                    counter = 30;
                    lose = 0;
                }

            }
            //Player loses due to death room
            if (outcome == 17) {
                lose = 2;
                counter = 30;
            }
        //View bag
        } else if (choice == 3) {
            cout << "\nBag Contents:\n";
            playerInv.dispItems();
            cout << endl;
        //Leave the game
        } else if (choice == 4) {
            string ans;
            cout << "\nAre you sure you want to leave(y/n)? ";
            cin >> ans;
            cout << endl;
            if (ans == "y") {
                counter = 30;
                lose = 3;
            }
        }
    }
    //If you lose due to turns running out
    if (lose == 1) {
        cout << "\n**********GAME OVER: YOU HAVE TAKEN TOO MANY STEPS. THE HOUSE COLLAPSED**********\n\n";
    }
    //If you lsoe due to the death room
    if (lose == 2) {
        cout << "\n**********GAME OVER: YOU HAVE FALLEN TO YOUR DEATH**********\n\n";
    }
    //If the user chooses to leave
    if (lose == 3) {
        cout << "\nThanks for trying the game! Play again another time!\n\n";
    }
}

//Function to print the map
void Map::printMap() {
    int i, j;
    cout << "\nMap\n";
    cout << "-------------\n";
    for (i = 0; i < 3; i++) {
        cout << "|";
        for (j = 0; j < 3; j++) {
            if (this->map_state[i][j]->discovered == 0) {
                cout << " ? ";
            } else if (this->map_state[i][j]->getTileType() == "player") {
                cout << " B ";
            } else if (this->map_state[i][j]->getTileType() == "environment") {
                cout << " S ";
            } else if (this->map_state[i][j]->getTileType() == "death") {
                cout << " X ";
            }
            cout << "|";
        }
        if (i == 0) {
            cout << "    You are in the room in Row " << this->playerRow+1 << " and Column " << this->playerCol+1;
        } else if (i == 1) {
            cout << "    B = Boss Room";
        } else if (i == 2) {
            cout << "    X = Death Room";
        }
        if (i == 0) {
            cout << "\n-------------\n";
        } else if (i == 1) {
            cout << "\n-------------    S = Supply Room\n";
        } else if (i == 2) {
            cout << "\n-------------    ? = Unexplored Room\n\n";
        }   
    }
}

//Function to set whether or not a tile has been discovered already
void Map::tileIsDiscovered(Tile *t) {
    t->discovered = 1;
}

//Function to move the player into a new room
void Map::movePlayer() {
    int count = 1;
    int above = 5, right = 5, below = 5, left = 5;
    int choice;
    cout << endl << "Which direction would you like to move?\n";
    //If statements check which adjacent rooms are accessible and provide them as options to user
    if (this->map_state[this->playerRow][this->playerCol]->above != NULL) {
        cout << "(" << count << ")" << " Move up\n";
        above = count;
        count++;
    }
    if (this->map_state[this->playerRow][this->playerCol]->right != NULL) {
        cout << "(" << count << ")" << " Move right\n";
        right = count;
        count++;
    }
    if (this->map_state[this->playerRow][this->playerCol]->below != NULL) {
        cout << "(" << count << ")" << " Move down\n";
        below = count;
        count++;
    }
    if (this->map_state[this->playerRow][this->playerCol]->left != NULL) {
        cout << "(" << count << ")" << " Move left\n";
        left = count;
        count++;
    }
    cout << "Enter a valid number and press [Enter]: ";
    cin >> choice;
    cout << endl;
    //Take the user's choice and move the player
    if (choice == above) {
        cout << "You walk into the room above you.\n\n";
        this->playerRow = this->playerRow - 1;
        this->tileIsDiscovered(this->map_state[this->playerRow][this->playerCol]);
    } else if (choice == right) {
        cout << "You walk into the room to your right.\n\n";
        this->playerCol = this->playerCol + 1;
        this->tileIsDiscovered(this->map_state[this->playerRow][this->playerCol]);
    } else if (choice == below) {
        cout << "You walk into the room below you.\n\n";
        this->playerRow = this->playerRow + 1;
        this->tileIsDiscovered(this->map_state[this->playerRow][this->playerCol]);
    } else if (choice == left) {
        cout << "You walk into the room to your left.\n\n";
        this->playerCol = this->playerCol - 1;
        this->tileIsDiscovered(this->map_state[this->playerRow][this->playerCol]);
    }
}
