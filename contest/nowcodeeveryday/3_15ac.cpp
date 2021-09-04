#include<bits/stdc++.h>
#include<iostream>
#include<stdio.h>
#define debug(x) cout<<#x<<":"<<x<<endl;
#define fastio ios::sync_with_stdio(0);cin.tie(0);
#define rep1(i,n)	for(int (i)=1;(i)<=(n);(i)++)
#define rep0(i,n)	for(int (i)=0;(i)<n;(i)++)
#define rep(i,s,t) for(int i=(s);i<=(t);i++)
#define repr(i,s,t) for(int i=(s);i>=(t);i--)
#define PI acos(-1)
#define VI vector<ll> 
#define PII pair<ll,ll>
#define INF 0x3f3f3f3f33f3ff
#define ll long long
// #define int long long 
#define mem(x,y) memset((x),(y),sizeof(x))
const int dx[8]={1,0,-1,0,1,-1,-1,1},dy[8]={0,1,0,-1,1,1,-1,-1};
using namespace std;
template<typename T>inline void read(T &a)
{
    char c=getchar();
    T x=0,f=1;
    while(!isdigit(c)){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(isdigit(c)){x=(x<<1)+(x<<3)+c-'0';c=getchar();}
    a=f*x;
}
template<typename T> void write(T x){
    if(x<0)putchar('-'),x=-x;
    if(x>9)write(x/10);
    putchar(x%10+'0');
}
template <typename T> T gcd(T x,T y){
	return y?gcd(y,x%y):x;
}
const int mod=1e9+7;
ll qpow (ll x,ll k=mod-2,ll m=mod) {
	if(!k)return 1;
	return (k&1)?(x*qpow((x*x)%m,k>>1,m))%m:qpow((x*x)%m,k>>1,m)%m;
}
const int maxn=1e6+50;
//
int n,m,k;
map<int,set<int>> s;
void solve(){
    cin>>n>>m>>k;
    rep1(i,k){
        int x,y;
        cin>>x>>y;
        if(!s.count(x))s[x]={y};
        else s[x].insert(y);
    }
    ll ans=1;
    for(auto i: s){
        ll t=(n*(n+1)/2)%mod;
        for(auto j : i.second)t-=j,t%=mod;
        t=(t%mod+mod)%mod;
        ans*=t;
        ans%=mod;
    }
    ans*=qpow((n*(n+1)/2)%mod,m-s.size());
    ans%=mod;
    cout<<ans<<endl;
}
signed main(){
	fastio;
	int T=1;
	// cin>>T;
	while(T--){
        solve();
	}
    return 0;
}
