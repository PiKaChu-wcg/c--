////////////////////////////////////////////////
////Author       : PiKaChu_wcg
////Date         : 2021-08-31 22:17:46
////LastEditors  : PiKachu_wcg
////LastEditTime : 2021-09-03 10:15:04
////FilePath     : \c++\tmp.cpp
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
//!===============================================================================================================
// todo define sum const var
const int mod = 1e9 + 7;
const bool mutliinput = false;
const int maxn = 1e5;
//!================================================================================================================
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1}, dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
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
ll qpow(ll x, ll k = mod - 2, ll m = mod)
{
    if (!k)
        return 1;
    return (k & 1) ? (x * qpow((x * x) % m, k >> 1, m)) % m : qpow((x * x) % m, k >> 1, m) % m;
}
//!===============================================================================================================

//todo declare some var i need
int n, m;
class Solution {
   public:
    static const long long maxn = 100;
    static const long long mod = 1e9 + 7;
    long long dp[maxn][maxn];
    bool used[maxn][maxn];
    int numberOfSets(int n, int k) {
        long long res = 0;
        for (int i = k; i <= n; i++) {
            res += dfs(i, k);
            res %= mod;
        }
        return res;
    }
    long long dfs(int n, int k) {
        if (used[n][k])
            return dp[n][k];
        used[n][k] = 1;
        if (k == 0)
            return dp[n][k] = 1;
        if (n == 1 + k)
            return dp[n][k] = 1;
        if (n <= k)
            return dp[n][k] = 0;
        dp[n][k] = dfs(n - 1, k) + dfs(n - 1, k - 1);
        dp[n][k] %= mod;
        return dp[n][k];
    }
}t;
// todo define the funcs i need
void solve() {
    cin >> n >> m;
    debug(t.numberOfSets(n, m));
}
//!===============================================================================================================

signed main()
{
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