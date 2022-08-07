CC = g++
OFLAGS = -c -Wall -pedantic -Werror -std=c++11
CFLAGS = -Wall -ansi -pedantic -Werror
LFLAGS = -lsfml-system -lsfml-graphics -lsfml-audio -lsfml-window

all: KSGuitarSim

KSGuitarSim: KSGuitarSim.o StringSound.o CircularBuffer.o
	$(CC) KSGuitarSim.o StringSound.o CircularBuffer.o $(LFLAGS) -o KSGuitarSim

KSGuitarSim.o: KSGuitarSim.cpp
	$(CC) $(OFLAGS) KSGuitarSim.cpp

StringSound.o: StringSound.cpp
	$(CC) $(OFLAGS) StringSound.cpp

CircularBuffer.o: CircularBuffer.cpp
	$(CC) $(OFLAGS) CircularBuffer.cpp

clean:
	\rm *.o  KSGuitarSim