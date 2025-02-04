#include <iostream>
#include <memory>
#include <vector>

template<typename T>
class myunique_ptr
{
	T *p_{};
public:
	myunique_ptr() = default;
	myunique_ptr(T *p) noexcept : p_{p} {}
	myunique_ptr(const myunique_ptr &o) = delete;
	myunique_ptr(myunique_ptr &&o) noexcept : p_{o.p_}
	{
		o.p_ = nullptr;
	}
	~myunique_ptr()
	{
		delete p_;
	}
	T* operator ->() noexcept { return p_; }
	const T* operator ->() const noexcept { return p_; }
};

template<typename T>
class myshared_ptr
{
	struct control_block
	{
		size_t nref{};
		T* ptr{};
	};

	control_block *cb_{};

public:
	myshared_ptr() = default;
	myshared_ptr(T *p)
	{
		cb_ = new control_block;
		cb_->nref = 1;
		cb_->ptr = p;
	}
	myshared_ptr(const myshared_ptr &o) noexcept : cb_{o.cb_}
	{
		if (cb_) {
			++cb_->nref;
		}
	}
	~myshared_ptr()
	{
		if (cb_) {
			if (!--cb_->nref) {
				delete cb_->ptr;
				delete cb_;
			}
		}
	}
	T *operator->() noexcept
	{
		return cb_->ptr;
	}
};

using std::cout, std::endl, std::shared_ptr, std::make_shared;

struct A
{
	int v_{};
	A(int v = 0) : v_{v}
	{
		cout << __PRETTY_FUNCTION__ << " " << v_ << endl;
	}
	~A()
	{
		cout << __PRETTY_FUNCTION__ << " " << v_ << endl;
	}

	A(const A&) = delete;
	constexpr A& operator=(const A&) = delete;
};

template <typename T>
myshared_ptr<T> mymake_shared()
{
	constexpr size_t a = alignof(myshared_ptr<T>::control_block);
	constexpr size_t s = sizeof(myshared_ptr<T>::control_block);
	size_t t = (sizeof(T) + a - 1) & ~(a - 1) + s;
	void *p = ::operator new((sizeof(T) + a - 1) & ~(a - 1) + s);
	T *pt = new (p) T();
	std::align(a, s, p, t);
	typename myshared_ptr<T>::control_block *cb = new (p) typename myshared_ptr<T>::control_block;
	myshared_ptr<T> res{};
	res->cb_ = cb;
	cb->nref = 1;
	cb->ptr = pt;
	return res;
}

int main()
{
	auto pa = make_shared<A>(100);
	
	std::vector<shared_ptr<A>> v(10, pa);
	v[5]->v_ = 200;

	cout << pa->v_ << endl;
	pa.reset();
}
