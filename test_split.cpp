/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include<iostream>
using namespace std;
int main(int argc, char* argv[])
{
    Node *head= new Node(1,nullptr);
    Node *curr=head;
    Node *odd = nullptr;
    Node *even = nullptr;
    for(int i=2;i<=10;i++){
        curr->next = new Node(i, nullptr);
        curr = curr->next;
    }
    split(head, odd, even);
    cout<<(odd->value)<<endl;
    if(even==nullptr){
        cout<<"Even list is empty\n";
    }
    cout<<(even->value)<<endl;
    for(int i=1;i<=5;i++){
        cout<<(odd->value)<<endl;
        auto temp=odd;
        odd=odd->next;
        delete temp;
    }
    for(int i=1;i<=5;i++){
        cout<<(even->value)<<endl;
        auto temp=even;
        even=even->next;
        delete temp;
    }
    if(head==nullptr){
        cout<<"head is set to null.\n";
    }
    if(even==nullptr){
        cout<<"Even list is empty\n";
    }
    if(odd==nullptr){
        cout<<"Odd list is empty\n";
    }
    return 0;
}
