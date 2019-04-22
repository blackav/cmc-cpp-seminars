#include <thread>
#include <iostream>
#include <mutex>
#include <condition_variable>

using namespace std;

constexpr int LIMIT = 1000;

void work(int serial, int &value, condition_variable &c, mutex &m, int &turn)
{
    while (1) {
        {
            unique_lock w{m};
            // ожидаем наступления события turn == serial
            c.wait(w, [&turn, &serial]() { return turn == serial; });
        }

        if (value >= 1000) {
            lock_guard w{m};
            turn = (turn + 1) % 2;
            c.notify_all();
            break;
        }
        cout << serial <<  " " << value << endl;
        ++value;

        {
            lock_guard w{m};
            turn = (turn + 1) % 2;
            c.notify_all();
        }
    }
}

int main()
{
    int value = 0;
    condition_variable c;
    mutex m;
    int turn = 0;
    thread t1(work, 0, ref(value), ref(c), ref(m), ref(turn));
    thread t2(work, 1, ref(value), ref(c), ref(m), ref(turn));

    {
        lock_guard w{m};
        c.notify_all();
    }

    t1.join();
    t2.join();
}
