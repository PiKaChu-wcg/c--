
#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e6+1;
int mod = 998244353;

#define sub(x) (((x)%mod+mod)%mod)
long long X[maxn], Y[maxn], ot;
long long pre[maxn], suf[maxn];
long long fac[maxn], inv[maxn], ifac[maxn];

void get_inv(int n, int p) {
    inv[1] = fac[0] = fac[1] = ifac[0] = ifac[1] = 1;
    for(int i = 2; i <= n; ++ i) {
        inv[i] = (p - p/i) * inv[p%i] % p;
        fac[i] = fac[i-1] * i % p;
        ifac[i] = ifac[i-1] * inv[i] % p;
    }
}

long long lagrange(long long x) {
    long long res = 0;
    pre[0] = sub(x-X[0]);
    for(int i = 1; i <= ot; ++ i) {
        pre[i] = pre[i-1] * sub(x-X[i]) % mod;
    }
    suf[ot] = sub(x-X[ot]);
    for(int i = ot-1; i >= 0; -- i) {
        suf[i] = suf[i+1] * sub(x-X[i]) % mod;
    }
    get_inv(ot, mod); // 初始化一次即可
    for(int i = 0; i <= ot; ++ i) {
        long long y = Y[i];
        if (i > 0) y = y * pre[i-1] % mod * ifac[i] % mod;
        if (i < ot) y = y * suf[i+1] % mod * ifac[ot-i] % mod;
        if ((ot-i)&1) y = sub(-y);
        res = (res + y) % mod;
    }
    return res;
}

long long ph(long long x) {
    long long res = x, a = x;
    for(int i = 2; i <= x/i; ++ i) {
        if(a % i == 0) {
            res = res / i * (i-1);
            while(a%i == 0) a /= i;
        }
    }
    if(a>1) res = res / a * (a-1);
    return res;
}

long long fast(long long a, long long n, long long p) {
    long long res = 1;
    while(n) {
        if (n & 1) res = res * a % p;
        n >>= 1;
        a = a * a % p;
    }
    return res;
}

long long dfs(long long x, long long p, long long phi) {
    if (p == 1) return 1;
    return fast(x, dfs(x, phi, ph(phi)) + phi, p);
}

int main() {
    int n, p;
    cin >> n >> p;
    mod = p, ot = n+1;
    for(int i = 0; i <= ot; ++ i) {
        X[i] = i+1;
        Y[i] = (i+1) * sub(fast(i+1, n, p) - fast(i, n, p)) % mod;
        if (i > 0) Y[i] = (Y[i] + Y[i-1]) % mod;
    }
    cout << lagrange(dfs(n, p, ph(p))) << "\n";
    return 0;
}



