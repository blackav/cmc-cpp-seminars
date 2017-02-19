#include <iostream>
#include <memory>

using namespace std;

struct Res
{
    int val;
    int serial;

    static int count;

    Res(int val) : val(val), serial(count++) { cout << "res" << serial << endl; }
    Res(const Res &o) : val(o.val), serial(count++) { cout << "copy" << serial << "," << o.serial << endl; }
    Res(Res &&o) : val(o.val), serial(o.serial) { cout << "move " << serial << endl; o.serial = -1; }
    ~Res() { cout << "~Res " << serial << endl; }
};

int Res::count = 0;

struct Tmp
{
    int serial;
    static int count;

    Tmp() : serial(count++) { cout << "Tmp" << serial << endl; }
    ~Tmp() { cout << "~Tmp" << serial << endl; }
};
    int Tmp::count = 0;

void ff(int val, int res)
{
    Tmp t1;
    Tmp *pp = new Tmp;
    unique_ptr<Tmp> t2{pp};
    unique_ptr<Tmp> t3{std::move(t2)};
    if (val <= 0) throw Res(res);
    ff(val - 1, res * val);
}

int main() try
{
    try {
        ff(6, 1);
    } catch (Res &r) {
        cout << r.val << endl;
        r.val++;
        throw r;
    }
} catch (Res rr) {
    cout << rr.val << endl;
}
