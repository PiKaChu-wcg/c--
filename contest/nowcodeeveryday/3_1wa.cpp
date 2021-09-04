#include<bits/stdc++.h>
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
#define ls x<<1
#define rs x<<1|1
ll t[maxn<<2];
int lazy[maxn<<2];
int a[maxn];
int n,m;
int op,l,r,k;
void build(int l,int r,int x){
    if(r-l==1){
        t[x]=a[l];
        return;
    }
    int mid=r+l+1>>1;
    build(l,mid,ls);
    build(mid,r,rs);
    t[x]=t[ls]+t[rs];
}
void pushdown(int l,int r,int x){
    if(lazy[x]){
        int mid=r+l+1>>1;
        lazy[ls]=lazy[x];
        t[ls]=(lazy[x]+lazy[x]+mid-l-1)*(mid-l)/2;
        t[rs]=(lazy[rs]+lazy[rs]+r-mid-1)*(r-mid)/2;
        lazy[x]=0;
    }
}
void updata(int l,int r,int L,int R,int x,int k){
    if(L<=l&&r<=R){
        t[x]=1LL*(r-l)*(k+l-L+k+r-L-1)/2;
        lazy[x]=k+l-L;
        return;
    }
    pushdown(l,r,x);
    int mid=l+r+1>>1;
    if(mid>L)updata(l,mid,L,R,ls,k);
    if(mid<R)updata(mid,r,L,R,rs,k);
    t[x]=t[ls]+t[rs];
}
ll query(int l,int r,int L,int R,int x){
    if(L<=r&&r<=R)return t[x];
    pushdown(l,r,x);
    ll res=0;
    int mid=l+r+1>>1;
    if(mid>L)res+=query(l,mid,L,R,ls);
    if(mid<R)res+=query(mid,r,L,R,rs);
    return res;
}
void solve(){  
    n=read();m=read();
    rep0(i,n)a[i]=read();
    build(0,n,1);
    rep0(i,m){
        op=read();
        if(op==1){
            l=read();r=read();k=read();
            updata(0,n,l-1,r,1,k);
        }else{
            l=read();r=read();
            cout<<query(0,n,l-1,r,1)<<endl;
        }
    }
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


