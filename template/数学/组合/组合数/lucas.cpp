#include<bits/stdc++.h>
using namespace std;
namespace exlucas
{
	const int N = 1e6;
	typedef long long ll;
	ll n, m, p;
    //快速幂
	inline ll power(ll a, ll b, const ll p = LLONG_MAX)
	{
		ll ans = 1;
		while (b)
		{
			if (b & 1)
				ans = ans * a % p;
			a = a * a % p;
			b >>= 1;
		}
		return ans;
	}
	ll fac(const ll n, const ll p, const ll pk)
	{
	    //求n!/p^a % p^k
	    //若要求n! % p^k  那还要多算上p^(n/p)的贡献
		if (!n) return 1;
		ll ans = 1;
		for (int i = 1; i < pk; i++)
			if (i % p) ans = ans * i % pk;
		ans = power(ans, n / pk, pk);
		for (int i = 1; i <= n % pk; i++)
			if (i % p) ans = ans * i % pk;
		return ans * fac(n / p, p, pk) % pk;
	}
	ll exgcd(const ll a, const ll b, ll &x, ll &y)
	{
		if (!b)
		{
			x = 1, y = 0;
			return a;
		}
		ll xx, yy, g = exgcd(b, a % b, xx, yy);
		x = yy;
		y = xx - a / b * yy;
		return g;
	}
	ll inv(const ll a, const ll p)
	{
		ll x, y;
		exgcd(a, p, x, y);
		return (x % p + p) % p;
	}
	ll C(const ll n, const ll m, const ll p, const ll pk)
	{
	    //求C(n,m) % p^k
		if (n < m) return 0;
		ll f1 = fac(n, p, pk), f2 = fac(m, p, pk), f3 = fac(n - m, p, pk), cnt = 0;
		for (ll i = n; i; i /= p) cnt += i / p;
		for (ll i = m; i; i /= p) cnt -= i / p;
		for (ll i = n - m; i; i /= p) cnt -= i / p;
		return f1 * inv(f2, pk) % pk * inv(f3, pk) % pk * power(p, cnt, pk) % pk;
	}
	ll a[N], c[N];
	int cnt;
	inline ll CRT()
	{
		ll M = 1, ans = 0;
		for (int i = 0; i < cnt; i++) M *= c[i];
		for (int i = 0; i < cnt; i++)
            ans = (ans + a[i] * (M / c[i]) % M * inv(M / c[i], c[i]) % M) % M;
		return ans;
	}
	ll exlucas(const ll n, const ll m, ll p)
	{
	    //将p分解成p^i的形式，各自求解，然后CRT
		ll tmp = sqrt(p);
		for (int i = 2; p > 1 && i <= tmp; i++)
		{
			ll tmp = 1;
			while (p % i == 0) p /= i, tmp *= i;
			if (tmp > 1)
				a[cnt] = C(n, m, i, tmp), c[cnt++] = tmp;
		}
		if (p > 1)
			a[cnt] = C(n, m, p, p), c[cnt++] = p;
		return CRT();
	}
}
int main()
{
    long long n,m,p;
    cin>>n>>m>>p;
	cout<<exlucas::exlucas(n,m,p)<<endl;
	return 0;
}
