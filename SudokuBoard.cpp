#include "SudokuBoard.h"
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <ctime>


 SudokuBoard::SudokuBoard() : board(9, std::vector<int>(9, 0)), lockedCells()
 {
 }

 SudokuBoard::SudokuBoard(std::vector<std::vector<int>> board) : board(board), lockedCells()
 {
 }

 SudokuBoard::~SudokuBoard()
 {

 }
 
 void SudokuBoard::printBoard() {

   for (int i = 0; i < BOARD_SIZE; i++)
     {
      std::cout << "------------------------------------------" << std::endl;
      for (int j = 0; j < BOARD_SIZE; j++)
      {
          
            if (board[i][j] == 0) {
                std::cout << " . ";
            } else {
                std::cout << " " << board[i][j] << " ";
            }
            if ((j + 1) % 3 == 0) {
                std::cout << "   | ";
            }
        }
      std::cout << std::endl;
   }
   std::cout << "------------------------------------------" << std::endl;

 }

 bool SudokuBoard::isSolved()
 {
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
                if (board[i][j] == 0)
                {
                    return false;
                }
        }
    }
     return true;
 }

 bool SudokuBoard::isValid(int row, int col)
 {


   return isRowValid(row) && isColValid(col) && isBoxValid(row, col);
 }

 bool SudokuBoard::loadBoard(std::string filename)
 {
   // TODO: Implement this function
   return false;
}

bool SudokuBoard::saveBoard(std::string filename)
{
    // TODO: Implement this function
     return false;
 }

 bool SudokuBoard::setCell(int row, int col, int value)
 {
    if (std::find(lockedCells.begin(), lockedCells.end(), std::make_pair(row, col)) != lockedCells.end()) {
        return false;
    }
    if (board[row][col] != 0) {
        return false;
    }
    if (isMoveValid(row, col, value)) {
        board[row][col] = value;
        return true;
    }

    return false;
 }

 bool SudokuBoard::isColValid(int col)
 {
   std::set<int> values;
     for (int i = 0; i < BOARD_SIZE; i++)
     {
        if (board[i][col] == 0) {
            continue;
        }
         if (!values.insert(board[i][col]).second) {
            // std::cout << "Invalid col move. Please try again." << std::endl;
               return false;
         }
     }

     return true;
 }

 bool SudokuBoard::isBoxValid(int row, int col)
 {
   std::pair box = {row / 3, col / 3}; // {0, 0} for top-left box
     std::set<int> values;

     for (int i = box.first * 3; i < box.first * 3 + 3; i++)
     {
         for (int j = box.second * 3; j < box.second * 3 + 3; j++)
         {
            if (board[i][j] == 0) {
                continue;
            }
             if (!values.insert(board[i][j]).second) {
                // std::cout << "Invalid box move. Please try again." << std::endl;

                   return false;
             }
         }
     }
     return true;
     
 }

 bool SudokuBoard::isMoveValid(int row, int col, int value)
 {
    int oldValue = board[row][col];
    board[row][col] = value;
    bool res = isValid(row, col);
    board[row][col] = oldValue;
    return res;
 }

 void SudokuBoard::reset()
 {
    
    // std::srand(static_cast<unsigned>(std::time(0)));
    for (int i = 0; i < BOARD_SIZE; i++)
      {
            for (int j = 0; j < BOARD_SIZE; j++)
            {
                 board[i][j] = 0;
            }
      }

      int num = rand() % 10 + 15;
    
      for (int i = 0; i < num; i++)
      {
        int row = rand() % BOARD_SIZE;
        int col = rand() % BOARD_SIZE;
        int value = rand() % BOARD_SIZE + 1;
        if (isMoveValid(row, col, value))
        {
            board[row][col] = value;
            lockedCells.push_back({row, col});
        }
      }
      
 }

 /**
  * @brief tries to solve sudoku board using backtracking
  *
  * @return true if solvable
  * @return false otherwise
  */
 bool SudokuBoard::solve()
 {
   for (int i = 0; i < BOARD_SIZE; i++)
     {
         for (int j = 0; j < BOARD_SIZE; j++)
         {
             if (board[i][j] == 0)
             {
                 for (int value = 1; value <= BOARD_SIZE; value++)
                 {
                     if (isMoveValid(i, j, value))
                     {
                         board[i][j] = value;
                         if (solve())
                         {
                             return true;
                         }
                         board[i][j] = 0;
                     }
                 }
                 return false;
             }
         }
     }
     return true;
     
 }

 bool SudokuBoard::isRowValid(int row)
 {
   std::set<int> values;
     for (int i = 0; i < BOARD_SIZE; i++)
     {
        if (board[row][i] == 0) {
            continue;
        }
         if (!values.insert(board[row][i]).second) {
            // std::cout << "Invalid row move. Please try again." << std::endl;
               return false;
         }
     }

     return true;
 }


 

