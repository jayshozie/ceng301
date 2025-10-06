#include <iostream>

void swap(int *p, int *q){
    int tmp;
    tmp = *p;
    *p = *q;
    *q = tmp;
}

int main()
{
    int a = 3;
    int b = 7;
    std::cout << a << " " << b << std::endl;
    swap(&a,&b);
    std::cout << a << " " << b << std::endl;
    return 0;
}
