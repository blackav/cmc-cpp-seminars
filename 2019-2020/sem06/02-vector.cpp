/* -*- mode: c++; c-basic-offset: 4 -*- */

/*
  std::vector
  https://en.cppreference.com/w/cpp/container/vector
 */

#include <vector>
#include <iostream>
#include <string>

int main()
{
    // для векторов работает uniform initializer
    // начиная с C++-17 поддерживается автовывод типа элемента вектора
    std::vector v1{1, 2, 3};

    // это будет std::vector<const char *>
    std::vector vs{"a", "b", "c"};

    // поэтому для строк нужно указать тип явно
    std::vector<std::string> v2{"a", "b", "c"};

    // это вектор с начальным размером 10, каждый 10 элементов проинициализирован значением 0.5
    std::vector<double> v3(10, 0.5);

    // количество элементов в векторе
    std::cout << v2.size() << std::endl;

    // размер, зарезервированный для размещения элементов
    // перевыделения памяти не будет, пока size() <= capacity()
    std::cout << v2.capacity() << std::endl;

    // в std::vector можно
    // 1) добавлять элементы в конец (push_back)
    // 2) удалять элементы из конца (pop_back)
    
    double z;
    while (std::cin >> z) {
        // добавление в конец вектора
        // push_back может перемещать данные на другое место в памяти
        v3.push_back(z);
        std::cout << v3.size() << "," << v3.capacity() << std::endl;
    }

    // удаление 3 элементов из начала вектора (со сдвигом оставшихся элементов на место удаленных)
    v3.erase(v3.begin(), v3.begin() + 3);
    // удаление не приводит к перевыделению памяти
    std::cout << v3.size() << "," << v3.capacity() << std::endl;

    // shrink_to_fit перевыделяет память, чтобы размер выделенной памяти стал равен размеру вектора
    v3.shrink_to_fit();
    std::cout << v3.size() << "," << v3.capacity() << std::endl;

    // цикл по всем элементам вектора
    for (const auto &s : v2) {
        std::cout << s << std::endl;
    }

    // получить элемент в начале вектора
    std::cout << v2.front() << std::endl;
    // получить элемент в конце вектора
    std::cout << v2.back() << std::endl;

    // удалить элемент из конца
    v2.pop_back();

    std::cout << v2.back() << std::endl;

    std::vector<std::string> v4{"A"};

    // два вектора одного типа можно сравнивать на все операции отношения
    std::cout << (v2 < v4) << std::endl;
}
