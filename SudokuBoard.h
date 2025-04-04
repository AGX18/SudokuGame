#pragma once
#include <iostream>
#include <vector>

/**
 * @file SudokuBoard.h
 * @author NAGX
 * @brief 
 * 
 * Stores and manipulates the 9×9 grid.
 * Validates row/column/box constraints.
 * Prints the board.
 * Loads and saves puzzle data to a file.
 * 
 * @version 0.1
 * @date 2025-03-30
 * 
 * @copyright Copyright (c) 2025
 * 
 */

 class SudokuBoard
 {
 private:
   std::vector<std::vector<int>> board;
   const int BOARD_SIZE = 9;
   std::vector<std::pair<int, int>> lockedCells;

 public:
    SudokuBoard();
    ~SudokuBoard();
    void printBoard();
    bool isSolved();
    bool isValid(int row, int col);
    bool loadBoard(std::string filename);
    bool saveBoard(std::string filename);
    bool setCell(int row, int col, int value);
    bool isRowValid(int row);
    bool isColValid(int col);
    bool isBoxValid(int row, int col);
    bool isMoveValid(int row, int col, int value);
    void reset();
    bool solve();
 };
