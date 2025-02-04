#include <vector>
#include <iostream>
#include <format>
#include <iterator>

using std::cout, std::endl, std::vector;

struct A
{
	int v_{};
	A(int v = 0) : v_(v) {}

	A(const A& other) : v_(other.v_)
	{
		cout << __PRETTY_FUNCTION__ << " " << v_ << endl;
	}
	A(A &&other) noexcept : v_(other.v_)
	{
		other.v_ = 0;
		cout << __PRETTY_FUNCTION__ << " " << v_ << endl;
	}
};

std::ostream &
operator <<(std::ostream &f, const A& a)
{
	f << a.v_;
	return f;
}

int main()
{
	vector<A> v1;
	v1.reserve(100);

	v1.push_back(A(100));
	v1.push_back(200);

	A a1 = 300;
	A a2 = 400;
	A a3 = 500;
	v1.push_back(a1);
	v1.push_back(std::move(a2));
	cout << a2.v_ << endl;
	v1.push_back((A&&) a3);

	v1.emplace_back(600);

	auto i1 = v1.begin();
	i1 += 2;

	auto i2 = v1.begin();
	std::advance(i2, 2);
	cout << *i2 << endl;
	
}
