# Семинар 15

## Темы, рассмотренные на семинаре

Исключения и гарантии обработки исключений (exception safety).
Уровни гарантий.
Методы обеспечения гарантий. Использование RAII-классов-менеджеров
ресурсов (например, умных указателей) как `true`-способ.

См. [пример 1](1.cpp).

Жизнь без исключений. Возврат из функции пары (значение, флаг успеха) - как в golang. Structured binding (C++-17) - декомпозиция структуры
или массива на индивидуальные переменные при их инициализации.

См. [пример 2](2.cpp).

Класс `std::optional` (C++-17).

См. [пример 3](3.cpp).

Класс `std::expected` (C++-23).

См. [пример 4](4.cpp).

Класс `std::any` (C++17) - контейнер для хранения значения любого типа.

См. [пример 5](5.cpp).
