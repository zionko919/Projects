CC = g++
OFLAGS = -c -Wall -pedantic -Werror -std=c++11
CFLAGS = -Wall -ansi -pedantic -Werror
LFLAGS = -lsfml-system -lsfml-graphics -lsfml-audio -lsfml-window

all: KSExtraSim

KSExtraSim: KSExtraSim.o StringSound.o CircularBuffer.o
	$(CC) KSExtraSim.o StringSound.o CircularBuffer.o $(LFLAGS) -o KSExtraSim

KSExtraSim.o: KSExtraSim.cpp
	$(CC) $(OFLAGS) KSExtraSim.cpp

StringSound.o: StringSound.cpp
	$(CC) $(OFLAGS) StringSound.cpp

CircularBuffer.o: CircularBuffer.cpp
	$(CC) $(OFLAGS) CircularBuffer.cpp

clean:
	\rm *.o  KSExtraSim