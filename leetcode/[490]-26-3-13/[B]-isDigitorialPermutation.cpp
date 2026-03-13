#include <bits/stdc++.h>
using namespace std;

bool isDigitorialPermutation(int n) {
    vector<int> preDoes(10, 1);
    for (int i = 1; i <= 9; ++i) {
        preDoes[i] = preDoes[i-1] * i;
    }
    int sum = 0;
    unordered_map<int, int> cnt;
    while (n) {
        sum += preDoes[n%10];
        cnt[n%10]++;
        n /= 10;
    }
    while (sum) {
        int t = sum % 10;
        cnt[t]--;
        if (cnt[t] < 0) {
            return false;
        }
        if (cnt[t] == 0) {
            cnt.erase(cnt.find(t));
        }
        sum /= 10;
    }
    if (cnt.empty()) {
        return true;
    }
    return false;
}

int main() {
    cout << isDigitorialPermutation(145);
}