#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#define _USE_MATH_DEFINES
#include <cmath>
#include <map>
#include <queue>
#include <deque>
#include <functional>
#include <algorithm>
#include <cassert>
#include <utility>
#include <bits/stdc++.h>
#include <stack>
#include <cstdlib>
#include <set>

using namespace std;

int main()
{
	int n, m, i, a, b, rem, j, connected = 0;
	cin >> n >> m;
	vector<bool> visited(n, false);
	vector<vector<int> > graph(n);
	for (i = 0; i < m; i++)
	{
		cin >> a >> b;
		a--; b--;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (i = 0; i < n; i++)
	{
		if (not visited[i])
		{
			connected++;
			queue<int> q;
			q.push(i);
			visited[i] = true;
			while (not q.empty())
			{
				rem = q.front();
				q.pop();
				for (i = 0; i < graph[rem].size(); i++)
					if (not visited[graph[rem][i]])
					{
						q.push(graph[rem][i]);
						visited[graph[rem][i]] = true;
					}
			}
		}
	}
	cout << (long long) pow(2, n - connected) << endl;
	return 0;
}
