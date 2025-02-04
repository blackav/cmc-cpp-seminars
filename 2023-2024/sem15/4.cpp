#include <iostream>
#include <typeinfo>
#include <cstdint>
#include <cstdlib>
#include <stdexcept>

using std::cin, std::cout, std::endl;

struct Ex
{
	Ex()
	{
		cout << __PRETTY_FUNCTION__ << endl;
	}
	Ex(const Ex &other)
	{
		cout << __PRETTY_FUNCTION__ << endl;
	}
	Ex(Ex &&other)
	{
		cout << __PRETTY_FUNCTION__ << endl;
	}
	~Ex()
	{
		cout << __PRETTY_FUNCTION__ << endl;
	}
};

struct Ex2 : public Ex
{
	int v_{};
	Ex2(int v = 0) : v_{v}
	{
		cout << __PRETTY_FUNCTION__ << endl;
	}
	Ex2(const Ex2 &other) : Ex(other)
	{
		cout << __PRETTY_FUNCTION__ << endl;
	}
	Ex2(Ex2 &&other) : Ex(std::move(other))
	{
		cout << __PRETTY_FUNCTION__ << endl;
	}
	~Ex2() noexcept(false)
	{
		cout << __PRETTY_FUNCTION__ << " " << v_ << endl;
		if (v_ < 0 && !std::uncaught_exceptions()) throw std::range_error("out");
	}
};

void g(int x)
{
	Ex2 y(x);
	cout << "g" << endl;
	throw 1;
}

void f(int x)
{
	Ex2 y(x);
	cout << "f" << endl;
	g(-x);
}

int main() try
{
	int x;
	cin >> x;
	f(x);
} catch (...) {
	cout << "unhandled" << endl;
	abort();
}
