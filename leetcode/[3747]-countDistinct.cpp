#include <bits/stdc++.h>
using namespace std;

long long countDistinct(long long n) {
    if (n < 10) {
        return n;
    }
    // long long to str
    string strNum;
    while (n != 0) {
        strNum += n % 10 + '0';
        n /= 10;
    }
    reverse(strNum.begin(), strNum.end());
    long long ans = 0;
    for (int i = 0; i < strNum.size(); ++i) {
        if (strNum[i] == '0') {
            return ans;
        }
        int tmpN = (strNum.size() - i - 1);
        if (tmpN >= 2) ans += 9;
        ans += pow(9, (strNum.size() - i - 1)) * (strNum[i] - '0');
        //if (n >= 100)
    }
    return ans;
}

int main() {
    cout << countDistinct(2048);
    return 0;
}