#include <iostream>

using namespace std;

void swap(int &a, int &b)
{
    auto t = a;
    a = b;
    b = t;
}

auto func(const int &a) -> auto
{
    return a + 10;
}

int main()
{
    int a;
    int &b = a;
    decltype(b) c = b;

    cin >> a;
    cin >> c;
    swap(a, c);
    cout << b << " " << c << endl;
    cout << func(a) << endl;
    cout << func(22) << endl;
}
