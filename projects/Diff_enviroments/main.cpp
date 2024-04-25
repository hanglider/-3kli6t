#include <iostream>

#include "c.h"
#include "t.h"

int main()
{
    std::cout << "ti pidor";
    int c = IT::f(1, 2);
    int c1 = IT1::f(1, 3);
    std::cout << c1 + c << "\n";
    system("pause");
}