#include <iostream>
#include <fstream>
#include "Board.h"
#include "Puzzle.h"

int main(int argc, char *argv[]) {
    
    std::ifstream input(argv[1]);
    
    Board board(input);
    Puzzle puzzle(&board);
    puzzle.solve();
    
    input.close();
    return 0;
}