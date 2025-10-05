#include <iostream>

void setIntToZero (int var) {
    std::cout << "var = " << var << std::endl;
    var = 0;
    std::cout << "var = " << var << std::endl;
}

int main()
{
    int a = 5;
    std::cout << "a = " << a << std::endl;
    setIntToZero(a);
    std::cout << "a = " << a << std::endl;
}
