#include <iostream>
#include <fstream>
#include "Board.h"
#include "Puzzle.h"

int main(int argc, char *argv[]) {
    
    Board board;
    Puzzle puzzle(&board);
    puzzle.solve();
    
    return 0;
}