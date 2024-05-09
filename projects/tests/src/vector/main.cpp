#include <iostream>
#include "vector.h"
using IBusko::Vector;


int main() {
    Vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    //printf("%d \n", a.has_item(4));
    //printf("%d \n", a.has_item(6));
    //a.insert(0, 69);
    //a.print();
    //a.remove_first(69);
    //a.print();
    printf("%d \n", a.size());
    auto t = nullptr;
    auto r = nullptr;
    printf("%d ", t = r);
    system("pause");
}