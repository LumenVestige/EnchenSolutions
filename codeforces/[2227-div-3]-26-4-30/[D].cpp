#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
    int n;
    cin >> n;
    vector<int> nums(2*n);
    vector<int> zeroPos(2, -1);
    for (int i = 0; i < 2*n; ++i) {
        cin >> nums[i];
        if (nums[i] == 0) {
            if (zeroPos[0] == -1) {
                zeroPos[0] = i;
            } else {
                zeroPos[1] = i;
            }
        }
    }
    int ans = 0;
    vector<int> aaa;
    // 情况 0是中心，向外辐射
    // 0 0对称，检测内部是否是，再向外辐射
    // 左0中心
    for (int cent = 0; cent < 2; ++cent) {
        aaa.clear();
        int l = zeroPos[cent], r = zeroPos[cent];
        int last = 0;
        while (l >= 0 && r < 2*n) {
            if (nums[l] != nums[r]) {
                break;
            }
            aaa.push_back(nums[l]);
            l--, r++;
        }
        sort(aaa.begin(), aaa.end());
        int ttt = 0;
        for (auto& i : aaa) {
            if (i > ttt) {
                if (i == ttt+1) {
                    ttt++;
                } else {
                    break;
                }
            }
        }
        ans = max(ans, ttt+1);
    }

    // 左右逼宫
    aaa.clear();
    int tmpA = 0;
    int l = zeroPos[0], r = zeroPos[1];
    while (r > l) {
        if (nums[l] != nums[r]) {
            cout << ans << endl;
            return;
        }
        l++;
        r--;
        aaa.push_back(nums[l]);
    }
    l = zeroPos[0], r = zeroPos[1];
    // 两个零蛋向外辐射堆成
    while (l >= 0 && r < 2*n) {
        if (nums[l] != nums[r]) {
            break;
        }
        aaa.push_back(nums[l]);
        l--;
        r++;
    }
    sort(aaa.begin(), aaa.end());
    int ttt = 0;
    for (auto& i : aaa) {
        if (i > ttt) {
            if (i == ttt+1) {
                ttt++;
            } else {
                break;
            }
        }
    }
    ans = max(ans, ttt+1);
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}