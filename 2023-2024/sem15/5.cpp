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
		if (v_ < 0) throw std::range_error("bad");
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
	~Ex2()
	{
		cout << __PRETTY_FUNCTION__ << " " << v_ << endl;
	}
};

struct C
{
	Ex2 x1, x2;

	C(int v1, int v2) try : x1{v1}, x2{v2}
	{
		cout << __PRETTY_FUNCTION__ << endl;
	} catch (...) {
		cout << "here" << endl;
	}
	~C()
	{
		cout << __PRETTY_FUNCTION__ << endl;
	}
};

int main() try
{
	int x, y;
	cin >> x >> y;
	C c{x, y};
} catch (...) {
	cout << "unhandled" << endl;
	abort();
}
