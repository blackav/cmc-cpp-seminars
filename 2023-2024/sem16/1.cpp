#include <iostream>

using std::cin, std::cout, std::endl;

struct B1
{
	int a_;
	B1(int a) : a_{a} {}
	void f()
	{
		cout << __PRETTY_FUNCTION__ << endl;
	}
	void g(int a)
	{
		cout << __PRETTY_FUNCTION__ << endl;
	}
};

struct B2
{
	int a_;
	B2(int a) : a_{a} {}
	void f()
	{
		cout << __PRETTY_FUNCTION__ << endl;
	}
	void g(char a)
	{
		cout << __PRETTY_FUNCTION__ << endl;
	}
};

struct D : public B1, public B2
{
	using B2::g;
	using B1::g;
	int b_;
	D(int a1, int a2, int b) : B1{a1}, B2{a2}, b_{b}
	{
	}
};

int main()
{
	D d(1, 2, 3);

	//cout << d.a_ << endl;
	cout << d.B1::a_ << endl;
	cout << d.B2::a_ << endl;

	d.B1::f();

	d.g(1);
	d.g('1');

	cout << static_cast<void*>(&d) << endl;
	B1 *pb1 = &d;
	cout << static_cast<void*>(pb1) << endl;
	B2 *pb2 = &d;
	cout << static_cast<void*>(pb2) << endl;

	D *pd1 = static_cast<D*>(pb1);
	D *pd2 = static_cast<D*>(pb2);
	cout << static_cast<void*>(pd1) << endl;
	cout << static_cast<void*>(pd2) << endl;

	auto pv1 = static_cast<void*>(pb2);
	auto pd3 = static_cast<D*>(pv1); // UB
	cout << static_cast<void*>(pd3) << endl;
}
