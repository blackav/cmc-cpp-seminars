#include <iostream>

using namespace std;

struct Data
{
    enum class Variant { A, B };

    Variant v;
    int a;
    int b;

    void process(int c);
};

void Data::process(/* Data *this, */ int c)
{
    cout << a << endl;
    this->a += c;
    b += c;
    Data::b += c;
}

int main()
{
    Data    d;
    Data    *pd = &d;
    Data    &rd = d;

    d.v = Data::Variant::B;
    pd->a = 10;
    rd.b = 20;

    d.process(100);
    pd->process(200);
    rd.process(300);
}
