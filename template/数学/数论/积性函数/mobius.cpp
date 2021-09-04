#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

const int maxn=1e6+7;
bool valid[maxn];
short mu[maxn];
int ans[maxn/10];
int tot;
//单值
short getmob(ll a){
    ll x=a;
    int cnt=0,now=0;
    for(int j=1;1LL*ans[j]*ans[j]<=x && j<=tot;j++){
        now=0;
        if(x%ans[j]==0){
            while(x%ans[j]==0){
                now++;
                if(now>1) return 0;
                x/=ans[j];
            }
            cnt++;
        }
    }
    if(x!=1) cnt++;
    return (cnt&1)?-1:1;
}
void get_mu(int n){
    for (int i = 1; i < n+1; i++)
    {
        int target=i==1?1:0;
        int delta=target-mu[i];
        mu[i]=delta;
        for (int j = 2*i; j < n; j+=i)
        {
            mu[j]+=delta;
        }
        
    }
    
}

void get_prime(int n)
{
    tot=0;
    mu[1]=1;
    memset(valid,true,sizeof(valid));
    for(int i=2;i<=n;++i){
        if(valid[i]){
            ans[++tot]=i;
            mu[i]=-1;
        }
        for(int j=1;j<=tot&&ans[j]*i<=n;j++){
            valid[i*ans[j]]=false;
            if(i%ans[j]==0){
                mu[i*ans[j]]=0;
                break;
            }
            else{
                mu[i*ans[j]]=-mu[i];
            }
        }
    }
}
