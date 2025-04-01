#include "SudokuBoard.h"
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>


 SudokuBoard::SudokuBoard() : board(9, std::vector<int>(9, 0))
 {
 }
 
 SudokuBoard::~SudokuBoard()
 {

 }
 
 void SudokuBoard::printBoard() {

   for (int i = 0; i < BOARD_SIZE; i++)
     {
         for (int j = 0; j < BOARD_SIZE; j++)
         {
            if (board[i][j] == 0) {
                  std::cout << " . ";
            } else {
               std::cout << " " << board[i][j] << " ";
            }
         }
         std::cout << std::endl;
     }

 }

 bool SudokuBoard::loadBoard(std::string filename)
 {
   
     return false;
 }

 bool SudokuBoard::saveBoard(std::string filename)
 {

     return false;
 }

 bool SudokuBoard::isColValid(int col)
 {
   std::set<int> values;
     for (int i = 0; i < BOARD_SIZE; i++)
     {
         if (!values.insert(board[i][col]).second) {
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
             if (!values.insert(board[i][j]).second) {
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
         if (!values.insert(board[row][i]).second) {
               return false;
         }
     }

     return true;
 }


 

