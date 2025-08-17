#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }

        unordered_map<int, int> last_occurrence; // 记录元素最后出现的位置
        int left = 0;
        int max_len = 0;

        for (int right = 0; right < n; ++right) {
            // 如果当前元素已出现过，并且最后出现的位置在left或之后
            // 则将left移动到最后出现位置的下一位
            if (last_occurrence.find(nums[right]) != last_occurrence.end() &&
                last_occurrence[nums[right]] >= left) {
                left = last_occurrence[nums[right]] + 1;
                }

            // 更新当前元素最后出现的位置
            last_occurrence[nums[right]] = right;
            // 更新最大长度
            max_len = max(max_len, right - left + 1);
        }

        cout << max_len << endl;
    }
    return 0;
}
