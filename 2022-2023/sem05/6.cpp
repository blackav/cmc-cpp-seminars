#include <iostream>

using namespace std;

class D
{
    int a;
public:
    D(int param = 5): a(param){}
    D operator+ (const D & myobj2) const {
        cout << 1 << endl; return D(2);
    }
    friend D operator+ (const D & myobj1, const D & myobj2);
};

D operator+ (const D & myobj1, const D & myobj2)
{
    cout << 2 << endl; return D(myobj1.a);
};

int main()
{
    D obj1 (3), obj2;
    obj2 = obj1 + obj2;
    return 0;
}
