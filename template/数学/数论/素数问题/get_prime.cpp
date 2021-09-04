#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

const int maxn=1e7+10;

bool valid[maxn];
int ans[maxn];
void getprime(int n,int & tot, int ans[]){
    tot=0;
    for(int i=2;i<=n;i++)valid[i]=true;
    for (int i = 2; i < n; i++)
    {
        if (valid[i])
        {
            ans[++tot]=i;
            if (n/i<i)
            {
                break;
            }
            for(int j=i*i;j<=n;j+=i)valid[j]=false;
        }
    }
}