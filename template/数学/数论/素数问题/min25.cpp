#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1000010;
struct Min25 {

    ll prime[N], id1[N], id2[N], flag[N], ncnt, m;

    ll g[N], sum[N], a[N], T, n;

    inline int ID(ll x) {
        return x <= T ? id1[x] : id2[n / x];
    }

    inline ll calc(ll x) {
        return x * (x + 1) / 2 - 1;
    }

    inline ll f(ll x) {
        return x;
    }
    inline void Init() {
        memset(prime, 0, sizeof(prime));
        memset(id1, 0, sizeof(id1));
        memset(id2, 0, sizeof(id2));
        memset(flag, 0, sizeof(flag));
        memset(g, 0, sizeof(g));
        memset(sum, 0, sizeof(sum));
        memset(a, 0, sizeof(a));
        ncnt = m = T = n = 0;
    }
    inline void init() {
        T = sqrt(n + 0.5);
        for (int i = 2; i <= T; i++) {
            if (!flag[i]) prime[++ncnt] = i, sum[ncnt] = sum[ncnt - 1] + i;
            for (int j = 1; j <= ncnt && i * prime[j] <= T; j++) {
                flag[i * prime[j]] = 1;
                if (i % prime[j] == 0) break;
            }
        }
        for (ll l = 1; l <= n; l = n / (n / l) + 1) {
            a[++m] = n / l;
            if (a[m] <= T) id1[a[m]] = m; else id2[n / a[m]] = m;
            g[m] = calc(a[m]);
        }
        for (int i = 1; i <= ncnt; i++)
            for (int j = 1; j <= m && (ll)prime[i] * prime[i] <= a[j]; j++)
                g[j] = g[j] - (ll)prime[i] * (g[ID(a[j] / prime[i])] - sum[i - 1]);
    }

    inline ll solve(ll x) {
        if (x <= 1) return x;
        return n = x, init(), g[ID(n)];
    }

}a;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        ll n, k;
        cin >> n >> k;
        a.Init();
        ll sum = 0;
        if (n >= 3) {
            if ((n + 4) & 1) sum = (n - 1) / 2 % k * ((n + 4) % k) % k;
            else sum = (n + 4) / 2 % k * ((n - 1) % k) % k;
        }
        sum = (sum + a.solve(n + 1) % k) % k;
        cout << (sum + k - 2) % k << '\n';
    }
    return 0;
}
