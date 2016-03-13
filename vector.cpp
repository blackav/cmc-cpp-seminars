#include <vector>
#include <iostream>

using namespace std;

using vi = vector<int>; // то же самое, что и typedef vector<int> vi; но C++14

int main()
{
    vi v1;                       // пустой вектор
    vi v2(10);                   // вектор из 10 нулевых элементов
    vi v3(4, 25);                // вектор из 4 элементов со значением 25
    vi v4{1, 2, 3, 4, 5, 6, 7};  // вектор размера 7 инициализированный 1..7
    vi v5{10, 11};               // вектор размера 2 со значениями 10, 11

    // сколько памяти зарезервировано
    cout << v5.size() << "," << v5.capacity() << endl;

    // резервируем память под 100 элементов, размер вектора не меняется
    v5.reserve(100);

    cout << v5.size() << "," << v5.capacity() << endl;

    v5.resize(12, 373);  // расширяем вектор до размера 12, дополняя его значениями 373
    cout << v5.size() << "," << v5.capacity() << endl;

    // итераторы
    std::vector<int>::iterator i1;
    std::vector<int>::const_iterator i2;
    std::vector<int>::reverse_iterator i3;
    std::vector<int>::const_reverse_iterator i4;

    // прямой проход по вектору
    for (i1 = v5.begin(); i1 != v5.end(); ++i1) {
        cout << *i1 << endl;
    }

    // вставка в вектор на позицию перед элементом [1]
    v5.insert(v5.begin() + 1, 25);

    // обратный проход по вектору
    for (i3 = v5.rbegin(); i3 != v5.rend(); ++i3) {
        cout << *i3 << endl;
    }

}
