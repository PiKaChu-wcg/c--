#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
//质因数分解
template<typename T>T mod_mul(T a,T b,T c){//a*b %c 乘法改加法 防止超long long
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
template<typename T> T fast_exp(T a,T b,T c){
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
template<typename T>bool test(T n,T a,T d)
{
    if(!(n&1)) return false;
    while(!(d&1))  d>>=1;
    T t=fast_exp(a,d,n);
    while(d!=n-1 && t!=1 && t!=n-1){
        t=mod_mul(t,t,n);
        d<<=1;
    }
    return ((t==n-1) || (d&1) ==1 );
}

template<typename T> bool is_prime(T n){
    if(n<2) return false;
    if(n==2) return true;
    T a[30];
    srand(time(0));
    for(int i=0;i<7;++i) {
        a[i]=rand()%(n-2)+2;
        if(!test(n,a[i],n-1)) return false;
    }
    return true;
}


//pollard_rho 

ll factor[100];
int tol;//质因数的个数
template<typename T> T gcd(T a,T b)
{
    return b==0? a:gcd(b,a%b);
}
template<typename T> T Pollard_rho(T x,T c){
    T i=1;k=2;
    T x0=rand()*x;
    T y=x0;
    while(1){
        i++;
        x0=(mod_mul(x0,x0,x)+c)%x;
        T d=gcd(y-x0,x);
        if(d!=1&&d!=x)return d;
        if(y==x0)return x;
        if(i==k)y=x0,k+=k;
        
    }
}
void findfac(ll n){
    if (is_prime(n))
    {
        factor[tol++]=n;
        return ;
    }
    ll p=n;
    while(p>=n)Pollard_rho(p,rand()%(n-1)+1);
    findfac(p);
    findfac(n/p);
}