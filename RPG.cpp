#include <fstream>
#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <cstdlib>

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
    LIGHTHELM_DEF = 2,
    LIGHTHELM_VAL = 10,
    MEDHELM_DEF = 4,
    MEDHELM_VAL = 4,
    HEAVYHELM_DEF = 6,
    HEAVYHELM_VAL = 6,
    // Body gear
    GAMBESON_DEF = 3,
    GAMBESON_VAL = 3,
    CUIRASS_DEF = 5,
    CUIRASS_VAL = 15,
    IRONPLATE_DEF = 9,
    IRONPLATE_VAL = 9,
    // Weapons
    DAGGER_DMG = 2,
    DAGGER_VAL = 5,
    SWORD_DMG = 5,
    SWORD_VAL = 5,
    LONG_SWORD_DMG = 8,
    LONG_SWORD_VAL = 8,
    EXCALIBUR_DMG = 11,
    EXCALIBUR_VAL = 11;

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
        name,           // Character name, input by player
        save_place,     // Town location where player saves
        head_name,      // Character head gear name, bought from store, found on monsters
        body_name,      // Character body gear name, bought from store, found on monsters
        weapon_name;    // Character weapon name, bought from store, found on monsters

    int
        hp = 10,             // Character heath, tracked by combat
        lvl = 1,        // Character level, tracked by exp
        exp = 0,        // Character experience, gained from killing monsters
        gold = 0,       // Character gold, gained from killing monsters
        head_value = 0,   // Character head gear value, bought from store, found on monsters
        body_value = 0,   // Character body gear value, bought from store, found on monsters
        weapon_value = 1; // Character weapon value, bought from store, found on monsters
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

    cout << "\t   Welcome to the\n";
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

    playerCharacter.save_place = "none";
    playerCharacter.lvl = 1;
    playerCharacter.exp = 0;
    playerCharacter.gold = 5;
    playerCharacter.head_name = "none";
    playerCharacter.head_value = 0;
    playerCharacter.body_name = "none";
    playerCharacter.body_value = 0;
    playerCharacter.weapon_name = "none";
    playerCharacter.weapon_value = 1;

    save_player << playerCharacter.name << endl;
    save_player << playerCharacter.save_place << endl;
    save_player << playerCharacter.lvl << endl;
    save_player << playerCharacter.exp << endl;
    save_player << playerCharacter.gold << endl;
    save_player << playerCharacter.head_name << endl;
    save_player << playerCharacter.head_value << endl;
    save_player << playerCharacter.body_name << endl;
    save_player << playerCharacter.body_value << endl;
    save_player << playerCharacter.weapon_name << endl;
    save_player << playerCharacter.weapon_value << endl;

    cout << "---------------------------------------------------------------------------" << endl;

    return playerCharacter;
}

