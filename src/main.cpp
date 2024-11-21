#include <string>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;



// [A00] Struct

struct Pokemon {
    string type, name;
    string skillName0, skillName1, skillName2, skillName3;
    string skillType0, skillType1, skillType2, skillType3;
    int hp;
    int skillDamage0, skillDamage1, skillDamage2, skillDamage3;
    int skillCount0, skillCount1, skillCount2, skillCount3;
    int maxUse0, maxUse1, maxUse2, maxUse3;
    string latestSkill, effectiveness;
    bool isTurn;
};



// [A01] Basic Functions

void printSep1() {
    // Function for printing seperator with a new line
    cout << "+-------------------------------------------------------------+\n";
}

void printSep2() {
    // Function for printing seperator with a new line
    cout << "+------------------------------+------------------------------+\n";
}

void printTitle() {
    // Function for printing title
    printSep1();
    cout << "| 2024-02 Object-Oriented Programming Pokemon Master          |\n";
    printSep2();
}

void printLine(string somethingToPrint1, string somethingToPrint2) {
    // Function for printing line
    int wordLength1 = somethingToPrint1.length();
    int wordLength2 = somethingToPrint2.length();
    cout << "| " << somethingToPrint1;
    for (int i = 0; i < 29 - wordLength1; i++) {
        cout << " ";
    }
    cout << "| " << somethingToPrint2;
    for (int i = 0; i < 29 - wordLength2; i++) {
        cout << " ";
    }
    cout << "|\n";
}



// [A02] Advanced Functions

int decision(string atkType, string defType) {
    // Function for deciding effectiveness of attack
    // Return value of this function will in/decrease damage
    if (atkType == "Ground") {
        if (defType == "Electric" || defType == "Fire") {
            return 5;  // super effective
        } else if (defType == "Grass") {
            return -3;  // not very effective
        }
    }
    if (atkType == "Electric") {
        if (defType == "Water") {
            return 5;  // super effective
        } else if (defType == "Ground" || defType == "Electric" || defType == "Grass") {
            return -3;  // not very effective
        }
    }
    if (atkType == "Water") {
        if (defType == "Ground" || defType == "Fire") {
            return 5;  // super effective
        } else if (defType == "Water" || defType == "Grass") {
            return -3;  // not very effective
        }
    }
    if (atkType == "Grass") {
        if (defType == "Water") {
            return 5;  // super effective
        } else if (defType == "Ground" || defType == "Grass" || defType == "Fire") {
            return -3;  // not very effective
        }
    }
    if (atkType == "Fire") {
        if (defType == "Grass") {
            return 5;  // super effective
        } else if (defType == "Water" || defType == "Fire") {
            return -3;  // not very effective
        }
    }
    return 0;  // effective for all the other cases
}

void printPokemonInfo(Pokemon object1, Pokemon object2) {
    // Function for printing Pokemon Information
    if (object1.isTurn == true) {
        printLine(object1.name + " (*)", object2.name);
        printLine("Type: " + object1.type, "Type: " + object2.type);
        printLine("HP: " + to_string(object1.hp), "HP: " + to_string(object2.hp));
    } else if (object2.isTurn == true) {
        printLine(object1.name, object2.name + " (*)");
        printLine("Type: " + object1.type, "Type: " + object2.type);
        printLine("HP: " + to_string(object1.hp), "HP: " + to_string(object2.hp));
    } else {
        cerr << "ERROR! (code 01)";
    }
}

void printPokemonLatest(Pokemon object1, Pokemon object2) {
    // Function for printing Pokemon Latest Skill Info
    printLine("Latest Skill: " + object1.latestSkill, "Latest Skill: " + object2.latestSkill);
    printLine(object1.effectiveness, object2.effectiveness);
}

