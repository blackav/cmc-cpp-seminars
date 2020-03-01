// некоторые правила перегрузки
// T <-> T
// const T & <-> T

// int[] <-> int*
// func() <-> (*)()

// T* -> const T*
// T& -> const T&

// ======================

// стандартные
// promotions
// char -> int
// short -> int
// float -> double

// conversions
// char <-> long
// long <-> double
// float <-> int

// ======================

// user-defined
// A -> B
// stand -> A -> B
// A -> B -> stand
// stand -> A -> B -> stand

//
// ellipsis (...)

void f(int);
//void f(long);
void f(long long);

int bar()
{
    char c;
    f(c);

    unsigned int u;
    f(u);
}
