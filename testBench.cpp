#include <iostream>
#include <math.h>

long long int fibonacci(long long int n){
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return (n + fibonacci(n-1));
}

int main()
{
    long long int x = fibonacci(100);
    std::cout << x << std::endl;
}


