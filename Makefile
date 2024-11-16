.default: all

all: clean minesweeper noObj

clean:
	rm -f minesweeper

noObj:
	rm -f *.o

minesweeper: minesweeper.o board.o
	g++ -Wall -Werror -std=c++17 -g -O -o $@ $^

%.o: %.cpp
	g++ -Wall -Werror -std=c++17 -g -O -c $^
