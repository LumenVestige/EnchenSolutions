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
    str += 'd';
    // 双指针
    int left = 0, right = 0;
    unordered_map<char, int> cnt;
    int ans = 0, tmp = 0;
    while (right < str.size()) {
        cnt[str[right]]++;
        // 如果存在了d了 还用回退吗，直接跳到当前位置，right++ left = right
        if (cnt['d'] != 0) {
            right++;
            left = right;
            cnt.clear();
            continue;
        }
        if (cnt['d'] == 0 && cnt['r'] != 0 && cnt['e'] != 0) {
            ans += ++tmp;
        }
        right++;
    }
    return ans;
}
signed main() {
    string str;
    cin >> str;
    cout << cph(str) << endl;
    cout << solve(str);

    return 0;
}