#include <iostream>

int main()
{
    int x = 10;
    int* ptr = &x;

    std::cout << "x : " << x << std::endl;
    std::cout << "Memory address of x: " << ptr << std::endl;

    return 0;
}
