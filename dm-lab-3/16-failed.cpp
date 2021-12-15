#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<char> vc;
typedef long long ll;

bool operator == (vi& a, vi& b) {
    if (a.size() != b.size()) {
        return false;
    }
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

vvi b(100, vi(100, -1));
int C(int n, int k) {
    if (k < 0 || n < 0) {
        return 0;
    }
    if (b[n][k] == -1) {
        if (n < k) b[n][k] = 0;
        else if (k == 0) b[n][k] = 1;
        else b[n][k] = C(n - 1, k) + C(n - 1, k - 1);
    }
    return b[n][k];
}

int n, k, z;
vi c;

void gen(vi p) {
    if (p.size() == k) {
        if (p == c) {
            cout << z;
            return;
        }
        z++;
    }
    for (int i = 1; i <= n; i++) {
        if (p.size() == 0 || p[p.size() - 1] < i) {
            int cnt = (p.size() > 0) ? p[p.size() - 1] : 0;
            int t = C(cnt, k - p.size() - 1);
            if (c[p.size()] == i) {
                p.push_back(i);
                gen(p);
                return;
            }
            z += t;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    c.resize(k);
    for (int i = 0; i < k; i++) {
        cin >> c[i];
    }

    gen(vi());

    return 0;
}
