//
// Created by sanenchen on 25-7-27.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int m;
        string str;
        cin >> m >> str;
        // 从左往右 找 1 找到了就记录当前的下标
        vector<int> tar;
        for (int j = 0; j < m; j++) {
            if (str[j] == '1') {
                tar.push_back(j);
            }
        }
        if (tar[1] - tar[0] == tar[2] - tar [1])
            cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}