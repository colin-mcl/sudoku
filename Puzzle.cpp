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
     
    initVals();
 }
 
 void Puzzle::solve() {

     board_p->printBoard();
     
     for (int i = 0; i < 9; i++) {
         for (int j = 1; j <= 9; j++) {
             if (numFound(squares[i], j))
                std::cout << j << " in square " << i << "\n";
         }
     }
 }
 
 void Puzzle::initVals() {
     for (int i = 0; i < 9; i++) {
         for (int j = 0; j < 9; j++) {
             short val = board_p->get(i, j);
             
             if (val != 0) {
                 //set num found in the row, column, and square
                 rows[i] = setFound(rows[i], val);
                 cols[j] = setFound(cols[j], val);
                 
                 int squarePos = ((i / 3) * 3) + (j / 3);
                 squares[squarePos] = setFound(squares[squarePos], val);
             }
             
         }
     }
 }
 
 int Puzzle::setFound(int found, short val) {
     int mask = 1;
     mask = mask << (val - 1);
     
     found = found | mask;
     return found;
 }
 
 //returns true if the value can be placed at position (row, col) in the board
 bool Puzzle::canPlace(short val, int row, int col) {
     int squarePos = ((row / 3) * 3) + (col / 3);
     
     //if the number is not found in the row, column and square, return true
     return not (numFound(rows[row], val) && numFound(cols[col], val) &&
            numFound(squares[squarePos], val));
 }
 
 bool Puzzle::numFound(int found, short val) {
     int mask = 1;
     mask = mask << (val - 1);
     
     mask = mask & found;
     
     if (mask == 0)
        return false;
    else
        return true;
 }