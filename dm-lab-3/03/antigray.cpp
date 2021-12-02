#include <iostream>
#include <vector>
using namespace std;
typedef vector<string> vs;

string str(int a) {
    a %= 3;
    return (a == 0) ? "0" : (a == 1) ? "1" : "2";
}

vs antiGray(int n) {
    if (n == 1) {
        return { "0", "1", "2" };
    }
    vs pred = antiGray(n - 1);
    vs tmp;
    int k = pred.size();
    for (int i = 0; i < k; i++) {
        tmp.push_back(str(i) + pred[i]);
    }
    for (int i = 1; i < k; i++) {
        tmp.push_back(str(i - 1) + pred[i]);
    }
    tmp.push_back("2" + pred[0]);
    for (int i = 2; i < k; i++) {
        tmp.push_back(str(i - 2) + pred[i]);
    }
    tmp.push_back("1" + pred[0]);
    tmp.push_back("2" + pred[1]);
    return tmp;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vs r = antiGray(n);
    for (string i : r) {
        cout << i + '\n';
    }

    return 0;
}
