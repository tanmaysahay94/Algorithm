#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

typedef long long LL;

vector<LL> weight, cost;
vector<vector<LL> > dp;
LL s, n;

LL knapsack(LL wt, LL it)
{
	if (it < 0 or wt < 0)
		return 0;
	if (dp[it][wt] != -1)
		return dp[it][wt];
	if (wt < weight[it])
		return dp[it][wt] = knapsack(wt, it - 1);
	return dp[it][wt] = max(knapsack(wt, it - 1), knapsack(wt - weight[it], it - 1) + cost[it]);
}

int main()
{
	optimizeIO();
	cin >> s >> n;
	weight = cost = vector<LL> (n);
	dp = vector<vector<LL> > (n, vector<LL> (s + 1, -1));
	for (int i = 0; i < n; i++)
		cin >> weight[i] >> cost[i];
	cout << knapsack(s, n - 1);
	return 0;
}
