/* Puzzle.cpp
 * By Colin Mclaughlin
 * January 2022
 *
 *
 * TODO: write documentation
 */
 
 #include "Puzzle.h"
 
 Puzzle::Puzzle(Board *original) {
     board_p = original;
     for (int i = 0; i < 9; i++) {
         rows[i] = 0;
         cols[i] = 0;
         squares[i] = 0;
     }
 }
 
 void Puzzle::solve() {
     board_p->printBoard();
 }