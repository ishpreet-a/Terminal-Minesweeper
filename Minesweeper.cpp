
#include <iostream>
#include <regex>
//#include "Board.h"
//#include "Prints.h"
using std::cin, std::cout, std::endl;
using std::string;

int getInt() {
    string rawInput = "";
    int num = 0;
    std::regex checkNum("\\d+");
    std::regex checkOnlyNum("\\D");
    cin.clear();
    std::getline(cin, rawInput);

    if (cin.eof()) {
        cout << "Ending program" << endl;
        exit(0);
    } else {
        while (!std::regex_search(rawInput, checkNum) || std::regex_search(rawInput, checkOnlyNum)) {
//          || rawInput > "2147483647"
            cout << "Error, please enter an integer only!" << endl;
            std::getline(cin, rawInput);
        }
        cout << rawInput << endl;
        num = std::stoi(rawInput);
    }

   return num;
}

int main() {
    cout << "starting...\n";
    int mainChoice = 0;
    //int subChoice = 0;
    //while (true) {
    for (int i=0; i<5; i++) {
        mainChoice = getInt();
        cout << '-' << mainChoice << endl;

    }
    cout << "ended successfully\n";
return 0;
}

