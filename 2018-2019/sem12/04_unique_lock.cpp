#include <thread>
#include <vector>
#include <iostream>
#include <mutex>

constexpr int COUNT = 5;
constexpr int ITER = 10000000;

long long value1 = 0;
long long value2 = 0;
std::mutex m;

int main()
{
    std::vector<std::thread> threads;
    for (int i = 0; i < COUNT; ++i) {
        threads.emplace_back([](int diff) {
            for (int i = 0; i < ITER; ++i) {
                // другая RAII-обертка над мьютексами: unique_lock<T>
                // unique_lock можно использовать в condition_variable
                std::unique_lock w{m};
                value1 += diff;
                value2 -= diff;
            }
        }, (i + 1) * 100);
    }
    for (auto &t : threads)
        t.join();
    std::cout << value1 << "\n" << value2 << "\n";
}
