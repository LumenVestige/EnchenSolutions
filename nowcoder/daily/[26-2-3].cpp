#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    vector<int> nums(n);
    int tot = 0;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        tot += nums[i];
    }
    sort(nums.begin(), nums.end());
    int avg = tot/n;
    if (tot%n == 0) {
        // 平均数情况
        int needAdd = 0, needDel = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] < avg) {
                needAdd += avg - nums[i];
            } else if (nums[i] > avg) {
                needDel += nums[i] - avg;
            }
        }
        cout << min(needAdd, needDel);
    } else {
        // 删除最小值
        int n1 = tot - nums[0];
        int avg = (n1 % (n-1) == 0) ? n1/(n-1) : n1/(n-1)+1;
        int needAdd = 0, needDel = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] < avg) {
                needAdd += avg - nums[i];
            } else if (nums[i] > avg) {
                needDel += nums[i] - avg;
            }
        }
        
        int ans1 = min(needAdd, needDel);
        // 删除最大值
        n1 = tot - nums[n-1];
        avg = (n1 % (n-1) == 0) ? n1/(n-1) : n1/(n-1)+1;
        needAdd = 0, needDel = 0;
        for (int i = 0; i < n-1; ++i) {
            if (nums[i] < avg) {
                needAdd += avg - nums[i];
            } else if (nums[i] > avg) {
                needDel += nums[i] - avg;
            }
        }
        int ans2 = min(needAdd, needDel);
        cout << min(ans1, ans2);
    }

    return 0;
}