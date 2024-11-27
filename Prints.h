#ifndef PRINTS_H
#define PRINTS_H
using std::cout, std::endl;
class Prints {

    public:
// printing width = 50
        void greeting() {
            cout << ("Welcome to Terminal Minesweeer!") << endl;
            cout << ("") << endl;
        }
        void startMenu() {
            cout << ("Main Menu") << endl;
            cout << ("-------------------------------") << endl;
            cout << ("For each menu, simply enter the option number which you would like to choose.") << endl;
            cout << ("1. Tutorial") << endl;
            cout << ("2. New Game") << endl;
            cout << ("3. Score Board") << endl;
            cout << ("0. Quit") << endl;
            cout << ("") << endl;
        }

        void Tutorial() {
            cout << ("Tutorial") << endl;
            cout << ("-------------------------------") << endl;
            cout << ("Welcome to the tutorial!") << endl;
            cout << ("to be continued...") << endl;
            cout << ("") << endl;
        }

        void newGameMenu() {
            cout << ("New Game") << endl;
            cout << ("-------------------------------") << endl;
            cout << ("Choose a difficultly:") << endl;
            cout << ("1. Easy    (10x10,  10 mines)") << endl;
            cout << ("2, Medium  (15x15,  45 mines)") << endl;
            cout << ("3. Hard    (25x25, 125 mines)") << endl;
            cout << ("4. Extreme (30x30, 450 mines)") << endl;
            cout << ("5. Custom") << endl;
            cout << ("0. Back") << endl;
            cout << ("") << endl;
        }
        void scoreBoard() {
            cout << ("Score Board") << endl;
            cout << ("-------------------------------") << endl;
            cout << ("Top Ten Past Played Games") << endl;
            cout << ("to be continued...") << endl;
            cout << ("") << endl;
        }

        void quitMenu() {
            cout << ("Exit triggered. Exiting now.") << endl;
            cout << ("") << endl;
        }
}

#endif