void Play(Character& playerCharacter) {

    bool running = true;

    int choice = 0;

    // Verification (second attempt) check
    string yes_no;

    ifstream load_player;   // ifstream object to load player data
    load_player.open("player_data.txt");

    load_player >> playerCharacter.name;
    load_player >> playerCharacter.save_place;
    load_player >> playerCharacter.lvl;
    load_player >> playerCharacter.exp;
    load_player >> playerCharacter.gold;
    load_player >> playerCharacter.head_name;
    load_player >> playerCharacter.head_value;
    load_player >> playerCharacter.body_name;
    load_player >> playerCharacter.body_value;
    load_player >> playerCharacter.weapon_name;
    load_player >> playerCharacter.weapon_value;

    cout << "\tWelcome back " << playerCharacter.name << "." << endl << endl;

    if (playerCharacter.save_place == "none") {
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

    while (running) {
    // Start new

    choice = GetChoice(TOWN);

    switch (choice) {

        case 1: {
            Shop(playerCharacter);
            break;
        }
        case 2: {
            Explore(playerCharacter);
            break;
        }
        case 3: {
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
            cout << "3. Save and Quit Game" << endl;
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

            if (!cin >> choice || choice < 1 || choice > 4) {
                cout << "Error. Please enter option 1, 2, or 4." << endl;
                cin.clear();
                cin.ignore(1024,'\n');
            }
        } while(!cin >> choice || choice < 1 || choice > 4);

    } else if (choiceOption == EXPLORE) {

        do {
            cout << "Choose your option" << endl;
            cout << "1. Wilderness" << endl;
            cout << "2. Travel to another town" << endl;
            cout << "3. Quit to menu" << endl;
            cout << "\n:";

            cin >> choice;

            if (!cin >> choice || choice < 1 || choice > 3) {
                cout << "Error. Please enter option 1, 2, or 3." << endl;
                cin.clear();
                cin.ignore(1024,'\n');
            }
        } while(!cin >> choice || choice < 1 || choice > 3);

    } else if (choiceOption == TRAVEL) {

        do {
            cout << "Choose your option" << endl;
            cout << "1. Hometown" << endl;
            cout << "2. Bluetown" << endl;
            cout << "3. Purpletown" << endl;
            cout << "\n:";

            cin >> choice;

            if (!cin >> choice || choice < 1 || choice > 3) {
                cout << "Error. Please enter option 1, 2, or 3." << endl;
                cin.clear();
                cin.ignore(1024,'\n');
            }
        } while(!cin >> choice || choice < 1 || choice > 3);

    }

    cout << "---------------------------------------------------------------------------" << endl;
    return choice;
}

void Shop(Character& playerCharacter) {

    int choice = 0;

    cout << "\tYou enter the shop..." << endl << endl;

    if (playerCharacter.save_place == HOMETOWN) {
        cout << "\tA feeble old man greets you." << endl << endl;
        cout << "  \"What would you like to buy?\"" << endl << endl;
        cout << "You have " << playerCharacter.gold << " gold." << endl << endl;

        // light helmet, gambeson, dagger
        cout << "1. light helmet - 10 gold" << endl;
        cout << "2. gambeson - 15 gold" << endl;
        cout << "3. dagger - 5 gold" << endl;
        cout << "4. Nothing" << endl;
        choice = GetChoice(SHOP);

        if (choice == 1) {
            if (playerCharacter.head_value == LIGHTHELM_DEF) {
            }
            if (playerCharacter.gold < 10) {
                cout << "  \"You do not have enough gold...\"" << endl;
            } else {
                cout << "  \"It's not much. But it'll keep yer head on...hehe\"" << endl;
                playerCharacter.head_name = "light helmet";
                playerCharacter.head_value = LIGHTHELM_DEF;
                playerCharacter.gold -= LIGHTHELM_VAL;
            }
        } else if (choice == 2) {
            if (playerCharacter.head_value == GAMBESON_DEF) {
            }
            if (playerCharacter.gold < 15) {
                cout << "  \"You do not have enough gold...\"" << endl;
            } else {
                cout << "  \"Ahh. A sturdy piece that one...hehe\"" << endl;
                playerCharacter.body_name = "gambeson";
                playerCharacter.body_value = GAMBESON_DEF;
                playerCharacter.gold -= GAMBESON_VAL;
            }
        } else if (choice == 3) {
            if (playerCharacter.head_value == DAGGER_DMG) {
            }
            if (playerCharacter.gold < 5) {
                cout << "  \"You do not have enough gold...\"" << endl;
            } else {
                cout << "  \"A mere butter knife...but sharp!...hehe\"" << endl;
                playerCharacter.weapon_name = "dagger";
                playerCharacter.weapon_value = DAGGER_DMG;
                playerCharacter.gold -= DAGGER_VAL;
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

void Explore(Character& playerCharacter) {

    playerCharacter.weapon_value;

    int choice = 0;
    int fightOrFind = 0;
    int findArtifact = 0;
    int swing = 0;
    int enemyHealth = 0;
    // Enemies
    int stag = 4;
    int scorpion = 5;
    int werebeast = 6;
    int tortoise = 6;
    int boa = 7;
    int grizzly = 8;
    int jaguar = 10;
    int wildebeast = 12;
    int rhinoceros = 14;

    cout << "\tYou leave town..." << endl << endl;

    if (playerCharacter.save_place == HOMETOWN) {

        choice = GetChoice(EXPLORE);

        if (choice == 1) {

            fightOrFind = rand() % 15 + 1;

            if (fightOrFind == 15) {
                cout << "You found an artifact!" << endl << endl;
                playerCharacter.gold += findArtifact;
                cout << "It's worth" << findArtifact << "gold. Cool." << endl << endl;

            } else if (fightOrFind < 5) {
                cout << "You encounter a stag." << endl << endl;
                enemyHealth = stag;
                swing = rand() % stag;
                cout << "You hit for " << swing << " damage." << endl << endl;
                while (enemyHealth > 0) {
                    swing = rand() % stag;
                    playerCharacter.hp -= swing;
                    cout << "The stag hit you for " << swing << " damage. Your health is " << playerCharacter.hp << endl << endl;
                    if (playerCharacter.hp < 1) {
                        cout << "You died..." << endl << endl;
                        exit(1);                                     // CAREFUL
                    }
                    swing = rand() % playerCharacter.weapon_value + 1;
                    cout << "You hit for " << swing << " damage." << endl << endl;
                    enemyHealth -= swing;
                    cout << "The stag has " << enemyHealth << " health." << endl << endl;
                    if (enemyHealth < 1) {
                        cout << "Victory... You killed the stag." << endl << endl;
                    }
                }

            } else if (fightOrFind > 5 && fightOrFind < 10) {
                cout << "You encounter a scorpion." << endl << endl;
                enemyHealth = scorpion;
                swing = rand() % scorpion;
                cout << "You hit for " << swing << " damage." << endl << endl;
                while (enemyHealth > 0) {
                    swing = rand() % scorpion;
                    playerCharacter.hp -= swing;
                    cout << "The scorpion hit you for " << swing << " damage. Your health is " << playerCharacter.hp << endl << endl;
                    if (playerCharacter.hp < 1) {
                        cout << "You died..." << endl << endl;
                        exit(1);                                     // CAREFUL
                    }
                    swing = rand() % playerCharacter.weapon_value;
                    cout << "You hit for " << swing << " damage." << endl << endl;
                    enemyHealth -= swing;
                    cout << "The scorpion has " << enemyHealth << " health." << endl << endl;
                    if (enemyHealth < 1) {
                        cout << "Victory... You killed the scorpion." << endl << endl;
                    }
                }

            } else if (fightOrFind > 10 && fightOrFind < 15) {
                cout << "You encounter a werebeast." << endl << endl;
                enemyHealth = werebeast;
                while (enemyHealth > 0) {
                    swing = rand() % werebeast;
                    playerCharacter.hp -= swing;
                    cout << "The werebeast hit you for " << swing << " damage. Your health is " << playerCharacter.hp << endl << endl;
                    if (playerCharacter.hp < 1) {
                        cout << "You died..." << endl << endl;
                        exit(1);                                     // CAREFUL
                    }
                    cout << "Player weapon value: " << playerCharacter.weapon_value << endl << endl;
                    swing = rand() % playerCharacter.weapon_value;
                    cout << "You hit for " << swing << " damage." << endl << endl;
                    enemyHealth -= swing;
                    cout << "The werebeast has " << enemyHealth << " health." << endl << endl;
                    if (enemyHealth < 1) {
                        cout << "Victory... You killed the werebeast." << endl << endl;
                    }
                }
            }
        } else if (choice == 2) {

            cout << "Where would you like to travel to?" << endl;
            choice = GetChoice(TRAVEL);

            if (choice == 1) {

                cout << "You travel to Hometown" << endl;
                playerCharacter.save_place = HOMETOWN;
            } else if (choice == 2) {

                cout << "You travel to Bluetown" << endl;
                playerCharacter.save_place = BLUETOWN;
            } else if (choice == 3) {

                cout << "You travel to Purpletown" << endl;
                playerCharacter.save_place = PURPLETOWN;
            }
        }

    } else if (playerCharacter.save_place == BLUETOWN) {

        choice = GetChoice(EXPLORE);

        if (choice == 1) {

            fightOrFind = rand() % 15;

            if (fightOrFind == 15) {
                cout << "You found an artifact!" << endl;
                playerCharacter.gold += findArtifact;
                cout << "It's worth" << findArtifact << "gold. Cool." << endl;
            } else if (fightOrFind < 5) {
                cout << "You encounter a tortoise." << endl;
            } else if (fightOrFind > 5 && fightOrFind < 10) {
                cout << "You find a boa." << endl;
            } else if (fightOrFind > 10 && fightOrFind < 15) {
                cout << "You find a grizzly." << endl;
            }
        } else if (choice == 2) {

            cout << "Where would you like to travel to?" << endl;
            choice = GetChoice(TRAVEL);

            if (choice == 1) {

                cout << "You travel to Hometown" << endl;
                playerCharacter.save_place = HOMETOWN;
            } else if (choice == 2) {

                cout << "You travel to Bluetown" << endl;
                playerCharacter.save_place = BLUETOWN;
            } else if (choice == 3) {

                cout << "You travel to Purpletown" << endl;
                playerCharacter.save_place = PURPLETOWN;
            }
        }

    } else if (playerCharacter.save_place == PURPLETOWN) {

        choice = GetChoice(EXPLORE);

        if (choice == 1) {

            fightOrFind = rand() % 15 + 12;

            if (fightOrFind == 15) {
                cout << "You found an artifact!" << endl;
                playerCharacter.gold += findArtifact;
                cout << "It's worth" << findArtifact << "gold. Cool." << endl;
            } else if (fightOrFind < 5) {
                cout << "You encounter a jaguar." << endl;
            } else if (fightOrFind > 5 && fightOrFind < 10) {
                cout << "You find a wildebeast." << endl;
            } else if (fightOrFind > 10 && fightOrFind < 15) {
                cout << "You find a rhinocerous." << endl;
            }

        } else if (choice == 2) {

            cout << "Where would you like to travel to?" << endl;
            choice = GetChoice(TRAVEL);


        }
    }
}

void Travel(Character& playerCharacter) {

    int choice = 0;

    cout << "\tWhere do you want to go?" << endl;
    choice = GetChoice(TRAVEL);

    if (choice == 1) {

            cout << "You travel to Hometown" << endl;
            playerCharacter.save_place = HOMETOWN;
        } else if (choice == 2) {

            cout << "You travel to Bluetown" << endl;
            playerCharacter.save_place = BLUETOWN;
        } else if (choice == 3) {

            cout << "You travel to Purpletown" << endl;
            playerCharacter.save_place = PURPLETOWN;
        }
    }