void printPokemonSkillInfo(Pokemon object1, Pokemon object2) {
    // Function for printing Pokemons' Skill Info
    printLine("(0) " + object1.skillName0, "(0) " + object2.skillName0);
    printLine("    - Type: " + object1.skillType0, "    - Type: " + object2.skillType0);
    printLine("    - Damage: " + to_string(object1.skillDamage0), "    - Damage: " + to_string(object2.skillDamage0));
    printLine("    - Count: " + to_string(object1.skillCount0) + "(" + to_string(object1.maxUse0) + ")", "    - Count: " + to_string(object2.skillCount0) + "(" + to_string(object2.maxUse0) + ")");
    printLine("(1) " + object1.skillName1, "(1) " + object2.skillName1);
    printLine("    - Type: " + object1.skillType1, "    - Type: " + object2.skillType1);
    printLine("    - Damage: " + to_string(object1.skillDamage1), "    - Damage: " + to_string(object2.skillDamage1));
    printLine("    - Count: " + to_string(object1.skillCount1) + "(" + to_string(object1.maxUse1) + ")", "    - Count: " + to_string(object2.skillCount1) + "(" + to_string(object2.maxUse1) + ")");
    printLine("(2) " + object1.skillName2, "(2) " + object2.skillName2);
    printLine("    - Type: " + object1.skillType2, "    - Type: " + object2.skillType2);
    printLine("    - Damage: " + to_string(object1.skillDamage2), "    - Damage: " + to_string(object2.skillDamage2));
    printLine("    - Count: " + to_string(object1.skillCount2) + "(" + to_string(object1.maxUse2) + ")", "    - Count: " + to_string(object2.skillCount2) + "(" + to_string(object2.maxUse2) + ")");
    printLine("(3) " + object1.skillName3, "(3) " + object2.skillName3);
    printLine("    - Type: " + object1.skillType3, "    - Type: " + object2.skillType3);
    printLine("    - Damage: " + to_string(object1.skillDamage3), "    - Damage: " + to_string(object2.skillDamage3));
    printLine("    - Count: " + to_string(object1.skillCount3) + "(" + to_string(object1.maxUse3) + ")", "    - Count: " + to_string(object2.skillCount3) + "(" + to_string(object2.maxUse3) + ")");
}

void printTurn(Pokemon object1, Pokemon object2) {
    // Integrated function for printing information of entire turn
    printTitle();
    printPokemonInfo(object1, object2);
    printSep2();
    printPokemonLatest(object1, object2);
    printSep2();
    printPokemonSkillInfo(object1, object2);
    printSep2();
}



// [A03] Pokemon Information

