#include <iostream>

using namespace std;

void f(int a, int b)
{
    cout << "f(int, int)" << endl;
}

void f(double a, double b)
{
    cout << "f(double, double)" << endl;
}

void f(int *a, int b)
{
    cout << "f(int *, int)" << endl;
}

/*
void f(...)
{
    cout << "f(...)" << endl;
}
*/

int main()
{
    f(10, 10);
    f(1.5, 2.5);

    //f(10, 5.5);
    f(10L, 10);
    f(10L, 10.6);
    //f("a", 10);
}
