#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

struct BIT {
    vector<int> tree;
    int n;
    BIT(int n) : tree(n), n(n) {}
    void change(int x, int k) {
        while (x <= n) {
            tree[x] += k;
            x += x & -x;
        }
    }
    int query(int x) {
        int t = 0;
        while (x) {
            t += tree[x];
            x -= x & -x;
        }
        return t;
    }
};

vector<int> resultArray(vector<int>& nums) {
    // 离散化
    vector<int> sorted = nums;
    sort(sorted.begin(), sorted.end());
    // 去重
    vector<int> arr1, arr2;
    arr1.push_back(nums[0]);
    arr2.push_back(nums[1]);
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
    BIT b1(20), b2(20);
    b1.change(lower_bound(sorted.begin(), sorted.end(), nums[0]) - sorted.begin() + 1, 1);
    b2.change(lower_bound(sorted.begin(), sorted.end(), nums[1]) - sorted.begin() + 1, 1);
    for (int i = 2; i < nums.size(); ++i) {
        int qb1 = arr1.size() - b1.query(lower_bound(sorted.begin(), sorted.end(), nums[i]) - sorted.begin() + 1);
        int qb2 = arr2.size() - b2.query(lower_bound(sorted.begin(), sorted.end(), nums[i]) - sorted.begin() + 1);
        if (qb1 > qb2) {
            arr1.push_back(nums[i]);
            b1.change(lower_bound(sorted.begin(), sorted.end(), nums[i]) - sorted.begin() + 1, 1);
        } else if (qb1 < qb2) {
            arr2.push_back(nums[i]);
            b2.change(lower_bound(sorted.begin(), sorted.end(), nums[i]) - sorted.begin() + 1, 1);
        } else if (arr1.size() == arr2.size()) {
            arr1.push_back(nums[i]);
            b1.change(lower_bound(sorted.begin(), sorted.end(), nums[i]) - sorted.begin() + 1, 1);
        } else {
            if (arr1.size() < arr2.size()) {
                arr1.push_back(nums[i]);
                b1.change(lower_bound(sorted.begin(), sorted.end(), nums[i]) - sorted.begin() + 1, 1);
            } else {
                arr2.push_back(nums[i]);
                b2.change(lower_bound(sorted.begin(), sorted.end(), nums[i]) - sorted.begin() + 1, 1);
            }
        }
    }
    arr1.insert(arr1.end(), arr2.begin(), arr2.end());
    return arr1;
}
signed main() {
    vector<int> nums = {5,14,3,1,2};
    for (auto& i : resultArray(nums)) {
        cout << i << " ";
    }
    return 0;
}