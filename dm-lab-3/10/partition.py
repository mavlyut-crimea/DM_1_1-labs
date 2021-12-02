#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;

int n, k;
vi a, used, f;

int fact(int p) {
    if (f[p] == 0) {
        if (p <= 1) {
            f[p] = 1;
        } else {
            f[p] = fact(p - 1) * p;
        }
    }
    return f[p];
}

void gen(int p) {
    if (p == n) {
        for (int i : a) {
            cout << i << " ";
        } cout << '\n';
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!used[i - 1]) {
            if (k >= fact(n - p - 1)) {
                k -= fact(n - p - 1);
            } else {
                used[i - 1] = 1;
                a[p] = i;
                gen(p + 1);
                return;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    f.resize(n + 1);
    a.resize(n);
    used.resize(n);
    gen(0);

    return 0;
}
