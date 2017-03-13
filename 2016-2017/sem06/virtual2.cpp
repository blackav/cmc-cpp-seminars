#include <iostream>
#include <vector>

using namespace std;

struct A
{
    int a{10};
    A(int a) : a(a) {}

    //A() = default;

    virtual string f(int z)
    {
        return "A::f:" + to_string(z);
    }
    virtual ~A()
    {
        cout << "A::~A()" << endl;;
    }
};

struct B : A
{
    string s;

    B(const string &s) : A(25), s(s + "asdfsadfsadfsadfsadfsadfsdfsadfsadfsdf") {}

    string f(int z) override
    {
        return "B::f:" + to_string(z);
    }
    ~B()
    {
        cout << "B::~B()" << endl;;
    }
};

int main()
{
    int z;
    vector<A*> vpa;
    
    while (cin >> z) {
        A *pa = nullptr;
        if (z > 0) pa = new A(z);
        else pa = new B(to_string(z));
        vpa.push_back(pa);
    }

    for (size_t i = 0; i < vpa.size(); ++i) {
        cout << vpa[i]->f(i + 1) << endl;
    }

    for (auto p : vpa) {
        delete p;
    }
}


