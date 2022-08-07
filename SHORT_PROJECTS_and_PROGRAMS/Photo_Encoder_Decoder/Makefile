CC= g++
CFLAGS = -std=c++11 -c -g -Og -Wall -Werror -pedantic
SFMLFLAGS= -lsfml-graphics -lsfml-window -lsfml-system

# Make exec
all:	PhotoMagic

# executable
PhotoMagic:	Phoc.o LFSR.o
	$(CC) PhotoMagic.o LFSR.o -o PhotoMagic $(SFMLFLAGS)

# object files
PhotoMagic.o:	main.cpp LFSR.hpp
	$(CC) -c main.cpp LFSR.hpp $(CFLAGS)

LFSR.o:		LFSR.cpp LFSR.hpp
	$(CC) -c LFSR.cpp $(CFLAGS)

# Cleanup
clean:
	rm *.o
	rm PhotoMagic
	rm *.gch
