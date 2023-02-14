#include <iostream>

using std::cout, std::endl;

struct A
{
    A(){ cout << "A()" << endl; } // default
    A(int a){ cout << "A(int)" << endl; }  // conversion constructor
    explicit A(double b){ cout << "A(double)" << endl; }
};

int main()
{
    A a;
    A a2{10};
    A a3{1.3};

    [[maybe_unused]]
    A a4 = 1.5;
    A a5 = A(1.6);
}
