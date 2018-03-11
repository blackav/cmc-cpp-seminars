#include <initializer_list>
#include <iostream>

class A
{
    int a = 100, b = 200, c = 300;

public:
    A(std::initializer_list<int> il)
    {
        auto it = il.begin();
        if (it != il.end()) {
            a = *it++;
        }
        if (it != il.end()) {
            b = *it++;
        }
        if (it != il.end()) {
            c = *it++;
        }
    }

    void print()
    {
        using std::cout;
        using std::endl;

        cout << a << " " << b << " " << c << endl;
    }
};


int main()
{
    A a1{};
    A a2{1};
    A a3{1, 2};
    A a4{1, 2, 3};
    A a5{1, 2, 3, 4};

    a1.print();
    a2.print();
    a3.print();
    a4.print();
    a5.print();
}
