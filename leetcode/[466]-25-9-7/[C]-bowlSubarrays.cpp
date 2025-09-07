#include <bits/stdc++.h>
using namespace std;
// 暂时没有解决 单调栈问题
long long bowlSubarrays(vector<int>& nums) {
    // 定长 + 不定长的滑动窗口
    int left = 0;
    long long ans = 0;
    for (int left = 0; left < nums.size(); ++left) {
        priority_queue<int> pq;
        pq.push(0);
        for (int right = left; right < nums.size(); ++right) {

            // 是否形成一个窗口
            if (right + 1 < 3) continue; // 暂时没有形成窗口
            // 核心判断 是否是个碗
            if (min(nums[left], nums[right]) > pq.top()) {
                ans++;
            }
            // in
            if (right != left)
            pq.push(nums[right]);
            // // out
            // if (nums[left] == pq.top()) pq.pop();
            // left++;
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {2,5,3,1,4};
    cout << bowlSubarrays(nums) << endl;
    return 0;
}