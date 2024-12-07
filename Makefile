.default: all

all: MainOnly

clean: NoObj
	rm -f Minesweeper

NoObj:
	rm -f *.o

MainOnly: Minesweeper.o
	g++ -Wall -Werror -std=c++17 -g -O -o $@ $^

#Minesweeper: Minesweeper.o Board.o
#	g++ -Wall -Werror -std=c++17 -g -O -o $@ $^

%.o: %.cpp
	g++ -Wall -Werror -std=c++17 -g -O -c $^
