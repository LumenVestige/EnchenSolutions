//
// Created by sanenchen on 25-8-16.
//
#include <bits/stdc++.h>
using namespace std;


int main() {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);
    string s;
    cin >> s;
    if (s == "red")
        cout << "SSS";
    else if (s == "blue")
        cout << "FFF";
    else if (s == "green")
        cout << "MMM";
    else cout << "Unknown";
    return 0;
}