#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    map<int, int> cnt;
    for (int i = 1; i <= n; ++i) {
        cnt[i] = 1;
    }
    while (q--) {
        int low, tar;
        cin >> low >> tar;
        int count = 0;
        vector<int> needRemove;
        for (auto& [x, y] : cnt) {
            if (x <= low) {
                count += y;
                needRemove.push_back(x);
            } else
                break;
        }
        for (auto i : needRemove)
            cnt.erase(i);
        cnt[tar] += count;
        cout << count << endl;
    }
    return 0;
}