#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int g[26][26] = {0};
int done[26] = {0};

void add(char a, char b)
{
	g[a-'a'][b-'a'] = 1;
}

int main()
{
	optimizeIO();
	int n;
	cin >> n;
	vector<string> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	bool possible = true;
	for (int i = 1; i < n and possible; i++)
	{
		int l1 = v[i-1].length();
		int l2 = v[i].length();
		int j;
		for (j = 0; j < min(l1, l2); j++)
			if (v[i-1][j] != v[i][j])
			{
				add(v[i-1][j], v[i][j]);
				break;
			}
		if (j == min(l1, l2) and l1 > l2)
			possible = false;
	}
	if (not possible)
	{
		cout << "Impossible\n";
		return 0;
	}
	vector<int> topo;
	queue<int> q;
	for (int i = 0; i < 26; i++)
	{
		bool incoming = false;
		for (int j = 0; j < 26; j++)
			if (g[j][i])
			{
				incoming = true;
				break;
			}
		if (!incoming)
		{
			done[i] = 1;
			topo.push_back(i);
			q.push(i);
		}
	}
	while (!q.empty())
	{
		int rem = q.front(); q.pop();
		for (int i = 0; i < 26; i++)
			g[rem][i] = 0;
		for (int i = 0; i < 26; i++)
		{
			bool incoming = false;
			for (int j = 0; j < 26; j++)
				if (g[j][i])
				{
					incoming = true;
					break;
				}
			if (!incoming and !done[i])
			{
				done[i] = 1;
				topo.push_back(i);
				q.push(i);
			}
		}
	}
	bool still_there = false;
	for (int i = 0; i < 26 and not still_there; i++)
		for (int j = 0; j < 26 and not still_there; j++)
			if (g[i][j])
				still_there = true;
	if (still_there or topo.size() < 26)
		possible = false;
	if (not possible)
	{
		cout << "Impossible\n";
		return 0;
	}
	for (int i = 0; i < (int) topo.size(); i++)
		printf("%c", topo[i] + 'a');
	cout << endl;
	return 0;
}
