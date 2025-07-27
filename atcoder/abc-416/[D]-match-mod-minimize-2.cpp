//
// Created by sanenchen on 25-7-26.
//
//
// 没解出来
#include <bits/stdc++.h>
using namespace std;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int k, m;
        cin >> k >> m;
        vector<int> num1(k), num2(k);
        for (int j = 0; j < k; j++) {
            cin >> num1[j];
        }
        for (int j = 0; j < k; j++) {
            cin >> num2[j];
        }
        sort(num1.begin(), num1.end());
        sort(num2.begin(), num2.end());
        int temp = 0;
        for (int j = 0; j < k; j++) {
            for (int z = k - 1; z >= 0; z--)
                temp += (num1[j] + num2[z]) % m;
        }
        cout << temp << endl;
    }

    return 0;
}