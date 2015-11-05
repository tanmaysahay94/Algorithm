#include <bits/stdc++.h>

using namespace std;

typedef long long 				LL;
typedef unsigned long long 		ULL;
typedef vector<int> 			VI;
typedef vector<LL> 				VLL;
typedef pair<int, int> 			PII;
typedef pair<LL, LL> 			PLL;

#define si(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define sull(n) scanf("%llu", &n)
#define sortv(v) sort(v.begin(), v.end())
#define each(it, v) for(__typeof(v.begin()) it(v.begin()); it != v.end(); it++)
#define sz(v) v.size()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

VI sol;

void backtrack(vector<VI>& table, VI& v, VI& u, int i, int j)
{
	if (i == 0 or j == 0)
		return;
	else if (v[i - 1] == u[j - 1])
	{
		sol.pb(v[i - 1]);
		backtrack(table, v, u, i - 1, j - 1);
	}
	else if (table[i][j - 1] > table[i - 1][j])
		backtrack(table, v, u, i, j - 1);
	else
		backtrack(table, v, u, i - 1, j);
}

int main()
{
	int n, m;
	cin >> n >> m;
	VI v(n), u(m);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	for (int i = 0; i < m; i++)
		cin >> u[i];
	vector<VI> table = vector<VI> (n + 1, VI(m + 1, 0));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (v[i-1] == u[j-1])
				table[i][j] = table[i-1][j-1] + 1;
			else
				table[i][j] = max(table[i-1][j], table[i][j-1]);
	for (int i = 0; i <= n; i++, cout << endl)
		for (int j = 0; j <= m; j++)
			cout << table[i][j] << ' ';
	backtrack(table, v, u, n, m);
	for (int i = sol.size() - 1; i >= 0; i--, cout << ' ')
		cout << sol[i];
	cout << endl;
	return 0;
}
