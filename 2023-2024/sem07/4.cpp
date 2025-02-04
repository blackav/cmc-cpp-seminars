#include <iostream>
#include <functional>

using std::cout, std::endl;

auto f(int a) -> std::function<int(int)>
{
	int b{1000};
	return [a,&b](int c) { return a + b + c; };
}

int main()
{
	auto f2 = f(2000);
	cout << "hello!"<< endl;
	cout << f2(3000) << endl;
}
