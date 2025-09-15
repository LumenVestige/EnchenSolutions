//
// Created by sanenchen on 25-9-14.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    // 勾股定理判断
    int OAP = pow(x1, 2) + pow(y1, 2);
    int OBP = pow(x2, 2) + pow(y2, 2);
    int ABP = pow(x1 - x2, 2) + pow(y1 - y2, 2);
    if (OAP + OBP == ABP || OBP + ABP == OAP || OBP + ABP == OAP) cout << "Yes";
    else cout << "No";
    return 0;
}