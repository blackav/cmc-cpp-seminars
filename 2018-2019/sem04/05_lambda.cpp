#include <iostream>

using namespace std;

int main()
{
    int z;
    cin >> z;
    auto f = [z](int a) { return z + a; };

    int x;
    cin >> x;
    cout << f(x) << endl;

    struct Lambda
    {
        int z_;

        Lambda(int z_) : z_(z_) {}
        int operator()(int a)
        {
            return z_ + a;
        }
    };

    Lambda ff(z);
    cout << ff(x) << endl;

}
