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
	int n, m;
	cin >> n >> m;
	vector<int> boys(n), girls(m);
	int b, g, idx;
	cin >> b;
	for (int i = 0; i < b; i++)
	{
		cin >> idx;
		boys[idx] = 1;
	}
	cin >> g;
	for (int i = 0; i < g; i++)
	{
		cin >> idx;
		girls[idx] = 1;
	}
	for (int i = 0; i < m * n * max(m, n); i++)
	{
		int bidx = i % n;
		int gidx = i % m;
		if (boys[bidx] == 1 or girls[gidx] == 1)
			boys[bidx] = girls[gidx] = 1;
	}
	bool ans = true;
	for (int i = 0; i < n; i++)
		ans = ans and boys[i];
	for (int i = 0; i < m; i++)
		ans = ans and girls[i];
	if (ans)
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}
