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
        
    };
    int left = 0, right = maxRange(start);
    while (left + 1 < right) {
        int mid = left + (right - left) / 2;
    }

    return left;   
}

int main() {

    return 0;
}