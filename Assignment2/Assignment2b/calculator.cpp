// Anisimov Vasiliy st129629@student.spbu.ru
// Home Assginment 2b

#include "calculator.h"

#include <iostream>
#include <ostream>
#include <sstream>
#include <string>

class Stack {
  
  private:
    double* stackArray;
    int top;
    int capacity;
    
  public:
    
    Stack(int size) {
      capacity = size;
      stackArray = new double[capacity];
      top = -1;
    }
    
    ~Stack() {
      delete[] stackArray;
    }

    void push(double value) {
      if (top == capacity - 1) {
        std::cerr << "Stack overflow\n";
        return;
      }
      stackArray[++top] = value;
    }

    double pop() {
      if (top == -1) {
        std::cerr << "Stack overflow\n";
        return -1;
      }
      return stackArray[top--];
    }

    bool isEmpty(){
      return top == -1;
    }

    double peek() {
      if (top != -1) return stackArray[top];
      return -1;
    }

    int size() {
      return top + 1;
    }
};

double perform_operation(double (*operation)(double, double), Stack *stack){
  
  if (stack->size() > 1)
     stack->push(operation(stack->pop(), stack->pop()));
  else
    std::cerr << "Stack size < 1\n";
  
  return stack->peek();
}


double addition(double a, double b) {
  return b + a;
}

double substraction(double a, double b) {
  return b - a;
}

double multiplication(double a, double b) {
  //std::cout << a << " " << b << std::endl;
  return b * a;
}

double division(double a, double b) {
  return b / a;
}

namespace assignment_2b {
  
  void Calculator() {
    
    Stack stack(100);
    
    std::string input;
    std::getline(std::cin, input);
    std::istringstream iss(input);
    
    std::string part;
    
    while (iss >> part) {
      switch (part[0]) {
        case '+':
          perform_operation(&addition, &stack);
          continue;
        case '-':
          perform_operation(&substraction, &stack);
          continue;
        case '*':
          perform_operation(&multiplication, &stack);
          continue;
        case '/':
          perform_operation(&division, &stack);
          continue;
        default:
          try {
            stack.push(std::stod(part));
          }
          catch(const char* error_message) {
            std::cout << error_message << std::endl;
          }
      }  
    }
    std::cout << stack.peek() << std::endl;
  }
}

