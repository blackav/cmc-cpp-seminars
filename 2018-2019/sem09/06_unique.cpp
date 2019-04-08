#include <memory>
#include <iostream>
#include <vector>

using namespace std;

/*
использование unique_ptr
 */

struct A
{
    int z{};

    A(int z) : z(z) {}

    // объекты этого класса нельзя ни копировать, ни переносить
    A(const A&) = delete;
    A(A&&) = delete;

    auto getz() const { return z; }
};

int main()
{
    unique_ptr<A> up1(new A(1));

    if (up1) { // <- определен operator bool, как для указателей
        cout << up1->getz() << endl;  // определена операция -> как для указателей
    }

    auto up2 = move(up1);
    // теперь up1 "пустой"
    if (up1) {
        cout << up1->getz() << endl;
    }
    // а указатель "переехал" в up2
    if (up2) {
        cout << up2->getz() << endl;
    }

    // вектор элементов unique_ptr
    vector<unique_ptr<A>> va;
    va.push_back(move(up2));

    // в unique_ptr можно хранить массивы
    unique_ptr<A[]> ma1(new A[3]{1, 2, 3});
    cout << ma1[2].getz() << endl;

    // полезная функция make_unique, которая возвращает уже готовый unique_ptr
    auto zz = make_unique<A>(100);
    cout << zz->getz() << endl;
}
