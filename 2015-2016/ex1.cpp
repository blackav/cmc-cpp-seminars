#include <iostream>

#include <memory>

using namespace std;

struct Res
{
    static int count;
    int val;
    int cnt;
    Res(int val) : val(val), cnt(count++) {}
    Res(const Res &other) : val(other.val), cnt(count++) { cout << "copy:" << cnt << endl; }
    Res(Res && other) : val(other.val), cnt(other.cnt) { cout << "move" << endl; other.cnt = -1; }
    ~Res() { cout << "Res:" << cnt << endl; }
};

int Res::count = 0;

struct Tmp
{
    int cnt;
    static int count;
    Tmp() : cnt(count++) {}
    ~Tmp() { cout << cnt << endl; }
};

int Tmp::count = 0;

void ff(int val, int res)
{
    Tmp tmp;
    //unique_ptr<Tmp> tmp2{new Tmp()};
    Tmp *tmp2 = new Tmp();
    try {
        if (val <= 0) throw Res(res);
        ff(val - 1, res * val);
    } catch (...) {
        delete tmp2;
        throw;
    }
}

int main() try
{
    try {
        ff(4, 1);
    } catch (Res rr) {
        cout << rr.val << endl;
        throw;
    } catch (int z) {
    }
} catch (Res rrr) {
    cout << rrr.val << endl;
}
