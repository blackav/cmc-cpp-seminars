# Семинар 3

## Темы, рассмотренные на семинаре

Аргументы функций по умолчанию. Аргументы по умолчанию рассматриваются
только на этапе компиляции программы исходя из того, какое объявление
функции видимо в точке вызова. В скомпилированной программе все аргументы
по умолчанию преобразованы в явные аргументы.

См. [1.cpp](1.cpp), [1_1.cpp](1_1.cpp).

У функции аргументами по умолчанию могут являться последние аргументы,
нельзя пропустить аргумент в середине списка аргументов.

См. [пример 2](2.cpp).

В С++ функция с одним именем может иметь несколько реализаций
с разными наборами параметров. Такая функция называется перегруженной
(overloaded).

Правила подбора наилучшего кандидата среди множества перегруженных функций
сложны [см. здесь](https://en.cppreference.com/w/cpp/language/overload_resolution).

При разрешении перегрузки рассматриваются только viable functions:
1) If there are M arguments, the candidate function that has exactly M parameters is viable - функции ровно с M аргументами нам подходят
2) If the candidate function has less than M parameters, but has an ellipsis parameter, it is viable - функции с меньше чем M аргументами, но `...` в конце
3) If the candidate function has more than M parameters and the M+1'st parameter and all parameters that follow have default arguments, it is viable. For the rest of overload resolution, the parameter list is truncated at M - больше чем M аргументов, но все аргументы после M имеют значения по умолчанию
4) If the function has an associated constraint, it must be satisfied - это концепты C++20.
5) For every argument there must be at least one implicit conversion sequence that converts it to the corresponding parameter. - должно существовать неявное преобразование для каждого аргумента
6) If any parameter has reference type, reference binding is accounted for at this step: if an rvalue argument corresponds to non-const lvalue reference parameter or an lvalue argument corresponds to rvalue reference parameter, the function is not viable - ссылки должны соответствовать

Для одного параметра степень пригодности функции оценивается по
рангу неявного преобразования типов. Чем ниже ранг, тем лучше.

Про неявные преобразования типов [здесь](https://en.cppreference.com/w/cpp/language/implicit_conversion)

* ранг 0 - точное соответствие (Exact match: no conversion required, lvalue-to-rvalue conversion, qualification conversion, function pointer conversion, user-defined conversion of class type to the same class).
* ранг 1 - повышение типа (Promotion: integral promotion, floating-point promotion).
* ранг 2 - преобразования (Conversion: integral conversion, floating-point conversion, floating-integral conversion, pointer conversion, pointer-to-member conversion, boolean conversion, user-defined conversion of a derived class to its base).

См. [пример 3](3.cpp).

Не-explicit конструкторы, которые допускают вызов с одним аргументом,
и не-explicit операции преобразования типа рассматриваются
при определении пригодности функции для перегрузки.
При использовании пользовательского преобразования возможно
стандартное преобразование до выполнения пользовательского
и стандартное преобразование после выполнения пользовательского.
Пользовательские преобразования имеют ранг ниже стандартных.

См. [пример 4](4.cpp).

При разрешении перегрузки функции от нескольких параметров
по каждому параметру строится множество подходящих функций
с преобразованием минимального ранга, затем множества пересекаются.
Должна остаться ровно одна функция.

См. [пример 5](5.cpp).

Класс может определить явное преобразование в `bool`: `explicit operator bool`.
Такое преобразование не рассматривается при подборе наилучшего
кандидата при перегрузке, но используется там, где требуется булевский
результат, то есть в условии `if`, `while`, аргументах `&&`, присваниваниях
bool переменной и т. п

См. [пример 6](6.cpp).
