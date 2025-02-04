#include <iostream>

using std::cout, std::endl;

struct B
{
	virtual void f()
	{
		cout << __PRETTY_FUNCTION__ << " " << endl;
	}
	virtual void f(int x)
	{
		cout << __PRETTY_FUNCTION__ << " " << x << endl;
	}
	virtual ~B() {}
};

struct D : public B
{
	void f(int x = 20) override
	{
		cout << __PRETTY_FUNCTION__ << " " << x << endl;
	}
};

int main()
{
	B *pb1 = new B;
	B *pb2 = new D;
	D *pd = new D;

	pb1->f();
	pb1->f(1);
	pb2->f(); ///// ! pb2->f(10);
	pb2->f(2);
	pd->f();
	pd->f(3);
	
}
