#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool myfunc(int x, int y)
{
    return abs(x) < abs(y);
}

struct SortStruct
{
    bool operator() (int x, int y) const noexcept
    {
        return abs(x) < abs(y);
    }
};

int main()
{
    vector<int> v1;
    int x;

    while (cin >> x) {
        v1.push_back(x);
    }

    //sort(v1.begin(), v1.end());
    //stable_sort(v1.begin(), v1.end());
    //sort(v1.begin(), v1.end(), less<int>());
    //stable_sort(v1.begin(), v1.end(), SortStruct{});
    //sort(v1.begin(), v1.end(), greater<int>());
    //sort(v1.begin(), v1.end(), [](auto x, auto y) { return abs(x) < abs(y); });

    int z = 0;
    sort(v1.begin(), v1.end(), [z](auto x, auto y) { return abs(x) < abs(y); });

    struct Lambda1
    {
        int &z;
        Lambda1(int &z) : z(z) {}
        bool operator()(int x, int y)
        {
            return abs(x) < abs(y);
        }
    }
    sort(v1.begin(), v1.end(), Lambda1(z));

    cout << z << endl;
    for (int x : v1) {
        cout << " " << x;
    }
    cout << endl;

}
