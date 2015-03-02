#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int main()
{
	optimizeIO();
	vector<int> g[111111];
	int n, m, a, b;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
	}
	return 0;
}
