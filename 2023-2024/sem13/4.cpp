#include <cassert>

struct Figure
{
	virtual int square() const noexcept = 0;
	virtual ~Figure() {}
};

struct Rectangle : public Figure
{
	int a_{}, b_{};

	Rectangle(int a, int b): a_(a), b_(b) {}

	int a() const noexcept { return a_; }
	int b() const noexcept { return b_; }

	int square() const noexcept override
	{
		return a_ * b_;	
	}

	virtual void set_a(int a) noexcept { a_ = a; }
	virtual void set_b(int b) noexcept { b_ = b; }
};

struct Square : public Figure
{
};

int main()
{
	Rectangle *pr = new Square(100);

	pr->set_a(200);

	pr->set_a(100);
	pr->set_b(200);
	assert(pr->a() == 100);

	
}
