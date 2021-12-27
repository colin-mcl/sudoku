CXX = g++
CXXFLAGS = -g3 -Wall -Wextra

sudoku: Board.o driver.o
	$(CXX) $(CXXFLAGS) $^ -o $@
	
Board.o: Board.cpp Board.h
	$(CXX) $(CXXFLAGS) -o Board.o -c Board.cpp

driver.o: driver.cpp Board.h
	$(CXX) $(CXXFLAGS) -o driver.o -c driver.cpp

clean:
	rm -f *.o
