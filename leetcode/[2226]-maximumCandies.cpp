#include <bits/stdc++.h>
using namespace std;
int maximumCandies(vector<int>& candies, long long k) {
    auto check = [&](int mid)-> bool {
        // 没人分配mid
        int allowK = 0;
        for (int i = 0; i < candies.size(); ++i) {
            if (candies[i] >= mid) {
                allowK += candies[i] / mid;
            }
        }
        return allowK >= k;
    };
    long long left = 0, right = 0;
    for(auto& i: candies){
        right = max((long long)i, right);
    }
    right *= 10;
    while (left + 1 < right) {
        int mid = left + (right - left) / 2;
        if (check(mid)) left = mid;
        else right = mid;
    }
    return left;
}
int main() {
    vector<int> candies = {5,8,6};
    cout << maximumCandies(candies, 3) << endl;
    return 0;
}