#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m,mod;// cal C(n,m)%mod

const int maxn=20;//同余方程个数
//在拓展卢卡斯中  模数一般1e6
//质因子数目很少

ll a[maxn];//每个方程的右值
ll M[maxn];//每个方程模的数
ll p[maxn];//底数
ll q[maxn];//质数
int num_equ;//方程数 即m的质因子数

//快速幂
ll fast_pow(ll a,ll b,ll mod)
{
    ll res=1;
    while(b)
    {
        if(b&1) res=a*res%mod;
        b>>=1;
        a=a*a%mod;
    }
    return res;
}

//拓展欧几里得
//返回值最小公因子
ll e_gcd(ll a,ll b,ll &x,ll &y)
{
    if(b==0){x=1;y=0;return a;}
    ll ans=e_gcd(b,a%b,x,y);
    ll temp=x; x=y; y=temp-a/b*y;
    return ans;
}

//%mod逆元
ll inv(ll a,ll mod)
{
    ll ans,tmp;
    e_gcd(a,mod,ans,tmp);
    return (ans+mod)%mod;
}

//x同余a  mod m
//a为方程右值 m为方程的模 n为方程数
//下标从0开始
ll CRT(ll a[],ll m[],int n){
    ll M=1;
    for(int i=0;i<n;++i) M*=m[i];
    ll ret=0;
    for(int i=0;i<n;++i){
        ll x,y;
        ll tm=M/m[i];
        ll tmp=e_gcd(tm,m[i],x,y);//tm 和 m[i]互质  只有一个解
        //cout<<x<<endl;
        ret=(ret+tm*x*a[i])%M;//这里x可能为负值  但不影响结果
    }
    return (ret+M)%M;
}

//质因子分解m
void solve_fac()
{
    int tp=mod;
    num_equ=0;
    for(int i=2;i<(int)(sqrt(tp)+1.0);++i){
        if(tp%i==0){
            //i是一个质因子
            p[num_equ]=i;
            int num=0;
            while(tp%i==0){
                num++;
                tp/=i;
            }
            q[num_equ++]=num;
        }
    }
    if(tp!=1){
        p[num_equ]=tp;
        q[num_equ++]=1;
    }
    //num_equ;方程数 即m的质因子数
    for(int i=0;i<num_equ;++i){
        M[i]=1; for(int j=0;j<q[i];++j) M[i]*=p[i];
    }
}

//求解n! % p^q
ll solve(ll n,int id)//id对应第几个质因子
{
    //为了保证和p^q互质 从而有逆元 我们提出来的公因子p是不考虑的
    if(n==0) return 1LL;
    ll res=1;
    ll num=n/M[id];//同余的组数
    if(num>0){//有完整的一组
        for(int i=1;i<=M[id];++i){
            if(i%p[id]) res=res*i%M[id];
        }
        res=fast_pow(res,num,M[id]);//num组
    }
    for(ll i=1;i<=n%M[id];++i){//不成组的单独处理
        if(i%p[id]) res=res*i%M[id];
    }
    //子问题递归即可
    return res*solve(n/p[id],id)%M[id];
}


ll C(ll n,ll m,int id)//id表示哪个质因子
{
    if(m>n) return 0;
    ll a=solve(n,id),b=solve(m,id),c=solve(n-m,id);
    ll k=0;
    //k为p的指数 即solve中没有考虑的部分
    for (ll i=n;i;i/=p[id]) k+=i/p[id];
    for (ll i=m;i;i/=p[id]) k-=i/p[id];
    for (ll i=n-m;i;i/=p[id]) k-=i/p[id];
    //cout<<"p M a b c k:   "<<p[id]<<" "<<M[id]<<" "<<a<<" "<<b<<" "<<c<<" "<<k<<endl;
    //k>=0是一定的  最后再乘上p^k
    return a*inv(b,M[id])%M[id]*inv(c,M[id])%M[id]*fast_pow(p[id],k,M[id])%M[id];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    ios::sync_with_stdio(false);
    cin>>n>>m>>mod;
    solve_fac();
    for(int i=0;i<num_equ;++i){
        a[i]=C(n,m,i);
    }
    cout<<CRT(a,M,num_equ)<<endl;
    return 0;
}