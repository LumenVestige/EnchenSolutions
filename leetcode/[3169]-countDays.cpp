//
// Created by sanenchen on 25-9-30.
//
#include <bits/stdc++.h>
using namespace std;
int countDays(int days, vector<vector<int>> &meetings) {
    // 排序一下
    sort(meetings.begin(), meetings.end(), [](vector<int> &a, vector<int> &b) {
        // 如果第一个相同
        if (a[0] == b[0])
            return a[1] < b[1];
        return a[0] < b[0];
    });
    int ans = meetings[0][0] - 1, maxDay = meetings[0][1];
    for (int i = 1; i < meetings.size(); ++i) {
        if (meetings[i][0] > maxDay)
            ans += meetings[i][0] - maxDay - 1;
        maxDay = max(maxDay, meetings[i][1]);
    }
    ans += days - maxDay;
    return ans;
}
int main() {
    vector<vector<int>> meetings = {{2, 4}, {1, 3}};
    cout << countDays(5, meetings);
    return 0;
}