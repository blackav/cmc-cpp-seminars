#include <iostream>

using namespace std;

class Complex
{
    // переменные базовых классов неявно не инициализируются,
    // но если выписать явный конструктор по умолчанию, это означает инициализацию нулем
    double re = double();
    double im{4.4}; // новый синтаксис C++11 (uniform initializer)

public:
    Complex() {}
    Complex(double re, double im);
    explicit Complex(double re)
    {
        Complex::re = re; // Complex::re - обращаемся в область видимости класса Complex (C++11)
    }

    double get_re() const { return re; }
    double get_im() const { return im; }

    void print() const
    {
        cout << "(" << re << "," << im << ")" << endl;
    }
};

Complex::Complex(double re, double im)
{
    Complex::re = re;
    this->im = im;
}

double mabs(Complex c)
{
    return c.get_re() * c.get_re() + c.get_im() * c.get_im();
}

int main()
{
    Complex c;
    Complex c2 = Complex();
    Complex c3{};

    Complex c4(1.1, 2.2);
    Complex c5 = Complex(4.4, 5.5);
    Complex c6{7.7, 8.8};

    Complex c7 = {};
    Complex c8 = { 111, 222 };

    Complex c9 = Complex(3.3);
    Complex c10{12};
    Complex c11(13);


    c.print();
    c2.print();
    c3.print();
    c4.print();
    c5.print();
    c6.print();
    c7.print();
    c8.print();
    c9.print();
    c10.print();
    cout << mabs(c10) << endl;
    cout << mabs(Complex(1.1)) << endl;
    cout << mabs(Complex{100}) << endl;
    cout << mabs({100}) << endl;
}
