#include <iostream>
#include <math.h>

class IntCell
{
public:
    IntCell(){
        storedValue = 0;
    }
    IntCell(int initialValue){
        storedValue = initialValue;
    }
    void read();
    void write(int x);
private:
    int storedValue;
};

void IntCell::read(){
    std::cout << storedValue << std::endl;
}

void IntCell::write(int x){
    this->storedValue = x;
}

int main()
{
    int *p = new int;
    IntCell *c = new IntCell;

    *p = 42;
    (*c).write(4);

    std::cout << *p << std::endl;
    (*c).read();

    delete c;
    delete p;
}

