#include <bits/stdc++.h>
using namespace std;
/*汉诺塔 开始 中间 目标*/
void hanota(vector<int>& A, vector<int>& B, vector<int>& C, int n) {
    if (n == 1) {
        C.push_back(A.back());
        A.pop_back();
        return;
    }
    hanota(A, C, B, n - 1);
    C.push_back(A.back());
    A.pop_back();
    hanota(B, A, C, n - 1);
}
int main() {
    vector<int> A = {2, 1, 0}, B, C;
    hanota(A, B, C, A.size());
    return 0;
}