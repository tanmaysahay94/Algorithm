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

int main()
{
	bool tree = true;
	int n;
	cin >> n;
	vector<VI> G(n, VI (n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> G[i][j];
			if ((i != j and not G[i][j]) or (i == j and G[i][j]))
				tree = false;
		}
	for (int i = 0; i < n and tree; i++)
		for (int j = i + 1; j < n and tree; j++)
			if (G[i][j] != G[j][i])
				tree = false;
	for (int i = 0; i < n and tree; i++)
	{
		int node = 0;
		for (int j = 0; j < n and tree; j++)
			if (i != j and G[i][j] < G[i][node])
				node = j;
		for (int j = 0; j < n and tree; j++)
			if (abs(G[i][j] - G[node][j]) != G[i][node])
				tree = false;
	}
	if (tree) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}
