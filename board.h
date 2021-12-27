/* board.h
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
 
 class board{
 public:
     board();
     // board(std::istream &input);
     // void printBoard();
     
 };
 
 #endif