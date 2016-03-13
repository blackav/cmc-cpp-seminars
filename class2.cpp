#include <iostream>

using namespace std;

class A
{
private:
    int a;
    double b;
    long c;
};

double a = 33.33;

struct B
{
    int a;
    double b;
    A c;
    const double c1 = 1.5;

    static int stat1;

    void func(int a = 383838)
    {
        // this
        // B *this
        cout << "B::func()" << B::a << endl;
    }
    void func2();

    void func3() const
    {
        // const B *this
        cout << "B::func3()\n";
        //this->a += 20;
        //((B*) this)->a += 20;
        cout << stat1++ << endl;
    }

    static void func4()
    {
        cout << stat2 << endl;
    }

private:
    static double stat2;
};

int B::stat1;
double B::stat2 = 4.5;

void B::func2()
{
    cout << "B::func2()\n";
}

int main()
{
    B b, *pb = &b, &rb = b;
    const B *cpb =  &b;
    const B &crb = b;

    b.a = 10;
    pb->b = 0.45;
    rb.a += 20;

    B b2;
 
    b2.a = 103039;

    b.func();
    b.func2();

    b2.func();

    pb->func();
    rb.func();

    cpb->func3();
    crb.func3();

    ++B::stat1;

    pb->func4();
    B::func4();
   
    cout << crb.a << endl;
    cout << cpb->b << endl;
    cout << B::stat1 << endl;
}
