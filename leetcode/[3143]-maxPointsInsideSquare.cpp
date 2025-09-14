//
// Created by sanenchen on 25-9-13.
//
#include <bits/stdc++.h>
using namespace std;

int maxPointsInsideSquare(vector<vector<int> > &points, string s) {
    // 二分边长 数据间接二分
    int left = -1, right = 0;
    // 二分的右边界
    for (auto &it: points) {
        right = max(right, max(abs(it[0]), abs(it[1])));
    }
    right += 1; // 确定有边界了
    int ans = 0;
    auto check = [&](const int mid)-> bool {
        // 判断这个mid边长是否存在重复值
        unordered_map<char, int> cnt;
        for (int i = 0; i < s.size(); ++i) {
            if (abs(points[i][0]) <= mid && abs(points[i][1]) <= mid ) {
                if (cnt.find(s[i]) == cnt.end()) cnt[s[i]]++;
                else return false;
            }
        }
        ans = cnt.size();
        return true;
    };
    while (left + 1 < right) {
        int mid = left + (right - left) / 2;
        if (check(mid)) left = mid;
        else right = mid;
    }
    return ans;
}

int main() {
    vector<vector<int> > points = {
        {-1000000000, 1000000000}, {-1000000000, 1000000000}
    };
    cout << maxPointsInsideSquare(points, "zy");
    return 0;
}
