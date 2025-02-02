/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"

/* Add a prototype for a helper function here if you need */
Node* findNextOdd(Node*& in);
Node* findNextEven(Node*& in);

void split(Node*& in, Node*& odds, Node*& evens)
{
/* Add code here */
// WRITE YOUR CODE HERE

//if at end of in/ in is empty, finish
if(in==nullptr){
  return;
}

if(((in->value)%2)!=0){
  //odd case
  Node* tempOdd=in->next;
  //initializes odd node with current value and looks
  //for next odd value for next odd list item
  odds=in;
  odds->next=findNextOdd(in);
  split(tempOdd, odds->next, evens);

}
else{
  //even case
  Node* tempEven=in->next;
  //initializes even node with current value and looks
  //for next even value for next even list item
  evens=in;
  evens->next=findNextEven(in);
  split(tempEven, odds, evens->next);
}

//sets in to null
in=nullptr;

}

/* If you needed a helper function, write it here */

//finds next odd node
Node* findNextOdd(Node*& in){
  //if next value is null, return
  if(in->next==nullptr){
     return nullptr;
  }
  //if next value is not odd, keep searching
  if((in->next->value%2)==0){
    findNextOdd(in->next);
  }
  else{
    //if next value is odd, return it
    return (in->next);
  }
  return nullptr;

}

//finds next even node
Node* findNextEven(Node*& in){
  //if next value is null, return
  if(in->next==nullptr){
    return nullptr;
  }
  //if next value is not even, keep searching
   if((in->next->value%2)!=0){
    findNextEven(in->next);
  }
  else{
    //if next value is even, return it
    return (in->next);
  }
  return nullptr;

}