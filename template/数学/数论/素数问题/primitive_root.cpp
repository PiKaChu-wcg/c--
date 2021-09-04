#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;


vector<ll> a;//p-1的质因子
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
//是否为原根
bool g_tst(ll g ,ll p){
    for (ll i = 0; i < a.size(); i++)
    {
        if(fast_exp(g,(p-1)/a[i],p)==1)return false;
    }
    return true;
}

template<typename T> T primitive_root(T p){
    //初始化a
    a.clear();
    T tmp=p-1;
    for (T i = 2; i < tmp/i; i++)
    {
        if(tmp%i==0)a.push_back(i);
        while(tmp%i==0)tmp/=i;
    }
    if(tmp!=1)a.push_back(tmp);
    //寻找原根
    ll g=1;
    while(true){
        if (g_test(g,p))
        {
            return g;   
        }
        g++;
    }
}