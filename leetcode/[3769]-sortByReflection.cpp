#include <bits/stdc++.h>
using namespace std;
struct node {
    int ori, react;
    node(int x, int y) : ori(x), react(y) {};
};
vector<int> sortByReflection(vector<int>& nums) {
    auto getReact = [&](int n) {
        // 转二进制
        string o2;
        while (n > 0) {
            o2 += (n & 1) + '0';
            n >>= 1;
        }
        // 转为10进制
        int react = 0;
        for (auto& i : o2) {
            react += (react << 1) + i - '0';
        }
        return react;
    };
    vector<node> num;
    for (auto& i : nums) {
        num.emplace_back(i, getReact(i));
    }
    sort(num.begin(), num.end(), [&](const node& a, const node& b) {
        if (a.react == b.react) {
            return a.ori < b.ori;
        }
        return a.react < b.react;
    });
    vector<int> ans(nums.size());
    for (int i = 0; i < nums.size(); ++i) {
        ans[i] = num[i].ori;
    }
    return ans;
}
int main() {
    vector<int> nums = {4,6,5,8};
    for (auto& i : sortByReflection(nums)) {
        cout << i << " ";
    }
    return 0;
}