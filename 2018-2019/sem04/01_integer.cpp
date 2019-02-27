#include <cstdlib>

class Integer
{
    int value;

public:
    const Integer &operator ++()
    {
        if (__builtin_add_overflow(value, 1, &value)) {
            abort();
        }
        return *this;
    }
    Integer operator ++(int dummy)
    {
        Integer tmp = *this;
        ++*this;
        return tmp;
    }
};

int main()
{
    Integer g;

    for (int i = 0; i < N; ++i) {
    }

    for (int i = 0; i < N; i++) {
    }
    //++++g;
    ++g;
}
