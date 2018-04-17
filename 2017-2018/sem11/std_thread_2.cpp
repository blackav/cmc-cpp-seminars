#include <thread>
#include <iostream>

using namespace std;

struct Foo
{
    int x;
    Foo(int x) : x(x) {}

    void run(int y)
    {
        cout << x + y << endl;
    }

    void start(int y)
    {
        // так работает
        thread t(&Foo::run, this, y);
        t.join();

        // более "прямолинейный" способ
        thread t2([this](int y) { return run(y); }, y);
        t2.join();
    }
};

int main()
{
    // передача ссылки на объект класса в замыкании
    Foo f1(1);
    thread t1([&f1](int x) { f1.run(x); }, 2);
    t1.join();

    // но так тоже работает
    Foo f2(1);
    thread t2(&Foo::run, f2, 2);
    t2.join();

    Foo f3(10);
    f3.start(14);
}