void pokemonInit(Pokemon& object, int type, bool firstPokemon) {

    if (type == 0) {
        // Pikachu
        object.name = "Pikachu";
        object.type = "Electric";
        object.hp = 35;
        object.skillName0 = "Tackle";
        object.skillType0 = "Normal";
        object.skillDamage0 = 4;
        object.skillName1 = "Grass Knot";
        object.skillType1 = "Grass";
        object.skillDamage1 = 8;
        object.skillName2 = "Thunderbolt";
        object.skillType2 = "Electric";
        object.skillDamage2 = 10;
        object.skillName3 = "Megabolt";
        object.skillType3 = "Electric";
        object.skillDamage3 = 15;
        object.skillCount0 = 5;
        object.skillCount1 = 5;
        object.skillCount2 = 5;
        object.skillCount3 = 3;
        object.maxUse0 = 5;
        object.maxUse1 = 5;
        object.maxUse2 = 5;
        object.maxUse3 = 3;
        object.latestSkill = "-";
        object.effectiveness = "";
    } else if (type == 1) {
        // Dratini
        object.name = "Dratini";
        object.type = "Water";
        object.hp = 41;
        object.skillName0 = "Wrap";
        object.skillType0 = "Normal";
        object.skillDamage0 = 4;
        object.skillName1 = "Aqua Tail";
        object.skillType1 = "Water";
        object.skillDamage1 = 3;
        object.skillName2 = "Water Pulse";
        object.skillType2 = "Water";
        object.skillDamage2 = 13;
        object.skillName3 = "Hyper Beam";
        object.skillType3 = "Normal";
        object.skillDamage3 = 20;
        object.skillCount0 = 10;
        object.skillCount1 = 5;
        object.skillCount2 = 2;
        object.skillCount3 = 1;
        object.maxUse0 = 10;
        object.maxUse1 = 5;
        object.maxUse2 = 2;
        object.maxUse3 = 1;
        object.latestSkill = "-";
        object.effectiveness = "";
    } else if (type == 2) {
        // Eevee
        object.name = "Eevee";
        object.type = "Normal";
        object.hp = 55;
        object.skillName0 = "Tackle";
        object.skillType0 = "Normal";
        object.skillDamage0 = 4;
        object.skillName1 = "Sand Attack";
        object.skillType1 = "Ground";
        object.skillDamage1 = 8;
        object.skillName2 = "Bite";
        object.skillType2 = "Normal";
        object.skillDamage2 = 12;
        object.skillName3 = "Rain Dance";
        object.skillType3 = "Water";
        object.skillDamage3 = 15;
        object.skillCount0 = 5;
        object.skillCount1 = 3;
        object.skillCount2 = 3;
        object.skillCount3 = 1;
        object.maxUse0 = 5;
        object.maxUse1 = 3;
        object.maxUse2 = 3;
        object.maxUse3 = 1;
        object.latestSkill = "-";
        object.effectiveness = "";
    } else if (type == 3) {
        // Charmander
        object.name = "Charmander";
        object.type = "Fire";
        object.hp = 39;
        object.skillName0 = "Tackle";
        object.skillType0 = "Normal";
        object.skillDamage0 = 4;
        object.skillName1 = "Flamethrower";
        object.skillType1 = "Fire";
        object.skillDamage1 = 11;
        object.skillName2 = "Dig";
        object.skillType2 = "Ground";
        object.skillDamage2 = 7;
        object.skillName3 = "Heat Wave";
        object.skillType3 = "Fire";
        object.skillDamage3 = 14;
        object.skillCount0 = 5;
        object.skillCount1 = 5;
        object.skillCount2 = 5;
        object.skillCount3 = 5;
        object.maxUse0 = 5;
        object.maxUse1 = 5;
        object.maxUse2 = 5;
        object.maxUse3 = 5;
        object.latestSkill = "-";
        object.effectiveness = "";
    } else if (type == 4) {
        // Palkia
        object.name = "Palkia";
        object.type = "Water";
        object.hp = 90;
        object.skillName0 = "Hydro Pump";
        object.skillType0 = "Water";
        object.skillDamage0 = 12;
        object.skillName1 = "Earth Power";
        object.skillType1 = "Ground";
        object.skillDamage1 = 15;
        object.skillName2 = "Surf";
        object.skillType2 = "Water";
        object.skillDamage2 = 13;
        object.skillName3 = "Spatial Rend";
        object.skillType3 = "Normal";
        object.skillDamage3 = 30;
        object.skillCount0 = 10;
        object.skillCount1 = 10;
        object.skillCount2 = 10;
        object.skillCount3 = 10;
        object.maxUse0 = 10;
        object.maxUse1 = 10;
        object.maxUse2 = 10;
        object.maxUse3 = 10;
        object.latestSkill = "-";
        object.effectiveness = "";
    }

    if (firstPokemon == true) {
        object.isTurn = true;
    } else {
        object.isTurn = false;
    }

}




// [A04] Main Function

