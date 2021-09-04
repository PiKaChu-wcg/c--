#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;


const int maxn=1e8+10;

bool valid[maxn];
int ans[maxn/10];
int res[maxn];//每个数的最小质因子
//埃氏筛
void getrprime(int n ,int & tot){
    tot=0;
    memset(valid,true,sizeof(valid));
    for (int i = 2; i < n; i++)
    {
        if (valid[i])
        {
            ans[++tot]=i;
            res[i]=i;
        }
        for(int j=1;(j<=tot)&&(i*ans[j]<=n);j++){
            int tp=i*ans[j];
            valid[tp]=false;
            res[tp]=ans[j];
            if (!(i%ans[j]))
            {
                break;
            }
        }
    }
}

bool check(int x){
    if(!(x&1))return false;
    if(valid[x])return false;//米歇尔数是合数
    int tp=x;
    while (tp!=1)
    {
        int minp=res[tp];
        if((x-1)%(minp-1))return false;
        tp=tp/minp;
        if(tp%minp==0)return false;
    }
    return true;
}
int tot;