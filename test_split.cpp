/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"

int main(int argc, char* argv[])
{
  
  Node* head=new Node(1,nullptr);
  Node* currTail=head;
  for(int i=2; i<10; i++){
    Node* newNode= new Node(i,nullptr);
    currTail->next=newNode;
    currTail=newNode;
  }
  Node* odds=nullptr;
  Node* evens=nullptr;

  split(head,odds,evens);

  Node* currElement=odds;
  while (currElement!=nullptr){
    Node*nextElement=currElement->next;
    delete currElement;
    currElement= nextElement;
  }

  Node* currElement2=evens;
  while (currElement2!=nullptr){
    Node*nextElement2=currElement2->next;
    delete currElement2;
    currElement2= nextElement2;
  }

}
