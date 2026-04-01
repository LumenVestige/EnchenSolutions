#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n,k;cin>>n>>k;
    vector<int> a(n+1);
    int ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i<=n-1) ans+=a[i];
    }
    ans+=1;
    int sum=k*n;
    int cnt1=0,cnt2=0,idx=-1;//已经有，必须
    for(int i=1;i<=n;i++){
        if(sum>a[i]){
            cnt1+=1;
            cnt2+=a[i]-1;
            sum-=a[i];
        }
        else{
            cnt1++;
            cnt2+=1;
            idx=i;
            break;
        }
    }
    if(cnt2<(n-idx)*k){
        cnt2=(n-idx)*k;
    }
    ans=min(ans,cnt2+cnt1);
    cout<<ans<<"\n";
}
signed main(){
    int t;cin>>t;
    while(t--) solve();
}