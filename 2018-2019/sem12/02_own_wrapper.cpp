#include <thread>
#include <vector>
#include <iostream>
#include <mutex>

constexpr int COUNT = 5;
constexpr int ITER = 10000000;

long long value1 = 0;
long long value2 = 0;
std::mutex m;

// простая RAII-обертка над мьютексом
class Wrapper
{
    std::mutex &m;
public:
    Wrapper(std::mutex &m) : m(m) { m.lock(); }
    ~Wrapper() { m.unlock(); }
};

int main()
{
    std::vector<std::thread> threads;
    for (int i = 0; i < COUNT; ++i) {
        threads.emplace_back([](int diff) {
            for (int i = 0; i < ITER; ++i) {
                Wrapper w{m}; // m.unlock вызовется автоматически при выходе из блока (в конце каждой итерации цикла)
                value1 += diff;
                value2 -= diff;
            }
        }, (i + 1) * 100);
    }

    for (auto &t : threads)
        t.join();
    std::cout << value1 << "\n" << value2 << "\n";
}
