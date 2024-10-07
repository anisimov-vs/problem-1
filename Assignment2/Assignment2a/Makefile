CXX = g++
CXXFLAGS = -std=c++14

all: main

main: main.o reverse.o
	$(CXX) $(CXXFLAGS) -o main main.o reverse.o

main.o: main.cpp reverse.h
	$(CXX) $(CXXFLAGS) -c main.cpp

reverse.o: reverse.cpp reverse.h
	$(CXX) $(CXXFLAGS) -c reverse.cpp

run: main
	./main
	
clean:
	rm -f *.o out_* main
