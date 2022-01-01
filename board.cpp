/* Board.cpp
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
    printf("-------------------------\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (j == 0) {
                printf("| ");
            }
            
            printf("%hi ", grid[i][j]);
            
            if ((j + 1) % 3 == 0) {
                printf("| ");
            }
        }
        printf("\n");
        if ((i + 1) % 3 == 0) {
            printf("-------------------------\n");
        }
    }
}

void Board::invalid_input() {
    std::cerr << "ERROR: insufficient input values provided\n"
                        "Please provide a 9x9 grid of integers from 0-9.\n";
    exit(EXIT_FAILURE);
}

void Board::insert(short row, short col, short val) {
    if (row < 0 || row > SIZE - 1 || col < 0 || col > SIZE - 1) {
        std::cerr << "ERROR: attempted to insert out of bounds [0,8]\n";
        return;
    } else if (val < 0 || val > 9) {
        std::cerr << "ERROR: values must be in range [0,9]\n";
        return;
    } else {
        grid[row][col] = val;
    }
}

short Board::get(short row, short col) {
    if (row < 0 || row > SIZE - 1 || col < 0 || col > SIZE - 1) {
        std::cerr << "ERROR: attempted to retrieve from out of bounds [0,8]\n";
        return -1;
    }
    else  {
        return grid[row][col];
    }
}
