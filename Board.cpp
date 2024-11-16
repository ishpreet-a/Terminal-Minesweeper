#include "Board.h"

Board::Board() {}
Board::Board(int length, int width, int totalMines)
    : length(length), width(width), totalMines(totalMines), isGenerated(false)
{}

void Board::init() {
    isGenerated = false;
    gameOver = false;
    gameWon = false;
    remainingMines = totalMines;

    boardMask = new char*[width];
    for (int i=0; i<width; i++) {
        boardMask = new char[length];
        for (int i=0; i<length; i++) {
            boardMask[i][j] = '.';
        }
    }
}


void generate(int x, int y) {
    init();
    int placedMines = 0;
    int t=0; l=0; w=0;

    while (placedMines < totalMines) {
        t = rand() % (length*width);
        l = t % length;
        w = t / length;

        if (l != x && w != y && !mines.objectExists(mine(l, w))){
            mines.addObject(l, w);
            placedMines++;
        }
    }
}

void Board::reveal(int x, int y) {
    if (!isGenerated) {
        generate(x, y);
        isGenerated = true;
    }

    if (objectExists(mine(x, y))) {
        gameOver = true;
        gameWon = false;
    } else {
        calculateRadius(x, y);
    }
}

bool Board::mark(int x, int y, bool marking = true) {
    bool result = false;
    if (x < length && y < width) {
        if (marking && boardMask[x][y] == '.') {
            boardMask[x][y] = 'x';
            result = true;
        } else if (!marking && boardMask[x][y] == 'x') {
            boardMask[x][y] = '.';
            result = true;
        }
    }
    return result;
}

void Board::calculateRadius(int x, int y) {
    int counter = 0;
    for (int i=x-1; i<=x+1; i++) {
        for (int j=y-1; j<=y+1; j++) {
            if (mines.objectExists(mine(i, j))) {
                counter++;
            }
        }
    }
    boardMask[x][y] = counter + '0';
}

