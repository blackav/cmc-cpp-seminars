#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    constexpr auto N = 4;
    int a[N];
    for (int i = 0; i != N; ++i) {
        cin >> a[i];
    }
    sort(a, a + N, [](auto x, auto y) -> auto { return x > y; } );
    for (auto x : a) {
        cout << x << endl;
    }
}
