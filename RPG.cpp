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
    PURPLETOWN = "Purpletown";

const int
    // Head gear
    LIGHTHELM = 2,
    MEDHELM = 4,
    HEAVYHELM = 6,
    // Body gear
    GAMBESON = 3,
    CUIRASS = 5,
    IRONPLATE = 9,
    // Weapons
    DAGGER = 2,
    SWORD = 5,
    LONG_SWORD = 8,
    EXCALIBUR = 11;

const int
    // Menu options
    MAIN = 1,
    TOWN = 2,
    SHOP = 3,
    EXPLORE = 4,
    TRAVEL = 5;

// Structures
struct Character {

    string
        name,       // Character name, input by player
        save_place; // Town location where player saves

    int
        lvl = 1,    // Character level, tracked by exp
        exp = 0,    // Character experience, gained from killing monsters
        gold = 0,   // Character gold, gained from killing monsters
        head = 0,   // Character head gear, bought from store, found on monsters
        body = 0,   // Character body gear, bought from store, found on monsters
        weapon = 0; // Character weapon, bought from store, found on monsters
};

// Function declarations
Character CreateCharacter();
int GetChoice(const int);
void Play(Character&);
void Shop(Character&);
void Explore(Character&);
void Travel(Character&);

int main()
{
    // Variables
    Character playerCharacter;  // Player character struct

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

        choice = GetChoice(MAIN);

        switch (choice) {
            case 1: {
                playerCharacter = CreateCharacter();
                Play(playerCharacter);
                break;
                }
           case 2: {
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

    ofstream save_player;   // ofstream object to write all player data, populated with
                            // option 1. New Game
    save_player.open("player_data.txt");

    // Clear stream buffer
    cin.clear();
    cin.ignore(1024,'\n');

    cout << "\tWelcome, player..." << endl;

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

    save_player << playerCharacter.name << endl;

    playerCharacter.save_place = HOMETOWN;
    save_player << playerCharacter.save_place << endl;

    return playerCharacter;
}

void Play(Character& playerCharacter) {

    bool running = true;

    int choice = 0;

    string yes_no;

    ifstream load_player;   // ifstream object to load player data
    load_player.open("player_data.txt");

    load_player >> playerCharacter.name;

    cout << "\tWelcome back " << playerCharacter.name << "." << endl << endl;

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

    choice = GetChoice(TOWN);

    switch (choice) {

        case 1: {
            cout << "\tYou enter the shop..." << endl << endl;
            Shop(playerCharacter);
            break;
        }
        case 2: {
            cout << "\tYou leave town..." << endl << endl;
            Explore(playerCharacter);
            break;
        }
        case 3: {
            cout << "\tWhere do you want to go?" << endl;
            // Load playerCharacter data
            Travel(playerCharacter);
            break;
        }
        case 4: {

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
}

int GetChoice(const int choiceOption) {

    int choice = 0;

    if (choiceOption == MAIN) {

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

    } else if (choiceOption == TOWN) {

        do {
            cout << "Choose your option" << endl;
            cout << "1. Shop" << endl;
            cout << "2. Explore" << endl;
            cout << "3. Travel" << endl;
            cout << "4. Quit to menu" << endl;
            cout << "\n:";

            cin >> choice;

            if (!cin >> choice || choice < 1 || choice > 4) {
                cout << "Error. Please enter option 1, 2, 3, or 4." << endl;
                cin.clear();
                cin.ignore(1024,'\n');
        }
    } while(!cin >> choice || choice < 1 || choice > 4);

    } else if (choiceOption == SHOP) {

        do {
            cout << "\n:";

            cin >> choice;

            if (!cin >> choice || choice < 1 || choice > 3) {
                cout << "Error. Please enter option 1, 2, or 3." << endl;
                cin.clear();
                cin.ignore(1024,'\n');
            }
        } while(!cin >> choice || choice < 1 || choice > 3);

    } else if (choiceOption == EXPLORE) {

        do {
            cout << "Choose your option" << endl;

            cout << "4. Quit to menu" << endl;
            cout << "\n:";

            cin >> choice;

            if (!cin >> choice || choice < 1 || choice > 3) {
                cout << "Error. Please enter option 1, 2, or 3." << endl;
                cin.clear();
                cin.ignore(1024,'\n');
            }
        } while(!cin >> choice || choice < 1 || choice > 3);
    }

    return choice;
}

void Shop(Character& playerCharacter) {

    int choice = 0;

    if (playerCharacter.save_place == HOMETOWN) {
        cout << "\tA feeble old man greets you." << endl << endl;
        cout << "  \"What would you like to buy?\"" << endl;

        // light helmet, gambeson, dagger
        cout << "1. light helmet - 10 gold" << endl;
        cout << "2. gambeson - 15 gold" << endl;
        cout << "3. dagger - 5 gold" << endl;
        cout << "4. Nothing" << endl;
        choice = GetChoice(SHOP);

        if (choice == 1) {
            if (playerCharacter.gold < 10) {
                cout << "  \"You do not have enough gold...\"" << endl;
            } else {
                cout << "  \"It's not much. But it'll keep yer head on...hehe\"" << endl;
                playerCharacter.head = LIGHTHELM;
                playerCharacter.gold -= 10;
            }
        } else if (choice == 2) {
            if (playerCharacter.gold < 15) {
                cout << "  \"You do not have enough gold...\"" << endl;
            } else {
                cout << "  \"Ahh. A sturdy piece that one...hehe\"" << endl;
                playerCharacter.head = LIGHTHELM;
                playerCharacter.gold -= 10;
            }
        } else if (choice == 3) {
            if (playerCharacter.gold < 5) {
                cout << "  \"You do not have enough gold...\"" << endl;
            } else {
                cout << "  \"A mere butter knife...but sharp!...hehe\"" << endl;
                playerCharacter.head = LIGHTHELM;
                playerCharacter.gold -= 10;
            }
        } else if (choice == 4) {
            cout << "  \"Take care of yourself now...\"" << endl;
        }

    } else if (playerCharacter.save_place == BLUETOWN) {
        cout << "\tA portly woman greets you." << endl << endl;
        cout << "  \"What would you like to buy?\"" << endl;

        // medium helmet, cuirass, sword
        cout << "1. medium helmet - 25 gold" << endl;
        cout << "2. cuirass - 50 gold" << endl;
        cout << "3. sword - 60 gold" << endl;
        choice = GetChoice(SHOP);

    } else if (playerCharacter.save_place == PURPLETOWN) {
        cout << "\tA sophisticated merchant greets you." << endl << endl;
        cout << "  \"What would you like to buy?\"" << endl;

        // heavy helmet, iron platebody, long sword
        cout << "1. heavy helmet - 80 gold" << endl;
        cout << "2. iron platebody - 120 gold" << endl;
        cout << "3. long sword - 150 gold" << endl;
        choice = GetChoice(SHOP);
    }
}

void Explore(Character&) {

    int choice = 0;

//    choice = GetChoice();
}

void Travel (Character&) {

    }
