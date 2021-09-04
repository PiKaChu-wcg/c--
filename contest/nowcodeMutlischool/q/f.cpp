/*
 * @Author: PiKaChu-wcg
 * @Github: https://github.com/PiKaChu-wcg/
 * @Date: 2021-05-10 21:51:47
 * @LastEditTime: 2021-05-11 11:27:52
 * @LastEditors: PiKaChu-wcg
 * @FilePath: \VScode\contest\nowcodeMutlischool\q\f.cpp
 * @Description: 
 */

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 998244353;
ll qpow(ll x, ll k = mod - 2, ll m = mod)
{
    if (!k)
        return 1;
    return (k & 1) ? (x * qpow((x * x) % m, k >> 1, m)) % m : qpow((x * x) % m, k >> 1, m) % m;
}

void solve(int n){
    ll res=(qpow(4,n-1)*(2*n+1)-1)*qpow(qpow(4,n)*(2*n+1));
    cout << (res%mod+mod)%mod << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    int n;
    while(cin>>n)
        solve(n);
}