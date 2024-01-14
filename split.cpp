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
void add_to_back(Node*&, Node*&);

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
  if(in==nullptr) return;
  int value = in->value;
  if(value&1){  //odd
    Node* temp = new Node(value, nullptr);
    if(odds==nullptr){
      odds=temp;
    }else{
      add_to_back(odds, temp);
    }
  }else{  //even
    Node* temp = new Node(value, nullptr);
    if(evens==nullptr){
      evens=temp;
    }else{
      add_to_back(evens, temp);
    }   
  }
  Node* prev = in;
  in = in->next;
  split(in, odds, evens);
  delete prev;
}

/* If you needed a helper function, write it here */
void add_to_back(Node*& curr, Node*& toAdd){
  if(curr->next!=nullptr){
    add_to_back(curr->next, toAdd);
    return;
  }else{
    curr->next = toAdd;
  }
}