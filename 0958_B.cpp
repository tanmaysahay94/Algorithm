#include <bits/stdc++.h>

using namespace std;

vector<int> visited(50005);

void dfs(int current, vector<int>& v)
{
	int start = current;
	current = v[start];
	while (current != start)
		current = v[current];
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> v(50005);
		visited = vector<int> (50005, 0);
		for (int i = 1; i <= n; i++)
			cin >> v[i];
		int loop = 0;
		for (int i = 1; i <= n; i++)
			if (!visited[i])
			{
				dfs(i, v);
				loop++;
			}
		cout << loop - 2 << endl;
	}
	return 0;
}
