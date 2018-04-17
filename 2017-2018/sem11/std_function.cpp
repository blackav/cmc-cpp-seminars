#include <functional>
#include <iostream>

using namespace std;

/*
std::function - вспомогательный класс для разных сущностей,
к которым применима операция ()
*/

int inc1(int x)
{
    return x + 1;
}

struct OldSchool
{
    int x;
    OldSchool(int x) : x(x) {}
    int operator()(int x) const { return OldSchool::x + x; }
    int func(int y) const { return x + y; }

    // передаем this в замыкание
    function<int (int)> getfunc(int y) const
    {
        return function<int (int)>([this, y](int z) { return x + y + z; });
    }
};

// возвращаем std::function из функции
// обратите внимание: нужно следить за временем жизни параметров
// и локальных переменных
function<int (int)> getfunc(int x)
{
    return function<int (int)>([x](int y) { return x + y; });
}

int main()
{
    function<int (int)> f1 = inc1;
    cout << f1(111) << endl;

    function<int (int)> f2 = OldSchool(202);
    cout << f2(303) << endl;

    function<int (int)> f3 = [](int x) { return x + 1; };
    cout << f3(1111) << endl;

    int v1 = 123456;
    function<int (int)> f4 = [&v1](int x) { return x + v1; };
    cout << f4(1) << endl;

    cout << getfunc(200)(100) << endl;

    function<int (const OldSchool &, int)> f5 = &OldSchool::func;
    OldSchool s(10);
    cout << f5(s, 11) << endl;

    cout << s.getfunc(15)(20) << endl;
}
