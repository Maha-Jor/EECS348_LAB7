CC = gcc
CFLAGS = -Wall -Werror -std=c11


main: main.cpp
	$(CC) $(CFLAGS) -o main main.cpp

clean:
	rm -f main
