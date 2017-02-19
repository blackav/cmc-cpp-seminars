#include <iostream>
#include <vector>

using namespace std;

int main()
{
    auto x = 1;
    auto y = x;
    auto z = &main;

    std::vector<int> vi;

    std::vector<int>::const_reverse_iterator ri = vi.crbegin();

    auto ri2 = vi.crbegin();

    constexpr auto N = 2;
    int ai[N];

    for (int i = 0; i < N; ++i) {
        cin >> ai[i];
    }

    for (int z : ai) {
        cout << z << endl;
    }

    for (auto z : ai) {
        cout << z << endl;
    }
}
