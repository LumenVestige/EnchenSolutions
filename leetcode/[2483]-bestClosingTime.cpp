#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int bestClosingTime(string customers) {
    int n = customers.size();
    vector<int> hasPrefix(n + 2, 0), noPrefix(n + 2, 0);
    for (int i = 1; i <= n; ++i) {
        hasPrefix[i] = hasPrefix[i - 1] + (customers[i - 1] == 'Y');
        noPrefix[i] = noPrefix[i - 1] + (customers[i - 1] == 'N');
    }
    int ans = INT_MAX;
    int pos = 0;
    for (int i = 0; i <= n; ++i) {
        int tmp = 0;
        tmp += hasPrefix[n] - hasPrefix[i];
        tmp += noPrefix[i];
        if (tmp < ans) {
            ans = tmp;
            pos = i;
        }
    }
    return pos;
}

int main() {
    cout << bestClosingTime("YYNY");
    return 0;
}