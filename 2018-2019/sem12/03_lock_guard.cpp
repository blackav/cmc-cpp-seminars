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
                // стандартная простая RAII-обертка над мьютексами: lock_guard
                std::lock_guard<std::mutex> w{m};
                // в C++-17 можно писать просто std::lock_guard w{m};
                value1 += diff;
                value2 -= diff;
            }
        }, (i + 1) * 100);
    }
    for (auto &t : threads)
        t.join();
    std::cout << value1 << "\n" << value2 << "\n";
}
