#include <thread>
#include <iostream>

using namespace std;

// thread_local storage (TLS)
// переменная создается при запуске нити и уничтожается при завершении нити
thread_local int value = 20;

struct Foo
{
    Foo() { cout << "Foo()" << endl; }
    ~Foo() { cout << "~Foo()" << endl; }
};

// реализация паттерна Singleton
// (https://en.wikipedia.org/wiki/Singleton_pattern)
Foo & getFoo()
{
    // конструктор foo будет вызван при первом вызове getFoo
    // причем вызов конструктора будет thread-safe
    static Foo foo{};
    return foo;
}

void func()
{
    func2();
    cout << value++ << endl;
}

int main()
{
    cout << "start" << endl;
    thread t1(func);
    thread t2(func);
    thread t3(func);

    t1.join();
    t2.join();
    t3.join();
    cout << "end" << endl;
}
