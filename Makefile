CC = gcc
CFLAGS = -Wall -Werror -std=c11


main: main.cpp
	g++ -std=c++11 main.cpp -o main
clean:
	rm -f *.o main
