#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL n;

vector<LL> v;
vector<vector<LL> >dp;

LL f(LL s, LL e, LL d)
{
	if (dp[s][e] != -1) return dp[s][e];
	if (e < s) return 0;
	if (e == s) return dp[s][e] = d * v[e];
	return dp[s][e] = max(d * v[e] + f(s, e - 1, d + 1), d * v[s] + f(s + 1, e, d + 1));
}

int main()
{
	scanf("%lld", &n);
	v = vector<LL> (n);
	dp = vector<vector<LL> > (n + 1, vector<LL> (n + 1, -1));
	for (int i = 0; i < n; i++)
		scanf("%lld", &v[i]);
	printf("%lld\n", f(0, n - 1, 1));
	return 0;
}
