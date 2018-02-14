#include <iostream>

using namespace std;

void f(int &x)
{
    cout << "f(int&)" << endl;
}

void f(const int &x)
{
    cout << "f(const int&)" << endl;
}

void f(int *px)
{
    cout << "f(int*);" << endl;
}

void f(const int *px)
{
    cout << "f(const int*);" << endl;
}

/*
void f(int x)
{
    cout << "f(int)" << endl;
}
*/

int main()
{
    f(10);
    int z;
    f(z);
    const int &zz = z;
    f(zz);
    f(&z);
    f(&zz);
}
