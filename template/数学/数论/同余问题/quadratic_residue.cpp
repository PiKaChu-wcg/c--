#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll fast_exp(ll a,ll b,ll c){
    ll res=1;
    a=a%c;
    while(b)
    {
        if(b&1) res=(res*a)%c;
        b>>=1;
        a=(a*a)%c;
    }
    return res;
}//求解x^2 \equiv -1 (mod p)
ll ran(ll n){
    //要保证n%4=1
    srand(time(0));
    for(;;){
        ll a=rand()*rand()%(n-1)+1;
        ll b=fast_exp(a,(n-1)/4,n);
        if(b*b%n==n-1) return b<=(n-1)/2 ? b:n-b;//若爆long long 则用快速乘
    }
}