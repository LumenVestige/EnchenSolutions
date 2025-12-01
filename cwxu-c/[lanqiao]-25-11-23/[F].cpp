#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve(int n, int k) {

}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    vector<int> cnt(10);
    int notZero = 9, flNum = 0;
    for (int i = 0; i <= 9; ++i) {
        int tmp;
        cin >> tmp;
        cnt[i] = tmp;
        if (tmp % 2 != 0) {
            flNum++;
        }
        if (tmp == 0) {
            notZero--;
        }
    }
    if (notZero == 0 && cnt[0] != 0) {
        cout << 0;
        return 0;
    }
    if (flNum > 1) {
        cout << -1;
        return 0;
    }
    if (notZero == 1 && flNum == 1) {
        cout << -1;
        return 0;
    }
    
    // 每个数字取出一半用
    string ans;
    char tm = 'n';
    for (int i = 0; i <= 9; ++i) {
        if (ans == "" && i == 0) {
            continue;
        }
        for (int j = 0; j < cnt[i] / 2; ++j) {
            ans += i + '0';
        }
        if (cnt[i] % 2 != 0) {
            tm = cnt[i] + '0';
        }
        if (ans != "" && cnt[0] != 0) {
            for (int j = 0; j < cnt[0] / 2; ++j) {
                ans += '0';
            }
            cnt[0] = 0;
        }
    }
    string tmp = ans;
    reverse(tmp.begin(), tmp.end());
    if (tm != 'n') {
        ans += tm;
    }
    ans.append(tmp);
    cout << ans;

    return 0;
}