#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int mod = 1e9 + 7;

void scan(vector<LL>& x, vector<LL>& y)
{
	for (int i = 0; i < (int) x.size(); i++)
		scanf("%lld%lld", &x[i], &y[i]);
}

void fix(LL& x)
{
	while (x < 0)
		x += mod;
}

LL solve(vector<LL>& x)
{
	sort(x.begin(), x.end());
	LL ret = 0;
	for (int i = x.size() - 1; i >= 0; i--)
		x[i] -= x[0];
	vector<LL> orig(x);
	for (int i = 1; i < (int) x.size(); i++)
		x[i] += x[i - 1];
	for (int i = 1; i < (int) x.size(); i++)
		x[i] %= mod;
	for (int i = 1; i < (int) x.size(); i++)
	{
		LL val = x[x.size() - 1] - x[i - 1];
		val %= mod;
		fix(val);
		LL rem = orig[i - 1] * ((LL) (x.size() - i));
		rem %= mod;
		fix(rem);
		val -= rem;
		val %= mod;
		fix(val);
		ret += val;
		ret %= mod;
		fix(ret);
	}
	return ret;
}

int main()
{
	LL n;
	LL ans = 0;
	scanf("%lld", &n);
	vector<LL> x(n), y(n);
	scan(x, y);
	ans += solve(x);
	ans %= mod;
	fix(ans);
	ans += solve(y);
	ans %= mod;
	fix(ans);
	printf("%lld\n", ans);
	return 0;
}
