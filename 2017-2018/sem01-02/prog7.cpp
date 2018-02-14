#include <iostream>

using namespace std;

void myswap(auto &a, auto &b)
{
    decltype(a) t = a;
    a = b;
    b = t;
}

// T ~ const T &

auto plus10(const auto &a)
{
    return (decltype(a)) (a + 10);
}

int f1(const int &a, const int &b)
{
    //(int &)a = 20;
    //a++;
    return a * b;
}

int main()
{
    int a = 10;
    int &b = a;
    int c = 20;

    b = c;


    b++;
    myswap(b, c);
    cout << a << endl;

    char f = 'a';
    cout << plus10(f) << endl;

    cout << plus10('A') << endl;
}
