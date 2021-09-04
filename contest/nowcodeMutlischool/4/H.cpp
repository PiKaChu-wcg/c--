/*
 * @Author: PiKaChu-wcg
 * @Github: https://github.com/PiKaChu-wcg/
 * @Date: 2021-05-10 21:11:49
 * @LastEditTime: 2021-05-10 21:11:50
 * @LastEditors: PiKaChu-wcg
 * @FilePath: \VScode\contest\nowcodeMutlischool\4\H.cpp
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
ll qpow(ll x, ll k)
{
    k %= mod - 1;
    ll res = 1;
    ll base = x;
    while (k)
    {
        if (k & 1)
        {
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
void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= m; i++)
    {
        if(prime[i]>n){
            
        }
    }
    

}
int main(){
    get_prime(2e5 + 10);
    int t;
    cin >> t;
    while(t--){
        solve();
    }

}