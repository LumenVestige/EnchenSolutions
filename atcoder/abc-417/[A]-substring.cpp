//
// Created by sanenchen on 25-8-2.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    string tmp = s.substr(a, n - a - b);
    cout << tmp;
    return 0;
}