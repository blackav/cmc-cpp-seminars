#include <iostream>
#include <memory>
#include <vector>

using std::cout, std::endl;
using std::unique_ptr;

struct A
{
	int x_{0};
	A(int x = 0) : x_{x}
	{
		cout << __PRETTY_FUNCTION__ << " " << x_ << endl;
	}
	virtual ~A()
	{
		cout << __PRETTY_FUNCTION__ << " " << x_ << endl;
	}
	A(const A&) = delete;
	void operator=(const A&) = delete;
	virtual unique_ptr<A> clone()
	{
		cout << __PRETTY_FUNCTION__ << " " << x_ << endl;
		return std::make_unique<A>(x_);
	}
};

struct B : A
{
	int y_{1};
	B(int x = 0, int y = 1):A(x), y_(y)
	{
		cout << __PRETTY_FUNCTION__ << " " << x_ << " " << y_ << endl;
	}
	~B()
	{
		cout << __PRETTY_FUNCTION__ << " " << y_ << endl;
	}
	unique_ptr<A> clone() override
	{
		cout << __PRETTY_FUNCTION__ << " " << x_ << " " << y_ << endl;
		return std::make_unique<B>(x_, y_);
	}
};

void f(unique_ptr<A> u3)
{
	cout << __PRETTY_FUNCTION__ << endl;
}

void f2(unique_ptr<A> p1, unique_ptr<A> p2)
{
}

int main()
{
	unique_ptr<A> u1{new A{1}};
	{
		auto u2 = std::move(u1);
		f(std::move(u2));
		cout << "before end 2" << endl;
	}
	cout << "before end" << endl;

	std::vector<unique_ptr<A>> v1;
	v1.emplace_back(new A{400});	
	v1.emplace_back(new A{401});	
	v1.push_back(unique_ptr<A>(new A{402}));

	unique_ptr<A> u3{new A{403}};
	v1.push_back(std::move(u3));

	unique_ptr<A[]> u4{new A[4]{501, 502, 503, 504}};

	cout << v1[0]->x_ << endl;

	unique_ptr<A> u5{new B{600, 601}};

	std::vector<A*> vv1; // bad!
	std::vector<std::unique_ptr<A>> vv2; // good

	//f2(unique_ptr<A>{new A{1000}}, unique_ptr<A>{new A{1001}});
	f2(std::make_unique<A>(1000), std::make_unique<A>(1001));
	auto u6 = std::make_unique<A>();

	unique_ptr<A> u7 = std::make_unique<B>(4,5);
	auto u8 = u7->clone();
}
