#include <iostream>

using namespace std;

// 0 - identity
// 1 - +"const" +"volatile" T[] -> T*
// 2 - promotions
// 3 - standard conversion
// 4 - user conversion
// 5 - auto (templates) (но это неточно)
// 6 - ellipsis (...) conversion

void f(short x)
{
    cout << "f(short)" << endl;
}

void f(int x)
{
    cout << "f(int)" << endl;
}

void f(double x)
{
    cout << "f(double)" << endl;
}

void f(unsigned long long x)
{
    cout << "f(unsigned long long)" << endl;
}

void f(void *x)
{
    cout << "f(void *)" << endl;
}

void f(int *x)
{
    cout << "f(int *)" << endl;
}

void f(nullptr_t x)
{
    cout << "f(nullptr_t)" << endl;
}

int main()
{
    f('a');
    short z = 10;
    f(z);
    f(1.0f);
    f(&z);

    f(nullptr);
}
