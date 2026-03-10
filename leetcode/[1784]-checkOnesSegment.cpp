#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
bool checkOnesSegment(string s) {
    return s.find("01") == string::npos;
}
signed main() {
    cout << checkOnesSegment("1001");
    return 0;
}