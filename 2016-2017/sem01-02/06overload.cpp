#include <iostream>

using namespace std;

/*
extern "C" void func(int a, int b, int c);

void func(int a, int b, int c)
{
}
*/

void func()
{
    cout << "func();" << endl;
}

void func(int a)
{
    cout << "func(int );" << endl;
}

void func(double a)
{
    cout << "func(double);" << endl;
}

void func(int a, int b)
{
    cout << "func(int, int);" << endl;
}

void func(double a, double b)
{
    cout << "func(double, double);" << endl;
}

void func(void *a, int b)
{
    cout << "func(void *, int);" << endl;
}

void func(char c)
{
    cout << "func(char);" << endl;
}

void func(char &c)
{
    cout << "func(char&);" << endl;
}

int main()
{
    func();

    func(10);
    func(0.0);

    //func(1L);
    //func(1.0L);
    //char c = 'a';
    func('a');

    unsigned char cc = 'z';
    func(cc);

    //func(10U);

    float f = 1.0;
    func(f);

    func(1, 2);
    //func(1, 2.2);
    func(2.5, 2.3);
    func(&f, 3.4);
}
