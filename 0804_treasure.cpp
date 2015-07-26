#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

const int maxn = 30001;
const int maxr = 505;
const int offs = 247;
int n, d;

int dp[maxn][maxr];
int gm[maxn];

int rec(int cur, int jmp)
{
	int diff = jmp - d + offs;
	if (cur >= maxn)
		return 0;
	if (dp[cur][diff] != -1)
		return dp[cur][diff];
	int& ret = dp[cur][diff];
	ret = 0;
	ret = rec(cur + jmp, jmp);
	if (jmp != 1)
		ret = max(ret, rec(cur + jmp - 1, jmp - 1));
	ret = max(ret, rec(cur + jmp + 1, jmp + 1));
	ret += gm[cur];
	return ret;
}

int main()
{
	optimizeIO();
	memset(dp, -1, sizeof(dp));
	memset(gm, 0, sizeof(gm));
	cin >> n >> d;
	for (int i = 0; i < n; i++)
	{
		int p;
		cin >> p;
		gm[p]++;
	}
	cout << rec(d, d);
	return 0;
}
