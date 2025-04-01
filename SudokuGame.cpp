#include "SudokuGame.h"
#include <iostream>
#include <string>

int SudokuGame::printMenu()
{
    std::cout <<    
        "1) Enter a move\n"
        "2) Solve automatically\n"  <<
        "3) Load puzzle from file " << 
        "4) Save current puzzle to file 5) Exit \n" <<
        "Choice:" 
        << std::endl;
        int choice;
        std::cin >> choice;

        if (choice < 1 || choice > 5)
        {
            std::cout << "Invalid choice. Please try again." << std::endl;
            choice = printMenu();
        }
    return choice;
}