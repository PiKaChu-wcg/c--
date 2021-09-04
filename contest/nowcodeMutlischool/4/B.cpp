/*
 * @Author: PiKaChu-wcg
 * @Github: https://github.com/PiKaChu-wcg/
 * @Date: 2021-05-10 20:25:03
 * @LastEditTime: 2021-05-10 20:46:36
 * @LastEditors: PiKaChu-wcg
 * @FilePath: \VScode\contest\nowcodeMutlischool\4\B.cpp
 * @Description: 
 */
#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
int prime[maxn];
int v[maxn];
int m;
int ans[maxn];
const int mod = 1e9 + 7;
#define ll long long
ll qpow(ll x,ll k){
    k %= mod - 1;
    ll res = 1;
    ll base = x;
    while(k){
        if(k&1){
            res *= base;
            res %= mod;
        }
        base *= base;
        base %= mod;
        k >>= 1;
    }
    return res;
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
ll dfs(int x){
    if(x==1)
        return 0;
    if(ans[x])
        return ans[x];
    return dfs(x / v[x]) + 1;
}
void solve(){
    int n, c;
    cin >> n >> c;
    cout << qpow(c, dfs(n)) << endl;
}
int main(){
    ios::sync_with_stdio(false);
    get_prime(1e6 + 10);
    int T;
    cin >> T;
    while(T--){
        solve();
    }
}
