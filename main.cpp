#include  "SudokuGame.h"

int main()
{
    SudokuGame game;
    while (!game.isSolved()) {
        game.play();
    }
    return 0;
}