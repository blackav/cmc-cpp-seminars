#include <iostream>
#include <memory>

using namespace std;

struct Resource
{
    Resource()
    {
        cout << "Resource()" << endl;
    }
    Resource(const Resource &other)
    {
        cout << "Resource(const Resource &)" << endl;
    }
    ~Resource()
    {
        cout << "~Resource()" << endl;
    }
};

struct Bad
{
    Bad()
    {
        cout << "Bad()" << endl;
        throw 1;
    }
    ~Bad()
    {
        cout << "~Bad()" << endl;
    }
};

struct Holder
{
    Resource *r1 = nullptr;
    Bad r2;
    Resource r3;

    Holder() 
        try : r1(new Resource()), r2(), r3() 
    {
        cout << "Holder()" << endl;
    } catch (...) {
        delete r1;
    }
    ~Holder()
    {
        cout << "~Holder()" << endl;
        delete r1;
    }
};

int main() try
{
    Holder h;
} catch (...) {
}

