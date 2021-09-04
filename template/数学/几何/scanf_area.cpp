#include<bits/stdc++.h>
using namespace std;
const double pi=acos(-1.0);
const double eps=1e-8;
const int maxn=1e6+5;

struct seg{
    double l,r,h;
    int v;
    seg(double l=0,double r=0,double h=0,int v=0):l(l),r(r),h(h),v(v){}
    bool operator <(seg& b){
        return h<b.h;
    }
};
struct node{
    double len;
    int v;
};
node t[1000];
double a,b,c,d;
int n,m;
seg s[220];
double x[220];
int cnt;
void pushdown(int l,int r,int rt){
    if(t[rt].v>0)t[rt].len=x[r+1]-x[l];
    else if(l==r)t[rt].len=0;
    else t[rt].len=t[rt<<1].len+t[rt<<1|1].len;
}
void add(int l,int r,int L,int R,int rt,int v){
    if(l<=L&&r>=R)t[rt].v+=v;
    else{
        int m=(L+R)/2;
        if(l<=m)add(l,r,L,m,rt<<1,v);
        if(r>m)add(l,r,m,L,rt<<1|1,v);
    }
    pushdown(L,R,rt);
}
int main(){
    int cas=1;
    while(cin>>n){
        if (n==0)
        {
            break;
        }
        cnt=0;
        memset(t,0,sizeof(t));
        for (int i = 0; i < n; i++)
        {
            cin>>a>>b>>c>>d;
            x[cnt]=a;
            s[cnt++]=seg(a,c,b,1);
            x[cnt]=c;
            s[cnt++]=seg(a,c,d,-1);
        }
        sort(x,x+cnt);
        sort(s,s+cnt);
        m=unique(x,x+cnt)-x;
        double ans=0;
        int r,l;
        for(int i;i<cnt-1;i++){
            l=lower_bound(x,x+m,s[i].l)-x;
            r=lower_bound(x,x+m,s[i].r)-x-1;
            add(l,r,0,m,1,s[i].v);
            ans+=t[l].len*(s[i+1].h-s[i].h);
        }
    }
    return 0;
}