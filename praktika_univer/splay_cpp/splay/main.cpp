#include <iostream>
#include "splay.h"
using namespace std;

int main()
{
    splay_tree test;
    test.Insert(4);
    test.show_it();
    node* look = new node();
    look = test.lookup(4);
    cout << look->value << "saint";
}
