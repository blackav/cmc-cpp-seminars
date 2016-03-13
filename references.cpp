#include <iostream>

using namespace std;

// неконстантная ссылка - для передачи "по ссылке"
void func(int &a)
{

    a *= a;
}

// константная ссылка
void func2(int const &b)
{
    cout << "const: " << b << endl;
}

int main()
{
    int a;
    int &b = a;

    while (cin >> a) {
        func2(a);
        cout << b << endl;
    }
}

// T == const T &
