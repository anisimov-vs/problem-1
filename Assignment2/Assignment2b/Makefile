CXX = g++
CXXFLAGS = -std=c++17

all: calculator

calculator: main.o calculator.o
	$(CXX) $(CXXFLAGS) -o calculator main.o calculator.o

main.o: main.cpp calculator.h
	$(CXX) $(CXXFLAGS) -c main.cpp

calculator.o: calculator.cpp calculator.h
	$(CXX) $(CXXFLAGS) -c calculator.cpp

run: calculator
	./calculator

clean:
	rm -f *.o calculator

