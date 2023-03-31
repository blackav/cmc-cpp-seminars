#include <iostream>
#include <type_traits>

using std::cout, std::endl;

template<typename T>
int print(const T &t)
{
    cout << t << endl;
    return 0;
}

template<typename ...Args>
void f(Args &&...args)
{
    int d[]{ print<Args>(args)... };
    cout << __PRETTY_FUNCTION__ << endl;
}

template<typename ...Types>
struct S
{
    static constexpr int depth = -1;
};

template<>
struct S<>
{
    static constexpr int depth = 0;
};

/*
template<typename T>
struct S<T>
{
    T f;
    static constexpr int depth = 1;
};
*/

template<typename T, typename ...Other>
struct S<T, Other...>
{
    T f;
    S<Other...> left;

    static constexpr int depth = S<Other...>::depth + 1;
};

template<int N, typename T, std::enable_if<N == 0, int>::type = 0>
decltype(auto) get(const T &t)
{
    return t.f;
}
template<int N, typename T, std::enable_if<N != 0, int>::type = 0>
decltype(auto) get(const T &t)
{
    return get<N - 1>(t.left);
}

int main()
{
    f<>();
    f<int>(10);
    f<int, double>(20, 4.0);

    S<> s0;
    S<int> s1{1000};
    S<double> s2{2000};
    S<double, double> s3{100, 240};
    S<double, double, double> s4{1, 2, 3};

    cout << s0.depth << endl;
    cout << s1.depth << endl;
    cout << s2.depth << endl;
    cout << s3.depth << endl;

    cout << get<0>(s1) << endl;
    cout << get<0>(s2) << endl;
    cout << get<0>(s3) << endl;
    cout << get<1>(s3) << endl;
    cout << get<2>(s4) << endl;
}
