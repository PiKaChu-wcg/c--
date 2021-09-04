
#include<vector>
#define ll long long 
const int MAXSIZE=100000;
const int mod=10000;

long long  fac[MAXSIZE],ifac[MAXSIZE],inv[MAXSIZE];
void invmod(int k) {
    int u = 1; for (int i = 1; i <= k; ++i) u = (ll)u * i % mod;
    fac[0] = ifac[0] = fac[1] = ifac[1] = inv[1] = 1;
    for (int i = 2; i <= k; ++i) {
        inv[i] = mod - (ll)(mod / i) * inv[mod % i] % mod;
        fac[i] = (ll)fac[i - 1] * i % mod;
        ifac[i] = (ll)ifac[i - 1] * inv[i] % mod;
    }
}