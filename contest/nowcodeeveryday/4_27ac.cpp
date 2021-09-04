/*
 * @Author: PiKaChu-wcg
 * @Github: https://github.com/PiKaChu-wcg/
 * @Date: 2021-03-07 13:04:34
 * @LastEditTime: 2021-04-28 20:22:28
 * @LastEditors: PiKaChu-wcg
 * @FilePath: \VScode\test.cpp
 * @Description: 
 */

#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#define debug(x) cout << #x << ":" << x << endl;
#define fastio ios::sync_with_stdio(0); cin.tie(0);
#define rep1(i, n) for (int(i) = 1; (i) <= (n); (i)++)
#define rep0(i, n) for (int(i) = 0; (i) < n; (i)++)
#define rep(i, s, t) for (int i = (s); i <= (t); i++)
#define repr(i, s, t) for (int i = (s); i >= (t); i--)
#define PI acos(-1)
#define VI vector<ll>
#define PII pair<ll, ll>
#define INF 0x3f3f3f3f3f
#define ll long long
#define int long long
#define mem(x, y) memset((x), (y), sizeof(x))
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1}, dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
using namespace std;
template <typename T>
inline void read(T &a)
{
    char c = getchar();
    T x = 0, f = 1;
    while (!isdigit(c))
    {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (isdigit(c))
    {
        x = (x << 1) + (x << 3) + c - '0';
        c = getchar();
    }
    a = f * x;
}
template <typename T>
void write(T x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}
template <typename T>
T gcd(T x, T y)
{
    return y ? gcd(y, x % y) : x;
}
const int mod = 1e9 + 7;
ll qpow(ll x, ll k = mod - 2, ll m = mod)
{
    if (!k)
        return 1;
    return (k & 1) ? (x * qpow((x * x) % m, k >> 1, m)) % m : qpow((x * x) % m, k >> 1, m) % m;
}

//
const int maxn=2e5+10;
int n,g,b,d;
PII p[maxn];
int nxt[maxn];
void solve()
{
    cin>>n>>g>>b>>d;
    rep0(i,n)cin>>p[i].first>>p[i].second;
    sort(p,p+n);
    p[n].first=d;
    int t=0;
    if(p[0].first>b){
        cout<<-1<<endl;
        return;
    }
    rep0(i,n){
        t=p[i+1].first-p[i].first;
        if(t>g){
            cout<<-1<<endl;
            return;
        }
    }
    nxt[n-1]=n;
    for (int i = n-1; i >= 0; i--)
    {   int j;
        for(j=i+1;j!=n&&p[i].second<=p[j].second;j=nxt[j]);
        nxt[i]=j;
    }
    b-=p[0].first;
    int ans=0;
    int now=0;
    while(now<n){
        if(p[nxt[now]].first-p[now].first>g){
            ans+=p[now].second*(g-b);
            b=g-p[now+1].first+p[now].first;
            now++;
        }else{
            if(b>=p[nxt[now]].first-p[now].first)
            b-=p[nxt[now]].first-p[now].first;
            else {
                ans+=p[now].second*(p[nxt[now]].first-p[now].first-b);
                b=0;
            }
            now=nxt[now];
        }
    }
    cout<<ans<<endl;
}
signed main()
{   
    int T=1;
    // cin>>T;
    while(T--)
    solve();
}
