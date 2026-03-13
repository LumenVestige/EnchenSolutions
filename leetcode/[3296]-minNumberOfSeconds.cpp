//
// Created by sanenchen on 25-9-11.
//
#include <bits/stdc++.h>
using namespace std;
// long long minNumberOfSeconds(int mountainHeight, vector<int> &workerTimes) {
//     // 前缀和 记录前n和
//     vector<long long> prefix(mountainHeight + 1, 0);
//     for (int i = 1; i <= mountainHeight; ++i)
//         prefix[i] = prefix[i - 1] + i;
//     // 找到工人干的最慢的那个
//     int lastTime = 0;
//     for (auto &i: workerTimes)
//         lastTime = max(i, lastTime);

//     // check 函数
//     auto check = [&](long long mid)-> bool {
//         // 所有工人在 mid 秒内 最大挖掘高度
//         long long height = 0;
//         if (workerTimes.size() >100) {
//             height = 0;
//             for (const auto &i: workerTimes) {
//                 long long tmpHeight = 1;
//                 int leftHeight = 0, rightHeight = mountainHeight;
//                 while (leftHeight + 1 < rightHeight) {
//                     int midHeight = leftHeight + (rightHeight - leftHeight) / 2;
//                     if (i * prefix[midHeight] > mid) rightHeight = midHeight;
//                     else leftHeight = midHeight;
//                 }
//                 height += leftHeight;
//             }
//         } else {
//             height = 0;
//             for (const auto& i : workerTimes) {
//                 long long tmpHeight = 1;
//                 while (tmpHeight <= mountainHeight && i * prefix[tmpHeight] <= mid)
//                     tmpHeight++;
//                 height += tmpHeight - 1;
//             }
//         }
//         return height >= mountainHeight;
//     };

//     long long left = 0, right = lastTime * prefix[mountainHeight];
//     while (left + 1 < right) {
//         long long mid = left + (right - left) / 2;
//         if (check(mid)) right = mid;
//         else left = mid;
//     }
//     return right;
// }
// 2026.3.13 复习
#define ll long long
long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
    auto calTimes = [&](ll h, ll workTime)->ll {
        return workTime * (h+1)*h/2;
    };
    // 二分猜答案
    // 假设最慢的人全干，这就是二分答案的上边界
    ll maxSec = calTimes(mountainHeight, *max_element(workerTimes.begin(), workerTimes.end()));
    // 如何校验？ 所有人在 x 秒内能干的活 总数是否大于山高
    auto check = [&](ll midT) {
        ll h = 0;
        for (auto& t : workerTimes) {
            // 二分查找做校验
            ll left = -1, right = mountainHeight+1;
            while (left + 1 < right) {
                ll midH = left + (right - left) / 2; // 计算出来的高度
                // 校验这个midH
                ll calT = calTimes(midH, t);
                if (calT > midT) {
                    right = midH;
                } else {
                    left = midH;
                }
            }
            h += left;
        }
        return h >= mountainHeight;
    };
    ll left = 0, right = maxSec;
    while (left + 1 < right) {
        ll mid = left + (right - left) / 2;
        // cout << mid << "!!";
        if (check(mid)) 
            right = mid;
        else left = mid;
    }
    return right;
}
int main() {
    vector<int> workTimes = {2, 1, 1};
    cout << minNumberOfSeconds(4, workTimes);
    return 0;
}
