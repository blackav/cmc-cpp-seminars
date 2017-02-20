#include <iostream>

using namespace std;

// POD (plain old data)
struct Foo
{
    int f1;
    double f2;

    static int f3;
    static void f4(int z) { Foo::f3 = z; }
    static void f5();
    
    void f6();
    auto f7(int a) -> auto
    {
        const auto &that = this;
        return that->Foo::f2 + a + this->Foo::f2;
    }

/*
private:
    int f4;
*/
};
int Foo::f3 = 4;
void Foo::f5()
{
    f3 = 3.14;
}
void Foo::f6()
{
    cout << "F6::f1" << endl;
}

Foo gf{3, 6.6};

int main()
{
    struct Foo a{ 1, 2.0};
    Foo *b = nullptr;
    Foo &c = a;
    const Foo &d = a;

    a.f1 = 4;
    //b->f2 = 0.5;
    c.f1 = 10;

    b = new Foo{3, 4.4};
    delete b;
    b = new Foo;

    cout << b->f1 << " " << b->f2 << endl;
    cout << Foo::f3 << endl;
    a.f3 = 10;
    //b = nullptr;
    cout << b->f3 << endl;

    Foo::f4(10);
    b->f5();
    a.f5();

    //Foo::f6();
    a.f6();
    a.Foo::f7(4);
}
