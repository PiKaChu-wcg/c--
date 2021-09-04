#include<bits/stdc++.h>
#include<iostream>
#include<stdio.h>
#define fastio ios::sync_with_stdio(0);cin.tie(0);
#define rep1(i,n)	for(int (i)=1;(i)<=(n);(i)++)
#define rep0(i,n)	for(int (i)=0;(i)<n;(i)++)
#define rep(i,s,t) for(int i=(s);i<=(t);i++)
#define repr(i,s,t) for(int i=(s);i>=(t);i--)
#define PI acos(-1)
#define VI vector<ll> 
#define PII pair<ll,ll>
#define INF 0x3f3f3f3f33f3ff3f
#define ll long long
#define int long long 
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
const int maxn=2e5+50;
//
int n,i,h,r;
vector<int> ch[maxn];
struct node{
    int c,t;
    int o;
    int cost;
    bool f=false;
}a[maxn];
void dfs(int x){
    int o=0;
    int t=a[x].t;
    int cost=0;
    for(auto i : ch[x]){
        if(!a[i].f)dfs(i);
        o+=a[i].o;
        cost+=a[i].cost;
        t=min(t,a[i].t);
    }
    if(a[x].c>o)cost+=(a[x].c-o)*t;
    a[x].o=max(o,a[x].c);
    a[x].cost=cost;
    a[x].t=t;
    a[x].f=true;
}
void solve(){  
    read(n);
    rep(i,1,n){
        int p;
        read(p);
        if(p>0)ch[p].push_back(i);
        read(a[i].c),read(a[i].t);
    }
    dfs(1);
    cout<<a[1].cost<<endl;
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
