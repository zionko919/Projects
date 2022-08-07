CC = g++
OFLAGS = -c -Wall -pedantic -Werror -std=c++11
CFLAGS = -Wall -pedantic -Werror -std=c++11
LFLAGS = -lsfml-window -lsfml-graphics -lsfml-system

all: main

main: main.o
	$(CC) main.o $(LFLAGS) -o main

main.o: main.cpp
	$(CC) $(OFLAGS) main.cpp

clean:
	\rm *.o main