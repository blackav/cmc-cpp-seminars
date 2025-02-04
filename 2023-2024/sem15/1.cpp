#include <iostream>
#include <typeinfo>
#include <cstdint>
#include <cstdlib>

void ff(uint64_t x, uint64_t y)
{
	if (x == 0) throw y;
	try {
		ff(x - 1, y * x);
	} catch (...) {
		throw;
	}
}

using std::cin, std::cout, std::endl;

int main() try
{
	uint64_t x;
	cin >> x;

	try {
		ff(x, 1);
	} catch (int res) {
	} catch (uint64_t res) {
		cout << res << endl;
	}
} catch (...) {
	cout << "unhandled" << endl;
	abort();
}
