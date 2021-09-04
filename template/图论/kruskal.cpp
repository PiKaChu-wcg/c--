
#include<iostream> 
#include<algorithm>
#include<cstdio>
using namespace std;
const int manx = 1e5 + 5; //锟斤拷应锟斤拷锟斤拷锟斤拷目
const int mamx = 1e5 + 5; //锟斤拷应锟竭碉拷锟斤拷目
int n, m, u, v, total = 1;
struct edge {
    int start, to;
    long long val;
}bian[mamx];
int a[manx];
long long ans;
int find(int x) //锟斤拷锟介集
{
    if (a[x] == x) return x;
    else return a[x] = find(a[x]);
}
bool cmp(edge x, edge y)
{
    return x.val < y.val;
}
inline void kruskal()
{
    for (int i = 1; i <= m; i++)
    {
        u = find(bian[i].start);
        v = find(bian[i].to);
        if (u == v) continue; 
        ans += bian[i].val;
        a[u] = v;
        total++;
        if (total == n - 1) break;
    }
}