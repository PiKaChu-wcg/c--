////////////////////////////////////////////////
////Author       : PiKaChu_wcg
////Date         : 2021-08-31 22:17:46
////LastEditors  : PiKachu_wcg
////LastEditTime : 2021-09-01 11:17:01
////FilePath     : \c++\template.cpp
////////////////////////////////////////////////
#include <bits/stdc++.h>
#define debug(x) cerr << #x << ":" << x << endl;
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
using namespace std;

//!=====================================================
// todo define sum const var
const int mod = 1e9 + 7;
const bool mutliinput = false;
const int maxn = 1e5;
//!=====================================================

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1},dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template <typename T>
inline void read(T& a) {
    char c = getchar();
    T x = 0, f = 1;
    while (!isdigit(c)) {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (isdigit(c)) {
        x = (x << 1) + (x << 3) + c - '0';
        c = getchar();
    }
    a = f * x;
}
template <typename T>
void write(T x) {
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}
template <typename T>
T gcd(T x, T y) {
    return y ? gcd(y, x % y) : x;
}
ll qpow(ll x, ll k = mod - 2, ll m = mod) {
    if (!k)
        return 1;
    return (k & 1) ? (x * qpow((x * x) % m, k >> 1, m)) % m
                   : qpow((x * x) % m, k >> 1, m) % m;
}

//!=====================================================
// todo define the funcs i need
void solve() {
    
}
//!=====================================================

signed main() {
    clock_t c1 = clock();
#ifdef LOCAL
    freopen("data/in.in", "r", stdin);
    freopen("data/out.out", "w", stdout);
#endif
    int T = 1;
    if (mutliinput)
        cin >> T;
    while (T--)
        solve();
    cerr << "Time Used:" << clock() - c1 << "(ms)" << endl;
    return 0;
}