/*
 * @Author: PiKaChu-wcg
 * @Github: https://github.com/PiKaChu-wcg/
 * @Date: 2021-05-05 15:53:13
 * @LastEditTime: 2021-05-05 16:58:12
 * @LastEditors: PiKaChu-wcg
 * @FilePath: \VScode\contest\nowcodeMutlischool\9\e.cpp
 * @Description: 
 */

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5 + 5;
int prime[maxn];
int v[maxn];
int m;
const int mod = 998244353;
// ll qpow(ll x, ll k = mod - 2, ll m = mod)
// {
//     if (!k)
//         return 1;
//     return (k & 1) ? (x * qpow((x * x) % m, k >> 1, m)) % m : qpow((x * x) % m, k >> 1, m) % m;
// }
inline ll qpow(ll x, ll k, ll r = 1)
{
    if(k<=0)
        cout<<x<<" "<<k;
    k %= mod - 1;
    for (; k; k >>= 1, x = 1ll * x * x % mod)
        if (k & 1)
            r = 1ll * r * x % mod;
    return r;
}
void get_prime(int n)
{
    memset(v, 0, sizeof(v));
    m = 0;
    for (int i = 2; i <= n; i++)
    {
        if (v[i] == 0)
        {
            v[i] = i;
            prime[++m] = i;
        }
        for (int j = 0; j <= m; j++)
        {
            if (prime[j] > v[i] || prime[j] > n / i)
                break;
            v[i * prime[j]] = prime[j];
        }
    }
}
map<int, int> xp, yp;

ll a, b, c, d, x, y;
ll p[maxn], xq[maxn], yq[maxn],rq[maxn];
int cnt = 0;
void f(int x){
    int i = 1;
    while(i<=m){
        if(x%prime[i]==0)
            p[++cnt] = prime[i];
        while(x%prime[i]==0){
            xq[cnt]++;
            x /= prime[i];
        }
        i++;
    }
    if(x>1){
        p[++cnt] = x;
        xq[cnt]++;
    }
}
int main(){
    get_prime(1e5);
    cin >>a >> b >> c >> d >> x >> y;
    f(x);
    for (int i = 1; i <= cnt;i++){
        while(y%p[i]==0){
            y /= p[i];
            yq[i]++;
        }
    }
    ll res = 1;
    for (int i = a; i <= b;i++){
        //printf("!");
        for (int j = 1; j <= cnt;j++)
        {
            int t = p[j];
            int u = i * xq[j];
            int v = yq[j];
            if(!v)
                continue;
            int z = u / v;
            if(c>z){
                rq[j] += u*(d - c + 1);
                
            }else if(d<=z){
                rq[j]+=v*(d + c) * (d - c + 1) / 2;
                res %= mod;
            }else{
                rq[j]+= u * (d - z);
                rq[j]+= v * (z + c) * (z - c + 1) / 2;
            }
        }
    }
    for(int i=1;i<=cnt;i++){res*=qpow(p[i],rq[i]);res%=mod;}
    cout << res << endl;
}