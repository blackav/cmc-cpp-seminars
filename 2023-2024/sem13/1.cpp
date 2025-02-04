struct A
{
	struct Impl;
	unique_ptr<Impl> pimpl;

	int get_x() const noexcept;
};

struct B
{
	shared_ptr<A> pa;
};

/////
struct C
{
};

struct D
{
	C c;

	int get_x() const noexcept { return c.get_x(); }
};


/////
struct P
{
};

struct Q : public P
{
	// P _;
	//
	//
	//
	//
	void get_x() const noexcept {
		int x;

		cout << x;
	}
};


