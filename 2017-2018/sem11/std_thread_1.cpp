#include <iostream>
#include <thread>
#include <array>

#include <unistd.h>

using namespace std;

int thrfunc(int x)
{
    for (int y = 0; y < 10; ++y) {
        cout << x + y << endl;
    }
    return x;
}

constexpr int CNT = 20;

int main()
{
    array<thread, CNT> ts;

    for (int i = 0; i < CNT; ++i) {
        thread t(thrfunc, i * 100);
        ts[i] = move(t);
    }

    for (auto &t: ts) {
        t.join();
    }
}
