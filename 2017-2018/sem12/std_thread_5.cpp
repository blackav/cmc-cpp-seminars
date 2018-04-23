#include <thread>
#include <iostream>
#include <mutex>
#include <condition_variable>
#include <cstdint>
#include <unistd.h>
#include <atomic>
#include <future>

using namespace std;

// использование promise/future

void work(unsigned low, unsigned high, promise<unsigned> &pr)
{
    try {
        for (unsigned val = low; val < high; ++val) {
            if (val == 1000002) throw 1024;
            if (val % 2) {
                int j;
                for (j = 3; j * j <= val; j += 2) {
                    if (!(val % j)) break;
                }
                if (j * j > val) {
                    pr.set_value(val);
                    break;
                }
            } 
        }
    } catch (...) {
        pr.set_exception(current_exception());
    }
}

int main()
{
    promise<unsigned> pr;
    thread thr1(work, 1000000, 20000000, ref(pr));

    future<unsigned> fut = pr.get_future();
    try {
        unsigned value = fut.get();
        cout << value << endl;
    } catch (int v) {
        cout << "exception " << v << endl;
    }

    thr1.join();
}
