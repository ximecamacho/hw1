#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
void ULListStr::push_back(const std::string& val){
  //first and last stay at beginning to allow more push backs
  //when push_back on empty list
  if(tail_==nullptr){
    //initializes head and tail with first list item
    Item* firstList_=new Item();
    head_=firstList_;
    tail_=firstList_;
    firstList_->val[firstList_->last]=val;
    firstList_->last++;
    size_++;
  }
  //push_back on list with no space
  else if(tail_->last==ARRSIZE){
    //create new item and update respective pointers
    Item* moreList_=new Item();
    moreList_->prev=tail_;
    tail_->next=moreList_;
    tail_=moreList_;
    moreList_->val[moreList_->last]=val;
    //move last pointer one beyond used slot
    moreList_->last++;
    size_++;

  }
  else{
    //normal push_back
    tail_->val[tail_->last]=val;
    //move last pointer one beyond used slot
    tail_->last++;
    size_++;
  }

}

void ULListStr::push_front(const std::string& val){
  //when push_front on empty list
  if(head_==nullptr){
    //initializes head and tail with first list item
    Item* firstList= new Item();
    head_=firstList;
    tail_=firstList;
    //set first and last at the end to allow space for more push fronts
    firstList->first=ARRSIZE-1;
    firstList->last=ARRSIZE;
    firstList->val[firstList->first]=val;
    size_++;
  }
  //push_front on list with no space
  else if(head_->first==0){
    //create new item and updates respective pointers
    Item* moreList=new Item();
    moreList->next=head_;
    head_->prev=moreList;
    head_=moreList;
    //set first and last at the end to allow space for more push fronts
    moreList->first=ARRSIZE-1;
    moreList->last=ARRSIZE;
    moreList->val[moreList->first]=val;
    size_++;
  }
  else{
    //normal push front
    //moves first to empty slot and updates list
    head_->first--;
    head_->val[head_->first]=val;
    size_++;
  }
}

void ULListStr::pop_back(){
  //updates tail to point to one beyond the end of previous value(deleted value's spot)
  tail_->last--;
  size_--;
  
  //if item becomes empty, delete it and update to previous item 
  if(tail_->last==-1){
    Item* temp=tail_->prev;
    tail_=temp;
  }

}

void ULListStr::pop_front(){
  //updates  head to point to the value in front of the deleted value
  head_->first++;
  size_--;
  
  //if item becomes empty, delete it and update to next item
  if(head_->first==ARRSIZE){
    Item* temp=head_->next;
    head_=temp;
  }

}

//return back and front values
std::string const & ULListStr::back() const{
  int temp=tail_->last;
  return (tail_->val[--temp]);
}

std::string const & ULListStr::front() const{
  return (head_->val[head_->first]);
}

std::string* ULListStr::getValAtLoc(size_t loc) const{
  Item* temp=head_;
  int count=0;
  //iterate through items that make up list
  while(temp!=nullptr){
    //from first to last in each item search for location
    //use count to represent location in case lists are not filled from 0 to 9 (starts at 
    //index 3 in first list item ect.)
    for(int i=temp->first; i<temp->last; i++){
      if(count==loc){
        return &(temp->val[i]);
      }
      count++;
    }
    temp=temp->next;
  }
  
}

//end my code 



void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
