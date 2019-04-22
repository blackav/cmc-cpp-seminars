#include <thread>
#include <iostream>
#include <mutex>
#include <condition_variable>

using namespace std;

constexpr int LIMIT = 1000;

void work(
        int serial,
        int &value,
        condition_variable &self,  // condvar, на котором ждем
        condition_variable &other, // condvar, который уведомляем
        mutex &m,                  // для критической секции
        bool &sf,                  // флаг, который проверям
        bool &of)                  // флаг, который устанавливаем
{
    while (1) {
        // операции с condvar выполняются в критической секции!
        // для ожидания на condvar нужен unique_lock
        {
            unique_lock w{m};
            // ждем наступления условия завершения ожидания
            // while нужен, так как бывают "неожиданные" (spurious) пробуждения
            while (!sf)
                self.wait(w);
            sf = false;
        }

        if (value >= 1000) {
            // отправляем уведомление в другую нить, чтобы она тоже завершилась
            lock_guard w{m};
            of = true;
            other.notify_one();
            break;
        }

        cout << serial <<  " " << value << endl;
        ++value;

        // уведомляем другую нить
        // здесь для критической секции достаточно lock_guard
        {
            lock_guard w{m};
            of = true;
            other.notify_one();
        }
    }
}

int main()
{
    int value = 0;
    condition_variable c1;
    condition_variable c2;
    mutex m;
    bool f1{}, f2{};
    thread t1(work, 0, ref(value), ref(c1), ref(c2), ref(m), ref(f1), ref(f2));
    thread t2(work, 1, ref(value), ref(c2), ref(c1), ref(m), ref(f2), ref(f1));

    // отправляем уведомление первой нити
    {
        std::lock_guard w{m};
        f1 = true;
        c1.notify_one();
    }

    t1.join();
    t2.join();
}
