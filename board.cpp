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

void Board::printBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("[%hi] ", grid[i][j]);
        }
        printf("\n");
    }
}