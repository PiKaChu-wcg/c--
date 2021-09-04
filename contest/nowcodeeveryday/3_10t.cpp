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
const int maxn=5e2+50;
//
int n,m;
int a[maxn];
int p;
int dp[maxn<<2][maxn];
void pushdown(int x){
    mem(dp[x],1);
    int l=x<<1;
    int r=x<<1|1;
    for(int i=1;dp[l][i];i++){
        for(int j=1;dp[r][j];j++){
            if(i+j>m)break;
            dp[x][i+j]=min(dp[x][i+j],dp[l][i]+dp[r][j]);
        }
    }
}
void build(int x,int l,int r){
    if(r-l==1){
        rep(j,1,min(m-n+1,a[l])){
            dp[x][j]=(a[l]%j)*(a[l]/j+1)*(a[l]/j+1)+(j-a[l]%j)*(a[l]/j)*(a[l]/j);
        }
        return;
    }
    int mid=l+r+1>>1;
    build(x<<1,l,mid);
    build(x<<1|1,mid,r);
    pushdown(x);
}
void modify(int x,int p,int v,int l,int r){
    if(r-l==1){
        a[l]=v;
        rep(j,1,min(m-n+1,a[l])){
            dp[x][j]=(a[l]%j)*(a[l]/j+1)*(a[l]/j+1)+(j-a[l]%j)*(a[l]/j)*(a[l]/j);
        }
        return;
    }
    int mid=l+r+1>>1;
    if(mid<=p)modify(x<<1|1,p,v,mid,r);
    if(p<mid)modify(x<<1,p,v,l,mid);
    pushdown(x);
}
int x,v;
void solve(){
    mem(dp,1);
    read(n),read(m);
    rep0(i,n)read(a[i]);
    build(1,0,n);
    read(p);
    rep(i,1,p){
        read(x),read(v);
        modify(1,x-1,v,0,n);
        cout<<dp[1][m]<<endl;
    }
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
