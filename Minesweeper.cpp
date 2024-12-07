
#include <iostream>
#include <regex>
//#include "Board.h"
#include "Prints.h"
using std::cin, std::cout, std::endl;
using std::string;

Prints print;
enum menuStates {mainMenu, tutorial, newGameMenu, scoreBoard, game, endGame, criticalError};
enum gameTypes {unset, easy, medium, hard, extreme, custom};
menuStates menuState;
gameTypes gameType;

int getInt() {
    string rawInput = "";
    int num = 0;
    std::regex checkNum("\\d+");
    std::regex checkOnlyNum("\\D");
    cin.clear();
    cout << ("Input: ");
    std::getline(cin, rawInput);
    cout << endl;
    cout << endl;

    if (cin.eof()) {
        print.quit();
        exit(0);
    } else {
        while (!std::regex_search(rawInput, checkNum) || std::regex_search(rawInput, checkOnlyNum)) {
//          || rawInput > "2147483647"
            cout << ("Error: Invalid input!") << endl;
            cout << ("Please enter an integer only!") << endl;
            cout << ("Input: ");
            std::getline(cin, rawInput);
            cout << endl;
            cout << endl;
        }
        //cout << rawInput << endl;
        num = std::stoi(rawInput);
    }

   return num;
}

menuStates MainMenu() {
    int option = 0;
    print.mainMenu();
    option = getInt();

    while (option < 0 || option > 3) {
        cout << ("Error: Invalid input!") << endl;
        cout << ("Please enter a number between 0 and 3") << endl;
        cout << ("") << endl;
        option = getInt();
    }

    switch (option) {
        case 0:
            return endGame;
        case 1:
            return tutorial;
        case 2:
            return newGameMenu;
        case 3:
            return scoreBoard;
        default:
            return criticalError;
    }

}
menuStates Tutorial() {
    print.Tutorial();
    return mainMenu;
}

menuStates NewGameMenu(gameTypes& gameType) {
    int option = 0;
    print.newGameMenu();
    option = getInt();

    while (option < 0 || option > 5) {
        cout << ("Error: Invalid input!") << endl;
        cout << ("Please enter a number between 0 and 5") << endl;
        cout << ("") << endl;
        option = getInt();
    }

    switch (option) {
        case 0:
            return mainMenu;
        case 1:
            gameType = easy;
            return game;
        case 2:
            gameType = medium;
            return game;
        case 3:
            gameType = hard;
            return game;
        case 4:
            gameType = extreme;
            return game;
        case 5:
            gameType = custom;
            return game;
        default:
            return criticalError;
    }
}

menuStates ScoreBoard() {
    cout << "Welcome to the Scoreboard" << endl;
    cout << "to be continued..." << endl;
    cout << ("") << endl;
    return mainMenu;
    //print the board
    /*
    "| Level details            | Time taken | Date      | Time (begin) |"
    "| ------------------------ | ---------- | --------- | ------------ |"
    "| Extreme                  | 15m 20s    | 02-Apr-24 | 23:40        |"
    "| Custom (27x27, 23 mines) | 13m 37s    | 03-Apr-24 | 00:01        |"
    */
}

menuStates PlayGame() {
    cout << "Playing game" << endl;
    cout << "Finished game" << endl;
    //code
    return mainMenu;
}


//enum states {mainMenu, tutorial, newGameMenu, scoreBoard, game, exit, criticalError};
//enum gameTypes {unset, easy, medium, hard, extreme, custom};

int main() {
    bool shouldExit = false;
    print.greeting();
    menuState = mainMenu;
    gameType = unset;

    while (!shouldExit) {
        switch (menuState) {
            case mainMenu:
                menuState = MainMenu();
                break;
            case tutorial:
                menuState = Tutorial();
                break;
            case newGameMenu:
                menuState = NewGameMenu(gameType);
                break;
            case scoreBoard:
                menuState = ScoreBoard();
                break;
            case game:
                menuState = PlayGame();
                break;
            case endGame:
                shouldExit = true;
                break;
            default:
                print.criticalError();
                exit(1);
        }
    }
cout << "finished" << endl;
return 0;
}

