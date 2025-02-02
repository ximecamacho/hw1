#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr* testList=new ULListStr();
  testList->push_back("hello");
  for(int i=0; i<12; i++){
    testList->push_back("hello_");
  }

  testList->get(3);
  testList->get(10);


  testList->pop_back();
  for(int i=0; i<12; i++){
    testList->pop_back();
  }

  testList->push_front("goodbye");
  for(int i=0; i<12; i++){
    testList->push_front("goodbye_");
  }


  testList->pop_front();
  for(int i=0; i<12; i++){
    testList->pop_front();
  }
  
  


}
