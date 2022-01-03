# sudoku
By Colin Mclaughlin
December 2021

A sudoku solving program using a backtracking algorithm.

## Usage
Compile with 'make' or 'make sudoku'
Usage: './sudoku [filename]'

Optional file should contain a valid Sudoku board in the following format:
- 81 integers from 0-9, representing the spaces of a 9x9 Sudoku grid.
- A 0 represents a blank square in the grid.
- If any numbers from 1-9 are repeated within a row, column, or 3x3 square, the grid is invalid and cannot be solved.

If a filename is not provided a Sudoku grid is expected to be provided on stdin.

## Files
- Board.h:
    The interface for a standalone Sudoku board object.
- Board.cpp:
    Implements a Sudoku board object using a 9x9 array if shorts.
- Puzzle.h:
    The interface for the Sudoku puzzle, containing the public function `solve()`.
- Puzzle.cpp:
    Implements the solvable Sudoku puzzle using a board object, backtracking algorithm, and bitpacking.
- driver.cpp:
    Contains `main()` for the Sudoku solver, which creates a puzzle object and attempts to solve the puzzle.
- README.md:
    This file.
- Makefile:
    Contains make rules to create a 'sudoku' binary executable.
- samples (director):
    Contains sample Sudoku board inputs.

## Algorithm
This Sudoku solver uses a fairly simple backtracking algorithm, along with some bitpacking, to solve the puzzles. Initially, a Sudoku Board object is created from either stdin or an input file. When a Puzzle object is created from this Board, the Puzzle records the integers that are filled in within each row, column, and 3x3 square by using bit manipulation. This works by maintaining three arrays of 9 integers, one array for rows, one for columns, and one for squares. The least significant 9 bits of each integer within the arrays record whether integers 1-9 have been filled in within the respective row, column, or square. For example, if integers 3, 4, and 9 have been filled in on row 0, the first 9 bits of rows[0] look like this:

1 0 0 0 0 1 1 0 0

The algorithm first populates all members of these arrays to track the initially filled in elements. Then it begins backtracking. The backtracking starts at position (0,0) and works its way down a column before moving to the next row. If all found trackers are maxed out, this means all spots have been filled in and the puzzle is solved. Otherwise, the algorithm places the next integer from 1-9 which is not currently present in the row, column, or square, into the open spot. It then recursively checks if this insertion leads to a solution. If it does it prints the board and exits. Otherwise, it removes the just inserted integer and tries the next possible answer. If this does not lead to a solution the program prints that the sudoku cannot be solved and exits.
