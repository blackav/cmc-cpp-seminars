#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

struct S
{
    int a = 0;

    S() = default;
    S(int a) : a(a) {}

    S &operator =(S b)
    {
        cout << "S::operator =(S)" << endl;
        a = b.a;
        return *this;
    }

    S & operator *= (const S &b)
    {
        a *= b.a;
        return *this;
    }

    double operator() (int a, int b, int c)
    {
        return (S::a - a + b * c)/2.0;
    }

    S operator[](int index)
    {
        return S(a + index);
    }

    S operator+ (S b) const
    {
        return S(a + b.a);
    }
    S operator- () const
    {
        return ~a;
    }

    const S &operator++()
    {
        cout << "S::operator++()" << endl;
        ++a;
        return *this;
    }

    S operator--(int dummy)
    {
        cout << "S::operator--(int)" << endl;
        S tmp{*this};
        --a;
        return tmp;
    }
};

const S & operator --(S &a)
{
    cout << "S::operator--()" << endl;
    --a.a;
    return a;
}

S operator ++(S &a, int dummy)
{
    cout << "S::operator++(int)" << endl;
    int b = a.a;
    ++a.a;
    return b;
}

auto operator - (S a, S b) 
{
    return S(a.a - b.a);
}

S operator * (S a, const S &b)
{
    return a *= b;
}

std::ostream & operator << (std::ostream &f, const S &s)
{
    return f << s.a;
}

std::istream & operator >> (std::istream &f, S &s)
{
    int z;
    f >> z;
    s = z;
    return f;
}

S operator ~ (const S &a)
{
    return S(-a.a);
}

S operator + (S a)
{
    a.a *= 2;
    return a;
}

bool operator == (const S &a, const S &b)
{
    return a.a == b.a;
}

bool operator < (const S &a, const S &b)
{
    return a.a > b.a; // implies reverse ordering
}

int main()
{
    int za, zb;
    cin >> za >> zb;
    S a{za}, b{zb};

    S c{a + b};
    S d = a.operator+(b);
    cout << c.a << " " << d.a << endl;

    S e = a + 66;
    cout << e.a << endl;

    S f = a - b;
    S g = operator-(a, b);
    cout << f.a << " " << g.a << endl;

    S h = b - 45;
    S i = 100 - a;
    cout << h.a << " " << i.a << endl;
    cout << h << endl;

    const S j{22};
    cout << j.operator+(55) << endl;

    S k = +j;
    cout << k << endl;

    //std::vector<S> vs;
    //std::sort(vs.begin(), vs.end()); // using S::operator <
    S l;
    cin >> l;
    l *= 20;
    cout << l << endl;
    S m{l * a};
    cout << m << endl;
    cout << m(44, 55, 66) << endl; // operator ()
    cout << l[10] << endl;
    cout << ++k << endl;
    cout << --k << endl;
    cout << k-- << endl;
    cout << k << endl;

}
