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
const int maxn=2e3+50;
//
ll n,m,k;
ll f,t,d;
struct node{
    ll first,second;
};
vector<node> a[maxn];
ll dp[maxn][maxn];
ll c[maxn];
void dfs(int x ,int fa){
    c[x]=1;dp[x][0]=dp[x][1]=0;
    for(auto v:a[x]){
        if(v.first==fa)continue;
        dfs(v.first,x);
        c[x]+=c[v.first];
        for(ll i=min(c[x],k);i>=0;i--){
            for(ll j=0;j<=min(c[v.first],i);j++){
                ll val=1ll*(1*j*(k-j)+1ll*(c[v.first]-j)*(n-k-(c[v.first]-j)))*v.second;;
                dp[x][i]=max(dp[x][i],dp[x][i-j]+dp[v.first][j]+val);
            }
        }
    }
}
void solve(){
    cin>>n>>k;
    mem(dp,-0x3f);
    for(int i=0;i<n-1;i++){
        cin>>f>>t>>d;
        a[f].push_back({t,d});
        a[t].push_back({f,d});
    }
    dfs(1,1);
    cout<<dp[1][k]<<endl;
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
