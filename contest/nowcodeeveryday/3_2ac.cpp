//#include<bits/stdc++.h>
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
//#define int long long
#define mem(x,y) memset((x),(y),sizeof(x))
#define mp make_pair
const int dx[8]={1,0,-1,0,1,-1,-1,1},dy[8]={0,1,0,-1,1,1,-1,-1};
using namespace std;
 inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
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
int n,k;
int a[maxn];
int ans=0;
bool dp[maxn];
int cnt=0;
void solve(){  
    cin>>n;cin>>k;
    rep0(i,n)cin>>a[i];
    rep0(i,n){
        if(dp[a[i]]==ans)dp[a[i]]++,cnt++;
        if(cnt==k)ans++,cnt=0;
    }
    cout<<ans+1<<endl;
}
int main(){
	fastio;
	int T=1;
	// cin>>T;
	while(T--){
        solve();
	}
    return 0;
}
