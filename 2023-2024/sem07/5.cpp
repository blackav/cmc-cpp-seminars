#include <iostream>
#include <vector>

using std::cout, std::endl, std::vector;

int main()
{
	vector<int> v1;
	vector<int> v2(10);
	cout << v2.size() << endl;

	vector<double> v3(8, 0.5);
	cout << v3.size() << endl;
	cout << sizeof(v3) << endl;

	vector<int> v4{1, 2, 3, 4, 5, 6};
	vector v5{3.0, 4.0};
	cout << v4.capacity() << endl;
	v4.push_back(7);
	cout << v4.capacity() << endl;
	v4.reserve(1024);
	cout << v4.size() << endl;
	cout << v4.capacity() << endl;
	v4.shrink_to_fit();
	cout << v4.capacity() << endl;

	for (vector<int>::iterator ii = v4.begin(); ii != v4.end(); ++ii) {
		cout << " " << *ii;
}
	cout << endl;

	for (vector<int>::const_iterator ii = v4.cbegin(); ii != v4.cend(); ++ii) {
		cout << " " << *ii;
}
	cout << endl;

	for (vector<int>::reverse_iterator ii = v4.rbegin(); ii != v4.rend(); ++ii) {
		cout << " " << *ii;
}
	cout << endl;

	for (vector<int>::const_reverse_iterator ii = v4.crbegin(); ii != v4.crend(); ++ii) {
		cout << " " << *ii;
}
	cout << endl;

	for (auto ii = v4.crbegin(); ii != v4.crend(); ++ii) {
		cout << " " << *ii;
	}
	cout << endl;

	for (auto x : v4) {
		cout << " " << x;
	}
	cout << endl;
}
