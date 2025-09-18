//
// Created by sanenchen on 25-9-18.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    vector<int> point_x(t), point_y(t);
    for (int i = 0; i < t; ++i)
        cin >> point_x[i] >> point_y[i];
    sort(point_x.begin(), point_x.end());
    sort(point_y.begin(), point_y.end());
    // 先来搞定y y要找到最小的那个和
    int ansY = 0;
    const int targetY = point_y[t / 2];
    for (auto& i : point_y)
        ansY += abs(targetY - i);
    // 再来搞定x 先偏移x 转化为 找到一个点 到其他点距离和最小问题
    // 之前是：|x0 - a| + |x1 - (a+1)| + |x2 - (a+2)| + |x3 - (a+3)|
    // 之后是 |x0' + 0 - a| + |x1' + 1 - (a+1)| + |x2' + 2 - (a+2)| + |x3' + 3 - (a+3)|
    // x3' + 3 = x3 所以 x3' = x3 - 3
    // 也就是 point_x[i] -= i;
    for (int i = 0; i < t; ++i)
        point_x[i] -= i;
    sort(point_x.begin(), point_x.end());
    int ansX = 0;
    int targetX = point_x[t / 2];
    for (auto& i : point_x)
        ansX += abs(i - targetX);

    // 输出总步数（y + x）
    cout << ansY + ansX << endl;
    return 0;
}