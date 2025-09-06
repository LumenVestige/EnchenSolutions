//
// Created by sanenchen on 25-8-4.
//
#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int x) {
    string tmp_r = to_string(x);
    string tmp_o = tmp_r;
    reverse(tmp_r.begin(), tmp_r.end());
    return tmp_o == tmp_r;
}

int main() {
    cout << isPalindrome(121);
    return 0;
}
