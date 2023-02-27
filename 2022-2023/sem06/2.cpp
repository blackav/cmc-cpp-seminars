#include <iostream>

using std::cout, std::endl;

class Array
{
    static constexpr size_t N = 10;

    double data[N]{};

public:

    double &operator [](size_t i) { return data[i]; }
    double operator[](size_t i) const { return data[i]; }

    size_t size() const { return N; }
    
};

void f(const Array &a)
{
    cout << a[0] << endl;
}

int main()
{
    Array a1;

    a1[0] = 1.0;
    f(a1);

    cout << std::ssize(a1) << endl;

    // UB - бесконечный цикл!
    for (size_t i = a1.size() - 1; i >= 0; --i) {
    }

    // а так хорошо
    for (ssize_t i = std::ssize(a1) - 1; i >= 0; --i) {
    }
}
