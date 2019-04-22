#include <thread>
#include <vector>
#include <iostream>
#include <mutex>
#include <array>

/*
обедающие философы
 */

constexpr int COUNT = 5;
constexpr int ITER = 10000000;

std::array<long long, COUNT> values;
std::array<std::mutex, COUNT> mutexes;

int main()
{
    std::vector<std::thread> threads;
    for (int i = 0; i < COUNT; ++i) {
        threads.emplace_back([](int serial, int diff) {
            for (int i = 0; i < ITER; ++i) {
                // необходимо захватить сразу два mutex, причем в правильном порядке
                // scoped_lock не равнозначен двум lock_guard
                std::scoped_lock w(mutexes[serial], mutexes[(serial + 1) % COUNT]);
                values[serial] += diff;
                values[(serial + 1) % COUNT] -= diff;
            }
        }, i, (i + 1) * 100);
    }
    for (auto &t : threads)
        t.join();
    for (auto x : values)
        std::cout << x << std::endl;
}
