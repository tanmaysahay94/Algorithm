#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MOD 1000000007
#define MAX 200005

typedef long long LL;
typedef pair<LL, LL> ii;

LL fact[MAX], inv_fact[MAX];
LL dp[MAX];

LL power(LL x, LL p, LL mod)
{
	if (p == 0)
		return 1;
	LL ans = 1, y = x % mod;
	while (p) 
	{
		if (p & 1)
			ans = (ans * y) % mod;
		y = (y * y) % mod;
		p = p / 2;
	}
	return ans;
}

LL inv_mod(LL a, LL mod) 
{
	return power(a, mod - 2, mod);
}

LL nCr(LL n, LL r) 
{
	return ((fact[n] * inv_fact[r]) % MOD * inv_fact[n-r]) % MOD;
}

LL get_ways(LL a, LL b, LL c, LL d) 
{
	LL rows = abs(c - a);
	LL cols = abs(d - b);
	return nCr(rows + cols, cols);
}

void precompute() 
{
	fact[0] = 1;
	inv_fact[0] = 1;
	for (LL i = 1; i < MAX; i++) 
	{
		fact[i] = (fact[i-1] * i) % MOD;
		inv_fact[i] = inv_mod(fact[i], MOD);
	}
}

int main() 
{
	precompute();
	LL n, m, k;
	vector<ii> v;
	cin >> n >> m >> k;
	for (LL i = 0; i < k; i++) 
	{
		LL x, y;
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}
	sort(v.begin(), v.end());
	LL result = get_ways(1, 1, n, m);
	for (LL i = 0; i < k; i++) 
	{
		LL &ways = dp[i];
		ways = get_ways(1, 1, v[i].F, v[i].S);
		for (LL j = 0; j < i; j++) 
		{
			if (v[j].F <= v[i].F and v[j].S <= v[i].S) 
			{
				LL t_ways = (dp[j] * get_ways(v[j].F, v[j].S, v[i].F, v[i].S)) % MOD;
				ways = (ways - t_ways + MOD) % MOD;
			}
		}
		result = (result - (ways * get_ways(v[i].F, v[i].S, n, m)) % MOD + MOD) % MOD;
	}
	cout << result << endl;
	return 0;
}
