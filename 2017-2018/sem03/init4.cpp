#include <iostream>
#include <initializer_list>

using namespace std;

struct A
{
    int a, b, c;

    A(std::initializer_list<int> il)
    {
        //std::initializer_list<int>::iterator x = il.begin();
        auto x = il.begin();
        if (x != il.end()) {
            a = *x;
            ++x;
        }
        if (x != il.end()) {
            b = *x;
            ++x;
        }
        if (x != il.end()) {
            c = *x;
            ++x;
        }
    }
    //A(int a) :a(a) {}

    void print()
    {
        cout << a << " " << b << " " << c << endl;
    }
};

int main()
{
    A a0{};
    A a1{1};
    A a2{1, 2};
    A a3{1, 2, 3};
    A a4{1, 2, 3, 4};
    //A a5(1.4);

    a0.print();
    a1.print();
    a2.print();
    a3.print();
}
