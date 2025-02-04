#include <iostream>
#include <vector>

using std::cout, std::endl;

struct A
{
	int x_{0};
	A(int x = 0) : x_{x}
	{
		cout << __PRETTY_FUNCTION__ << " " << x_ << endl;
	}
	virtual ~A()
	{
		cout << __PRETTY_FUNCTION__ << " " << x_ << endl;
	}
};

struct B : A
{
	int y_{1};
	B(int x = 0, int y = 1):A(x), y_(y)
	{
		cout << __PRETTY_FUNCTION__ << " " << x_ << " " << y_ << endl;
	}
	~B()
	{
		cout << __PRETTY_FUNCTION__ << " " << y_ << endl;
	}
};

int main()
{
	A a1{10};

	A* p1 = new A{20};

	delete p1;

	A* p2 = new A[2]{31, 32};
	
	A* p3 = new A[1]{45};

	delete []p2;

	delete []p3;

	A* q1 = new B(100, 101);
	delete q1;

	void *vp = ::operator new (sizeof(A) * 2);
	auto q2 = new (vp) A{1000};
	auto q3 = new ((void*) ((A*) vp + 1)) A{1001};
	//auto q3 = new (vp) A{1001};

	q3->~A();
	q2->~A();
	::operator delete(vp);
	//free(vp);

	void *vp2 = ::operator new (sizeof(A) * 4);
	auto q4 = new (vp2) A[4]{2001, 2002, 2003, 2004};

	q4[3].~A();
	q4[2].~A();
	q4[1].~A();
	q4[0].~A();

	::operator delete(vp2);
}
