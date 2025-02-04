#include <iostream>
#include <memory>
#include <vector>

using std::cout, std::endl, std::shared_ptr, std::make_shared, std::weak_ptr;

struct B
{
	virtual int f() const noexcept = 0;
	virtual ~B() {};
};

// CRTP
struct A : public B, public std::enable_shared_from_this<A>
{
	int v_{};
	A(int v = 0) : v_{v}
	{
		cout << __PRETTY_FUNCTION__ << " " << v_ << endl;
	}
	~A()
	{
		cout << __PRETTY_FUNCTION__ << " " << v_ << endl;
	}

	A(const A&) = delete;
	constexpr A& operator=(const A&) = delete;

	int f() const noexcept override
	{
		cout << __PRETTY_FUNCTION__ << " " << v_ << endl;
		return v_;
	}

	shared_ptr<A> get_shared()
	{
		return shared_from_this();
	}
};

int main()
{
	shared_ptr<B> pb = make_shared<A>(1);
	cout << pb->f() << endl;

	auto pb2 = make_shared<A>(2);
	auto pb3 = pb2->get_shared();
}
