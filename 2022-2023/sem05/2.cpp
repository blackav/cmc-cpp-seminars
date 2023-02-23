#include <iostream>

using std::cin, std::cout, std::endl;

struct A
{
    A()
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    ~A()
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
    void g() const
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

const A &f(const A &a)
{
    cout << __PRETTY_FUNCTION__ << endl;
    return a;
}

int main()
{
    cout << 1 << endl;
    A a1;
    cout << 2 << endl;
    A& ra1 = a1;
    cout << 3 << endl;
    const A ca2;
    cout << 4 << endl;
    const A &cra2 = ca2;
    cout << 5 << endl;
    const A& rt = A();    // время жизни этого временного объекта
                          // продлевается на время жизни ссылки rt
    cout << 6 << endl;
    const A &rt2 = f(A()); // а здесь не продлевается!!!
    // с этого момента rt2 - висящая ссылка, работа с ней - UB!
    cout << 7 << endl;
}
