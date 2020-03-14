/* -*- mode: c++; c-basic-offset: 4 -*- */

/*
  шаблонный класс std::array - массив фиксированного размера
  параметры шаблона: std::array<T, Z> T - тип элемента, Z - количество элементов
  https://en.cppreference.com/w/cpp/container/array
 */

#include <array>
#include <iostream>

int main()
{
    constexpr int SIZE = 10;

    // для инициализации всех контейнерных классов (std::array, std::vector, ...)
    // можно использовать uniform initializer
    std::array<int, SIZE> arr
    {
       1, 2, 3, 4, 5, 6, 7, 8, 9, 10
    };

    // в отличие от массива в Cи std::array является value-классом
    // то есть его можно присваивать и при передаче в качестве параметра по значению он копируется

    int arr2[SIZE];

    // каждый контейнер STL определяет 4 типа-итератора:
    // 1) прямой read-write итератор
    std::array<int, SIZE>::iterator i1 = arr.begin();
    // 2) прямой const (read-only) итератор
    std::array<int, SIZE>::const_iterator i2 = arr.cbegin();

    /*
      в реализации прямые итераторы над std::array, std::vector и std::string
      скорее всего будут обычными указателями
     */

    // 3) обратный read-write итератор
    std::array<int, SIZE>::reverse_iterator i3 = arr.rbegin();
    // 4) обратный const (read-only) итератор
    std::array<int, SIZE>::const_reverse_iterator i4 = arr.crbegin();

    /*
      реализация обратных итераторов более сложна, чем прямых
      это не будут просто указатели, а некоторые proxy-классы
      т. е. обратные итераторы, скорее всего, менее эффективны
     */

    // проход по массиву от начала до конца в прямом порядке
    for (auto ii = arr.begin(); ii != arr.end(); ++ii) {
        std::cout << ++*ii << std::endl;
    }

    // итераторы классов std::array, std::vector, std::string
    // являются итераторами произвольного доступа (random access)
    // то есть ведут себя как указатели, то есть поддерживают арифметические операции
    // этот цикл проходит от элемента с индексом 2 от начала до элемента с индексом -3 от конца (не включая его)
    for (auto ii = arr.cbegin() + 2; ii != arr.cend() - 3; ++ii) {
        std::cout << *ii << std::endl;
    }

    // проход по массиву в обратном порядке
    for (auto ii = arr.rbegin(); ii != arr.rend(); ++ii) {
        std::cout << *ii << std::endl;
    }

    // в C++-17 поддерживается авто-вывод параметров шаблона по инициализатору
    // в этому примере автоматически выводится тип int и количество элементов 3
    std::array arr3{1, 2, 3};

    // std::next сдвигает итератор на указанное число шагов вперед (по умолчанию на 1 шаг) и возвращает итератор в качестве результата
    // для итераторов произвольного доступа - это одна операция, но для последовательных итераторов может быть цикл
    // std::prev сдвигает итератор на указанное число шагов назад (по умолчанию на 1 шаг)
    // std::advance модифицирует свой первый параметр, сдвигая его вперед на указанное число шагов
    for (auto ii = std::next(std::begin(arr), 3); ii != std::prev(std::end(arr), 2); std::advance(ii, 1)) {
        std::cout << *ii << std::endl;
    }

    // range-based for loop
    // здесь v - это временная переменная того же типа, который хранится в контейнере
    // значение будет копироваться в v
    for (auto v : arr) {
        std::cout << v << std::endl;
    }

    // в этом примере v - константная ссылка, значение копироваться не будет
    for (const auto &v : arr) {
        std::cout << v << std::endl;
    }
}
