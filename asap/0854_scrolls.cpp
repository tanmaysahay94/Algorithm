#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

typedef long long LL;

LL b, s, g;
vector<vector<LL> > v(3, vector<LL> (11));
vector<LL> stone(31);
LL dp[11][11][11][11][11][11];

LL f(LL bs, LL be, LL ss, LL se, LL gs, LL ge, LL idx)
{
	if (be < bs or se < ss or ge < gs)
		return 0;
	if (dp[bs][be][ss][se][gs][ge] != -1)
		return dp[bs][be][ss][se][gs][ge];
	LL mul = stone[idx];
	LL add = 0;
	if (be == bs)
		add += mul * v[0][be];
	if (se == ss)
		add += mul * v[1][se];
	if (ge == gs)
		add += mul * v[2][ge];
	LL ret = f(bs + 1, be, ss, se, gs, ge, idx + 1);
	ret = max(ret, f(bs, be - 1, ss, se, gs, ge, idx + 1));
	ret = max(ret, f(bs, be, ss + 1, se, gs, ge, idx + 1));
	ret = max(ret, f(bs, be, ss, se - 1, gs, ge, idx + 1));
	ret = max(ret, f(bs, be, ss, se, gs + 1, ge, idx + 1));
	ret = max(ret, f(bs, be, ss, se, gs, ge - 1, idx + 1));
	ret += add;
	return dp[bs][be][ss][se][gs][ge] = ret;
}

int main()
{
	optimizeIO();
	memset(dp, -1, sizeof(dp));
	cin >> b >> s >> g;
	for (int i = 0; i < b; i++)
		cin >> v[0][i];
	for (int i = 0; i < s; i++)
		cin >> v[1][i];
	for (int i = 0; i < g; i++)
		cin >> v[2][i];
	for (int i = 0; i < b + s + g; i++)
		cin >> stone[i];
	cout << f(0, b - 1, 0, s - 1, 0, g - 1, 0) << endl;
	return 0;
}
