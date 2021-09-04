#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

//O sqrt(p) 求解欧拉函数
int phi(int x)
{
    int res=x;
    for(int i=2;i*i<=x;++i){
        if(x%i==0){
            res-=res/i;
            do{
                x/=i;
            }while(x%i==0);
        }
    }
    if(x>1) res-=res/x;
    return res;
}


ll fast_exp(ll a,ll b,ll c)
{
    ll res=1;
    a=a%c;
    assert(b>=0);
    while(b)
    {
        if(b&1){
            res=res*a%c;
        }
        a=a*a%c;
        b>>=1;
    }
    return res;
}
