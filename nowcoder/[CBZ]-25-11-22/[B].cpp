#include <bits/stdc++.h>
using namespace std;
#define int long long
int qpow(int a, int n) {
    int res = 1;
    while (n) {
        if (n & 1) {
            res *= a;
        }
        a *= a;
        n >>= 1;
    }
    return res;
}
int to10(string num) {
    int res = 0;
    for (int i = 0; i < num.size(); ++i) {
        res += (num[i] - '0') * qpow(2, num.size() - i - 1);
    }
    return res;
}
signed main() {
    string str;
    cin >> str;
    vector<int> ans;
    int pos = 0;
    while (true) {
        for (int i = 1; i <= 10; ++i) {
            if (str.size() - pos >= i) {
                ans.push_back(to10(str.substr(pos, i)));
                pos += i;
            } else {
                cout << ans.size() << endl;
                for (auto& i : ans) {
                    cout << i << " ";
                }
                return 0;
            }
        }
    }
    return 0;
}