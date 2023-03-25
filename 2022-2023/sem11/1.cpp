#include <iostream>
#include <memory>

using std::cout, std::endl;

// 1: (T) v
// 2: T(v) T{v}
// static_cast, const_cast, reinterpret_cast     dynamic_cast
//
// static_cast:
//    double->int
//    int->char
//    bool->double
//    void * -> T *
//    nullptr_t -> T *
//
//
//    Base* -> Derived*
//    Base & -> Derived &
//
//    reinterpret_cast:
//      int -> T*
//      T* -> int
//      A* -> B*
//
//    const_cast:
//      const T * -> T*
//      const T & -> T&
//      volatile T * -> T*



//    dynamic_cast:
//      Base * -> Derived *
//      Base *b
//      dynamic_cast<Derived*>(b)
//        if (is_class_or_derived<Derived*>(b)) {
//          static_cast<Derived*>(b)
//        } else {
//          nullptr
//        }

class A
{
public:
    virtual ~A() {}
    virtual void add(A *)
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }
};

class B : public A
{
    void add(A *x) override
    {
        cout << __PRETTY_FUNCTION__ << endl;
        if (auto p = dynamic_cast<B*>(x); p) {
        }
    }
};

int main()
{
    std::shared_ptr<A> bp = std::make_shared<B>();

    bp->add(nullptr);
}



