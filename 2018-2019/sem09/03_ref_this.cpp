#include <iostream>

using namespace std;

/*
хотя this и указатель, его можно квалифицировать как ссылку
чтобы устранить неоднозначности при вызовах методов
 */

struct A
{
    A() = default;
    A(const A&a) = default;
    A(A &&a) = default;

    // вызывается в обычной ситуации при неконстантном this
    void f() &
    {
        cout << "A::f() &" << endl;
    }
    // вызывается при константном this
    void f() const &
    {
        cout << "A::f() const &" << endl;
    }
    // вызывается для временного объекта
    void f() &&
    {
        cout << "A::f() &&" << endl;
    }
};

int main()
{
	A a;
	A b(move(a));
	A c(a);

	a.f();            // A::f() &
	const A &ra = a;
	ra.f();           // A::f() const &
	move(a).f();      // A::f() &&
}
