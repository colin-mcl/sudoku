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
     if (solve(0, 0))
        board_p->printBoard();
    else
        std::cout << "Puzzle cannot be solved!\n";
     
 }
 
 bool Puzzle::solve(int row, int col) {
     if (allFound())
        return true;
     else if (col > 8)
        return false;
     else if (row > 8) {
         return solve(0, col + 1);
     }
     else if (board_p->get(row, col) != 0) {
         return solve(row + 1, col);
     }
     else {
         for (short i = 1; i <= 9; i++) {
             if (canPlace(row, col, i)) {
                 place(row, col, i);
                 if (solve(row + 1, col))
                    return true;
                 else
                     clear(row, col, i);
             }
         }
     }
     
     return false;
 }
 
 bool Puzzle::allFound() {
     for (int i = 0; i < 9; i++) {
          if (rows[i] != 511 || cols[i] != 511 || squares[i] != 511)
            return false;
     }
     
     return true;
 }
 
 void Puzzle::clear(int row, int col, short val) {
     board_p->insert(row, col, 0);
     rows[row] = clearFound(rows[row], val);
     cols[col] = clearFound(cols[col], val);
     
     int squarePos = ((row / 3) * 3) + (col / 3);
     squares[squarePos] = clearFound(squares[squarePos], val);
 }
 
 void Puzzle::place(int row, int col, short val) {
     board_p->insert(row, col, val);
     rows[row] = setFound(rows[row], val);
     cols[col] = setFound(cols[col], val);
     
     int squarePos = ((row / 3) * 3) + (col / 3);
     squares[squarePos] = setFound(squares[squarePos], val);
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
 
 int Puzzle::clearFound(int found, short val) {
     int mask = 1;
     mask = mask << (val - 1);
     mask = ~mask;
     return found & mask; 
 }
 //returns true if the value can be placed at position (row, col) in the board
 bool Puzzle::canPlace(int row, int col, short val) {
     int squarePos = ((row / 3) * 3) + (col / 3);
     
     //if the number is not found in the row, column and square, return true
     return not (numFound(rows[row], val) || numFound(cols[col], val) ||
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