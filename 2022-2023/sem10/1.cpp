#include <iostream>
#include <memory>

using std::cout, std::endl, std::shared_ptr, std::weak_ptr, std::make_shared;

struct A
{
    A() { cout << __PRETTY_FUNCTION__ << endl; }
    ~A() { cout << __PRETTY_FUNCTION__ << endl; }

    void g() const { cout << __PRETTY_FUNCTION__ << endl; }
};

int main()
{
    auto p1 = make_shared<A>();
    auto p2 = make_shared<A>();

    p2->g();

    {
        weak_ptr<A> w1(p1);

        if (auto p3 = w1.lock(); p3) {
            p3->g();
        }

        weak_ptr<A> w2(p2);

        p2.reset();

        if (auto p3 = w2.lock(); p3) {
            p3->g();
        } else {
            cout << "nullptr" << endl;
        }
    }
}
