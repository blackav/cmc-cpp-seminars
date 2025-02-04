#include <iostream>
#include <iterator>
#include <array>
#include <deque>
#include <list>

using std::cout, std::endl;
using std::array;

void f1(int v[64])
{
}

void f2(array<int,64> v)
{
}

int main()
{
	int a1[64];
	array<int,64> a2;

	cout << sizeof(a1) << endl;
	cout << sizeof(a2) << endl;

	std::deque<double> dd;

	dd.push_back(1.0);
	dd.push_front(2.0);

	dd.pop_back();
	dd.pop_front();

	std::list<int> l1{1, 2, 3, 4, 5};
}
