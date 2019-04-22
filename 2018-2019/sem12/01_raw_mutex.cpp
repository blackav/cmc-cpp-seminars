#include <thread>
#include <vector>
#include <iostream>
#include <mutex>

constexpr int COUNT = 5;
constexpr int ITER = 10000000;

long long value1 = 0;
long long value2 = 0;

// мьютекс для организации критической секции
std::mutex m;

int main()
{
    std::vector<std::thread> threads;
    for (int i = 0; i < COUNT; ++i) {
        threads.emplace_back([](int diff) {
            for (int i = 0; i < ITER; ++i) {
                m.lock();   // захват мьютекса
                value1 += diff;
                value2 -= diff;
                m.unlock(); // освобождение мьютекса
            }
        }, (i + 1) * 100);
    }

    for (auto &t : threads)
        t.join();
    std::cout << value1 << "\n" << value2 << "\n";
}
