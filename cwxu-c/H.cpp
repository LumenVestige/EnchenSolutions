#include<bits/stdc++.h>
using namespace std;
using ll=long long;
void solve(){
    ll n;cin>>n;
    vector<vector<ll>>v(4);
    unordered_map<ll,ll>mp;
    for(ll i=1;i<=n;i++){
        ll a;cin>>a;
        a%=4;
        mp[a]++;
        v[a].push_back(i);
    }
    ll len1=v[1].size(),len2=v[2].size(),len3=v[3].size();
    ll t3=v[3].size()-v[1].size();
    ll tt=t3/2-v[2].size();
    if(2*mp[2]+mp[3]<mp[1]||tt>=3){cout<<"-1\n";return;}
    ll i3=0,i2=0,i1=0;
    while(i3<len3&&i1<len1){
        cout<<v[3][i3]<<" "<<v[1][i1]<<" ";
        i3++;i1++;
    }
    if(i1==len1&&i3==len3){
        for(auto a:v[2])cout<<a<<" ";
    }
    else if(i1==len1){
        while(i3<len3&&i2<len2){
            cout<<v[3][i3]<<" ";
            i3++;
            if(i3==len3)break;
            cout<<v[3][i3]<<" ";
            cout<<v[2][i2]<<" ";
            i2++;
        }
        for(;i2<len2;i2++)cout<<v[2][i2]<<" ";
    }
    else if(i3==len3){
        while(i1<len1&&i2<len2){
            cout<<v[2][i2]<<" "<<v[1][i1]<<" ";
            i1++;i2++;
        }
        for(;i2<len2;i2++)cout<<v[2][i2]<<" ";
    }
    for(auto a:v[0])cout<<a<<" ";
    return;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    ll t=1;cin>>t;
    while(t--)solve();
    return 0;
}