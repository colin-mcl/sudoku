CXX = g++
CXXFLAGS = -g3 -Wall -Wextra

sudoku: Board.o driver.o Puzzle.o
	$(CXX) $(CXXFLAGS) $^ -o $@
	
Board.o: Board.cpp Board.h
	$(CXX) $(CXXFLAGS) -o Board.o -c Board.cpp

driver.o: driver.cpp Board.h
	$(CXX) $(CXXFLAGS) -o driver.o -c driver.cpp

Puzzle.o: Puzzle.cpp Puzzle.h
	$(CXX) $(CXXFLAGS) -o Puzzle.o -c Puzzle.cpp

clean:
	rm -f *.o
