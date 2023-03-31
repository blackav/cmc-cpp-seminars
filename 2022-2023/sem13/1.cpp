#include <iostream>
#include <initializer_list>
#include <vector>
#include <typeinfo>

using std::cout, std::endl;

template<typename T>
void type_to_str(T t)
{
    cout << __PRETTY_FUNCTION__ << endl;
}

int main()
{
    auto p = {1, 2, 3};

    for (auto x: p) {
        cout << x << endl;
    }

    std::vector<int> x{1, 2, 3};
    std::vector<int> x1{2};
    std::vector<int> x2(2);
    std::vector x3(p);
    auto p2(p);

    cout << typeid(p2).name() << endl;
    type_to_str(p2);

    cout << x1.size() << endl;
    cout << x2.size() << endl;
    cout << x3.size() << endl;

    int y1(2);
    int y2{2};
}
