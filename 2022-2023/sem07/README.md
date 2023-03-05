# Семинар 7

## Темы, рассмотренные на семинаре

В C++23 появится (появилась) поддержка многомерной индексации,
когда в квадратных скобках записывается несколько выражений,
разделенных запятой. Это позволяет реализовывать структуры
данных, подобные многомерным массивам, намного проще.
Многомерная индексация уже поддерживается в g++-12 при
включенной опции `-std=gnu++2b`.

См. [пример 1](1.cpp).

Продолжаем рассмативать класс `FD`. Хранение в векторе
элементов FD потребует много лишних системных вызовов `dup`.
Так в примере при добавлении всего трех элементов в FD
будет выполнено 9 системных вызовов `dup`, из которых 6 - лишние.
Отчасти сократить количество копирований можно с помощью `reserve`
у вектора.

См. [пример 2](2.cpp).

Повысить эффективность кода позволяет семантика переноса (move semantics).
В класс добавляются конструктор переноса и операция присваивания
с переносом. Но если присваивание реализовано идиомой copy-and-swap,
присваивание с переносом оказывается реализованным автоматически,
как только появляется конструктор переноса.

Чтобы использовать семантику переноса у класса должно быть "пустое" значение,
чтобы обозначить, что объект не владеет никаким ресурсом. Например,
после переноса значения из этого объекта в другой, объект должен стать пустым.
Чтобы получить все преимущества семантики переноса еще необходимо
использовать спецификацию `noexcept` для методов, которые не могут
выбрасывать исключения.

Стандартная конструкция `std::move` разрешает перенос значения из
обычной переменной (lvalue). Если не использовать `std::move`,
как правило, будет использоваться копирование.

Минимизировать число вызовов конструкторов, то есть избавиться даже
от конструктора переноса, позволяет метод `emplace_back` класса `std::vector`.

См. [пример 3](3.cpp).

По применимости операций копирования/переноса классы в C++ можно
разделить на несколько категорий.

* Если в классе не определен конструктор переноса и не запрещен (`= delete`)
конструктор копирования, такой объект будет всегда копироваться
с помощью вызова конструктора копирования (модель "всегда копирование").
Примеры таких классов - различные классы-значения простой структуры,
например `std::complex<T>` и подобные ему.

* Если в классе не запрещен конструктор копирования и определен
(возможно как `= default`) конструктор переноса, для такого класса
доступна семантика переноса. Примеры таких классов - `std::string`, `std::vector` и т. п.

* Если в классе запрещен конструктор копирования и определен
конструктор переноса, объекты такого классы можно переносить,
но не копировать. Пример: `std::thread`.

* Если в классе запрещен и конструктор копирования, и конструктор переноса,
объекты такого класса нельзя ни копировать, ни перемещать.
Пример: `std::mutex`.

См. [пример 4](4.cpp).

Вектор `std::vector`.

См. [пример 5](5.cpp).