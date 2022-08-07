#PS1a Makefile

CC = g++ 
CFLAGS = -Wall -std=c++11 -Werror -ansi -pedantic 
OBJECTS = test.o FibLFSR.o
BOOST_LIB = -l boost_unit_test_framework

all : ps1a

FibLFSR.o : FibLFSR.cpp FibLFSR.h
	$(CC) -o FibLFSR.o -c FibLFSR.cpp $(CFLAGS)

ps1a : test.o FibLFSR.o
	$(CC) -o ps1a $(OBJECTS) $(CFLAGS) $(BOOST_LIB)

test.o : test.cpp FibLFSR.h
	$(CC) -o test.o -c test.cpp $(CFLAGS)

clean :
	 rm ps1a $(OBJECTS) 

