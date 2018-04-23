#include <thread>
#include <iostream>
#include <mutex>
#include <condition_variable>
#include <cstdint>
#include <unistd.h>
#include <atomic>
#include <future>

using namespace std;

unsigned work(unsigned low, unsigned high)
{
    for (unsigned val = low; val < high; ++val) {
        //if (val == 1000002) throw 1024;
        if (val % 2) {
            int j;
            for (j = 3; j * j <= val; j += 2) {
                if (!(val % j)) break;
            }
            if (j * j > val) {
                return val;
            }
        } 
    }
}

// использование packaged_task

int main()
{
    packaged_task<unsigned (unsigned, unsigned)> pt(work);

    future<unsigned> fut = pt.get_future();
    thread thr1(move(pt), 1000000, 20000000);

    try {
        unsigned value = fut.get();
        cout << value << endl;
    } catch (int v) {
        cout << "exception " << v << endl;
    }
    thr1.join();
}
