#include <bits/stdc++.h>
using namespace std;

int iceBreakingGame1(int num, int target) {
    vector<int> nums(num);
    for (int i = 0 ; i < num; ++i) {
        nums[i] = i;
    }
    int pos = 0;
    while (nums.size() > 1) {
        pos = (pos + target - 1) % nums.size();
        // 移除第pos个
        cout << nums[pos] << " ";
        nums.erase(nums.begin() + pos);

    }
    cout << endl;
    return nums[0];
}
// 递归解法
int iceBreakingGame(int num, int target) {
    auto dfs = [&](auto&& dfs, int num) {
        if (num == 1) {
            return 0;
        }
        int x = dfs(dfs, num - 1);
        return (target + x) % num;
    };
    return dfs(dfs, num);
}

int main() {
    cout << iceBreakingGame(7, 4);
    return 0;
}