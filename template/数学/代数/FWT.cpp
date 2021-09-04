#include<bits/stdc++.h>
using namespace std;
const int maxn=1024,mod=1e9+7,rev=(mod+1)>>1;
int a[maxn+50],b[maxn+50];
long long fc[maxn*maxn];
int T,n,m;
void fwt(int *a,int n)
{
    for(int d=1;d<n;d<<=1)
        for(int m=d<<1,i=0;i<n;i+=m)
            for(int j=0;j<d;j++)
            {
                int x=a[i+j],y=a[i+j+d];
                a[i+j]=(x+y)%mod,a[i+j+d]=(x-y+mod)%mod;
                //xor:a[i+j]=x+y,a[i+j+d]=(x-y+mod)%mod;
                //and:a[i+j]=x+y;
                //or:a[i+j+d]=x+y;
            }
}
void ufwt(int *a,int n)
{
    for(int d=1;d<n;d<<=1)
        for(int m=d<<1,i=0;i<n;i+=m)
            for(int j=0;j<d;j++)
            {
                int x=a[i+j],y=a[i+j+d];
                a[i+j]=1LL*(x+y)*rev%mod,a[i+j+d]=(1LL*(x-y)*rev%mod+mod)%mod;
                //xor:a[i+j]=(x+y)/2,a[i+j+d]=(x-y)/2;
                //and:a[i+j]=x-y;
                //or:a[i+j+d]=y-x;
            }
}
void solve(int *a,int *b,int n)//下标0..n-1的数组a和b求异或卷积，O(nlogn)，返回值在a中
{
    fwt(a,n);
    fwt(b,n);
    for(int i=0;i<n;++i) a[i]=1LL*a[i]*b[i]%mod;
    ufwt(a,n);
}
int main()
{
    fc[0]=1;
    for(int i=1;i<=1000000;++i) fc[i]=fc[i-1]*i%mod;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for(int i=1;i<=n;++i) a[i]=1;
        for(int i=1;i<=m;++i) b[i]=1;
        solve(a,b,maxn);
        long long ans=1;
        for(int i=0;i<maxn;++i) ans=ans*fc[a[i]]%mod;
        printf("%lld\n",ans);
    }
    return 0;
}