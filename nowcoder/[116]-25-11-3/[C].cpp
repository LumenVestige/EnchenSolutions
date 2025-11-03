#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node {
    int l;
    int r;
    int idx;
};
bool cmp(const node& a, const node& b) {
    return a.l < b.l;
}

int lowerBound(const vector<node>& nums, int target) {
    // 查右边那个就好
    int left = -1, right = nums.size();
    while (left + 1 != right) {
        int mid = (left + right) / 2;
        if (nums[mid].r >= target) {
            right = mid;
        } else {
            left = mid;
        }
    }
    return right;
}

signed main() {
    vector<node> nums;
    int n, q;
    cin >> n >> q;
    int idCnt = 1;
    while (n--) {
        int l, r;
        cin >> l >> r;
        node n = {l,r, idCnt++};
        nums.push_back(n);
    }
    sort(nums.begin(), nums.end(), cmp);
    while (q--) {
        int tar;
        cin >> tar;
        int pos = lowerBound(nums, tar);
        if (pos == nums.size()) {
            cout << -1 << endl;
            continue;
        }
        if (nums[pos].l > tar) {
            cout << -1 << endl;
            continue;
        }
        cout << nums[pos].idx << endl;
        
    }
    return 0;
}