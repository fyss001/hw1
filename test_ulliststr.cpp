#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"
using namespace std;
//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
    auto list = new ULListStr();
    list->push_front("Hello");
    list->push_back(" World");
    cout<<(list->front())<<endl;
    cout<<(list->back())<<endl;
    delete list;
    cout<<"Run successfully!\n";
    ULListStr dat;
    dat.push_back("7");
    dat.push_front("8");
    dat.push_back("9");
    cout << dat.get(0) << endl;
    cout << dat.get(1) << endl;
    cout << dat.get(2) << endl;
    cout << dat.size() << endl;  // prints 3 since there are 3 strings stored
    return 0;
}
