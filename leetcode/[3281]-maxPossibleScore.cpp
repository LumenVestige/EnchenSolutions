#include<bits/stdc++.h>
using namespace std;
int maxRange(vector<int>& nums) {
    int m = 0;
    for (auto& i : nums) {
        m = max(m, i);
    }
    return m;
}
int maxPossibleScore(vector<int>& start, int d) {
    // 先对start进行排序
    sort(start.begin(), start.end());
    auto check = [&](int mid)-> bool {
        long long x = LLONG_MIN;
        for (auto& s : start) {
            x = max(x + mid, (long long)s);
            if (x > s + d) return false;
        }
        return true;
    };
    long long left = 0, right = maxRange(start) + d;
    while (left + 1 < right) {
        int mid = left + (right - left) / 2;
        if (check(mid)) left = mid;
        else right = mid;
    }

    return left;   
}

int main() {

    return 0;
}