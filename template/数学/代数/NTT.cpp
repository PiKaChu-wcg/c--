#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=262144*4;
//const long long P=50000000001507329LL; // 190734863287 * 2 ^ 18 + 1
//const int P=1004535809; // 479 * 2 ^ 21 + 1
const ll mod=998244353; // 119 * 2 ^ 23 + 1
const ll G=3;

ll len=0;
ll pw[maxn+5],pwinv[maxn+5];
ll A[maxn+5],B[maxn+5];
ll f[maxn+5];
int n,m;

ll Pow(ll a,ll b,ll mod)
{
    ll ans=1;
    while(b)
    {
        if(b&1) ans=ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}
ll Inv(ll x)
{
    return Pow(x,mod-2,mod);
}
void Init()
{
    ll inv=Inv(G);
    for (int i=1;i<=maxn;i<<=1)
    {
        pw[i]=Pow(G,(mod-1)/i,mod);
        pwinv[i]=Pow(inv,(mod-1)/i,mod);
    }
}
void rader(ll *a)
{
    for(int i=0,j=0;i<len;i++)
    {
        if(i>j) swap(a[i],a[j]);
        int k=len;
        do{k>>=1;j^=k;}while(j<k);
    }
}
void ntt(ll *a,int f)
{
    rader(a);
    for(int i=2;i<=len;i<<=1)
    {
        int m=i>>1;
        for(int j=0;j<len;j+=i)
        {
            ll w=1,wn=pw[i];
            if(f==-1) wn=pwinv[i];
            for(int k=0;k<m;k++)
            {
                ll x=a[j+k+m]*w%mod;
                a[j+k+m]=(a[j+k]-x+mod)%mod;
                a[j+k]=(a[j+k]+x)%mod;
                w=w*wn%mod;
            }
        }
    }
    if(f==-1)
    {
        ll inv=Inv(len);
        for(int i=0;i<len;i++) a[i]=a[i]*inv%mod;
    }
}
void con(ll *A,int n,ll *B,int m)
{
    /*A[0..n-1]与B[0..m-1]卷积*/
    for(len=1;len<max(n,m);len<<=1);
    len<<=1;
    for(int i=n;i<len;++i) A[i]=0;
    for(int i=m;i<len;++i) B[i]=0;
    ntt(A,1);
    ntt(B,1);
    for(int i=0;i<len;++i) A[i]=A[i]*B[i]%mod;
    ntt(A,-1);
}
int main()
{
    Init();
    con(A,n,B,m);
    return 0;
}