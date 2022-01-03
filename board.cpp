/* Board.cpp
 * By Colin Mclaughlin
 * December 2021
 *
 * The implementation of a board object.
 */
 
 #include "Board.h"
 // default constructor
 // creates a blank board object (all 0s)
 Board::Board() {
     for (int i = 0; i < SIZE; i++) {
         for (int j = 0; j < SIZE; j++) {
             grid[i][j] = 0;
         }
     }
 }
 
 /* istream constructor
  * 
  * expects an istream object which will read 81 integers from 0-9 to fill in
  * the board
  *
  * starts from (0,0) and fills in row by row
  */
 Board::Board(std::istream &input) {
    char digit;
     for (int i = 0; i < SIZE; i++) {
         for (int j = 0; j < SIZE; j++) {
             
             if (input.eof())
                 invalid_input(); //if 81 ints are not provided
             else {
                 input >> digit;
                 digit -= '0';
                 if (digit > 9 || digit < 0) //if the input is not 0-9
                    invalid_input();
                 grid[i][j] = digit;
             }
         }
     }
 }
 

//prints the sudoku board
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

//catches invalid inputs and exits
void Board::invalid_input() {
    std::cerr << "ERROR: insufficient input values provided\n"
                        "Please provide a 9x9 grid of integers from 0-9.\n";
    exit(EXIT_FAILURE);
}

/* Input: expects two numbers from 0-8 for the row and column at which to 
 *        insert, and a number from 0-9 to insert
 *
 * Purpose: inserts val at position (row, col) in the board
 */
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

/* Input: expects two numbers from 0-8 for the row and column to retrieve
 *        from the board
 *
 * Purpose: returns the board element at position (row, col)
 */
short Board::get(short row, short col) {
    if (row < 0 || row > SIZE - 1 || col < 0 || col > SIZE - 1) {
        std::cerr << "ERROR: attempted to retrieve from out of bounds [0,8]\n";
        return -1;
    }
    else  {
        return grid[row][col];
    }
}
