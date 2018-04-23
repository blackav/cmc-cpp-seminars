#include <thread>
#include <iostream>
#include <mutex>
#include <condition_variable>
#include <cstdint>
#include <unistd.h>
#include <atomic>

using namespace std;

/*
 * condition_variable используется для пересылки
 * простого числа из нити в основную программу
 */

unsigned prime;
condition_variable c;
mutex m;

// работа с atomic-типами не приводит к data race
atomic<bool> flag{false};

void work(unsigned low, unsigned high)
{
    for (unsigned val = low; val < high; ++val) {
        if (flag) break;
        if (val % 2) {
            int j;
            for (j = 3; j * j <= val; j += 2) {
                if (!(val % j)) break;
            }
            if (j * j > val) {
                // send to main
                {
                    lock_guard lg(m);
                    prime = val;
                    c.notify_one();
                }
            }
        } 
    }
}

int main()
{
    thread thr1(work, 1000000, 20000000);

    for (int i = 0; i < 10; ++i) {
        // receive from work
        unsigned local;
        {
            unique_lock lk(m);
            c.wait(lk, [] { return prime != 0; });
            local = prime;
            prime = 0;
        }
        cout << local << endl;
        usleep(100);
    }
    flag = true;

    thr1.join();
}
