#include <iostream>

using std::cout, std::endl;

class N
{
    int v{};

public:
    N(int vv = {}) : v(vv) {}

    N operator+ () const
    {
        cout << __PRETTY_FUNCTION__ << endl;
        return N(v);
    }

    friend N operator - (N n)
    {
        cout << __PRETTY_FUNCTION__ << endl;
        return N(-n.v);
    }
    friend bool operator !(N n)
    {
        return !n.v;
    }

    const N & operator += (N n)
    {
        cout << __PRETTY_FUNCTION__ << endl;
        return *this;
    }

    const N & operator++()
    {
        cout << __PRETTY_FUNCTION__ << endl;
        ++v;
        return *this;
    }
    N operator++(int)
    {
        cout << __PRETTY_FUNCTION__ << endl;
        N old(*this);
        ++v;
        return old;
    }

    friend auto operator <=> (N n1, N n2) = default;
};

N operator +(N n1, N n2)
{
    cout << __PRETTY_FUNCTION__ << endl;
    n1 += n2;
    return n1;
}

int main()
{
    N n1, n2;

    N n3 = -n1;
    N n4 = +n2;

    n4 += n1;

    N n5 = n1 + n2;

    ++n2;
    n5++;

    n5.operator++(100);
}
