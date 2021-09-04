#include<bits/stdc++.h>
using namespace std;

const int maxn=(1<<16)+10;

bool valid[maxn];
int prime[maxn];
int tot;

void get_prime(int n)
{
    tot=0;
    for(int i=2;i<=n;++i) valid[i]=true;
    for(int i=2;i<=n;++i){
        if(valid[i]==true){
            prime[++tot]=i;
        }
        for(int j=1;j<=tot && prime[j]*i<=n;++j){
            valid[prime[j]*i]=false;
            if(i%prime[j]==0) break;
        }
    }
}

//<<2是为了1e6区间而已
vector<int> ans[maxn<<2];//区间每个数的质因子
vector<int> bns[maxn<<2];//质因子对应的指数

int many_prime_factorize()
{
    //freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false);
    get_prime(1<<16);
    int L,R;
    cin>>L>>R;
    for(int i=1;i<=tot;++i){
        for(int j=(L-1)/prime[i]+1;j<=R/prime[i];++j){
            ans[j*prime[i]-L].push_back(prime[i]);
        }
    }

    //L存在0这里
    for(int i=0;i<R-L+1;++i){
        if(ans[i].size()==0){
            ans[i].push_back(i),bns[i].push_back(1);
            continue;
        }
        int x=i+L;
        for(int j=0;j<ans[i].size();++j){
            int tp=ans[i][j];
            int num=0;
            while(x%tp==0){
                x/=tp;
                num++;
            }
            bns[i].push_back(num);
        }
        if(x!=1) ans[i].push_back(x),bns[i].push_back(1);
    }
    //输出
    for(int i=0;i<R-L+1;++i){
        cout<<i+L<<": ";
        for(int j=0;j<ans[i].size();++j)
            if(j==ans[i].size()-1) cout<<ans[i][j]<<'^'<<bns[i][j];
            else cout<<ans[i][j]<<'^'<<bns[i][j]<<" * ";
        cout<<endl;
    }
}
