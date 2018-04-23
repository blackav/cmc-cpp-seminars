#include <thread>
#include <iostream>

using namespace std;

int value;

void func(int n)
{
    // если исключение не обрабатывается в нити, программа падает
    if (n == 2) throw 10;
    cout << value++ << endl;
}

int main()
{
    cout << "start" << endl;
    thread t1(func, 1);
    thread t2(func, 2);
    thread t3(func, 3);

    t1.join();
    t2.join();
    t3.join();
    cout << "end" << endl;
}
