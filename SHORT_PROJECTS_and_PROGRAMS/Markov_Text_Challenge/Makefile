CC = g++
CFLAGS = -g -Wall -Werror -pedantic -std=c++11
OBJ = TextGenerator.o MModel.o
TESTOBJ = test.o MModel.o
DEPS = 
LIBS = 
BOOST = -l boost_unit_test_framework

all: TextGenerator test

TextGenerator: $(OBJ)
	$(CC) $(CFLAGS) -o TextGenerator $(OBJ) 
test: $(TESTOBJ)
	$(CC) $(CFLAGS) -o test $(TESTOBJ) $(BOOST)

TextGenerator.o: TextGenerator.cpp
	$(CC) $(CFLAGS) -c TextGenerator.cpp -o TextGenerator.o
MModel.o: MModel.cpp
	$(CC) $(CFLAGS) -c MModel.cpp -o MModel.o
test.o: test.cpp
	$(CC) $(CFLAGS) -c test.cpp -o test.o

clean:
	rm *.o
	rm TextGenerator
	rm test

