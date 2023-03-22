#include <iostream>

using std::cout, std::endl;

auto inc(auto x) { return x + 1; }
auto inc2(auto x, auto y) { return x + y + 1; }

template<typename T>
T inc3(T x, T y)
{
    return x + y + 1;
}

//template<> char inc3(char x, char y);

template<>
char inc3(char x, char y)
{
    cout << __PRETTY_FUNCTION__ << endl;
    return x - y;
}

int main()
{
    int a = 10;
    double b = 20;
    long long c = 100;
    long d = 200;


    cout << inc(a)  << endl;
    cout << inc(b) << endl;
    cout << inc(c) << endl;
    cout << inc(d) << endl;
    
    cout << inc3(a, 10) << endl;
    cout << inc3<long>(a, b) << endl;
    cout << inc3('a', 'b') << endl;
}
