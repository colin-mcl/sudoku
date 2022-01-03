#include <iostream>
#include <fstream>
#include "Board.h"
#include "Puzzle.h"

void usage_error();
void invalid_file(std::string filename);
void run(std::istream &input);

int main(int argc, char *argv[]) {
    
    if (argc > 2) 
        usage_error();
    
    
    if (argc == 1)
        run(std::cin);
    else {
        std::ifstream infile(argv[1]);
        if (infile.fail())
            invalid_file(argv[1]);
        
        run(infile);
        infile.close();
    }
    
    return 0;
}

void usage_error() {
    std::cerr << "Usage error: ./sudoku [filename]\n";
    exit(EXIT_FAILURE);
}

void invalid_file(std::string filename) {
    std::cerr << "Failed to open " << filename << "\n";
    exit(EXIT_FAILURE);
}

void run(std::istream &input) {
    Board board(input);
    Puzzle puzzle(&board);
    puzzle.solve();
}