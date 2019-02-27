struct Func
{
    int operator()(int a) const
    {
        return a + 1;
    }
    double operator()(int a, int b) const
    {
        return (a + b + 0.0) / 2;
    }
};

#include <iostream>

using namespace std;

int main()
{
    Func f;

    cout << f(10) << endl;
    cout << f(1, 2) << endl;
}
