#include <iostream>

using std::cout;
using namespace std;

int f = 400;

class A
{
    double df;
};

struct B
{
//public:
    int f;
    double v;
    A z;

    void dosome();
    void do2(int f = 10)
    {
        // B *this
        cout << ::f << endl;
    }

    void cdo() const;

    static void stfunc();
protected:
    double ff;
private:
    int g;
    static int stv;
    static constexpr auto cval = 400;
};

int B::stv = 102020;

void B::cdo() const
{
    // const B *this;
    //g += 20;
    cout << g << endl;
}

void B::stfunc()
{
    //cout << B::f << endl;
    cout << stv << endl;
}

void B::dosome()
{
    cout << "B::dosome()\n";
}

void func(const B &b)
{
    //b.dosome();
    ((B&) b).dosome();
    b.cdo();
}

// POD (plain old data)
//
int main()
{
    B b, *pb = &b;

    //cout << B::cval << endl;

    b.f = 1;
    pb->v = 2.0;

    b.dosome();
    pb->dosome();
    pb->do2();

    b.stfunc();
    func(b);
}
