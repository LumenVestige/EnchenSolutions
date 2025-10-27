//
// Created by sanenchen on 25-10-25.
//
#include <bits/stdc++.h>
using namespace std;
string maxSumOfSquares(int num, int sum) {
    string s;
    int tmp = 0;
    // if (num * 9 < sum)
    //     return "";
    for (int i = 0; i < num; ++i) {
        s.push_back('9');
        tmp += 9;
    }
    int p = s.size() - 1;
    int t = tmp - sum;
    while (t--) {
        if (s[p] == '0')
            p--;
        if (p < 0)
            return "";
        s[p]--;
    }
    if (s[0] <= '0')
        return "";
    return s;
}

int main() {
    cout << maxSumOfSquares(1, 10);
    return 0;
}
