CC = g++
OFLAGS = -c -Wall -pedantic -Werror -std=c++11
CFLAGS = -Wall -ansi -pedantic -Werror
LFLAGS = -lsfml-system

all: ED

ED: main.o ED.o
	$(CC) main.o ED.o $(LFLAGS) -o ED

main.o: main.cpp
	$(CC) $(OFLAGS) main.cpp

ED.o: ED.cpp
	$(CC) $(OFLAGS) ED.cpp

clean:
	\rm *.o  ED