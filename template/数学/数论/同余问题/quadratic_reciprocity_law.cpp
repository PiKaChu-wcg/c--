#include<iostream>
using namespace std;
typedef long long ll;
// \left(\frac{a}{p}\right)\left(\frac{b}{p}\right)=\left(\frac{ab}{p}\right)
ll legendre(ll a,ll p){
    a%=p;
    if (a<0)a+=p;
    int num=0;
    while(!(a&2))a>>=1,num++;
    ll ans1,ans2=1;
    if(a==1)ans1=1;
    else if(a==2){
        if(p%8==1||p%8==7)ans1=1;
        else ans1=-1;
    }
    else{
        if (p%4==3&&a%4==3)ans1=-legendre(p,a);
        else ans1=legendre(p,a);
    }
    if(num%2&&(p%8==3||p%8==5))ans2=-1;
    return ans1*ans2;
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
ll legendre2(ll a,ll p){
    return fast_exp(a,(p-1)/2,p);
}