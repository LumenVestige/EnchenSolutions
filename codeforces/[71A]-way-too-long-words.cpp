//
// Created by sanenchen on 25-7-23.
//
#include "codeforces.h"
#include "bits/stdc++.h"
using namespace std;
int CodeForces::wayTooLongWords() {
    int n;
    cin >> n;
    vector<string> strs;

    strs.resize(n);
    for (int i = 0; i < n; i++)
        cin >> strs[i];
    // 遍历每个str
    vector<string> ans;
    for (auto it : strs) {
        if (it.size() <= 10) {
            ans.push_back(it);
            continue;
        }
        // 大于10个字母
        string temp = "";
        temp += it[0];
        temp += to_string(it.size() - 2);
        temp += it[it.size() - 1];
        ans.push_back(temp);
    }

    for (auto it : ans) {
        cout << it << endl;
    }
    return 0;
}