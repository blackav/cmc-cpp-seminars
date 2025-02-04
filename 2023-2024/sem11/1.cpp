#include <iostream>
#include <format>

using std::cin, std::cout, std::format, std::endl;

template<typename A>
void swap(A &a, A &b)
{
	cout << __PRETTY_FUNCTION__ << endl;
	auto t = a;
	a = b;
	b = t;
}

template<typename A>
void swap(A *a, A *b)
{
	cout << __PRETTY_FUNCTION__ << "!!" << endl;
	auto t = *a;
	*a = *b;
	*b = t;
}

template<>
void swap(int &a, int &b)
{
	cout << __PRETTY_FUNCTION__ << "!" << endl;
	auto t = a;
	a = b;
	b = t;
}

template<>
void swap(int *&a, int *&b)
{
	cout << __PRETTY_FUNCTION__ << "*" << endl;
	auto t = a;
	a = b;
	b = t;
}

void swap2(auto &a, auto &b)
{
	auto t = a;
	a = b;
	b = t;
}

template<typename A, typename B>
void swap3(A &a, B &b)
{
	auto t = a;
	a = b;
	b = t;
}

int main()
{
	int x = 100, y = 200;

	swap<int>(x, y);
	cout << format("{} {}", x, y) << endl;
	
	swap(x, y);
	cout << format("{} {}", x, y) << endl;

	int *px = &x, *py = &y;
	swap(px, py);
	cout << format("{} {}", x, y) << endl;

	swap<int*>(px, py);
	cout << format("{} {}", x, y) << endl;

	swap(&x, &y);
	cout << format("{} {}", x, y) << endl;

	long xx = 1, yy = 2;
	swap(xx, yy);
	cout << format("{} {}", xx, yy) << endl;

	swap2(xx, yy);
	cout << format("{} {}", xx, yy) << endl;

}
