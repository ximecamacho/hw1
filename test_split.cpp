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
  Node* curr=head;
  for(int i=2; i<10; i++){
    Node* newNode= new Node(i,nullptr);
    curr->next=newNode;
    curr=newNode;
  }
  Node* odds=nullptr;
  Node* evens=nullptr;

  split(head,odds,evens);

  Node* curr_=odds;
  while (curr_!=nullptr){
    Node*next=curr_->next;
    delete curr_;
    curr_= next;
  }

  Node* curr_2=evens;
  while (curr_2!=nullptr){
    Node*next2=curr_2->next;
    delete curr_2;
    curr_2= next2;
  }

}
