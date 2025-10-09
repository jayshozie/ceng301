#include <iostream>

void fun2(int &a, int b) {
    a = a * 2;
    b = a + b;
    std::cout << a << ' ' << b << std::endl;
}

int main()
{
    int x = 3, y = 5;
    fun2(x,y);
    std::cout << x << ' ' << y << std::endl;
}
