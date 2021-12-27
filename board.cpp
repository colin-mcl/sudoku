/* board.cpp
 * By Colin Mclaughlin
 * December 2021
 *
 * The implementation of a board object.
 */
 
 #include "Board.h"
 
 Board::Board() {
     for (int i = 0; i < SIZE; i++) {
         for (int j = 0; j < SIZE; j++) {
             grid[i][j] = 0;
         }
     }
 }
 
 Board::Board(std::istream &input) {
    char digit;
     for (int i = 0; i < SIZE; i++) {
         for (int j = 0; j < SIZE; j++) {
             
             if (input.eof())
                 invalid_input();
             else {
                 input >> digit;
                 digit -= '0';
                 if (digit > 9 || digit < 0)
                    invalid_input();
                 grid[i][j] = digit;
             }
         }
     }
 }


void Board::printBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("[%hi] ", grid[i][j]);
        }
        printf("\n");
    }
}

void Board::invalid_input() {
    std::cerr << "ERROR: insufficient input values provided\n"
                        "Please provide a 9x9 grid of integers from 0-9.\n";
    exit(EXIT_FAILURE);
}

