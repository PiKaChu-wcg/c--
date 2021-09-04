#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

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