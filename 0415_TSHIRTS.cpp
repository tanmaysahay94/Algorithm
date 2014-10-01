#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;

#define SI(n) scanf("%d", &n)
#define SLL(n) scanf("%lld", &n)
#define SULL(n) scanf("%llu", &n)
#define sortv(v) sort(v.begin(), v.end())
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

const LL mod = 1e9 + 7;

vector<LL> arr[110];
vector<VLL> dp(1030, vector<LL> (110));

LL solve(LL mask, LL id, LL n)
{
	if (mask == (1 << n) - 1)
		return dp[mask][id] = 1;
	if (id == 101)
		return 0;
	if (dp[mask][id] != -1)
		return dp[mask][id];
	LL ans = solve(mask, id + 1, n);
	for (int i = 0; i < arr[id].size(); i++)
	{
		LL user = arr[id][i];
		if (mask & (1 << (user - 1)))
			continue;
		ans = (ans % mod + solve(mask | (1 << (user - 1)), id + 1, n) % mod) % mod;
	}
	return dp[mask][id] = ans;
}

void init()
{
	for (int j = 0; j < 110; j++)
		arr[j].clear();
	for (int i = 0; i < 1030; i++)
		for (int j = 0; j < 110; j++)
			dp[i][j] = -1;
}

int main()
{
	LL t, n, val;
	char c;
	SLL(t);
	while (t--)
	{
		init();
		SLL(n);
		for (int i = 0; i < n; i++)
		{
			c = 'c';
			while (c != '\n')
			{
				SLL(val);
				arr[val].pb(i + 1);
				scanf("%c", &c);
			}
		}
		cout << solve(0, 1, n) << endl;
	}
	return 0;
}
