#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5+10;
#define lx x<<1
#define rx x<<1|1
#define ll long long 
ll sum[maxn<<2],add[maxn<<2];
void push_up(int x){
    sum[x]=sum[lx]+sum[rx];
}
void push_down(int x,int v){
    if(add[x]){
        add[lx]+=add[x];
        add[rx]+=add[x];
        sum[lx]+=(v-(v>>1))*add[x];
        sum[rx]+=(v>>1)*add[x];
        add[x]=0;
    }
}
void build(int l,int r,int x){
    add[x]=0;
    if(l==r){
        cin>>sum[x];
        return;
    }
    int mid=(l+r)>>1;
    build(l,mid,lx);
    build(mid+1,r,rx);
    push_up(x);
}
void updata(int l,int r,int v,int L,int R,int x){
    if(l<=L&&r>=R){
        sum[x]+=(R-L+1)*v;
        add[x]+=v;
        return;
    }
    push_down(x,R-L+1);
    int mid=(R+L)>>1;
    if(l<=mid)updata(l,r,v,L,mid,lx);
    if(r>mid)updata(l,r,v,mid+1,R,rx);
    push_up(x);
}
ll query(int l,int r,int L,int R,int x){
    // cout<<l<<" "<<r<<" "<<L<<" "<<R<<" "<<x<<endl;
    // cout<<l<<" "<<r<<" "<<L<<" "<<R<<" "<<x<<endl;
    if(l<=L&&r>=R)return sum[x];
    push_down(x,R-L+1);
    int mid=(L+R)>>1;
    ll ans=0;
    if(l<=mid)ans+=query(l,r,L,mid,lx);
    if(r>mid)ans+=query(l,r,mid+1,R,rx);
    return ans;
}
int n,m;
int a,b;
ll c;
char str[2];
int main(void){
    cin>>n>>m;
    build(1,n,1);
    while(m--){
        cin>>str;
        if(str[0]=='C'){
            cin>>a>>b>>c;
            updata(a,b,c,1,n,1);
        }
        else{
            cin>>a>>b;
            printf("%lld\n",query(a,b,1,n,1));
        }
    }
}
