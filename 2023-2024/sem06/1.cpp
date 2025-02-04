#include <iostream>

struct A
{
	int v_{};

	A(int v) : v_(v) {}

	int &operator[](int x) noexcept
	{
		v_ += x;
		return v_;
	}
	int operator[](int x) const noexcept
	{
		return v_ + x;
	}

	struct AA
	{
		int operator[](size_t y) noexcept
		{
			return 100500;
		}
	};

	AA operator[](char x) noexcept
	{
		return {};
	}

	int &operator[](size_t x, size_t y) noexcept
	{
		v_ += x + y;
		return v_;
	}
};

int main()
{
	A a(10);
	const A b(20);
	int c[] = {1, 2, 3};

	std::cout << a[15] << std::endl;
	std::cout << b[20] << std::endl;

	std::cout << a['x'][20] << std::endl;

	std::cout << a[10, 15] << std::endl;
	std::cout << c[1, 2] << std::endl;
}
