#include <iostream>

struct C
{
	int m[10][10]{{0, 1, 2, 3, 4}};

	int &operator[](int r, int c) { return m[r][c]; }
};

int main()
{
	C c;

	std::cout << c[0, 2] << std::endl;
}
