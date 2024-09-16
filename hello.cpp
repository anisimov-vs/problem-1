#include <iostream>
#include "hello.h"
#include "stdio.h"

namespace problem_1
{
  void SayHello()
  {
    //Print "Hello, world!" in console
    printf("Hello, world!\n");

    while (true){
      //Create string for input
      std::string input;
      //Read input from console
      getline(std::cin, input);
      //std::cin >> input;
      //Print "Hello, <string>!" in console  
      printf("Hello, %s!\n", input.c_str());
    }
  }
}
