//
// Created by sanenchen on 25-10-26.
//
#include <bits/stdc++.h>
using namespace std;
long long removeZeros(long long n) {
    string s;
    while(n != 0) {
        long long t = n % 10;
        if (t != 0) {
            s += t + '0';
        }
        n /= 10;
    }
    reverse(s.begin(), s.end());
    long long t = 0;
    for (int i = 0; i < s.size(); ++i) {
        t = t * 10 + s[i] - '0';
    }
    return t;
}
int main() {
    cout << removeZeros(1020030);
    return 0;
}