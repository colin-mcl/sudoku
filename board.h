/* Board.h
 * By Colin Mclaughlin
 * December 2021
 *
 * The interface for a sudoku board object. Consists of a 9x9 grid of integers.
 * Blank spots are represented with 0. Can be constructed as a blank grid or
 * from an istream.
 */
 
 #ifndef BOARD_H
 #define BOARD_H
 
 #include <iostream>
 #include <cstdio>
 
 
 /* A Sudoku board
  *
  * Allows getting and inserting integers from 0-9 on a 9x9, zero-indexed
  * array. Has a print function that prints a formatted board.
  */
 class Board{
 public:
     const static int SIZE = 9; //the size of a Sudoku board is 9x9

     Board(); //constructs a blank (all 0s) board
     
     /* Input: expects an input stream to read 81 integers from
      *
      * Purpose: constructs a board object by reading an integer from the 
      *          istream, then placing that integer on the board, starting from
      *          the top left and working row by row.
      */
     Board(std::istream &input);
     

     void printBoard(); //prints a formatted board to stdout 
     
     /* Input: expects two numbers from 0-8 for the row and column at which to 
      *        insert, and a number from 0-9 to insert
      *
      * Purpose: inserts val at position (row, col) in the board
      */
     void insert(short row, short col, short val);
     
     /* Input: expects two numbers from 0-8 for the row and column to retrieve
      *        from the board
      *
      * Purpose: returns the board element at position (row, col)
      */
     short get(short row, short col);

 private:
     short grid[SIZE][SIZE]; // the 9x9 array of shorts used under the hood
     
     void invalid_input(); // prints an error message and exits if an input
                           // not from 0-9 is provided
 };
 
 #endif
 