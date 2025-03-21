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
int GetChoice();

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

    cout << "\tWelcome to the RPG\n";
    cout << R"(
         ____  ____   ____
        |  _ \|  _ \ / ___|
        | |_) | |_) | |  _
        |  _ <|  __/| |_| |
        |_| \_\_|    \____|
        )" << endl << endl;

    while (running) {

        int choice = 0;

        do {
            cout << "Choose your option" << endl;
            cout << "1. New Game" << endl;
            cout << "2. Load Game" << endl;
            cout << "3. Quit Game" << endl;
            cout << "\n:";

            cin >> choice;

            if (!cin >> choice || choice < 1 || choice > 3) {
                cout << "Error. Please enter option 1, 2, or 3." << endl;
                cin.clear();
                cin.ignore(1024,'\n');
            }
        } while(!cin >> choice || choice < 1 || choice > 3);

        switch (choice) {
            case 1: {
                cout << "\tWelcome, player..." << endl;
                playerCharacter = CreateCharacter();
                Play(playerCharacter);
                break;
                }
           case 2: {
                cout << "\tWelcome back..." << endl;
                // Load playerCharacter data
                Play(playerCharacter);
                break;
                }
            case 3: {
                cout << "\tThanks for playing!" << endl;
                running = false;
                break;
                }
        }
    }

    return 0;
}

// Function definitions

Character CreateCharacter() {

    // Variables
    string yes_no;
    Character playerCharacter;

    // Clear stream buffer
    cin.clear();
    cin.ignore(1024,'\n');

    cout << "\tWhat is your name, adventurer?" << endl;
    getline(cin, playerCharacter.name);

    do {
        cout << "\n\t" << playerCharacter.name << endl << endl;
        cout << "\tConfirm name... (yes or no)" << endl << endl;
        getline(cin, yes_no);

        if (yes_no == "no" || yes_no == "n") {
            cout << "\tWhat is your name, adventurer?" << endl;
            getline(cin, playerCharacter.name);
            }

    } while (yes_no != "yes" && yes_no != "y");

    cout << "\tWell met " << playerCharacter.name << endl;
    cout << "\tWelcome to the world of Arpegee." << endl << endl;


    return playerCharacter;
}

void Play(Character& playerCharacter) {

    bool running = true;

    int choice = 0;

    string yes_no;

    while (running) {
    // Start new
    if (playerCharacter.save_place == "") {
        cout << "\tYou begin your adventure in your hometown of ";
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

    choice = GetChoice();

    switch (choice) {
        case 1: {

            cout << "\tYou enter the shop..." << endl << endl;

            break;

            }


        case 2: {

            cout << "\tYou leave town..." << endl << endl;

            break;

            }


        case 3: {

            cout << "\tAre you sure? (yes or no)" << endl << endl;
            cin.clear();
            cin.ignore(1024,'\n');
            getline(cin, yes_no);

            if (yes_no == "yes" || yes_no == "y") {
                    running = false;
                    break;
                    }
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

int GetChoice() {

    int choice = 0;

    do {
        cout << "Choose your option" << endl;
        cout << "1. Shop" << endl;
        cout << "2. Explore" << endl;
        cout << "3. Quit to menu" << endl;
        cout << "\n:";

        cin >> choice;

        if (!cin >> choice || choice < 1 || choice > 3) {
            cout << "Error. Please enter option 1, 2, or 3." << endl;
            cin.clear();
            cin.ignore(1024,'\n');
        }
    } while(!cin >> choice || choice < 1 || choice > 3);

    return choice;
}
