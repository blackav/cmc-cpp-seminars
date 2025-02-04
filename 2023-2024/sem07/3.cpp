#include <iostream>

using std::cout, std::endl;

struct lambda_f2
{
	int a;
	int &b;

	lambda_f2(int a_, int &b_) : a(a_), b(b_) {}
	int operator()(int c)
	{
		return a + b + c;
	}
};

int main()
{
	int a = 100;
	int b = 200;

	auto f1 = [a, &b](int c) { return a + b + c; };
	cout << f1(300) << endl;

	lambda_f2 f2{a, b};
	cout << f2(300) << endl;
	
}
