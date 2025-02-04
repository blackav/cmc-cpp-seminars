struct A
{
protected:
	enum class Kind { A, B, C, D };
	Kind kind_;
	A(Kind kind) : kind_{kind} {}

public:
	virtual ~A() = default;
};

struct B : public A
{
	B() : A(Kind::B) {}
};
