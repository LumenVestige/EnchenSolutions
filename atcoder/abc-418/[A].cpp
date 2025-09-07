//
// Created by sanenchen on 25-8-9.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string str;
    cin >> str;
    if (str.size() < 3) {
        cout << "No";
        return 0;
    }
    if (str.substr(n - 3) == "tea")
        cout << "Yes";
    else cout << "No";
    return 0;
}