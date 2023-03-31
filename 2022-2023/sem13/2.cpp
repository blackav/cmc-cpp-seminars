#include <iostream>
#include <functional>

using std::cout, std::endl, std::function;

template<typename T> struct ff;

template<typename T, typename ...Args>
struct ff<T(Args...)>
{
    T (*ptr)(Args...);

    static void func()
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    T operator() (Args ...args) const
    {
        return (*ptr)(args...);
    }
};

int main()
{

    std::function<int (int)> w;

    ff<int (int)> ww;

    ww.func();

    ff<void (int, double, char*)> www;
    www.func();
}
