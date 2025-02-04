#include <iostream>

using std::cout, std::endl;

struct A
{
};

A operator+ (A a1, A a2)
{
	cout << __PRETTY_FUNCTION__ << endl;
	return {};
}

namespace B
{
	struct A
	{
	};

	A operator+(A a1, A a2)
	{
		cout << __PRETTY_FUNCTION__ << endl;
		return {};
	}
};

int main()
{
	A a1, a2;

	A a3 = a1 + a2;

	A a4 = operator+(a1, a2);

	B::A aa1, aa2;

	B::A aa3 = aa1 + aa2;
	B::A aa4 = operator+(aa1, aa2);
	B::A aa5 = B::operator+(aa1, aa2);
}
