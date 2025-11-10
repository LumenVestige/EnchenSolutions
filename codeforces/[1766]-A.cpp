//
// Created by sanenchen on 25-7-26.
//

#include <bits/stdc++.h>

using namespace std;

bool solve(string tar) {

    for (int i = 0; i < tar.size() - 1; i++) {
        // 构造查询
        string need_query = tar.substr(i, 2);
        string be_query = tar.substr( i + 2);
        if (be_query.find(need_query) != be_query.npos)
            return true;
    }

    return false;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t;
        string tar;
        cin >> t >> tar;
        if (solve(tar))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;

    }
    return 0;
}
