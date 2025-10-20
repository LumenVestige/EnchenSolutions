#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    // 目的就是要找到那个中间变化的地方
    // 注意 变一个我们就是加1 变化的数目可以初步判断变化范围
    // 这样从而我们就只需要找到左边第一个变化的数就可以了
    // 询问完整的原来的
    int oriN;
    int chaN;
    cout << "1 1 " << n << endl;
    cin >> oriN;
    // 询问变化后的
    cout << "2 1 " << n << endl;
    cin >> chaN;
    int changeNumber = chaN - oriN; // 这就是变化的数量
    // 下面我就要找到从那个地方开始变化的
    // 二分查找 去找到这个变化的节点 找到新结果比原结果大1的位置
    // 如果相等则右推 如果等于1则找到 如果大于一则左推
    int mid = (1 + n) / 2;
    cout << "1 1 " << mid << endl;
    cout.flush();
    cin >> oriN;
    cout << "2 1 " << mid << endl;
    cout.flush();
    cin >> chaN;
    int last = n;
    while (oriN + 1 != chaN) {
        if (chaN > oriN) {
            mid = (1 + mid) / 2;
        } else {
            mid = (mid + last) / 2;
        }
        last = mid;
        cout << "1 1 " << mid << endl;
        cin >> oriN;
        cout << "2 1 " << mid << endl;
        cin >> chaN;
    }
    cout << "! " << mid << " " << mid + changeNumber - 1 << endl;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}