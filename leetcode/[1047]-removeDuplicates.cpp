#include <bits/stdc++.h>
using namespace std;
string removeDuplicates(string s) {
    char tmp = ' ';
    stack<char> st;
    for (auto& i : s) {
        if (i == tmp) {
            st.pop();
            if (!st.empty())
                tmp = st.top();
            else tmp = ' ';
        } else {
            tmp = i;
            st.emplace(i);
        }
    }
    string ans;
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main() {
    cout << removeDuplicates("abbaca");
    return 0;
}