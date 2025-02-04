#include <iostream>
#include <typeinfo>
#include <cstdint>
#include <cstdlib>

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
	char data[8*1024*1024];
	Ex2()
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
	~Ex2()
	{
		cout << __PRETTY_FUNCTION__ << endl;
	}
};

void f(int x)
{
	if (x < 0) {
		throw Ex2();
	}
}

int main() try
{
	int x;
	cin >> x;
	try {
		f(x);
	} catch (Ex &x) {
		cout << "Ex" << endl;
		throw;
	} catch (Ex2 &x) {
		cout << "Ex2" << endl;
	}
} catch (...) {
	cout << "unhandled" << endl;
	abort();
}
