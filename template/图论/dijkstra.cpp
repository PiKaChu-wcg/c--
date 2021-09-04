#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=1e5+50;
struct edge
{
    ll v;
    ll w;
    ll next;
}e[maxn];
ll head[maxn];
ll cnt=0;
void add(ll x,ll y,ll z){
    e[cnt++].v=y;
    e[cnt].w=z;
    e[cnt].next=head[cnt];
    head[x]=cnt;
}
ll d[maxn];
bool v[maxn];

//  dijkstra   不能处理负边,  spfa可以处理负边
priority_queue<pair<ll ,ll>> q;
void dijkstra(){
    memset(d,0x3f,sizeof(d));
    memset(v,0,sizeof(v));
    d[1]=0;
    q.push(make_pair(0,1));
    while (q.size())
    {
        ll x=q.top().second;q.pop();
        if (v[x])continue;
        v[x]=1;
        for (int i = head[x]; i ; i=e[i].next)
        {
            ll y=e[i].v,z=e[i].w;
            if(d[y]>d[x]+z)d[y]=d[x]+z,q.push(make_pair(d[y],y));
        }   
    }
}