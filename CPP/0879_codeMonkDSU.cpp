#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

typedef long long LL;

vector<int> parent(100001);

int ancestor(int x)
{
	if (parent[x] != x)
		parent[x] = ancestor(parent[x]);
	return parent[x];
}

void merge(int x, int y)
{
	int xx = ancestor(x);
	int yy = ancestor(y);
	if (xx != yy)
		parent[xx] = yy;
}

int main()
{
	optimizeIO();
	int t;
	cin >> t;
	while (t--)
	{
		LL n, m;
		cin >> n >> m;
		map<int, LL> mp;
		for (int i = 0; i < n; i++)
			parent[i] = i;
		for (int i = 0; i < m; i++)
		{
			int x, y;
			cin >> x >> y;
			x--; y--;
			merge(x, y);
		}
		for (int i = 0; i < n; i++)
			parent[i] = ancestor(i);
		vector<LL> banana(n);
		for (int i = 0; i < n; i++)
			cin >> banana[i];
		for (int i = 0; i < n; i++)
			mp[parent[i]] += banana[i];
		LL ans = LLONG_MIN;
		for (auto zzz: mp)
			ans = max(ans, zzz.second);
		cout << ans << '\n';
	}
	return 0;
}
