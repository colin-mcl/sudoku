/* Puzzle.h
 * By Colin Mclaughlin
 * January 2022
 *
 *
 * TODO: write documentation
 */
 
 #ifndef PUZZLE_H
 #define PUZZLE_H
 
 #include "Board.h"
 #include <iostream>
 
 class Puzzle{
 public:
     Puzzle(Board *original);
     void solve();
 private:
     Board *board_p;
     int rows[9];
     int cols[9];
     int squares[9];
 };
 
 
 
 #endif