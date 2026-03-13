#include <bits/stdc++.h>
using namespace std;
int minCost(int n) {
    int ans = 0;
    for (int i = n-1; i >= 1; --i) {
        ans += i;
    }
    return ans;
}
int main() {
    cout << minCost(3);
}