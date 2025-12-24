#include <bits/stdc++.h>
using namespace std;
int maximumSwap(int num) {
    string strNum = to_string(num);
    int idx = strNum.size() - 1;
    int ans = num;
    for (int i = strNum.size() - 2; i >= 0; i--) {
        if (strNum[i] > strNum[idx]) {
            idx = i;
            continue;
        }
        string tmpStr = strNum;
        swap(tmpStr[i], tmpStr[idx]);
        ans = max(ans, stoi(tmpStr));
    }
    return ans;
}
int main() {
    cout << maximumSwap(2736);
    return 0;
}