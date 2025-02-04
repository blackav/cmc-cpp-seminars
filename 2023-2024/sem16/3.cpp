#include <iostream>
#include <memory>
#include <cstddef>

using std::cin, std::cout, std::endl;

struct BB
{
	int x_;
	BB(int x = 0) : x_{x}
	{
	}
	virtual ~BB()
	{
		cout << __PRETTY_FUNCTION__ << endl;
	}
};

struct B1 : public BB
{
	// B1::VTBL[] = { &B1::~B1(), &B1::v1 }
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

	virtual ~B1()
	{
		cout << __PRETTY_FUNCTION__ << endl;
	}
	virtual void v1()
	{
		cout << __PRETTY_FUNCTION__ << endl;
	}
};

struct B2 : public BB
{
	// B2::VTBL[] = { &B2::~B2(), &B2::v2 }
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

	virtual ~B2()
	{
		cout << __PRETTY_FUNCTION__ << endl;
	}
	virtual void v2()
	{
		cout << __PRETTY_FUNCTION__ << endl;
	}
};

struct D : public B1, public B2
{
	// D::VTBL<B1>[] = { &D::~D, &B1::v1, D::v2 }

	// [16] D::VTBL<B2>[] = { &trampoline<D::~D>, &B2::v2, ? };

	using B2::g;
	using B1::g;
	int b_;
	D(int a1, int a2, int b) : B1{a1}, B2{a2}, b_{b}
	{
	}
	~D()
	{
		cout << __PRETTY_FUNCTION__ << endl;
	}
	virtual void v3()
	{
		cout << __PRETTY_FUNCTION__ << endl;
	}
};

int main()
{
	using std::unique_ptr, std::make_unique;
	unique_ptr<B1> u1 = make_unique<D>(4,5,6);
	unique_ptr<B2> u2 = make_unique<D>(10, 11, 12);

	cout << sizeof(BB) << endl;
	cout << sizeof(B1) << endl;
	cout << sizeof(B2) << endl;
	cout << sizeof(D) << endl;

	cout << offsetof(BB, x_) << endl;
	cout << offsetof(B1, x_) << endl;
	cout << offsetof(B1, a_) << endl;
	cout << offsetof(B2, x_) << endl;
	cout << offsetof(B2, a_) << endl;
	cout << offsetof(D, B1::x_) << endl;
	cout << offsetof(D, B1::a_) << endl;
	cout << offsetof(D, B2::x_) << endl;
	cout << offsetof(D, B2::a_) << endl;
	cout << offsetof(D, b_) << endl;

	u1->v1();
	u2->v2();
}
