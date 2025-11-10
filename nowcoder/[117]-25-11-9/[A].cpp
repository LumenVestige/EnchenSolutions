//
// Created by sanenchen on 25-11-9.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    a++;
    b++;
    if (a == 0 && b == 0) {
        cout << "LU";
    } else if (a == 1 && b == 0) {
        cout << "LD";
    } else if (a == 1 && b == 1) {
        cout << "RD";
    } else if (a == 0 && b == 1) {
        cout << "RU";
    }
    return 0;
}