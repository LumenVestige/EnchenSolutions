#include <bits/stdc++.h>
using namespace std;

int minOperations(string s) {
    // 找最小的那一个字符
    char minChar = '{';
    for (auto& i : s) {
        if (i != 'a') minChar = min(minChar, i);
    }
    cout << 26 - (minChar - 'a');
    return 0;
}

int main() {
    cout << minOperations("yz");
    return 0;
}