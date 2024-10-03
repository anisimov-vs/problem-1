CXX = g++
CXXFLAGS = -std=c++17

all: hello

hello: main.o hello.o
	$(CXX) $(CXXFLAGS) -o hello main.o hello.o

main.o: main.cpp hello.h
	$(CXX) $(CXXFLAGS) -c main.cpp

hello.o: hello.cpp hello.h
	$(CXX) $(CXXFLAGS) -c hello.cpp

clean:
	rm -f *.o hello
