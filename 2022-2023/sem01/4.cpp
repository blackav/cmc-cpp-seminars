constexpr int N = 10;
int m[N];

constexpr int func(int n) {
    int res = 1;
    for (int i = 2; i < n; ++i) {
        res *= i;
    }
    return res;
}

int mm[func(3)];
