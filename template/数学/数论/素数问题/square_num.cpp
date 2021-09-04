// m=p_1p_2...p_rM^2
// **其中$p_1,p_2,...,p_r$是互不相同的素因子，
// 则$m$可以表示成两个平方数之和的充要条件是每个$p_i$或为2或为模4余1**
// - $m$能表示成$m=a^2+b^2$，且$gcd(a,b)=1$，当且仅当以下两个条件之一成立：
// 1. $m$是奇数，且$m$的每个素因子都模4余1
// 2. $m$是偶数，$m/2$是奇数且$m/2$的每个素因子都模4余1
//本原勾股数,a^2+b^2=c^2,(c-b)和(c+b)是完全平方数





// 求大区间内的完全平方数

// 求素数分解平方数之和

// * $n ≠ 4^a(8m + 7) $ 是 $n$ 可以用三个平方数表示的一个**充分必要条件**
// * 每个正整数都是四个平方数之和

//设$p$是素数，则$p$是两平方数之和的充要条件是$p\equiv 1 \ (mod \ 4)   $ 或$p=2$


#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
typedef long long ll;
typedef pair<ll,ll> pll;


const int maxn=100;
int a[maxn];//质因数下标从1开始
int b[maxn];//质因数的指数
int tot;
void factor(int n){
    int now=n;
    tot=0;
    for (int  i = 2; i*i <= n; i++)
    {
        if (now%i==0)
        {
            a[++tot]=i;
            b[tot]=0;
            while(now%i==0)++b[tot],now/=i;
        }
    }
    if (now>1)
    {
        a[++tot]=now;
        b[tot]=1;
    }   
}
template<typename T> T mod_mul(T a,T b,T c){//a*b %c 乘法改加法 防止超long long
    T res=0;
    a=a%c;
    b=b%c;
    while(b)
    {
        if(b&1) res=(res+a)%c;
        b>>=1;
        a=(a+a)%c;
    }
    return res;
}

template<typename T>T fast_exp(T a,T b,T c){
    T res=1;
    a=a%c;
    while(b)
    {
        if(b&1) res=mod_mul(res,a,c);
        b>>=1;
        a=mod_mul(a,a,c);
    }
    return res;
}
//得到-1的二次剩余
ll ran(ll n){
    srand(time());
    while(true){
        ll a=rand()%(n-1)+1;
        ll b=fast_exp(a,(n-1)/4,n);
        if (mod_mul(b,b,n))
        {
            return b<=n/2?b:n-b;
        }
    }
}
//费马降阶法
pll feyman(ll p){
    if(p==2)return mp(1,1);
    if(p%4!=1)return mp(-1,-1);
    ll A,B,u,v,k;
    A=ran(p);B=1;
    k=ll((A*A+B*B)/p);
    while(k>1){
        u=(A%k);v=B%k;
        if(2*u>k)u=k-u;
        if(2*v>k)v=k-v;
        ll ta=A;
        A=(u*A+v*B)/k;
        B=(v*ta-u*B)/k;
        k=(u*u+v*v)/k
    }
    return mp(min(A,B),max(A,B));
}

bool check_factor(ll n){
    factor(n);
    bool flag=false;
    for(int i=1;i<=tot;i++){
        if (a[i]%4==3&&b[i]%2)  
        {
            return false;
        }
        if(a[i]%4==1&&b[i])flag=true;
    }
    return flag;
}
pll solve(ll n){
    ll k=1;
    pll ans,tmp;
    ll tx,ty;
    vector<int> odd;
    for (int i = 1; i < tot; i++)
    {
        for (int j = 0; j < b[i]/2; j++)
        {
            k*=a[i];
        }
        if(b[i]%2)odd.push_back(i);
    }
    ans=feyman(a[odd[0]]);
    for (int i = 1; i < odd.size(); i++)
    {
        tmp=feyman(a[odd[i]]);
        tx=ans.first;ty=ans.second;
        ans.first=abs(tx*tmp.first+ty*tmp.second);
        ans.second=abs(ty*tmp.first-tx*tmp.first);
    }
    ans.first*=k;
    ans.second*=k;
    return ans;
 }
 bool is_square(ll n){
     return (ll)sqrt(n)*(ll)sqrt(n)==n;
 }
