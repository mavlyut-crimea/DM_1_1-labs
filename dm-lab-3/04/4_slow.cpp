#include <iostream>
#include <vector>
#include <set>
using namespace std;
typedef vector<int> vi;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    set<vi> w = { vi(n) };
    vi tmp(n);
    while (true) {
        vi(tmp.begin() + 1, tmp.end()).swap(tmp);
        tmp.push_back(1);
        if (w.find(tmp) != w.end()) {
            tmp.resize(n - 1);
            tmp.push_back(0);
            if (w.find(tmp) != w.end()) {
                break;
            }
        }
        for (int i : tmp) {
            cout << i;
        } cout << '\n';
        w.insert(tmp);
    }
  
    return 0;
}
