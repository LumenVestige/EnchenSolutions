#include<bits/stdc++.h>
using namespace std;
using i128 = __int128;
using u128 = unsigned __int128;
#define int long long

const int N = 770;
const int mod = 998244353;
struct matrix
{
    int Mat[N + 1][N + 1];
    matrix()
    {
        memset(Mat, 0, sizeof Mat);
    }
};
matrix operator*(matrix x, matrix y)
{
    matrix t;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            for (int k = 1; k <= N; ++k)
            {
                t.Mat[i][j] = (t.Mat[i][j] + 1ll * x.Mat[i][k] * y.Mat[k][j] % mod) % mod;
            }
        }
    }
    return t;
}
matrix qmi(matrix a, int b)
{
    matrix res;
    for (int i = 1; i <= N; ++i)
    {
        res.Mat[i][i] = 1;
    }
    while (b)
    {
        if (b & 1)
        {
            res = res * a;
        }
        a = a * a;
        b >>= 1;
    }
    return res;
}
void init(){

}
#define MultiTest   0
void solve(){
    // vector dp(9,vector<int>(3));
    // dp[0][1] = dp[0][0] = dp[0][2] = 1;
    // for(int i = 1;i<9;i++){
    //     dp[i][0] += dp[i-1][1]+dp[i-1][2];
    //     dp[i][1] += dp[i-1][0]+dp[i-1][2];
    //     dp[i][2] += dp[i-1][1]+dp[i-1][0];
    // }
    // cout<<(dp[8][0]+dp[8][1]+dp[8][2])<<"\n";

    int n,m;cin>>n>>m;

    // vector<string> a(1);
    // string cur;
    // auto build = [&](auto build,int s){
    //     if(s == n){
    //         a.push_back(cur);
    //         return ;
    //     }
    //     for(int i = 0;i<=2;i++){
    //         if(s!=0 and cur.back()-'0' == i) continue;
    //         cur += char(i+'0');
    //         build(build,s+1);
    //         cur.pop_back();
    //     }

    // };
    // build(build, 0);

    // matrix mat;

    // for(int i = 1;i<a.size();i++){
    //     for(int j = 1;j<a.size();j++){
    //         bool ok = true;
    //         for(int k = 0;k<n;k++){
    //             if(a[i][k] == a[j][k]) ok = false;
    //         }
    //         if(ok) mat.Mat[i][j] = 1;
    //     }
    // }

    // matrix res = qmi(mat, m-1);
    // int ans = 0;
    // for(int i = 0;i<N;i++){
    //     for(int j = 0;j<N;j++){
    //         ans += res.Mat[i][j];
    //     }
    // }
    // cout<<ans<<"\n";
}

signed main(){
    std::cin.tie(nullptr)->sync_with_stdio(false);
    init();
    int T = 1;
    if(MultiTest)
        std::cin>>T;
    while(T--) solve();
    return 0;
}