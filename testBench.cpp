#include <iostream>

int main()
{
    int *p = new int;
    *p = 10;
    int &r = *p;
    r++;
    std::cout << *p << std::endl;
}
