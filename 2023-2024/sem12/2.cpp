#include <iostream>
#include <memory>
#include <vector>

using std::cout, std::endl, std::shared_ptr, std::make_shared, std::weak_ptr;

struct A
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
};

int main()
{
	auto pa1 = make_shared<A>(1);
	auto pa2 = make_shared<A>(2);

	weak_ptr wa1{pa1};
	cout << pa1->v_ << endl;

	if (auto pa3 = wa1.lock(); pa3) {
		cout << pa3->v_ << endl;
	}

	pa1 = pa2;
	if (auto pa3 = wa1.lock(); pa3) {
		cout << "!" << pa3->v_ << endl;
	}

}
