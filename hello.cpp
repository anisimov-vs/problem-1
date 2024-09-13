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
      //Create string s
      std::string input;   
      //Resize input (to make it work in scanf)
      input.resize(100);
      //Read s from console
      scanf("%s", &input[0]);
      //Print "Hello, <string>!" in console  
      printf("Hello, %s!\n", input.c_str());
    }
  }
}
