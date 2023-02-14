#include <iostream>

using std::cin, std::cout, std::endl;

struct A final
{
    int f1{};
    int f2{};

    int f4{};

    int f3{};

    A() : f1(1), f2(2), f4(3), f3(4)
    {
        cout << "A" << endl;
    }
    ~A()
    {
        cout << "~A" << endl;
    }
};

struct B
{
    A a1{};
    A a2{};

    B()
    {
        cout << "B" << endl;
    }
    ~B()
    {
        cout << "~B" << endl;
    }
};

struct C final
{
    C()
    {
        cout << "C" << endl;
    }
    ~C()
    {
        cout << "~C" << endl;
    }
};

void func(C c)
{
    cout << "?" << endl;
}

int main()
{
    A aa;
    B bb;

    {
        A aaa;
    }
    {
        B bbb;
    }

    func(C{});

    cout << "!" << endl;

}
