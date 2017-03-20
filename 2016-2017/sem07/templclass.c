#include <iostream>

template<typename T>
class Rational
{
    T nom, denom;

public:
    Rational(T nom, T denom) : nom(nom), denom(denom) {}
    T get_nom() const { return nom; }
};

int main()
{
    Rational<int> r(0, 1);
}
