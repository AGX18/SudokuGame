#pragma once
/**
 * @brief 
 * Presents console menu, reads/writes user input. 
 * Coordinates SudokuBoard and SudokuSolver.
 * Handles error-checking for moves and file operations
 * 
 */
#include "SudokuBoard.h" 

class SudokuGame {
public:
    SudokuGame();
    // bool load(std::string filename);
    // bool save(std::string filename);
    int printMenu();
    void play();
    void reset();
    bool isSolved();
    void loadBoardFromFile(std::string filename);
    void saveBoard(std::string filename);
private:   
    SudokuBoard board;
};