int main() {
    
    // Step 1 : Choose a Pokemon
    int pokemonName1, pokemonName2;
    cout << "Choose a Pokemon(0~4): ";
    cin >> pokemonName1;
    cout << "Choose another Pokemon(0~4): ";
    cin >> pokemonName2;

    if (pokemonName1 == pokemonName2) {

        // The program no longer proceeds
        cout << "You have to choose Pokemons different from each other.";

    } else {

        // Step 2-1 : Pokemon initialization
        Pokemon pokemon1, pokemon2;
        pokemonInit(pokemon1, pokemonName1, true);
        pokemonInit(pokemon2, pokemonName2, false);

        // Step 2-2 : Pokemon Battle
        bool battleOnProgress = true;

        while (battleOnProgress == true) {

            printTurn(pokemon1, pokemon2);
            cout << "Choose a skill (0~3): ";
            int toPerform;
            cin >> toPerform;

            if (pokemon1.isTurn == true) {

                if (toPerform == 0) {
                    if (pokemon1.skillCount0 == 0) {
                        cout << pokemon1.name << " failed to perform " << pokemon1.skillName0 << ".\n";
                        pokemon1.isTurn == false;
                        pokemon2.isTurn == true;
                    } else {
                        cout << pokemon1.name << " used " << pokemon1.skillName0 << ".\n";
                        pokemon1.latestSkill = pokemon1.skillName0;
                        if (decision(pokemon1.skillType0, pokemon2.type) == 5) {
                            cout << "It was super effective.\n\n"; // TYPO HERE!!
                            pokemon2.hp -= pokemon1.skillDamage0 + 5;
                            pokemon1.skillCount0 -= 1;
                            pokemon1.effectiveness = "It was super effective."; // TYPO HERE!!
                        } else if (decision(pokemon1.skillType0, pokemon2.type) == -3) {
                            cout << "It was not very effective.\n\n"; // TYPO HERE!!
                            pokemon2.hp -= pokemon1.skillDamage0 - 3;
                            pokemon1.skillCount0 -= 1;
                            pokemon1.effectiveness = "It was not very effective."; // TYPO HERE!!
                        } else {
                            cout << "It was effective.\n\n"; // TYPO HERE!!
                            pokemon2.hp -= pokemon1.skillDamage0;
                            pokemon1.skillCount0 -= 1;
                            pokemon1.effectiveness = "It was effective."; // TYPO HERE!!
                        }
                        pokemon1.isTurn == false;
                        pokemon2.isTurn == true;
                    }
                } else if (toPerform == 1) {
                    if (pokemon1.skillCount1 == 0) {
                        cout << pokemon1.name << " failed to perform " << pokemon1.skillName1 << ".\n";
                        pokemon1.isTurn == false;
                        pokemon2.isTurn == true;
                    } else {
                        cout << pokemon1.name << " used " << pokemon1.skillName1 << ".\n";
                        pokemon1.latestSkill = pokemon1.skillName1;
                        if (decision(pokemon1.skillType1, pokemon2.type) == 5) {
                            cout << "It was super effective.\n\n"; // TYPO HERE!!
                            pokemon2.hp -= pokemon1.skillDamage1 + 5;
                            pokemon1.skillCount1 -= 1;
                            pokemon1.effectiveness = "It was super effective."; // TYPO HERE!!
                        } else if (decision(pokemon1.skillType1, pokemon2.type) == -3) {
                            cout << "It was not very effective.\n\n"; // TYPO HERE!!
                            pokemon2.hp -= pokemon1.skillDamage1 - 3;
                            pokemon1.skillCount1 -= 1;
                            pokemon1.effectiveness = "It was not very effective."; // TYPO HERE!!
                        } else {
                            cout << "It was effective.\n\n"; // TYPO HERE!!
                            pokemon2.hp -= pokemon1.skillDamage1;
                            pokemon1.skillCount1 -= 1;
                            pokemon1.effectiveness = "It was effective."; // TYPO HERE!!
                        }
                        pokemon1.isTurn == false;
                        pokemon2.isTurn == true;
                    }
                } else if (toPerform == 2) {
                    if (pokemon1.skillCount2 == 0) {
                        cout << pokemon1.name << " failed to perform " << pokemon1.skillName2 << ".\n";
                        pokemon1.isTurn == false;
                        pokemon2.isTurn == true;
                    } else {
                        cout << pokemon1.name << " used " << pokemon1.skillName2 << ".\n";
                        pokemon1.latestSkill = pokemon1.skillName2;
                        if (decision(pokemon1.skillType2, pokemon2.type) == 5) {
                            cout << "It was super effective.\n\n"; // TYPO HERE!!
                            pokemon2.hp -= pokemon1.skillDamage2 + 5;
                            pokemon1.skillCount2 -= 1;
                            pokemon1.effectiveness = "It was super effective."; // TYPO HERE!!
                        } else if (decision(pokemon1.skillType2, pokemon2.type) == -3) {
                            cout << "It was not very effective.\n\n"; // TYPO HERE!!
                            pokemon2.hp -= pokemon1.skillDamage2 - 3;
                            pokemon1.skillCount2 -= 1;
                            pokemon1.effectiveness = "It was not very effective."; // TYPO HERE!!
                        } else {
                            cout << "It was effective.\n\n"; // TYPO HERE!!
                            pokemon2.hp -= pokemon1.skillDamage2;
                            pokemon1.skillCount2 -= 1;
                            pokemon1.effectiveness = "It was effective."; // TYPO HERE!!
                        }
                        pokemon1.isTurn == false;
                        pokemon2.isTurn == true;
                    }
                } else if (toPerform == 3) {
                    if (pokemon1.skillCount3 == 0) {
                        cout << pokemon1.name << " failed to perform " << pokemon1.skillName3 << ".\n";
                        pokemon1.isTurn == false;
                        pokemon2.isTurn == true;
                    } else {
                        cout << pokemon1.name << " used " << pokemon1.skillName3 << ".\n";
                        pokemon1.latestSkill = pokemon1.skillName3;
                        if (decision(pokemon1.skillType3, pokemon2.type) == 5) {
                            cout << "It was super effective.\n\n"; // TYPO HERE!!
                            pokemon2.hp -= pokemon1.skillDamage3 + 5;
                            pokemon1.skillCount3 -= 1;
                            pokemon1.effectiveness = "It was super effective."; // TYPO HERE!!
                        } else if (decision(pokemon1.skillType0, pokemon2.type) == -3) {
                            cout << "It was not very effective.\n\n"; // TYPO HERE!!
                            pokemon2.hp -= pokemon1.skillDamage3 - 3;
                            pokemon1.skillCount3 -= 1;
                            pokemon1.effectiveness = "It was not very effective."; // TYPO HERE!!
                        } else {
                            cout << "It was effective.\n\n"; // TYPO HERE!!
                            pokemon2.hp -= pokemon1.skillDamage3;
                            pokemon1.skillCount3 -= 1;
                            pokemon1.effectiveness = "It was effective."; // TYPO HERE!!
                        }
                        pokemon1.isTurn == false;
                        pokemon2.isTurn == true;
                    }
                } else {
                    cerr << "ERROR! (code 03)";
                }

                if (pokemon2.hp <= 0) {
                    battleOnProgress = false;
                    cout << "===============================================================";
                    cout << "Match Result: " << pokemon1.name << " defeats " << pokemon2.name;
                }

            } else if (pokemon2.isTurn == true) {

                if (toPerform == 0) {
                    if (pokemon2.skillCount0 == 0) {
                        cout << pokemon2.name << " failed to perform " << pokemon2.skillName0 << ".\n";
                        pokemon2.isTurn == false;
                        pokemon1.isTurn == true;
                    } else {
                        cout << pokemon2.name << " used " << pokemon1.skillName0 << ".\n";
                        pokemon2.latestSkill = pokemon2.skillName0;
                        if (decision(pokemon2.skillType0, pokemon1.type) == 5) {
                            cout << "It was super effective.\n\n"; // TYPO HERE!!
                            pokemon1.hp -= pokemon2.skillDamage0 + 5;
                            pokemon2.skillCount0 -= 1;
                            pokemon2.effectiveness = "It was super effective."; // TYPO HERE!!
                        } else if (decision(pokemon2.skillType0, pokemon1.type) == -3) {
                            cout << "It was not very effective.\n\n"; // TYPO HERE!!
                            pokemon1.hp -= pokemon2.skillDamage0 - 3;
                            pokemon2.skillCount0 -= 1;
                            pokemon2.effectiveness = "It was not very effective."; // TYPO HERE!!
                        } else {
                            cout << "It was effective.\n\n"; // TYPO HERE!!
                            pokemon1.hp -= pokemon2.skillDamage0;
                            pokemon2.skillCount0 -= 1;
                            pokemon2.effectiveness = "It was effective."; // TYPO HERE!!
                        }
                        pokemon2.isTurn == false;
                        pokemon1.isTurn == true;
                    }
                } else if (toPerform == 1) {
                    if (pokemon2.skillCount1 == 0) {
                        cout << pokemon2.name << " failed to perform " << pokemon2.skillName1 << ".\n";
                        pokemon2.isTurn == false;
                        pokemon1.isTurn == true;
                    } else {
                        cout << pokemon2.name << " used " << pokemon2.skillName1 << ".\n";
                        pokemon2.latestSkill = pokemon2.skillName1;
                        if (decision(pokemon2.skillType1, pokemon1.type) == 5) {
                            cout << "It was super effective.\n\n"; // TYPO HERE!!
                            pokemon1.hp -= pokemon2.skillDamage1 + 5;
                            pokemon2.skillCount1 -= 1;
                            pokemon2.effectiveness = "It was super effective."; // TYPO HERE!!
                        } else if (decision(pokemon2.skillType1, pokemon1.type) == -3) {
                            cout << "It was not very effective.\n\n"; // TYPO HERE!!
                            pokemon1.hp -= pokemon2.skillDamage1 - 3;
                            pokemon2.skillCount1 -= 1;
                            pokemon2.effectiveness = "It was not very effective."; // TYPO HERE!!
                        } else {
                            cout << "It was effective.\n\n"; // TYPO HERE!!
                            pokemon1.hp -= pokemon2.skillDamage1;
                            pokemon2.skillCount1 -= 1;
                            pokemon2.effectiveness = "It was effective."; // TYPO HERE!!
                        }
                        pokemon2.isTurn == false;
                        pokemon1.isTurn == true;
                    }
                } else if (toPerform == 2) {
                    if (pokemon2.skillCount2 == 0) {
                        cout << pokemon2.name << " failed to perform " << pokemon2.skillName2 << ".\n";
                        pokemon2.isTurn == false;
                        pokemon1.isTurn == true;
                    } else {
                        cout << pokemon2.name << " used " << pokemon2.skillName2 << ".\n";
                        pokemon2.latestSkill = pokemon2.skillName2;
                        if (decision(pokemon2.skillType2, pokemon1.type) == 5) {
                            cout << "It was super effective.\n\n"; // TYPO HERE!!
                            pokemon1.hp -= pokemon2.skillDamage2 + 5;
                            pokemon2.skillCount2 -= 1;
                            pokemon2.effectiveness = "It was super effective."; // TYPO HERE!!
                        } else if (decision(pokemon2.skillType2, pokemon1.type) == -3) {
                            cout << "It was not very effective.\n\n"; // TYPO HERE!!
                            pokemon1.hp -= pokemon2.skillDamage2 - 3;
                            pokemon2.skillCount2 -= 1;
                            pokemon2.effectiveness = "It was not very effective."; // TYPO HERE!!
                        } else {
                            cout << "It was effective.\n\n"; // TYPO HERE!!
                            pokemon1.hp -= pokemon2.skillDamage2;
                            pokemon2.skillCount2 -= 1;
                            pokemon2.effectiveness = "It was effective."; // TYPO HERE!!
                        }
                        pokemon2.isTurn == false;
                        pokemon1.isTurn == true;
                    }
                } else if (toPerform == 3) {
                    if (pokemon2.skillCount3 == 0) {
                        cout << pokemon2.name << " failed to perform " << pokemon2.skillName3 << ".\n";
                        pokemon2.isTurn == false;
                        pokemon1.isTurn == true;
                    } else {
                        cout << pokemon2.name << " used " << pokemon2.skillName3 << ".\n";
                        pokemon2.latestSkill = pokemon2.skillName3;
                        if (decision(pokemon2.skillType3, pokemon1.type) == 5) {
                            cout << "It was super effective.\n\n"; // TYPO HERE!!
                            pokemon1.hp -= pokemon2.skillDamage3 + 5;
                            pokemon2.skillCount3 -= 1;
                            pokemon2.effectiveness = "It was super effective."; // TYPO HERE!!
                        } else if (decision(pokemon2.skillType0, pokemon1.type) == -3) {
                            cout << "It was not very effective.\n\n"; // TYPO HERE!!
                            pokemon1.hp -= pokemon2.skillDamage3 - 3;
                            pokemon2.skillCount3 -= 1;
                            pokemon2.effectiveness = "It was not very effective."; // TYPO HERE!!
                        } else {
                            cout << "It was effective.\n\n"; // TYPO HERE!!
                            pokemon1.hp -= pokemon2.skillDamage3;
                            pokemon2.skillCount3 -= 1;
                            pokemon2.effectiveness = "It was effective."; // TYPO HERE!!
                        }
                        pokemon2.isTurn == false;
                        pokemon1.isTurn == true;
                    }
                } else {
                    cerr << "ERROR! (code 03)";
                }

                if (pokemon1.hp <= 0) {
                    battleOnProgress = false;
                    cout << "===============================================================";
                    cout << "Match Result: " << pokemon2.name << " defeats " << pokemon1.name;
                }

            } else {

                cerr << "ERROR! (code 02)";

            }

        }

    }

    return 0;

}