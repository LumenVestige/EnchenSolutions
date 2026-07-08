 #include<bits/stdc++.h>
using namespace std;
using i64 = long long;
#define debug(x) cerr << #x << ": " << x << "\n";
void solve(){
    int m, k;
    cin >> m >> k;
    if(m >= 7 && k == 3){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while(t--) solve();
    return 0;
}