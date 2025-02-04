#include <iostream>
#include <vector>
#include <memory>

using std::cout, std::endl, std::vector, std::unique_ptr, std::make_unique;

struct A
{
	virtual void f() noexcept = 0; 
	virtual ~A() = default;
};

struct B: public A
{
	unique_ptr<char[]> v_;
	B()
	{
		v_ = make_unique<char[]>(1024);
	}
	void f() noexcept override
	{
		cout << __PRETTY_FUNCTION__ << endl;
	}
	~B()
	{
		cout << __PRETTY_FUNCTION__ << endl;
	}
};

struct C: public A
{
	unique_ptr<int[]> v_;
	C()
	{
		v_ = make_unique<int[]>(1024);
	}
	void f() noexcept override
	{
		cout << __PRETTY_FUNCTION__ << endl;
	}
	~C()
	{
		cout << __PRETTY_FUNCTION__ << endl;
	}
};

int main()
{
	vector<unique_ptr<A>> v;

	v.emplace_back(make_unique<B>());
	v.emplace_back(make_unique<B>());
	v.emplace_back(make_unique<C>());
	v.emplace_back(make_unique<C>());

	for (auto &p : v) {
		p->f();
	}
}
