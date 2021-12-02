#include <iostream>
#include <vector>
using namespace std;
typedef vector<string> vs;

int k;
string str(int i) {
    return string({ (char)(i + 48) });
}

vs gray(int n) {
    if (n == 1) {
        vs ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(str(i));
        }
        return ans;
    }
    vs pred = gray(n - 1);
    int r = pred.size();
    vs ans;
    for (string i : pred) {
        for (int j = 0; j < k; j++) {
            ans.push_back(str(j) + i);
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n >> k;
    vs ans = gray(n);
    for (string i : ans) {
        cout << i + '\n';
    }

    return 0;
}
