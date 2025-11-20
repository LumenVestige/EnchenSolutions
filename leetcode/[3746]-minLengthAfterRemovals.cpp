#include <bits/stdc++.h>
using namespace std;

int minLengthAfterRemovals(string s) {
    int cntA = 0;
    for (auto& i : s) {
        if (i == 'a') cntA++;
    }
    return abs(cntA - int(s.size() - cntA));
}

int main() {
    cout << minLengthAfterRemovals("aabbab");
    return 0;
}