#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;

vi a;
vi used;
int n;

void gen(int p) {
    if (p == n) {
        for (int i : a) {
            cout << i << " ";
        } cout << '\n';
    }
    for (int i = 1; i <= n; i++) {
        if (!used[i - 1]) {
            used[i - 1] = 1;
            a[p] = i;
            gen(p + 1);
            used[i - 1] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    a.resize(n);
    used.resize(n);
    gen(0);

    return 0;
}
