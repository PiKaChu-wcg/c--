/*
 * @Author: PiKaChu-wcg
 * @Github: https://github.com/PiKaChu-wcg/
 * @Date: 2021-05-08 21:30:22
 * @LastEditTime: 2021-05-08 22:10:01
 * @LastEditors: PiKaChu-wcg
 * @FilePath: \VScode\contest\nowcodeMutlischool\8\I.cpp
 * @Description: 

 */
#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#define debug(x) cout << #x << ":" << x << endl;
#define fastio               \
    ios::sync_with_stdio(0); \
    cin.tie(0);
#define rep1(i, n) for (int(i) = 1; (i) <= (n); (i)++)
#define rep0(i, n) for (int(i) = 0; (i) < n; (i)++)
#define rep for (int i = 0; i < n; i++)
#define repr(i, s, t) for (int i = (s); i >= (t); i--)
#define PI acos(-1)
#define VI vector<ll>
#define PII pair<ll, ll>
#define INF 0x3f3f3f3f3f
#define ll long long
#define int long long
#define mem(x, y) memset((x), (y), sizeof(x))
#define please return
#define AC 0
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

const int maxn = 1e5+20;
int n;
ll a[maxn];
ll b[maxn];
void solve(){
    cin >> n;
    rep0(i, n) cin >> a[i];
    rep0(i, n) cin >> b[i];
    cout << b[0];
    ll ans = 0;
    ll num = b[0];
    int idx = 1;
    ll sum = 0;
    ans += a[0] * b[0];
    while(idx<n){
        sum += a[idx];
        num = min(num, b[idx]);
        if(sum>0){
            ans += sum * num;
            sum = 0;
        }
        idx++;
    }
    cout << " " << ans;

}
signed main(){
    int T;
    cin >> T;
    rep1(i,T){
        cout << "Case #" << i << " ";
        solve();
    }
}
