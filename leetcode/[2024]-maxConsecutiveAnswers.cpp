#include <bits/stdc++.h>
using namespace std;

int maxConsecutiveAnswers(string answerKey, int k) {
    int left = 0, ans = 0;
    int cntT = 0, cntF = 0;
    for (int right = 0; right < answerKey.size(); ++right) {
        if (answerKey[right] == 'T') cntT++; else cntF++;
        while (cntT > k && cntF > k) {
            // out
            if (answerKey[left] == 'T') cntT--; else cntF--;
            left++;
        }
        ans = max(ans, cntF + cntT);
    }
    return ans;
}

int main() {
    cout << maxConsecutiveAnswers("TTFF", 2) << endl;
    return 0;
}