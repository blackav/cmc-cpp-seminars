#include <iostream>
using namespace std;

// overloading
// name mangling

void fddd(const int &a)
{
    cout << "f(const int &): " << a << endl;
}

void f(int a)
{
    cout << "f(int): " << a << endl;
}

bool f(double a)
{
    cout << "f(double): " << a << endl;
    return false;
}

void f(int a, int b)
{
    cout << "f(int, int): " << a << b << endl;
}

void f(char z = 'a', int c = 10)
{
    cout << "f(char, int)" << endl;
}

void f(unsigned char z)
{
    cout << "f(unsigned char)" << endl;
}

// int, int
// const int &, int
// int &, int

int main()
{
    cout << (void*)(void(*)(int,int))f << endl;
    f('a');
    f(10);
    f(1.0);
    f(100, 200);
    unsigned char z = 'x';
    f(z);
    long double a = 1.0L;
    f(a);
    long b = 100;
    f(b);
}
