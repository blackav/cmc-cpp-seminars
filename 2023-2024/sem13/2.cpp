#include <iostream>
#include <vector>

using std::cout, std::endl;

struct B
{
	void f(char c)
	{
		cout << __PRETTY_FUNCTION__ << endl;
	}
	void f(const char *s)
	{
		cout << __PRETTY_FUNCTION__ << endl;
	}
};

struct D : public B
{
	using B::f;
	void f(int a)
	{
		cout << __PRETTY_FUNCTION__ << endl;
	}
};

int main()
{
	B b;
	D d;

	b.f('c');
	b.f(1);
	d.f('c');
	d.f(1);
	d.f("aa");
}
