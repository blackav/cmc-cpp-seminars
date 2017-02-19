#include <iostream>

using namespace std;

struct s
{
};

void f(int a, double b, int c = 0.0)
{
    cout << "f(int, double, int)\n";
}

void f(double a, int b)
{
    cout << "f(double, int)\n";
}

void f(double a, const double &b)
{
    cout << "f(double, double)\n";
}

void f(struct s, int i)
{
    cout << "f(s, int)\n";
}

int main()
{
    char c = 0;
    f(0.0, c);
    float z = 0;
    f(1, 0.0);
    f(1, z);
    f(z, 0.0);
}
