#include "SudokuGame.h"
#include <iostream>
#include <string>

SudokuGame::SudokuGame()
{
    board.reset();
}




int SudokuGame::printMenu()
{
    std::cout <<    
        "1) Enter a move\n"
        "2) Solve automatically\n"  <<
        "3) Load puzzle from file\n" << 
        "4) Save current puzzle to file 5) Exit \n" <<
        "Choice: ";
        int choice;
        std::cin >> choice;

        if (choice < 1 || choice > 5)
        {
            std::cout << "Invalid choice. Please try again." << std::endl;
            choice = printMenu();
        }
    return choice;
}

void SudokuGame::play()
{
    board.printBoard();
    int choice = printMenu();
    switch (choice)
    {
    case 1:
        std::cout << "Enter row (1-9), column (1-9), and value (1-9): 10 5 2" << std::endl;
        int row, col, value;
        std::cin >> row >> col >> value;
        
        if (row > 9 || row < 1) {
            std::cout << "Row must be between 1 and 9." << std::endl;
            play();
        }
        if (col > 9 || col < 1) {
            std::cout << "Column must be between 1 and 9." << std::endl;
            play();
        }
        if (value > 9 || value < 1) {
            std::cout << "Value must be between 1 and 9." << std::endl;
            play();
        }
        
        if (!board.setCell(row - 1, col - 1, value))
        {
            std::cout << "Invalid move. Please try again." << std::endl;
            play();
        } 
        if (isSolved())
        {
            std::string answer;
            std::cout << "Congratulations! You solved the puzzle." << std::endl;
            std::cout << "wanna play again (y -> yes, n -> no): " << std::endl;
            std::cin >> answer;
            if (answer == "yes" || answer == "y")
            {
                reset();
            } else {
                exit(0);
            }
            
        }
        break;
    
    case 2:
        board.solve();
        if (isSolved())
        {
            std::cout << "Puzzle solved!" << std::endl;
            board.printBoard();
            exit(0);
        }
        else
        {
            std::cout << "Puzzle is not solvable." << std::endl;
        }
        break;
    
    case 3:
        std::cout << "Loading" << std::endl;
        break;
        
    case 4:
        std::cout << "Saving" << std::endl;
        break;
    
    case 5:
        exit(0);
        break;
    default:
        break;
    }
}

void SudokuGame::reset()
{
    board.reset();
}

bool SudokuGame::isSolved()
{
    return board.isSolved();
}
