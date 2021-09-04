#include<bits/stdc++.h>

using namespace std;
const int maxn=1e5+5;
int prime[maxn];
int v[maxn];
int m;
void get_prime(int n){
    memset(v,0,sizeof(v));
    m=0;
    for (int i = 2; i <= n; i++)
    {
        if (v[i]==0)
        {
            v[i]=i;
            prime[++m]=i;
        }
        for (int j = 0; j <=m; j++)
        {
            if(prime[j]>v[i]||prime[j]>n/i)break;
            v[i*prime[j]]=prime[j];
        }  
    }
}