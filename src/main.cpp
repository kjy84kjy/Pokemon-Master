#include <string>
#include <iostream>
using namespace std;



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
        cout << "-";
    }
    cout << "| " << somethingToPrint2;
    for (int i = 0; i < 29 - wordLength2; i++) {
        cout << "-";
    }
    cout << "|\n";
}



// [A02] Advanced Functions

int decision(string atkType, string defType) {
    // Function for deciding effectiveness of attack
    // Return value of this function will in/decrease damage
    if (atkType == "ground") {
        if (defType == "electric" || defType == "fire") {
            return 5;  // super effective
        } else if (defType == "glass") {
            return -3;  // not very effective
        }
    }
    if (atkType == "electric") {
        if (defType == "water") {
            return 5;  // super effective
        } else if (defType == "ground" || defType == "electric" || defType == "glass") {
            return -3;  // not very effective
        }
    }
    if (atkType == "water") {
        if (defType == "ground" || defType == "fire") {
            return 5;  // super effective
        } else if (defType == "water" || defType == "glass") {
            return -3;  // not very effective
        }
    }
    if (atkType == "glass") {
        if (defType == "water") {
            return 5;  // super effective
        } else if (defType == "ground" || defType == "glass" || defType == "fire") {
            return -3;  // not very effective
        }
    }
    if (atkType == "fire") {
        if (defType == "glass") {
            return 5;  // super effective
        } else if (defType == "water" || defType == "fire") {
            return -3;  // not very effective
        }
    }
    return 0;  // effective for all the other cases
}



// [A03] Structs

struct Pokemon {
    string type;
    int hp;
    int skillCount0, skillCount1, skillCount2, skillCount3;
};

Pokemon pokemonInit(Pokemon& object, int type) {

    if (type == 0) {
        // Pikachu
        object.type = "electic";
        object.hp = 35;
        object.skillCount0 = 5;
        object.skillCount1 = 5;
        object.skillCount2 = 5;
        object.skillCount3 = 5;
    } else if (type == 1) {
        // Dratini
        object.type = "water";
        object.hp = 41;
        object.skillCount0 = 10;
        object.skillCount1 = 5;
        object.skillCount2 = 2;
        object.skillCount3 = 1;
    } else if (type == 2) {
        // Eevee
        object.type = "normal";
        object.hp = 55;
        object.skillCount0 = 5;
        object.skillCount1 = 3;
        object.skillCount2 = 3;
        object.skillCount3 = 1;
    } else if (type == 3) {
        // Charmander
        object.type = "fire";
        object.hp = 39;
        object.skillCount0 = 5;
        object.skillCount1 = 5;
        object.skillCount2 = 5;
        object.skillCount3 = 5;
    } else if (type == 4) {
        // Palkia
        object.type = "water";
        object.hp = 90;
        object.skillCount0 = 10;
        object.skillCount1 = 10;
        object.skillCount2 = 10;
        object.skillCount3 = 10;
    }

    return object;

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
        pokemonInit(pokemon1, pokemonName1);
        pokemonInit(pokemon2, pokemonName2);

    }

    return 0;
}