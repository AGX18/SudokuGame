/**
 * @brief 
 * Presents console menu, reads/writes user input. 
 * Coordinates SudokuBoard and SudokuSolver.
 * Handles error-checking for moves and file operations
 * 
 */

 #include <SudokuBoard.h>
 

class SudokuGame {
public:
    SudokuGame();
    bool load(std::string filename);
    bool save(std::string filename);
    int printMenu();
private:   
    SudokuBoard board;

};