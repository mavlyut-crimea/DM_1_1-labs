#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;

int n;

int gen(string p, int delta) {
    if (p.length() == n * 2) {
        cout << p << '\n';
        return -1;
    }
    if (delta + 1 < 2 * n - p.length()) {
        gen(p + '(', delta + 1);
    }
    if (delta > 0) {
        gen(p + ')', delta - 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    gen("", 0);

    return 0;
}
