#include <fstream>
#include <iostream>
#include <string>
using namespace std;

// Constants
const string
    // Towns
    HOMETOWN = "Hometown",
    GREENTOWN = "Greentown",
    BLUETOWN = "Bluetown",
    PURPLETOWN = "Purpletown",
    // Head gear
    LIGHTHELM = "light helmet",
    MEDHELM = "medium helmet",
    HEAVYHELM = "heavy helmet",
    // Body gear
    GAMBESON = "gambeson",
    CUIRASS = "cuirass",
    IRONPLATE = "iron platebody",
    // Weapons
    DAGGER = "dagger",
    SWORD = "sword",
    LONG_SWORD = "long_sword",
    EXCALIBUR = "Excalibur";

// Structures
struct Character {

    string
        name,       // Character name, input by player
        lvl,        // Character level, tracked by exp
        exp,        // Character experience, gained from killing monsters
        head,       // Character head gear, bought from store, found on monsters
        body,       // Character body gear, bought from store, found on monsters
        weapon,     // Character weapon, bought from store, found on monsters
        save_place; // Town location where player saves
};

// Function declarations
Character CreateCharacter();

void Play(Character&);

int main()
{
    // Variables
    ifstream load;   // ifstream object to load player data
    ofstream player_file; // ofstream object to write all player data, populated with
                     // option 1. New Game

    Character playerCharacter;  // Player character struct

    load.open("player_data.txt");
    player_file.open("player_data.txt");

    bool
        running = true; // running variable for game loop, programmed

    int
        choice;      // menu choice, input by the player

    // Game loop

    cout << "Welcome to the RPG\n";
    cout << R"(
         ____  ____   ____
        |  _ \|  _ \ / ___|
        | |_) | |_) | |  _
        |  _ <|  __/| |_| |
        |_| \_\_|    \____|
        )" << endl << endl;

    cout << "Choose your option" << endl;
        cout << "1. New Game" << endl;
        cout << "2. Load Game" << endl;
        cout << "3. Quit Game" << endl;
        cout << ":";

        cin >> choice;

    while (running) {

        switch (choice) {
            case 1: {
                cout << "Welcome, player..." << endl;
                playerCharacter = CreateCharacter();
                break;
                }
           case 2: {
                cout << "Welcome back..." << endl;
                Play(playerCharacter);
                break;
                }
            case 3: {
                cout << "Thanks for playing!" << endl;
                running = false;
                break;
                }
        }
    }

    return 0;
}

Character CreateCharacter() {

    Character playerCharacter;

    cout << "\tWhat is your name, adventurer?" << endl;

    while (!(cin >> playerCharacter.name)) {
        getline(cin, playerCharacter.name);
    }

    cout << "\tWell met " << playerCharacter.name << endl << endl;
    cout << "\tWelcome to the" << endl;

    cout << R"(
     ____  ____   ____
    |  _ \|  _ \ / ___|
    | |_) | |_) | |  _
    |  _ <|  __/| |_| |
    |_| \_\_|    \____|
    )" << endl << endl;


    return playerCharacter;
}

void Play(Character& playerCharacter) {

    bool running = true;

    int choice = 0;

    string yes_no;

    while (running) {
        // Start new
    if (playerCharacter.save_place == "") {
        cout << "You begin your adventure in your hometown of ";
        cout << HOMETOWN << endl << endl;
        playerCharacter.save_place = HOMETOWN;
    // Start in Hometown
    } else if (playerCharacter.save_place == HOMETOWN) {
        cout << "\tYou wake up in your bed..." << endl << endl;
    // Start in Greentown
    } else if (playerCharacter.save_place == GREENTOWN) {
        cout << "\tYou wake up in an earthen room..." << endl << endl;
    // Start in Bluetown
    } else if (playerCharacter.save_place == BLUETOWN) {
        cout << "\tYou wake up in an oceanside room..." << endl << endl;
    // Start in Purpletown
    } else if (playerCharacter.save_place == PURPLETOWN) {
        cout << "\tYou wake up in a darkened room..." << endl << endl;
    }

        while (running) {
            cout << "\tWhat would you like to do next?" << endl;
            cout << "1. Shop" << endl ;
            cout << "2. Explore" << endl;
            cout << "3. Save and Quit" << endl << endl;

            while (!(cin >> choice)) {
                    cin >> choice;
                }
            switch (choice) {
                case 1:

                cout << "\tYou enter the shop..." << endl << endl;

                break;

                case 2:

                cout << "\tYou leave town..." << endl << endl;

                break;

                case 3:

                cout << "\tAre you sure?" << endl << endl;

                while (!(cin >> yes_no)) {
                    getline(cin, yes_no);
                }

                break;
            }
        }
    }


    if (playerCharacter.save_place == GREENTOWN) {

    }

    if (playerCharacter.save_place == BLUETOWN) {

    }

    if (playerCharacter.save_place == PURPLETOWN) {

    }
}
