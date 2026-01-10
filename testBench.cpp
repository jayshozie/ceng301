#include <iostream>

bool is_prime(int n) {
    if(n <= 1) { return false; }
    if(n == 2 || n == 3) { return true; }
    if(n % 2 == 0 || n % 3 == 0) { return false; }
    for(int i = 5; i*i<=n; i+= 6) {
        if(n % i == 0 || n % (i + 2) == 0) { return false; }
    }
    return true;
}

int get_next_prime(int n) {
    switch(n) {
        case 0:
            return 2;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 5;
    }
    int next_prime = n + 1;
    if(next_prime % 2 == 0) { next_prime++; }
    for(;;) {
        if(is_prime(next_prime)) { return next_prime; }
        next_prime += 2;
    }
}

int main()
{
    int next_prime;
    for(int i = 0; i <= 100000000; i++) {
        next_prime = get_next_prime(i);
    }

    printf("Last Prime : %d\n", next_prime);
}
