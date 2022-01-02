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
     
     bool solve(int row, int col);
     
     bool canPlace(int row, int col, short val);
     bool numFound(int found, short val);
     int setFound(int found, short val);
     int clearFound(int found, short val);
     bool allFound();

     void initVals();
     void place(int row, int col, short val);
     void clear(int row, int col, short val);

 };
 
 
 
 #endif