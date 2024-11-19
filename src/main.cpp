#include <string>
#include <iostream>
using namespace std;



// [A01] Basic Functions

void printSep() {
    // Function for printing seperator with a new line
    cout << "+-------------------------------------------------------------+\n";
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

void something() {
    // Something
}



// [A03] Classes

class Pokemon {
    //
};




// [A04] Main Function

int main() {
    // Something here
    return 0;
}