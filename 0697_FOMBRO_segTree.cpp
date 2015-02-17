#include <bits/stdc++.h>
 
using namespace std;
 
void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}
 
long long powMod(long long base, long long pow, long long mod)
{
	base %= mod;
	long long ret = 1;
	while (pow)
	{
		if (pow & 1)
			ret = (ret * base) % mod;
		base = (base * base) % mod;
		pow >>= 1;
	}
	return ret;
}
 
vector<long long> fwd(1e6 + 5), bwd(1e6 + 5), tree(1e7);

void init(long long idx, long long l, long long r, long long m)
{
	if (l == r)
	{
		tree[idx] = l % m;
		return;
	}
	long long mid = (l + r) >> 1;
	init(2 * idx, l, mid, m);
	init(2 * idx + 1, mid + 1, r, m);
	tree[idx] = (tree[2 * idx] * tree[2 * idx + 1]) % m;
}

long long query(long long idx, long long rl, long long rr, long long sl, long long sr, long long m)
{
	long long v1, v2;
	if (rr < sl or rl > sr or sl > sr)
		return 1;
	if (sl <= rl and sr >= rr)
		return tree[idx];
	long long mid = (rl + rr) >> 1;
	if (mid >= sr)
		return query(2 * idx, rl, mid, sl, sr, m);
	else if (mid < sl)
		return query(2 * idx + 1, mid + 1, rr, sl, sr, m);
	v1 = query(2 * idx, rl, mid, sl, mid, m);
	v2 = query(2 * idx + 1, mid + 1, rr, mid + 1, sr, m);
	return (v1 * v2) % m;
}

int main()
{
	optimizeIO();
	long long t, n, m, q, r;
	cin >> t;
	while (t--)
	{
		cin >> n >> m >> q;
		init(1, 1, n, m);
		fwd[0] = fwd[1] = 1;
		for (long long i = 2; i <= n; i++)
			fwd[i] = (fwd[i - 1] * powMod(i, i - 1, m)) % m;
		bwd[n] = n;
		for (long long i = n - 1, j = 2; i >= 1; i--, j++)
			bwd[i] = (bwd[i + 1] * powMod(i, j, m)) % m;
		while (q--)
		{
			cin >> r;
			r = min(r, n - r);
			long long ans = query(1, 1, n, r + 1, n - r, m);
			ans = powMod(ans, r, m);
			ans = (ans * fwd[r]) % m;
			ans = (ans * bwd[n - r + 1]) % m;
			cout << ans << endl;
		}
	}
	return 0;
}
