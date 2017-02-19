#include <iostream>

using namespace std;

void bar(int a, int b)
{
}

void func2()
{
    bar(2, 2);
}

void bar(int a, int b = 200);

void func3()
{
    bar(2);
}

void func(int a, int b = 2, int c = 100)
{
    cout << "a: " << a << " b: " << b << endl;
}

void func(int b, int c)
{
    cout << "func(int, int);" << endl;
}

void func(int x)
{
    cout << "func(int);" << endl;
}

void func(double x)
{
    cout << "func(double)" << endl;
}

void func(double x, double y)
{
    cout << "func(double, double)" << endl;
}

int main()
{
    //func(10, 20);
    //func(1);
    func(1.5);
    //func(1, 6);
}
