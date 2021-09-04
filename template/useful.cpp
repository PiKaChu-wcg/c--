#include<bits/stdc++.h>
#define ll long long
const int MAXSIZE=1000000;
const int mod=1e9+7;

//数论
inline ll qpow(ll x,ll k,ll r=1){
    for(;k;k>>=1,x=1ll*x*x%mod) if(k&1) r=1ll*r*x%mod;
    return r;
}
inline ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }

//图论

//几何

