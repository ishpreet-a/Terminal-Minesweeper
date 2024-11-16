#ifndef BOARD_H
#define BOARD_H

#include <cstdlib>
#include "ObjectMan.h"

class Board {
    public:
        Board();
        Board(int, int, int);
        void reveal(int, int);
        bool mark(int, int, bool);

        bool isGameOver() { return gameOver; }
        bool isGameWon() { return gameWon; }
        
    private:
        // Functions
        void init();
        void generate(int, int);
        void calculateRadius(int, int);

        // Variables
        bool isGenerated;
        bool gameOver, gameWon;
        int length, width;
        int totalMines, remainingMines;

        char** boardMask;
        ObjectMan<mine> mines;

}
#endif
