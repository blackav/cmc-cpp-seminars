#include <iostream>
#include <format>
#include <algorithm>

using std::cout, std::endl;

int main()
{
	auto f = []() {
		cout << "hello!" << endl;
	};

	f();

	auto f2 = [](int a) -> int {
		return a + 1;
	};

	cout << f2(100) << endl;

	auto f3 = [](int a) {
		return a + 2;
	};
	cout << f3(102) << endl;

	auto f4 = [](int a) -> auto {
		return a + 4;
	};
	cout << f4(111) << endl;

	auto f5 = [](auto a) {
		return a + 100;
	};
	cout << f5(200) << endl;
	cout << f5(300.0) << endl;

	/*
	auto f6 = [](int a) { a + 2; };
	cout << f6(1) << endl;
	*/
	int x = 100;
	int y = 600;

	auto f6 = [=]() { return x + y; };
	cout << f6() << endl;

	auto f7 = [&]() { ++x; return x + y; };
	cout << f7() << endl;
	cout << x << endl;

	auto f8 = [&y, x]() { ++y; return x + y; };
	cout << f8() << endl;

	auto f9 = [z=100,&x] { ++x; return x + z; };
	cout << f9() << endl;

	int arr[]{8, 7, 6, 5, 4, 3, 2, 1};
	std::sort(arr, arr + 8, [m=-1](auto x, auto y) {
		return y*m < x*m;
	});
	for (auto x : arr) {
		cout << " " << x;
	}
	cout << endl;
	cout << sizeof(f9) << endl;
}
