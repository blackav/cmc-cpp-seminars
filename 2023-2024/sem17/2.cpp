#include <iostream>

using std::cout, std::endl;

struct A
{
	A operator+(A a2)
	{
		cout << __PRETTY_FUNCTION__ << endl;
		return {};
	}
	// A A::operator+(A *this, A a2)
};

int main()
{
	A a1, a2;

	A a3 = a1 + a2;
	A a4 = a1.operator+(a2);
	A a5 = A{}.operator+(a2);
	A a6 = A{} + a2;
}
