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
  if(tail_==nullptr){  // in this case, head_ must be null as well
    head_ = new Item;
    tail_ = head_;
  }
  if(tail_->last==ARRSIZE){
    tail_->next = new Item;
    tail_->next->prev = tail_;
    tail_=tail_->next;
  }
  (tail_->val)[tail_->last] = val;
  (tail_->last)++;
  size_++;
}

void ULListStr::pop_back(){
  size_--;
  (tail_->last)--;
  if(tail_->last==tail_->first){
    Item* temp = tail_;
    tail_ = tail_->prev;
    if(tail_!=nullptr){
      tail_->next = nullptr;
    }
    delete temp;
    if(tail_==nullptr){
      head_=nullptr;
    }
  }
}

void ULListStr::push_front(const std::string& val){
  size_++;
  if(head_==nullptr){  // in this case, tail_ must be null as well
    head_ = new Item;
    tail_ = head_;
  }
  if(head_->first == 0 && head_->last!=0){
    Item* temp = head_;
    head_ = new Item;
    head_->next = temp;
    temp->prev = head_;
  }
  if(head_->first == 0){
    (head_->val)[0] = val;
    (head_->last)++;
  }else{
    (head_->val)[--(head_->first)] = val;
  }
}

void ULListStr::pop_front(){
  (head_->first)++;
  size_--;
  if(head_->first == head_->last){
    Item* temp = head_;
    head_ = head_->next;
    if(head_!=nullptr){
      head_->prev = nullptr;
    }
    delete temp;
    if(head_==nullptr){
      tail_ = nullptr;
    }
  }
}

std::string const & ULListStr::back() const{
  return (tail_->val)[(tail_->last)-1];
}

std::string const & ULListStr::front() const{
  return (head_->val)[head_->first];
}
std::string* ULListStr::getValAtLoc(size_t loc) const{
  Item* curr = head_;
  int cnt = loc;
  while(curr!=nullptr && cnt>=0) {
    int cur_size = curr->last - curr->first;
    if(cur_size<=cnt){
      cnt-=cur_size;
      curr = curr -> next;
    }else{
      return &((curr->val)[(curr->first)+cnt]);
    }
  }
  return nullptr;
}


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
