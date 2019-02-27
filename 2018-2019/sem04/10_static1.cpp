#include <iostream>

using namespace std;

struct X
{
    X() { cout << "X::X" << endl; }
    ~X() { cout << "X::~X" << endl; }
};

void foo()
{
    static X x;
    X y;
}

X x1;
static X x2;

int main()
{
    cout << "before foo" << endl;
    foo();
    cout << "after foo" << endl;
}
