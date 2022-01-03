/* Puzzle.h
 * By Colin Mclaughlin
 * January 2022
 *
 *
 * The interface for a Puzzle object. A puzzle represents a Sudoku Puzzle using
 * a board object. It contains a single constructor using a pointer to a board,
 * and the public function solve(), which attempts to solve the sudoku puzzle.
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
     Board *board_p; // a pointer to the sudoku board of the puzzle
     
     /* These arrays use bit manipulation to keep track of the numbers that
      * have been placed in each row, column, and square. The first 9 bits of
      * each int in each array track whether a number from 1-9 has been found
      * (1) or not (0). They are used in the backtracking algorithm to
      * determine whether a number can be placed in a certain position or not.
      *
      *
      * e.g. if the numbers 1, 2, 5, and 9 have been placed in row 0 then the first
      *     9 bits of rows[0] look like this
      *     1 0 0 0 1 0 0 1 1
      */
     int rows[9];
     int cols[9];
     int squares[9];
     
     /* solve: a wrapper function for the public solve() function
      *
      * Input: the row and column of the sudoku puzzle to solve
      * Output: returns true if the puzzle can be solved, false otherwise
      */
     bool solve(int row, int col);
     
     /* canPlace: determines whether val (1-9) can be placed at position
      *           (row, col) in the sudoku grid
      *
      * Input: two ints from 0-8 for the position to place, a number from 1-9
      *        to place
      * Output: uses the found arrays to determine if val is already present
      *         in the row, column, or square. Returns true if val can be
      *         placed at (row, col) and false otherwise
      */
     bool canPlace(int row, int col, short val);
     
     /* numFound: a bit manipulation function that determines whether a number
      *           from 1-9 has been found in a row, column, or square using the
      *           tracking arrays.
      *
      * Input: the found tracker (value from rows, cols, or squares) to search
      *        from and the value (1-9) to check
      * Output: returns true if val has been found as tracked by int found, and
      *         false otherwise
      */
     bool numFound(int found, short val);
     
     /* setFound: a bit manipulation function that marks short val as found in
      *           int found
      *
      * Input: the found nums tracking int and the val (1-9) to mark
      * Output: returns a new found tracker with the bit corresponding to val
      *         set to 1
      */
     int setFound(int found, short val);
     
     /* clearFound: a bit manipulation function that marks short val as not
      *             found in int found
      *
      * Input: the found nums tracking int and the val (1-9) to clear
      * Output: returns a new found tracker with the bit corresponding to val
      *         set to 0
      */
     int clearFound(int found, short val);
     
     /* allFound: checks if numbers 1-9 are marked as found in all positions
      *           of arrays rows, cols, and squares (i.e. all sudoku squares
      *            have been filled)
      *
      * Input: none
      * Output: returns true if bits 0-8 in all members of rows, cols, and
      *         squares are set (i.e. the number == 511)
      */
     bool allFound();
     
     //initializes all the found numbers by iterating over the entire sudoku
     //board
     void initVals();
     
     /* place: place a number on the sudoku board and mark it as found in the
      *        corresponding arrays
      *
      * Input: the row and column at which to place val (1-9)
      * Output: none, after running the sudoku board will have val at position
      *         (row, col) and the corresponding values in rows, cols, and
      *         squares will have val marked as found
      */
     void place(int row, int col, short val);
     
     /* clear: clear val from the the sudoku board at position row, col
      *
      * Input: the row and column at which to clear val (1-9)
      * Output: none, after running the sudoku board will have a 0 at position
      *         (row, col) and the corresponding values in rows, cols and
      *         squares will have marked val as not found
      */
     void clear(int row, int col, short val);

 };
 
 
 
 #endif