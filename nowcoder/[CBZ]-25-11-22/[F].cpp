#include <bits/stdc++.h>
using namespace std;
#define int long long

int cph(string str) {
    int ans = 0;
    for (int i = 0; i < str.size(); ++i) {
        unordered_map<char, int> cnt;
        for (int j = i; j < str.size(); ++j) {
            if (str[j] == 'd') {
                break;
            }
            cnt[str[j]]++;
            if (cnt['e'] && cnt['r']) {
                ans++;
            }
        }
    }
    return ans;
}
int solve(string str) {
    int ans = 0;
    int last_r = -1; 
    int last_e = -1;
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == 'r') {
            last_r = i;
        } else if (str[i] == 'e') {
            last_e = i;
        } else if (str[i] == 'd') {
            last_r = -1;
            last_e = -1;
        }
        if (last_r != -1 && last_e != -1) {
            ans += min(last_e, last_r) + 1;
        }
    }
    return ans;
}
signed main() {
    // string str;
    // cin >> str;
    // cout << cph(str) << endl;
    // cout << solve(str);
    int a[3];
    cout << sizeof(__int128);
    return 0;
}