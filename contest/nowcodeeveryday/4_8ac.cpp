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
#define INF 0x3f3f3f3f3f
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
const int maxn=2e6+50;
//
int k,n;
int f[1<<17];
ll c[20];
ll a[maxn];
ll s[maxn];
int bi_search(int b,ll c){
    ll a=s[b]+c;
    return upper_bound(s+1,s+n+1,a)-s-1;
}
void p(int x){
    rep1(i,16){cout<<(x&1);x>>=1;}
    cout<<endl;
}
void solve(){
    cin>>k>>n;
    rep0(i,k)cin>>c[i];
    rep1(i,n)cin>>a[i];
    rep1(i,n)s[i]=s[i-1]+a[i];
    rep1(i,(1<<(k))-1){
        rep0(j,k){
            if((i>>j)&1){
            f[i]=max(f[i],bi_search(f[i-(1<<j)],c[j]));}
        }
    }
    ll ans=-1;
    rep0(i,1<<17){
        if(f[i]==n){
            ll t=0;
            int q=i;
            rep0(j,k){
                if((q&1)==0)t+=c[j];
                q>>=1;
            }
            ans=max(ans,t);
        }
    }
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
