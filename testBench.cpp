#include <iostream>

void swap(int &a, int &b) {
    int tmp = a; // a is an alias
    a = b;
    b = tmp;
}

int main()
{
    int x = 10, y = 20;
    std::cout << x << ' ' << y << std::endl;
    swap(x, y);
    std::cout << x << ' ' << y << std::endl;
}
