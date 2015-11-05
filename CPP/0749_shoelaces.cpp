#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

set<int> graph[111];
int n, m;

int main()
{
	optimizeIO();
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		graph[a].insert(b);
		graph[b].insert(a);
	}
	int ans = 0;
	bool run = true;
	set<int>::iterator it;
	while (run)
	{
		bool tmp = false;
		vector<int> processed(n, false);
		for (int i = 0; i < n; i++)
			if ((int) graph[i].size() == 1 and not processed[i])
			{
				tmp = true;
				it = graph[i].begin();
				int nbh = *it;
				graph[i].erase(nbh);
				graph[nbh].erase(i);
				processed[i] = processed[nbh] = true;
			}
		if (tmp) ans++;
		tmp = false;
		for (int i = 0; i < n and tmp == false; i++)
			if ((int) graph[i].size() == 1)
				tmp = true;
		run = run and tmp;
	}
	cout << ans << endl;
	return 0;
}
