#include <bits/stdc++.h>
using namespace std;

int findRadius(vector<int> &houses, vector<int> &heaters) {
    sort(heaters.begin(), heaters.end());
    sort(houses.begin(), houses.end());
    int houseMin = houses[0], houseMax = houses[houses.size() - 1];
    // 复杂度：O(N + M)
    auto check = [&](int radius) {
        int houseIdx = 0;
        for (int heater : heaters) {
            // 对于当前加热器，它的覆盖范围是 [heater - radius, heater + radius]
            // 我们看看它能覆盖掉哪些房子
            int leftRange = heater - radius;
            int rightRange = heater + radius;
            
            // 只要当前房子在覆盖范围内，就处理下一个房子
            while (houseIdx < houses.size() && 
                    houses[houseIdx] >= leftRange && 
                    houses[houseIdx] <= rightRange) {
                houseIdx++;
            }
            
            // 如果所有房子都处理完了，返回 true
            if (houseIdx == houses.size()) return true;
        }
        // 遍历完所有加热器，仍有房子没被覆盖
        return false;
    };
    //return check(0);
    int left = -1, right = INT_MAX;
    while (left + 1 != right) {
        int mid = (left + right) / 2;
        if (check(mid)) {
            right = mid;
        } else {
            left = mid;
        }
    }
    return right;
}

int main() {
    vector<int> houses = {1}, heaters = {1,2,3,4};
    cout << findRadius(houses, heaters);
    return 0;
}